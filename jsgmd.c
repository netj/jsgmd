/****************************************************************************
 * 4541.681A Genetic Algorithm (2005/Spring) Áö¼ö±Í¹®µµ                     *
 * 2004-23580  Jaeho Shin <netj@ropas.snu.ac.kr>                            *
 * Created: 2005-04-26                                                      *
 ****************************************************************************/

#ifndef A
#define A 3
#endif
#ifndef B
#define B 8
#endif
#if A>B
#error "A must be less than or equal to B"
#endif
#define SUM(n) ((n)*((n)+1)/2)
#define M (2*(SUM(B-1) - SUM(A-1)) + B)
#define N (4*(SUM(B) - SUM(A-1)) + 2*(B-A+1))

#define P 512
#define K (P * 1 / 2)
#define F(mean, var) ((mean) / M / N -(var))
#define Fopt(mean, var) ((mean) - sqrt((var)* N))
#define SELPRESS 3
#define MUTRATE N/4
#define REPLACE_WORST K/5
//#define XOVER_CUTS 2
#define XOVER_2DCUTMOVE 3

//#define OPTFULL
//#define OPTMAXIMPROVE 1.5
//#define OPTAPPLY K/4

//#define ENCODING_RANDOM

//#define EXPLOSION P/4
#define EXPLOSION_DIFF 0.005
#define EXPLOSION_THRESHOLD K/2
#define SWAPRATE 2
#define HEXSPINRATE 2

#define DONE \
    ((solfound > 0 && (fbestidx == var0idx || gbest_age > P * 100 / N)) \
     || gbest_age > P * 2000 / N)

#ifdef DEBUG
#define debug(fmt...) fprintf(stderr, "## " fmt)
#else
#define debug(fmt...)
#endif
#define message(fmt...) fprintf(stderr, "# " fmt)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <time.h>


typedef short idx_t;
typedef short gene;
typedef gene *chromo;
typedef gene Chromo[N];
typedef double fitness_t;
typedef struct _evaluation {
    fitness_t fitness, var, mean;
    int age;
} Evaluation;
typedef Evaluation *evaluation;

#define new_chromosome() malloc(N * sizeof(gene))
#define copy_chromosome(dest, src) memcpy(dest, src, N * sizeof(gene))
#define new_evaluation() malloc(sizeof(Evaluation))

int generations = 0,
    solfound = 0;
chromo pop[P], offspring[K];
evaluation eval[P], offspring_eval[K];
fitness_t fbest = -1.0/0.0, fworst = 1.0/0.0,
          fsum = 0, varsum = 0, meansum = 0;
int find_worst = 0,
    find_best = 0,
    fbestidx = -1,
    var0idx = -1;
int parent1[K], parent2[K];

fitness_t gbest = -1.0/0.0;
int gbest_age = 1;

#ifdef ENCODING_RANDOM
int encoding_age = 1;
#endif

fitness_t ffsum = 0, ff[P];
int rank[P];

#ifdef EXPLOSION
int explosion_countdown = EXPLOSION_THRESHOLD;
#endif

#define rnd_one() \
    (((double)random())/((double)0x7fffffff + 1.0))
#define rnd_f(ub) ((double)(ub) * ((rnd_one() + rnd_one()) / 2.0))
#define rnd(n) ((unsigned int)rnd_f(n))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))


/****************************************************************************
 * Hexagon Structure                                                        *
 ****************************************************************************/

#define prepare_C(i) \
        C = B - ((i < B-A) ? B-A - i : i - (B-A))
#define prepare_LH(i) L = (i < B-A) ? 1 : 0, \
                      H = (i > B-A) ? 1 : 0 
#define prepare_LHC(i) \
        prepare_LH(i), prepare_C(i)
/* NOTE: Following variables must be defined within the same scope:
 *       idx_t i,j,C; char L,H;  */

#define for_each_i \
        for (i=0, C=A, \
                prepare_LH(i); \
                i<=2*(B-A); \
                i++, C += L ? +1 : -1, \
                prepare_LH(i) \
            )
#define for_each_j \
        for (j=0; j<C; j++)
#define for_each_ij for_each_i for_each_j

