int main() {
#define A(i) i+1
#define code A(1) + A(2)

code;

#define A(i) i+2

code;
}