idx_t idx[2*(B-A)+1][B][6];
idx_t shares[N][3][3];
char numshares[N];
/* filling idx */
void initialize_encoding() {
    /* initialize idx for gene # assignment */
    idx_t i,j,k, C, L,H;
    for_each_ij {
        for (k=0; k<6; k++)
            idx[i][j][k] = N+1;
    }
    int gene_idx_cnt = 0;
#ifdef ENCODING_RANDOM
    int gene_idx[N] = {0};
    int next_gene_idx() {
        int c = rnd(N - gene_idx_cnt--);
        int i = rnd(N);
        while (c >= 0) {
            while (gene_idx[i])
                i = (i+1) % N;
            c--;
        }
        gene_idx[i] = 1;
        return i;
    }
#else
#define next_gene_idx()  gene_idx_cnt++
    // TODO: There must be a better encoding..
#endif
    /* assign gene indexes */
    for_each_ij {
#define if_exists(i0, j0) \
        if (0<=i0 && i0<=2*(B-A) && 0<=j0 && j0<C+(i0-i)*(L?1:H?-1:-(i0-i)))
#define assign(i,j,k) \
        numshares[gene_idx]++, \
        idx[i][j][k] = gene_idx, \
        share = shares[gene_idx][s++], \
        share[0] = i, share[1] = j, share[2] = k
#define share(k, i1, j1, k1, i2, j2, k2) \
        if (idx[i][j][k] > N) { \
            int gene_idx = next_gene_idx(); \
            idx_t *share; idx_t s = 0; \
            numshares[gene_idx] = 0; \
                                  assign(i   ,j   ,k ); \
            if_exists(i+i1, j+j1) assign(i+i1,j+j1,k1); \
            if_exists(i+i2, j+j2) assign(i+i2,j+j2,k2); \
        }
        share(0,  -1, -1+H, 4,  00, -1+0, 2);
        share(1,  -1, 00+H, 2,  -1, -1+H, 3);
        share(2,  00, +1+0, 0,  -1, 00+H, 4);
        share(3,  +1, 00+L, 1,  00, +1+0, 5);
        share(4,  +1, -1+L, 2,  +1, 00+L, 0);
        share(5,  00, -1+0, 3,  +1, -1+L, 1);
#undef share
#undef assign
#undef if_exists
#undef next_gene_idx
    }
}

void print_chromo(FILE *out, chromo c) {
    idx_t i, j, C;
#define print(fmt...) fprintf(out, fmt)
#define indent() for (j=C; j<B; j++) print("    ");
    for (C=A, i=0; C<=B; C++, i++) {
        indent(); for_each_j print("    %3d ", c[idx[i][j][1]]); print("\n");
        indent(); for_each_j print("%3d     ", c[idx[i][j][0]]);
        print("%3d\n", c[idx[i][j-1][2]]);
    }
    for (C=B, i=B-A; C>=A; C--, i++) {
        indent(); for_each_j print("%3d     ", c[idx[i][j][5]]);
        print("%3d\n", c[idx[i][j-1][3]]);
        indent(); for_each_j print("    %3d ", c[idx[i][j][4]]); print("\n");
    }
#undef print
#undef indent
}

/* sum of all points in hexagon i,j */
inline int hexsum(chromo c, idx_t i, idx_t j) {
    int s = 0;
    idx_t k;
    idx_t *ij = idx[i][j];
    for (k=0; k<6; k++)
        s += c[ij[k]];
    return s;
}

/* evaluation of variance, mean, fitness for a given chromosome */
void evaluate(chromo c, evaluation e) {
    int s, sum = 0, sqsum = 0;
    idx_t i,j,C; char L,H;
    for_each_ij {
        s = hexsum(c,i,j);
        sum += s;
        sqsum += s*s;
    }
    fitness_t mean   = (fitness_t)sum / M,
              sqmean = (fitness_t)sqsum / M;
    e->mean     = mean;
    e->var      = sqmean - mean*mean;
    e->fitness  = F(mean, e->var);
}

inline fitness_t fitness(int sum, int sqsum) {
    fitness_t mean = (fitness_t)sum / M;
    return Fopt(mean, (fitness_t)sqsum / M - mean*mean);
}

/* exhaustive local optimization */
inline void exhaustive_opt(chromo c) {
    idx_t i,j,C, g1,g2, *share, L,H, m,n,cm, s,s1,s2;
    int hsum[2*(B-A)+1][B], p,q;
    int sqsum = 0, sum = 0, d, newsum, newsqsum;
    for_each_ij {
        d = hexsum(c,i,j);
        hsum[i][j] = d;
        sum += d;
        sqsum += d*d;
    }
    fitness_t orig = fitness(sum, sqsum), new;
#ifdef OPTMAXIMPROVE
    fitness_t init = orig;
#endif
#ifndef OPTFULL
    /* build inverse map */
    idx_t inv[N+1], g;
    for (g=0; g<N; g++)
        inv[c[g]] = g;
#endif
#define prepare(S, h, g) \
        S = numshares[g]; \
        for (h=0,s=0; s<S; s++) \
            share = shares[g][s], h += hsum[share[0]][share[1]];
    char changed;
    do {
        changed = 0;
#ifdef OPTFULL
        /* for every pair of genes */
        for (g1=0; g1<N-1; g1++) {
            prepare(m,p, g1);
            for (g2=g1+1; g2<N; g2++)
#else
        /* for each consecutive gene values */
        g1 = inv[1];
        prepare(m,p, g1);
#define d 1
        for (g=2;  g<=N;  g1=g2,m=n,p=q,g++) {
            g2 = inv[g];
#endif
            /* try swapping */
            {
                prepare(n,q, g2);
                /* find common ones */
                for (cm=0, s1=0; s1<m; s1++)
                    for (s2=0; s2<n; s2++)
                        if (shares[g1][s1][0] == shares[g2][s2][0] &&
                                shares[g1][s1][1] == shares[g2][s2][1])
                            cm++;
                if (m+n-2*cm > 0) {
                    /* compute the difference of fitness when g1, g2 are swapped */
#ifdef OPTFULL
                    d = c[g2] - c[g1];
#endif
                    newsum = sum + d*(m-n);
                    newsqsum = sqsum + d*(2*(p-q) + d*(m+n-2*cm));
                    new = fitness(newsum, newsqsum);
                    /* XXX: gcc -O2 bug.
                     *      new > orig is true even when new == orig. */
                    if (new > orig && new != orig
                            && (newsqsum != sqsum || newsum != sum)) {
                        /* if increased, then swap g1 and g2 */
#ifdef OPTFULL
                        tmp = c[g1], c[g1] = c[g2], c[g2] = tmp;
#else
                        c[g1] = g, c[g2] = g-1;
#endif
#ifdef OPTMAXIMPROVE
                        if (new / init > OPTMAXIMPROVE)
                            return;
#endif
                        /* update relevant values */
                        changed = 1;
                        orig = new, sum = newsum, sqsum = newsqsum;
#define update_hsum(g, S, d) \
                        for (s=0; s<S; s++) \
                            share = shares[g][s], \
                            hsum[share[0]][share[1]] += d;
                        update_hsum(g1,m,+d);
                        update_hsum(g2,n,-d);
                        p += (m-cm)*d;
#ifndef OPTFULL
                        q -= (n-cm)*d;
                        inv[g-1] = g2, inv[g] = g1;
                        g2 = g1;
#undef d
#endif
                    }
                }
            }
        }
    } while (changed);
#undef update_hsum
#undef prepare
}



/****************************************************************************
 * Output & Auxilliary procedures                                           *
 ****************************************************************************/

void error(char *msg) {
    message("error: %s\n", msg);
    exit(4);
}

void print_pop(FILE *out, int n) {
    evaluation e = eval[n];
    if (e->var == 0)
        fprintf(out, "found: ");
    fprintf(out, "sum=%8.4f var=%8.4f fitness=%8.4f age=%d\n",
            e->mean, e->var, e->fitness, e->age);
    fprintf(out, "-->8--\n");
    print_chromo(out, pop[n]);
    fprintf(out, "--8<--\n");
#ifdef ENCODING_RANDOM
    printf("ENCODING: age=%d\n", encoding_age);
    idx_t i,j,k, C, L,H;
    Chromo _c; chromo c = &_c;
    for_each_ij {
        for (k=0; k<6; k++)
            c[idx[i][j][k]] = idx[i][j][k];
    }
    printf("-->8--\n");
    print_chromo(out, c);
    printf("--8<--\n");
#endif
}

int best_pop() {
    int n, b = 0;
    fitness_t f = eval[b]->fitness;
    for (n=1; n<P; n++)
        if (eval[n]->fitness > f)
            b = n, f = eval[n]->fitness;
    return b;
}

#define print_summary(o, s, m, v, f) \
    fprintf(o, s "m=%7.3f v=%5.3f f=%7.3f", m, v, f);
#define print_summary_pop(o) \
    print_summary(o, "pop ", meansum / P, varsum / P, fsum / P)

void print_status(FILE *out) {
    fprintf(out, "generation #%d: ", generations);
    print_summary_pop(out);
    fprintf(out, "\n");
}

void ping(int x) {
    fprintf(stderr, "%d: ", generations);
    print_summary_pop(stderr);
    fprintf(stderr, " F=%5.3f/%d", ffsum/P, SELPRESS);
    fprintf(stderr, "; ");
    int b = best_pop();
    print_summary(stderr, "best ",
            eval[b]->mean, eval[b]->var, eval[b]->fitness);
    fprintf(stderr, " a=%d", eval[b]->age);
    fprintf(stderr, " F=%5.3f/%d", ff[b], SELPRESS);
    fprintf(stderr, "\n");
}

void status(int x) {
    FILE *out = (x == SIGQUIT) ? stderr : stdout;
    /* show the best if it wasn't a solution */
    int b = best_pop();
    if (eval[b]->var != 0)
        print_status(out),
        fprintf(out, "best: "),
        print_pop(out, b);
}

void ga_info() {
    printf("jsgmd%d: M=%d A=%d B=%d P=%d K=%d", N, M, A, B, P, K);
#ifdef SELPRESS
    printf(" sp=%d", SELPRESS);
#endif
    printf(" xover="
#ifdef XOVER_CUTS
            "%d", XOVER_CUTS
#else
            "2D/%d", XOVER_2DCUTMOVE
#endif
          );
#ifdef MUTRATE
    printf(" mut=%d", MUTRATE);
#endif
#ifdef REPLACE_WORST
    printf(" replace_worst=%d", REPLACE_WORST);
#endif
    printf(" aging");
#ifdef OPTAPPLY
    printf(" optapply=%d", OPTAPPLY);
#endif
#ifdef OPTMAXIMPROVE
    printf(" optmax=%f", OPTMAXIMPROVE);
#endif
#ifdef OPTFULL
    printf(" optfull");
#endif
#ifdef EXPLOSION
    printf(" explosion=%d@%f*%d swap=%d hexspin=%d",
            EXPLOSION, EXPLOSION_DIFF, EXPLOSION_THRESHOLD,
            SWAPRATE, HEXSPINRATE);
#endif
    printf("\n");
}

struct timeval tbegin, tend;
void die(int x) {
    status(x);
    ping(x);
    gettimeofday(&tend, NULL);
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) >= 0) {
#define tdiff(s, t) \
	(float)(t.tv_sec - s.tv_sec) + (float)(t.tv_usec - s.tv_usec) * 1e-6
#define ptime(t) printf("%fs", (float)t.tv_sec + (float)t.tv_usec * 1e-6)
	printf("execution time:");
	printf(" real %fs", tdiff(tbegin, tend));
	printf(" user "); ptime(usage.ru_utime);
	printf(" sys "); ptime(usage.ru_stime);
	printf("\n");
#undef ptime
#undef tdiff
    }
    exit(x);
}



/****************************************************************************
 * Operators for Genetic Algorithm                                          *
 ****************************************************************************/

void xover(chromo p1, chromo p2, chromo o) {
#ifdef XOVER_CUTS
    // FIXME: don't use d.  use (N - i) for more uniform randomness
    idx_t i = 0, j, c = XOVER_CUTS, d = N / XOVER_CUTS;
    chromo p = p1;
    while (c > 0) {
        for (j=i, i+= rnd(d); j<=i; j++)
            o[j] = p[j];
        c--;
        i++;
        p = (p == p1) ? p2 : p1;
    }
    for (; i<N; i++)
        o[i] = p[i];
#else
    idx_t i,j,C, bnd,cut,g;
#define copy_from(p1, kpfx, cut) \
        for (; j<cut; j++) \
            g = idx[i][j/2][kpfx j%2], \
            o[g] = p1[g]
#define copy(kpfx) { \
        bnd = min(cut, 2*C); \
        copy_from(p1, kpfx, bnd); \
        copy_from(p2, kpfx, 2*C); \
        g = idx[i][C-1][kpfx 2]; \
        o[g] = ((cut > 2*C) ? p1 : p2)[g];  \
        cut += rnd(2*XOVER_2DCUTMOVE+1) - XOVER_2DCUTMOVE; \
        cut = min(max(0, cut), 2*C+1); \
    }
    cut = rnd(2*A+2);
    for (C=A,i=0,j=0;   C<=B;   C++,i++,j=0) copy();
    for (C=B,i=B-A;     C>=A;   C--,i++,j=0) copy(5-);
#undef copy
#undef copy_from
#endif
}

void mutate(chromo c) {
    idx_t i, r = MUTRATE;
    for (i=0; r>0; i++) {
        r--;
        i += rnd(N - i - r);
        if (rnd(2))
            c[i]++;
        else
            c[i]--;
    }
}

void repair(chromo c) {
    idx_t uses[N+2] = {0},
          dups[N+2][N] = {{0}},
          i,j,k,g;
    /* count # of uses for each gene values, and remember their indexes */
    for (i=0; i<N; i++)
        dups[c[i]][uses[c[i]]++] = i;
    /* fill consecutively according to dups and usedby */
    for (g=1, i=0; i<N+2; i++)
        for (k=uses[i]; k>0; k--) {
            j = rnd(uses[i]);
            while (dups[i][j] == N)
                j = (j+1) % uses[i];
            c[dups[i][j]] = g++;
            dups[i][j] = N;
        }
}

inline void create(chromo c) {
    idx_t i;
    for (i=0; i<N; i++)
        c[i] = 1+rnd(N);
    repair(c);
    exhaustive_opt(c);
}

void explode(chromo c) {
    int m, n;
#ifdef SWAPRATE
    /* swapping */
    n = rnd(SWAPRATE) + 1;
    for (m=0; m<n; m++) {
        idx_t i = rnd(N),
              j = (i + rnd(N-1)+1) % N,
              tmp = c[i];
        c[i] = c[j];
        c[j] = tmp;
    }
#endif
#ifdef HEXSPINRATE
    /* hexagon spinning */
    n = rnd(HEXSPINRATE) + 1;
    idx_t tmp[6];
    for (m=0; m<n; m++) {
        idx_t i = rnd(2*(B-A)+1),
              j = rnd(B - abs(B-A - i)),
              *ij = idx[i][j],
              k, d = rnd(5) + 1;
        for (k=0; k<6; k++)
            tmp[(k+d)%6] = c[ij[k]];
        for (k=0; k<6; k++)
            c[ij[k]] = tmp[k];
    }
#endif
    exhaustive_opt(c);
}



/****************************************************************************
 * Genetic Algorithm                                                        *
 ****************************************************************************/

inline void sync_evaluation(int n, evaluation new) {
    evaluation old = eval[n];
    /* bookkeep tracking values, e.g. sums, counts and indexes */
    fsum -= old->fitness, fsum += new->fitness;
    varsum -= old->var, varsum += new->var;
    meansum -= old->mean, meansum += new->mean;
    if (fbest < new->fitness) {
        fbest = new->fitness;
        fbestidx = n;
    } else if (old->fitness == fbest)
        find_best = 1;
    if (fworst > new->fitness)
        fworst = new->fitness;
    else if (old->fitness == fworst)
        find_worst = 1;
}

inline void check_solution(int n) {
    /* check variance */
    if (eval[n]->var == 0) {
        if (var0idx == -1 || eval[var0idx]->fitness < eval[n]->fitness)
            var0idx = n;
        print_status(stdout),
        print_pop(stdout, n);
        solfound++;
    }
}

inline void update_evaluation(int n, evaluation new) {
    sync_evaluation(n, new);
    *eval[n] = *new;
    check_solution(n);
}

void initialize_population() {
    Evaluation _e;
    evaluation e = &_e;
    int n;
    for (n=0; n<P; n++) {
        chromo c = pop[n];
        e->age = eval[n]->age;
        evaluate(c, e);
        update_evaluation(n, e);
    }
}

inline void begin_generation() {
    int n;
#ifdef EXPLOSION
beginning_of_generation:
#endif /* EXPLOSION */
    ffsum = 0;
#define ff(f) ((SELPRESS - 1) * (f - fworst) / (fbest - fworst) + 1)
    for (n=0; n<P; n++) {
        fitness_t f = ff(eval[n]->fitness)
            - (fitness_t) eval[n]->age / N * M / P / 10;
        ffsum += f;
        ff[n] = f;
    }
#undef ff
#ifdef REPLACE_WORST
    int cmp(const void *a, const void *b) {
        fitness_t fa = ff[*(int *)a],
                  fb = ff[*(int *)b];
        if (fa < fb)
            return +1;
        else if (fa > fb)
            return -1;
        else
            return 0;
    }
    qsort(rank, P, sizeof(int), cmp);
#endif /* REPLACE_WORST */
#ifdef EXPLOSION
    double diff = varsum / P - eval[fbestidx]->var;
    if ((diff > 0 ? diff : -diff) < EXPLOSION_DIFF) {
        if (explosion_countdown-- < 0) {
            int i, r;
            chromo o;
            Evaluation _e; evaluation e = &_e;
            for (i=1; i<P; i++) {
                if (rnd(EXPLOSION)) {
                    r = rank[i];
                    o = pop[r];
                    explode(o);
                    evaluate(o, e);
                    e->age = 0;
                    update_evaluation(r, e);
                }
            }
            explosion_countdown = EXPLOSION_THRESHOLD;
            goto beginning_of_generation;
        }
    }
#endif /* EXPLOSION */
}

inline int pick() {
    fitness_t s = 0, pt = rnd_f(ffsum);
    int i;
    for (i=0; i<P; i++) {
        s += ff[i];
        if (s > pt)
            return i;
    }
    return rnd(P);
}

inline void generate_offspring(int n) {
    /* select parents */
    int p1, p2;
    p1 = pick();
    do {
        p2 = pick();
    } while (p1 == p2);
    parent1[n] = p1;
    parent2[n] = p2;
    /* and generate offspring */
    chromo o = offspring[n];
    xover(pop[p1], pop[p2], o);
    mutate(o);
    repair(o);
#ifdef OPTAPPLY
    if (rnd(OPTAPPLY))
#endif
        exhaustive_opt(o);
    evaluate(o, offspring_eval[n]);
    offspring_eval[n]->age = 0;
}

inline void generate_offsprings();

inline void replace_population() {
    int n;
    int r = P-1;
    for (n=0; n<K; n++) {
#ifdef REPLACE_WORST
        int p = rank[r--];
        if (!rnd(REPLACE_WORST))
            r--;
#else
        int p = parent2[n];
        if (ff[p1] < ff[p2])
            p = parent1[n];
#endif
        chromo c;
        c = pop[p], pop[p] = offspring[n], offspring[n] = c;
        sync_evaluation(p, offspring_eval[n]);
        evaluation e;
        e = eval[p], eval[p] = offspring_eval[n], offspring_eval[n] = e;
        check_solution(p);
    }
}

inline void end_generation() {
    int n;
#ifdef ENCODING_RANDOM
    if (encoding_age > P) {
        idx_t idx2[2*(B-A)+1][B][6];
        idx_t i,j,C; char L,H,k;
        for_each_ij
            for (k=0; k<6; k++)
                idx2[i][j][k] = idx[i][j][k];
        initialize_encoding();
        Chromo _orig; chromo orig = &_orig;
        for (n=0; n<P; n++) {
#define move(c) \
            copy_chromosome(orig, c); \
            for_each_ij \
                for (k=0; k<6; k++) \
                    c[idx[i][j][k]] = orig[idx2[i][j][k]];
            move(pop[n]);
#undef move
        }
        initialize_population();
        ga_info();
        encoding_age = 0;
    }
#endif

    int x;
#define find(what, cmp) { \
            x = 0, what = eval[0]->fitness; \
            for (n=1; n<P; n++) \
                if (eval[n]->fitness cmp what) \
                    x = n, what = eval[n]->fitness; \
        }
    if (find_best) {
        find(fbest, >);
        fbestidx = x;
    }
    if (find_worst)
        find(fworst, <);
#undef find

    for (n=0; n<P; n++)
        eval[n]->age++;

    gbest_age = (gbest != fbest) ? 1 : gbest_age + 1;
    gbest = fbest;
    eval[fbestidx]->age = gbest_age;

    generations++;
}

void ga() {
    while (! DONE) {
        begin_generation();
        generate_offsprings();
        replace_population();
        end_generation();
    }
}

#ifndef SINGLETHREAD
#include <pthread.h>

#ifndef NUMTHREADS
#define NUMTHREADS 3
#endif

pthread_mutex_t generated_mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t generate_new_cond = PTHREAD_COND_INITIALIZER,
               generation_ready_cond = PTHREAD_COND_INITIALIZER;
int generated = K;
int working = 0;

void *offspring_generator(void *p) {
    int n;
    pthread_mutex_lock(&generated_mtx);
    for (;;) {
        /* wait until a new generation begins */
        working++;
        while (generated < K) {
            /* assign an offspring # */
            n = generated++;
            pthread_mutex_unlock(&generated_mtx);
            /* work in parallel */
            generate_offspring(n);
            pthread_mutex_lock(&generated_mtx);
        }
        working--;
        /* signal new offsprings are all ready, if i'm the last worker */
        if (working == 0)
            pthread_cond_signal(&generation_ready_cond);
        pthread_cond_wait(&generate_new_cond, &generated_mtx);
    }
    pthread_mutex_unlock(&generated_mtx);
    return NULL;
}

inline void generate_offsprings() {
    generated = 0;
    pthread_cond_broadcast(&generate_new_cond);
    pthread_cond_wait(&generation_ready_cond, &generated_mtx);
}

inline void GA() {
    int n;
    pthread_t threads[NUMTHREADS];
    pthread_mutex_trylock(&generated_mtx);
    for (n=0; n<NUMTHREADS; n++)
        pthread_create(&threads[n], NULL, offspring_generator, NULL);
    debug("threads ready\n");
    ga();
    pthread_mutex_unlock(&generated_mtx);
}

#else
inline void generate_offsprings() {
    int n;
    for (n=0; n<K; n++)
        generate_offspring(n);
}

#define GA() ga()

#endif




/****************************************************************************
 * and finally, the main()                                                  *
 ****************************************************************************/

int main(int argc, char *argv[]) {
    srandomdev();
    gettimeofday(&tbegin, NULL);

    int n;
    for (n=0; n<P; n++) {
        chromo c = new_chromosome();
        create(c);
        pop[n] = c;
        rank[n] = n;
    }
    for (n=0; n<K; n++) offspring[n] = new_chromosome();
    for (n=0; n<P; n++) {
        evaluation e = new_evaluation();
        e->age = 0;
        eval[n] = e;
    }
    for (n=0; n<K; n++) offspring_eval[n] = new_evaluation();
    initialize_encoding();
    initialize_population();
    debug("memory, data ready\n");

#ifdef T
    alarm(T);
    signal(SIGALRM, die);
#endif
    signal(SIGHUP,  die);
    signal(SIGTERM, die);
    signal(SIGINT,  ping);
    signal(SIGQUIT, status);
    debug("signal handlers ready\n");

    message("starting jsgmd%d\n", N);
    ga_info();
    ping(0);
    GA();
    die(solfound == 0);
    return -1;
}
