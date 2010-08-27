





















typedef unsigned int size_t;












typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;




__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;







__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;









__extension__ typedef unsigned long long int __dev_t;
__extension__ typedef unsigned int __uid_t;
__extension__ typedef unsigned int __gid_t;
__extension__ typedef unsigned long int __ino_t;
__extension__ typedef unsigned long long int __ino64_t;
__extension__ typedef unsigned int __mode_t;
__extension__ typedef unsigned int __nlink_t;
__extension__ typedef long int __off_t;
__extension__ typedef long long int __off64_t;
__extension__ typedef int __pid_t;
__extension__ typedef struct { int __val[2]; } __fsid_t;
__extension__ typedef long int __clock_t;
__extension__ typedef unsigned long int __rlim_t;
__extension__ typedef unsigned long long int __rlim64_t;
__extension__ typedef unsigned int __id_t;
__extension__ typedef long int __time_t;
__extension__ typedef unsigned int __useconds_t;
__extension__ typedef long int __suseconds_t;

__extension__ typedef int __daddr_t;
__extension__ typedef long int __swblk_t;
__extension__ typedef int __key_t;


__extension__ typedef int __clockid_t;


__extension__ typedef int __timer_t;


__extension__ typedef long int __blksize_t;




__extension__ typedef long int __blkcnt_t;
__extension__ typedef long long int __blkcnt64_t;


__extension__ typedef unsigned long int __fsblkcnt_t;
__extension__ typedef unsigned long long int __fsblkcnt64_t;


__extension__ typedef unsigned long int __fsfilcnt_t;
__extension__ typedef unsigned long long int __fsfilcnt64_t;

__extension__ typedef int __ssize_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


__extension__ typedef int __intptr_t;


__extension__ typedef unsigned int __socklen_t;










typedef struct _IO_FILE FILE;






typedef struct _IO_FILE __FILE;







typedef long int wchar_t;

typedef unsigned int wint_t;










typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;


typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;

















enum
{
  __GCONV_OK = 0,
  __GCONV_NOCONV,
  __GCONV_NODB,
  __GCONV_NOMEM,

  __GCONV_EMPTY_INPUT,
  __GCONV_FULL_OUTPUT,
  __GCONV_ILLEGAL_INPUT,
  __GCONV_INCOMPLETE_INPUT,

  __GCONV_ILLEGAL_DESCRIPTOR,
  __GCONV_INTERNAL_ERROR
};



enum
{
  __GCONV_IS_LAST = 0x0001,
  __GCONV_IGNORE_ERRORS = 0x0002
};



struct __gconv_step;
struct __gconv_step_data;
struct __gconv_loaded_object;
struct __gconv_trans_data;



typedef int (*__gconv_fct) (struct __gconv_step *, struct __gconv_step_data *,
                            __const unsigned char **, __const unsigned char *,
                            unsigned char **, size_t *, int, int);


typedef wint_t (*__gconv_btowc_fct) (struct __gconv_step *, unsigned char);


typedef int (*__gconv_init_fct) (struct __gconv_step *);
typedef void (*__gconv_end_fct) (struct __gconv_step *);



typedef int (*__gconv_trans_fct) (struct __gconv_step *,
                                  struct __gconv_step_data *, void *,
                                  __const unsigned char *,
                                  __const unsigned char **,
                                  __const unsigned char *, unsigned char **,
                                  size_t *);


typedef int (*__gconv_trans_context_fct) (void *, __const unsigned char *,
                                          __const unsigned char *,
                                          unsigned char *, unsigned char *);


typedef int (*__gconv_trans_query_fct) (__const char *, __const char ***,
                                        size_t *);


typedef int (*__gconv_trans_init_fct) (void **, const char *);
typedef void (*__gconv_trans_end_fct) (void *);

struct __gconv_trans_data
{

  __gconv_trans_fct __trans_fct;
  __gconv_trans_context_fct __trans_context_fct;
  __gconv_trans_end_fct __trans_end_fct;
  void *__data;
  struct __gconv_trans_data *__next;
};



struct __gconv_step
{
  struct __gconv_loaded_object *__shlib_handle;
  __const char *__modname;

  int __counter;

  char *__from_name;
  char *__to_name;

  __gconv_fct __fct;
  __gconv_btowc_fct __btowc_fct;
  __gconv_init_fct __init_fct;
  __gconv_end_fct __end_fct;



  int __min_needed_from;
  int __max_needed_from;
  int __min_needed_to;
  int __max_needed_to;


  int __stateful;

  void *__data;
};



struct __gconv_step_data
{
  unsigned char *__outbuf;
  unsigned char *__outbufend;



  int __flags;



  int __invocation_counter;



  int __internal_use;

  __mbstate_t *__statep;
  __mbstate_t __state;



  struct __gconv_trans_data *__trans;
};



typedef struct __gconv_info
{
  size_t __nsteps;
  struct __gconv_step *__steps;
  __extension__ struct __gconv_step_data __data [];
} *__gconv_t;

typedef union
{
  struct __gconv_info __cd;
  struct
  {
    struct __gconv_info __cd;
    struct __gconv_step_data __data;
  } __combined;
} _G_iconv_t;

typedef int _G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__)));




typedef __builtin_va_list __gnuc_va_list;


struct _IO_jump_t; struct _IO_FILE;

typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;

};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};

struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;

  __off64_t _offset;





  void *__pad1;
  void *__pad2;

  int _mode;

  char _unused2[15 * sizeof (int) - 2 * sizeof (void *)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;

typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, __const char *__buf,
                                 size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);

extern int __underflow (_IO_FILE *) ;
extern int __uflow (_IO_FILE *) ;
extern int __overflow (_IO_FILE *, int) ;
extern wint_t __wunderflow (_IO_FILE *) ;
extern wint_t __wuflow (_IO_FILE *) ;
extern wint_t __woverflow (_IO_FILE *, wint_t) ;

extern int _IO_getc (_IO_FILE *__fp) ;
extern int _IO_putc (int __c, _IO_FILE *__fp) ;
extern int _IO_feof (_IO_FILE *__fp) ;
extern int _IO_ferror (_IO_FILE *__fp) ;

extern int _IO_peekc_locked (_IO_FILE *__fp) ;





extern void _IO_flockfile (_IO_FILE *) ;
extern void _IO_funlockfile (_IO_FILE *) ;
extern int _IO_ftrylockfile (_IO_FILE *) ;

extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
                        __gnuc_va_list, int *__restrict) ;
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
                         __gnuc_va_list) ;
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t) ;
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t) ;

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int) ;
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int) ;

extern void _IO_free_backup_area (_IO_FILE *) ;




typedef _G_fpos_t fpos_t;










extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;







extern int remove (__const char *__filename) ;

extern int rename (__const char *__old, __const char *__new) ;









extern FILE *tmpfile (void);

extern char *tmpnam (char *__s) ;





extern char *tmpnam_r (char *__s) ;

extern char *tempnam (__const char *__dir, __const char *__pfx)
     __attribute__ ((__malloc__));








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);


extern int fflush_unlocked (FILE *__stream);







extern FILE *fopen (__const char *__restrict __filename,
                    __const char *__restrict __modes);




extern FILE *freopen (__const char *__restrict __filename,
                      __const char *__restrict __modes,
                      FILE *__restrict __stream);



extern FILE *fdopen (int __fd, __const char *__modes) ;




extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) ;



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
                    int __modes, size_t __n) ;





extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
                       size_t __size) ;


extern void setlinebuf (FILE *__stream) ;








extern int fprintf (FILE *__restrict __stream,
                    __const char *__restrict __format, ...);




extern int printf (__const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
                    __const char *__restrict __format, ...) ;





extern int vfprintf (FILE *__restrict __s, __const char *__restrict __format,
                     __gnuc_va_list __arg);




extern int vprintf (__const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, __const char *__restrict __format,
                     __gnuc_va_list __arg) ;





extern int snprintf (char *__restrict __s, size_t __maxlen,
                     __const char *__restrict __format, ...)
     __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
                      __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 3, 0)));







extern int fscanf (FILE *__restrict __stream,
                   __const char *__restrict __format, ...);




extern int scanf (__const char *__restrict __format, ...);

extern int sscanf (__const char *__restrict __s,
                   __const char *__restrict __format, ...) ;







extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);


extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);

extern int fgetc_unlocked (FILE *__stream);











extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);


extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);








extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream);






extern char *gets (char *__s);







extern int fputs (__const char *__restrict __s, FILE *__restrict __stream);





extern int puts (__const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
                     size_t __n, FILE *__restrict __stream);




extern size_t fwrite (__const void *__restrict __ptr, size_t __size,
                      size_t __n, FILE *__restrict __s);


extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
                              size_t __n, FILE *__restrict __stream);
extern size_t fwrite_unlocked (__const void *__restrict __ptr, size_t __size,
                               size_t __n, FILE *__restrict __stream);








extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream);




extern void rewind (FILE *__stream);








extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream, __const fpos_t *__pos);





extern void clearerr (FILE *__stream) ;

extern int feof (FILE *__stream) ;

extern int ferror (FILE *__stream) ;




extern void clearerr_unlocked (FILE *__stream) ;
extern int feof_unlocked (FILE *__stream) ;
extern int ferror_unlocked (FILE *__stream) ;








extern void perror (__const char *__s);








extern int sys_nerr;
extern __const char *__const sys_errlist[];





extern int fileno (FILE *__stream) ;




extern int fileno_unlocked (FILE *__stream) ;

extern FILE *popen (__const char *__command, __const char *__modes);





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) ;

extern void flockfile (FILE *__stream) ;



extern int ftrylockfile (FILE *__stream) ;


extern void funlockfile (FILE *__stream) ;



extern __inline int
vprintf (__const char *__restrict __fmt, __gnuc_va_list __arg)
{
  return vfprintf (stdout, __fmt, __arg);
}


extern __inline int
getchar (void)
{
  return _IO_getc (stdin);
}




extern __inline int
getc_unlocked (FILE *__fp)
{
  return ((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}


extern __inline int
getchar_unlocked (void)
{
  return ((stdin)->_IO_read_ptr >= (stdin)->_IO_read_end ? __uflow (stdin) : *(unsigned char *) (stdin)->_IO_read_ptr++);
}




extern __inline int
putchar (int __c)
{
  return _IO_putc (__c, stdout);
}




extern __inline int
fputc_unlocked (int __c, FILE *__stream)
{
  return (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}





extern __inline int
putc_unlocked (int __c, FILE *__stream)
{
  return (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}


extern __inline int
putchar_unlocked (int __c)
{
  return (((stdout)->_IO_write_ptr >= (stdout)->_IO_write_end) ? __overflow (stdout, (unsigned char) (__c)) : (unsigned char) (*(stdout)->_IO_write_ptr++ = (__c)));
}

extern __inline int
feof_unlocked (FILE *__stream)
{
  return (((__stream)->_flags & 0x10) != 0);
}


extern __inline int
ferror_unlocked (FILE *__stream)
{
  return (((__stream)->_flags & 0x20) != 0);
}














typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;




extern size_t __ctype_get_mb_cur_max (void) ;




extern double atof (__const char *__nptr) __attribute__ ((__pure__));

extern int atoi (__const char *__nptr) __attribute__ ((__pure__));

extern long int atol (__const char *__nptr) __attribute__ ((__pure__));





__extension__ extern long long int atoll (__const char *__nptr)
     __attribute__ ((__pure__));





extern double strtod (__const char *__restrict __nptr,
                      char **__restrict __endptr) ;




extern long int strtol (__const char *__restrict __nptr,
                        char **__restrict __endptr, int __base) ;

extern unsigned long int strtoul (__const char *__restrict __nptr,
                                  char **__restrict __endptr, int __base)
     ;




__extension__
extern long long int strtoq (__const char *__restrict __nptr,
                             char **__restrict __endptr, int __base) ;

__extension__
extern unsigned long long int strtouq (__const char *__restrict __nptr,
                                       char **__restrict __endptr, int __base)
     ;





__extension__
extern long long int strtoll (__const char *__restrict __nptr,
                              char **__restrict __endptr, int __base) ;

__extension__
extern unsigned long long int strtoull (__const char *__restrict __nptr,
                                        char **__restrict __endptr, int __base)
     ;


extern double __strtod_internal (__const char *__restrict __nptr,
                                 char **__restrict __endptr, int __group)
     ;
extern float __strtof_internal (__const char *__restrict __nptr,
                                char **__restrict __endptr, int __group)
     ;
extern long double __strtold_internal (__const char *__restrict __nptr,
                                       char **__restrict __endptr,
                                       int __group) ;

extern long int __strtol_internal (__const char *__restrict __nptr,
                                   char **__restrict __endptr,
                                   int __base, int __group) ;



extern unsigned long int __strtoul_internal (__const char *__restrict __nptr,
                                             char **__restrict __endptr,
                                             int __base, int __group) ;




__extension__
extern long long int __strtoll_internal (__const char *__restrict __nptr,
                                         char **__restrict __endptr,
                                         int __base, int __group) ;



__extension__
extern unsigned long long int __strtoull_internal (__const char *
                                                   __restrict __nptr,
                                                   char **__restrict __endptr,
                                                   int __base, int __group)
     ;








extern __inline double
strtod (__const char *__restrict __nptr, char **__restrict __endptr)
{
  return __strtod_internal (__nptr, __endptr, 0);
}
extern __inline long int
strtol (__const char *__restrict __nptr, char **__restrict __endptr,
        int __base)
{
  return __strtol_internal (__nptr, __endptr, __base, 0);
}
extern __inline unsigned long int
strtoul (__const char *__restrict __nptr, char **__restrict __endptr,
         int __base)
{
  return __strtoul_internal (__nptr, __endptr, __base, 0);
}


__extension__ extern __inline long long int
strtoq (__const char *__restrict __nptr, char **__restrict __endptr,
        int __base)
{
  return __strtoll_internal (__nptr, __endptr, __base, 0);
}
__extension__ extern __inline unsigned long long int
strtouq (__const char *__restrict __nptr, char **__restrict __endptr,
         int __base)
{
  return __strtoull_internal (__nptr, __endptr, __base, 0);
}




__extension__ extern __inline long long int
strtoll (__const char *__restrict __nptr, char **__restrict __endptr,
         int __base)
{
  return __strtoll_internal (__nptr, __endptr, __base, 0);
}
__extension__ extern __inline unsigned long long int
strtoull (__const char * __restrict __nptr, char **__restrict __endptr,
          int __base)
{
  return __strtoull_internal (__nptr, __endptr, __base, 0);
}




extern __inline double
atof (__const char *__nptr)
{
  return strtod (__nptr, (char **) ((void *)0));
}
extern __inline int
atoi (__const char *__nptr)
{
  return (int) strtol (__nptr, (char **) ((void *)0), 10);
}
extern __inline long int
atol (__const char *__nptr)
{
  return strtol (__nptr, (char **) ((void *)0), 10);
}




__extension__ extern __inline long long int
atoll (__const char *__nptr)
{
  return strtoll (__nptr, (char **) ((void *)0), 10);
}


extern char *l64a (long int __n) ;


extern long int a64l (__const char *__s) __attribute__ ((__pure__));












typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;

typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;

typedef __pid_t pid_t;




typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;





typedef __time_t time_t;




typedef __clockid_t clockid_t;

typedef __timer_t timer_t;







typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;

typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));


typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));
















typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;




typedef __sigset_t sigset_t;







struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };




struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };



typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;

typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;



extern int select (int __nfds, fd_set *__restrict __readfds,
                   fd_set *__restrict __writefds,
                   fd_set *__restrict __exceptfds,
                   struct timeval *__restrict __timeout);








typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;





struct __sched_param
  {
    int __sched_priority;
  };


typedef int __atomic_lock_t;


struct _pthread_fastlock
{
  long int __status;
  __atomic_lock_t __spinlock;

};



typedef struct _pthread_descr_struct *_pthread_descr;





typedef struct __pthread_attr_s
{
  int __detachstate;
  int __schedpolicy;
  struct __sched_param __schedparam;
  int __inheritsched;
  int __scope;
  size_t __guardsize;
  int __stackaddr_set;
  void *__stackaddr;
  size_t __stacksize;
} pthread_attr_t;





__extension__ typedef long long __pthread_cond_align_t;




typedef struct
{
  struct _pthread_fastlock __c_lock;
  _pthread_descr __c_waiting;
  char __padding[48 - sizeof (struct _pthread_fastlock)
                 - sizeof (_pthread_descr) - sizeof (__pthread_cond_align_t)];
  __pthread_cond_align_t __align;
} pthread_cond_t;



typedef struct
{
  int __dummy;
} pthread_condattr_t;


typedef unsigned int pthread_key_t;





typedef struct
{
  int __m_reserved;
  int __m_count;
  _pthread_descr __m_owner;
  int __m_kind;
  struct _pthread_fastlock __m_lock;
} pthread_mutex_t;



typedef struct
{
  int __mutexkind;
} pthread_mutexattr_t;



typedef int pthread_once_t;

typedef unsigned long int pthread_t;











extern long int random (void) ;


extern void srandom (unsigned int __seed) ;





extern char *initstate (unsigned int __seed, char *__statebuf,
                        size_t __statelen) ;



extern char *setstate (char *__statebuf) ;







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
                     int32_t *__restrict __result) ;

extern int srandom_r (unsigned int __seed, struct random_data *__buf) ;

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
                        size_t __statelen,
                        struct random_data *__restrict __buf) ;

extern int setstate_r (char *__restrict __statebuf,
                       struct random_data *__restrict __buf) ;






extern int rand (void) ;

extern void srand (unsigned int __seed) ;




extern int rand_r (unsigned int *__seed) ;







extern double drand48 (void) ;
extern double erand48 (unsigned short int __xsubi[3]) ;


extern long int lrand48 (void) ;
extern long int nrand48 (unsigned short int __xsubi[3]) ;


extern long int mrand48 (void) ;
extern long int jrand48 (unsigned short int __xsubi[3]) ;


extern void srand48 (long int __seedval) ;
extern unsigned short int *seed48 (unsigned short int __seed16v[3]) ;
extern void lcong48 (unsigned short int __param[7]) ;





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
                      double *__restrict __result) ;
extern int erand48_r (unsigned short int __xsubi[3],
                      struct drand48_data *__restrict __buffer,
                      double *__restrict __result) ;


extern int lrand48_r (struct drand48_data *__restrict __buffer,
                      long int *__restrict __result) ;
extern int nrand48_r (unsigned short int __xsubi[3],
                      struct drand48_data *__restrict __buffer,
                      long int *__restrict __result) ;


extern int mrand48_r (struct drand48_data *__restrict __buffer,
                      long int *__restrict __result) ;
extern int jrand48_r (unsigned short int __xsubi[3],
                      struct drand48_data *__restrict __buffer,
                      long int *__restrict __result) ;


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     ;

extern int seed48_r (unsigned short int __seed16v[3],
                     struct drand48_data *__buffer) ;

extern int lcong48_r (unsigned short int __param[7],
                      struct drand48_data *__buffer) ;









extern void *malloc (size_t __size) __attribute__ ((__malloc__));

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__malloc__));







extern void *realloc (void *__ptr, size_t __size) __attribute__ ((__malloc__));

extern void free (void *__ptr) ;




extern void cfree (void *__ptr) ;














extern void *alloca (size_t __size) ;











extern void *valloc (size_t __size) __attribute__ ((__malloc__));



extern void abort (void) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) ;





extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     ;






extern void exit (int __status) __attribute__ ((__noreturn__));




extern char *getenv (__const char *__name) ;




extern char *__secure_getenv (__const char *__name) ;





extern int putenv (char *__string) ;





extern int setenv (__const char *__name, __const char *__value, int __replace)
     ;


extern int unsetenv (__const char *__name) ;






extern int clearenv (void) ;

extern char *mktemp (char *__template) ;

extern int mkstemp (char *__template);

extern char *mkdtemp (char *__template) ;








extern int system (__const char *__command);


extern char *realpath (__const char *__restrict __name,
                       char *__restrict __resolved) ;






typedef int (*__compar_fn_t) (__const void *, __const void *);









extern void *bsearch (__const void *__key, __const void *__base,
                      size_t __nmemb, size_t __size, __compar_fn_t __compar);



extern void qsort (void *__base, size_t __nmemb, size_t __size,
                   __compar_fn_t __compar);



extern int abs (int __x) __attribute__ ((__const__));
extern long int labs (long int __x) __attribute__ ((__const__));












extern div_t div (int __numer, int __denom)
     __attribute__ ((__const__));
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__const__));


extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign) ;




extern char *gcvt (double __value, int __ndigit, char *__buf) ;




extern char *qecvt (long double __value, int __ndigit,
                    int *__restrict __decpt, int *__restrict __sign) ;
extern char *qfcvt (long double __value, int __ndigit,
                    int *__restrict __decpt, int *__restrict __sign) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign, char *__restrict __buf,
                   size_t __len) ;
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign, char *__restrict __buf,
                   size_t __len) ;

extern int qecvt_r (long double __value, int __ndigit,
                    int *__restrict __decpt, int *__restrict __sign,
                    char *__restrict __buf, size_t __len) ;
extern int qfcvt_r (long double __value, int __ndigit,
                    int *__restrict __decpt, int *__restrict __sign,
                    char *__restrict __buf, size_t __len) ;







extern int mblen (__const char *__s, size_t __n) ;


extern int mbtowc (wchar_t *__restrict __pwc,
                   __const char *__restrict __s, size_t __n) ;


extern int wctomb (char *__s, wchar_t __wchar) ;



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
                        __const char *__restrict __s, size_t __n) ;

extern size_t wcstombs (char *__restrict __s,
                        __const wchar_t *__restrict __pwcs, size_t __n)
     ;








extern int rpmatch (__const char *__response) ;

extern int getloadavg (double __loadavg[], int __nelem) ;




















extern void *memcpy (void *__restrict __dest,
                     __const void *__restrict __src, size_t __n) ;


extern void *memmove (void *__dest, __const void *__src, size_t __n)
     ;






extern void *memccpy (void *__restrict __dest, __const void *__restrict __src,
                      int __c, size_t __n)
     ;





extern void *memset (void *__s, int __c, size_t __n) ;


extern int memcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__pure__));


extern void *memchr (__const void *__s, int __c, size_t __n)
      __attribute__ ((__pure__));




extern char *strcpy (char *__restrict __dest, __const char *__restrict __src)
     ;

extern char *strncpy (char *__restrict __dest,
                      __const char *__restrict __src, size_t __n) ;


extern char *strcat (char *__restrict __dest, __const char *__restrict __src)
     ;

extern char *strncat (char *__restrict __dest, __const char *__restrict __src,
                      size_t __n) ;


extern int strcmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__pure__));

extern int strncmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__pure__));


extern int strcoll (__const char *__s1, __const char *__s2)
     __attribute__ ((__pure__));

extern size_t strxfrm (char *__restrict __dest,
                       __const char *__restrict __src, size_t __n) ;


extern char *strdup (__const char *__s) __attribute__ ((__malloc__));



extern char *strchr (__const char *__s, int __c) __attribute__ ((__pure__));

extern char *strrchr (__const char *__s, int __c) __attribute__ ((__pure__));











extern size_t strcspn (__const char *__s, __const char *__reject)
     __attribute__ ((__pure__));


extern size_t strspn (__const char *__s, __const char *__accept)
     __attribute__ ((__pure__));

extern char *strpbrk (__const char *__s, __const char *__accept)
     __attribute__ ((__pure__));

extern char *strstr (__const char *__haystack, __const char *__needle)
     __attribute__ ((__pure__));



extern char *strtok (char *__restrict __s, __const char *__restrict __delim)
     ;




extern char *__strtok_r (char *__restrict __s,
                         __const char *__restrict __delim,
                         char **__restrict __save_ptr) ;

extern char *strtok_r (char *__restrict __s, __const char *__restrict __delim,
                       char **__restrict __save_ptr) ;



extern size_t strlen (__const char *__s) __attribute__ ((__pure__));




extern char *strerror (int __errnum) ;




extern char *strerror_r (int __errnum, char *__buf, size_t __buflen) ;




extern void __bzero (void *__s, size_t __n) ;



extern void bcopy (__const void *__src, void *__dest, size_t __n) ;


extern void bzero (void *__s, size_t __n) ;


extern int bcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__pure__));


extern char *index (__const char *__s, int __c) __attribute__ ((__pure__));


extern char *rindex (__const char *__s, int __c) __attribute__ ((__pure__));



extern int ffs (int __i) __attribute__ ((__const__));

extern int strcasecmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__pure__));


extern int strncasecmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__pure__));

extern char *strsep (char **__restrict __stringp,
                     __const char *__restrict __delim) ;







extern void *__rawmemchr (const void *__s, int __c);

extern __inline size_t __strcspn_c1 (__const char *__s, int __reject);
extern __inline size_t
__strcspn_c1 (__const char *__s, int __reject)
{
  register size_t __result = 0;
  while (__s[__result] != '\0' && __s[__result] != __reject)
    ++__result;
  return __result;
}

extern __inline size_t __strcspn_c2 (__const char *__s, int __reject1,
                                     int __reject2);
extern __inline size_t
__strcspn_c2 (__const char *__s, int __reject1, int __reject2)
{
  register size_t __result = 0;
  while (__s[__result] != '\0' && __s[__result] != __reject1
         && __s[__result] != __reject2)
    ++__result;
  return __result;
}

extern __inline size_t __strcspn_c3 (__const char *__s, int __reject1,
                                     int __reject2, int __reject3);
extern __inline size_t
__strcspn_c3 (__const char *__s, int __reject1, int __reject2,
              int __reject3)
{
  register size_t __result = 0;
  while (__s[__result] != '\0' && __s[__result] != __reject1
         && __s[__result] != __reject2 && __s[__result] != __reject3)
    ++__result;
  return __result;
}

extern __inline size_t __strspn_c1 (__const char *__s, int __accept);
extern __inline size_t
__strspn_c1 (__const char *__s, int __accept)
{
  register size_t __result = 0;

  while (__s[__result] == __accept)
    ++__result;
  return __result;
}

extern __inline size_t __strspn_c2 (__const char *__s, int __accept1,
                                    int __accept2);
extern __inline size_t
__strspn_c2 (__const char *__s, int __accept1, int __accept2)
{
  register size_t __result = 0;

  while (__s[__result] == __accept1 || __s[__result] == __accept2)
    ++__result;
  return __result;
}

extern __inline size_t __strspn_c3 (__const char *__s, int __accept1,
                                    int __accept2, int __accept3);
extern __inline size_t
__strspn_c3 (__const char *__s, int __accept1, int __accept2, int __accept3)
{
  register size_t __result = 0;

  while (__s[__result] == __accept1 || __s[__result] == __accept2
         || __s[__result] == __accept3)
    ++__result;
  return __result;
}

extern __inline char *__strpbrk_c2 (__const char *__s, int __accept1,
                                     int __accept2);
extern __inline char *
__strpbrk_c2 (__const char *__s, int __accept1, int __accept2)
{

  while (*__s != '\0' && *__s != __accept1 && *__s != __accept2)
    ++__s;
  return *__s == '\0' ? ((void *)0) : (char *) (size_t) __s;
}

extern __inline char *__strpbrk_c3 (__const char *__s, int __accept1,
                                     int __accept2, int __accept3);
extern __inline char *
__strpbrk_c3 (__const char *__s, int __accept1, int __accept2,
              int __accept3)
{

  while (*__s != '\0' && *__s != __accept1 && *__s != __accept2
         && *__s != __accept3)
    ++__s;
  return *__s == '\0' ? ((void *)0) : (char *) (size_t) __s;
}

extern __inline char *__strtok_r_1c (char *__s, char __sep, char **__nextp);
extern __inline char *
__strtok_r_1c (char *__s, char __sep, char **__nextp)
{
  char *__result;
  if (__s == ((void *)0))
    __s = *__nextp;
  while (*__s == __sep)
    ++__s;
  __result = ((void *)0);
  if (*__s != '\0')
    {
      __result = __s++;
      while (*__s != '\0')
        if (*__s++ == __sep)
          {
            __s[-1] = '\0';
            break;
          }
      *__nextp = __s;
    }
  return __result;
}

extern char *__strsep_g (char **__stringp, __const char *__delim);

extern __inline char *__strsep_1c (char **__s, char __reject);
extern __inline char *
__strsep_1c (char **__s, char __reject)
{
  register char *__retval = *__s;
  if (__retval != ((void *)0) && (*__s = (__extension__ (__builtin_constant_p (__reject) && (__reject) == '\0' ? (char *) __rawmemchr (__retval, __reject) : strchr (__retval, __reject)))) != ((void *)0))
    *(*__s)++ = '\0';
  return __retval;
}

extern __inline char *__strsep_2c (char **__s, char __reject1, char __reject2);
extern __inline char *
__strsep_2c (char **__s, char __reject1, char __reject2)
{
  register char *__retval = *__s;
  if (__retval != ((void *)0))
    {
      register char *__cp = __retval;
      while (1)
        {
          if (*__cp == '\0')
            {
              __cp = ((void *)0);
          break;
            }
          if (*__cp == __reject1 || *__cp == __reject2)
            {
              *__cp++ = '\0';
              break;
            }
          ++__cp;
        }
      *__s = __cp;
    }
  return __retval;
}

extern __inline char *__strsep_3c (char **__s, char __reject1, char __reject2,
                                   char __reject3);
extern __inline char *
__strsep_3c (char **__s, char __reject1, char __reject2, char __reject3)
{
  register char *__retval = *__s;
  if (__retval != ((void *)0))
    {
      register char *__cp = __retval;
      while (1)
        {
          if (*__cp == '\0')
            {
              __cp = ((void *)0);
          break;
            }
          if (*__cp == __reject1 || *__cp == __reject2 || *__cp == __reject3)
            {
              *__cp++ = '\0';
              break;
            }
          ++__cp;
        }
      *__s = __cp;
    }
  return __retval;
}

extern char *__strdup (__const char *__string) __attribute__ ((__malloc__));

extern char *__strndup (__const char *__string, size_t __n)
     __attribute__ ((__malloc__));



























extern double acos (double __x) ; extern double __acos (double __x) ;

extern double asin (double __x) ; extern double __asin (double __x) ;

extern double atan (double __x) ; extern double __atan (double __x) ;

extern double atan2 (double __y, double __x) ; extern double __atan2 (double __y, double __x) ;


extern double cos (double __x) ; extern double __cos (double __x) ;

extern double sin (double __x) ; extern double __sin (double __x) ;

extern double tan (double __x) ; extern double __tan (double __x) ;




extern double cosh (double __x) ; extern double __cosh (double __x) ;

extern double sinh (double __x) ; extern double __sinh (double __x) ;

extern double tanh (double __x) ; extern double __tanh (double __x) ;




extern double acosh (double __x) ; extern double __acosh (double __x) ;

extern double asinh (double __x) ; extern double __asinh (double __x) ;

extern double atanh (double __x) ; extern double __atanh (double __x) ;







extern double exp (double __x) ; extern double __exp (double __x) ;


extern double frexp (double __x, int *__exponent) ; extern double __frexp (double __x, int *__exponent) ;


extern double ldexp (double __x, int __exponent) ; extern double __ldexp (double __x, int __exponent) ;


extern double log (double __x) ; extern double __log (double __x) ;


extern double log10 (double __x) ; extern double __log10 (double __x) ;


extern double modf (double __x, double *__iptr) ; extern double __modf (double __x, double *__iptr) ;




extern double expm1 (double __x) ; extern double __expm1 (double __x) ;


extern double log1p (double __x) ; extern double __log1p (double __x) ;


extern double logb (double __x) ; extern double __logb (double __x) ;




extern double pow (double __x, double __y) ; extern double __pow (double __x, double __y) ;


extern double sqrt (double __x) ; extern double __sqrt (double __x) ;





extern double hypot (double __x, double __y) ; extern double __hypot (double __x, double __y) ;






extern double cbrt (double __x) ; extern double __cbrt (double __x) ;








extern double ceil (double __x) __attribute__ ((__const__)); extern double __ceil (double __x) __attribute__ ((__const__));


extern double fabs (double __x) __attribute__ ((__const__)); extern double __fabs (double __x) __attribute__ ((__const__));


extern double floor (double __x) __attribute__ ((__const__)); extern double __floor (double __x) __attribute__ ((__const__));


extern double fmod (double __x, double __y) ; extern double __fmod (double __x, double __y) ;




extern int __isinf (double __value) __attribute__ ((__const__));


extern int __finite (double __value) __attribute__ ((__const__));





extern int isinf (double __value) __attribute__ ((__const__));


extern int finite (double __value) __attribute__ ((__const__));


extern double drem (double __x, double __y) ; extern double __drem (double __x, double __y) ;



extern double significand (double __x) ; extern double __significand (double __x) ;





extern double copysign (double __x, double __y) __attribute__ ((__const__)); extern double __copysign (double __x, double __y) __attribute__ ((__const__));


extern int __isnan (double __value) __attribute__ ((__const__));



extern int isnan (double __value) __attribute__ ((__const__));


extern double j0 (double) ; extern double __j0 (double) ;
extern double j1 (double) ; extern double __j1 (double) ;
extern double jn (int, double) ; extern double __jn (int, double) ;
extern double y0 (double) ; extern double __y0 (double) ;
extern double y1 (double) ; extern double __y1 (double) ;
extern double yn (int, double) ; extern double __yn (int, double) ;






extern double erf (double) ; extern double __erf (double) ;
extern double erfc (double) ; extern double __erfc (double) ;
extern double lgamma (double) ; extern double __lgamma (double) ;


extern double gamma (double) ; extern double __gamma (double) ;






extern double lgamma_r (double, int *__signgamp) ; extern double __lgamma_r (double, int *__signgamp) ;







extern double rint (double __x) ; extern double __rint (double __x) ;


extern double nextafter (double __x, double __y) __attribute__ ((__const__)); extern double __nextafter (double __x, double __y) __attribute__ ((__const__));





extern double remainder (double __x, double __y) ; extern double __remainder (double __x, double __y) ;



extern double scalbn (double __x, int __n) ; extern double __scalbn (double __x, int __n) ;



extern int ilogb (double __x) ; extern int __ilogb (double __x) ;






extern float acosf (float __x) ; extern float __acosf (float __x) ;

extern float asinf (float __x) ; extern float __asinf (float __x) ;

extern float atanf (float __x) ; extern float __atanf (float __x) ;

extern float atan2f (float __y, float __x) ; extern float __atan2f (float __y, float __x) ;


extern float cosf (float __x) ; extern float __cosf (float __x) ;

extern float sinf (float __x) ; extern float __sinf (float __x) ;

extern float tanf (float __x) ; extern float __tanf (float __x) ;




extern float coshf (float __x) ; extern float __coshf (float __x) ;

extern float sinhf (float __x) ; extern float __sinhf (float __x) ;

extern float tanhf (float __x) ; extern float __tanhf (float __x) ;




extern float acoshf (float __x) ; extern float __acoshf (float __x) ;

extern float asinhf (float __x) ; extern float __asinhf (float __x) ;

extern float atanhf (float __x) ; extern float __atanhf (float __x) ;







extern float expf (float __x) ; extern float __expf (float __x) ;


extern float frexpf (float __x, int *__exponent) ; extern float __frexpf (float __x, int *__exponent) ;


extern float ldexpf (float __x, int __exponent) ; extern float __ldexpf (float __x, int __exponent) ;


extern float logf (float __x) ; extern float __logf (float __x) ;


extern float log10f (float __x) ; extern float __log10f (float __x) ;


extern float modff (float __x, float *__iptr) ; extern float __modff (float __x, float *__iptr) ;




extern float expm1f (float __x) ; extern float __expm1f (float __x) ;


extern float log1pf (float __x) ; extern float __log1pf (float __x) ;


extern float logbf (float __x) ; extern float __logbf (float __x) ;




extern float powf (float __x, float __y) ; extern float __powf (float __x, float __y) ;


extern float sqrtf (float __x) ; extern float __sqrtf (float __x) ;





extern float hypotf (float __x, float __y) ; extern float __hypotf (float __x, float __y) ;






extern float cbrtf (float __x) ; extern float __cbrtf (float __x) ;








extern float ceilf (float __x) __attribute__ ((__const__)); extern float __ceilf (float __x) __attribute__ ((__const__));


extern float fabsf (float __x) __attribute__ ((__const__)); extern float __fabsf (float __x) __attribute__ ((__const__));


extern float floorf (float __x) __attribute__ ((__const__)); extern float __floorf (float __x) __attribute__ ((__const__));


extern float fmodf (float __x, float __y) ; extern float __fmodf (float __x, float __y) ;




extern int __isinff (float __value) __attribute__ ((__const__));


extern int __finitef (float __value) __attribute__ ((__const__));





extern int isinff (float __value) __attribute__ ((__const__));


extern int finitef (float __value) __attribute__ ((__const__));


extern float dremf (float __x, float __y) ; extern float __dremf (float __x, float __y) ;



extern float significandf (float __x) ; extern float __significandf (float __x) ;





extern float copysignf (float __x, float __y) __attribute__ ((__const__)); extern float __copysignf (float __x, float __y) __attribute__ ((__const__));


extern int __isnanf (float __value) __attribute__ ((__const__));



extern int isnanf (float __value) __attribute__ ((__const__));


extern float j0f (float) ; extern float __j0f (float) ;
extern float j1f (float) ; extern float __j1f (float) ;
extern float jnf (int, float) ; extern float __jnf (int, float) ;
extern float y0f (float) ; extern float __y0f (float) ;
extern float y1f (float) ; extern float __y1f (float) ;
extern float ynf (int, float) ; extern float __ynf (int, float) ;






extern float erff (float) ; extern float __erff (float) ;
extern float erfcf (float) ; extern float __erfcf (float) ;
extern float lgammaf (float) ; extern float __lgammaf (float) ;


extern float gammaf (float) ; extern float __gammaf (float) ;






extern float lgammaf_r (float, int *__signgamp) ; extern float __lgammaf_r (float, int *__signgamp) ;







extern float rintf (float __x) ; extern float __rintf (float __x) ;


extern float nextafterf (float __x, float __y) __attribute__ ((__const__)); extern float __nextafterf (float __x, float __y) __attribute__ ((__const__));





extern float remainderf (float __x, float __y) ; extern float __remainderf (float __x, float __y) ;



extern float scalbnf (float __x, int __n) ; extern float __scalbnf (float __x, int __n) ;



extern int ilogbf (float __x) ; extern int __ilogbf (float __x) ;






extern long double acosl (long double __x) ; extern long double __acosl (long double __x) ;

extern long double asinl (long double __x) ; extern long double __asinl (long double __x) ;

extern long double atanl (long double __x) ; extern long double __atanl (long double __x) ;

extern long double atan2l (long double __y, long double __x) ; extern long double __atan2l (long double __y, long double __x) ;


extern long double cosl (long double __x) ; extern long double __cosl (long double __x) ;

extern long double sinl (long double __x) ; extern long double __sinl (long double __x) ;

extern long double tanl (long double __x) ; extern long double __tanl (long double __x) ;




extern long double coshl (long double __x) ; extern long double __coshl (long double __x) ;

extern long double sinhl (long double __x) ; extern long double __sinhl (long double __x) ;

extern long double tanhl (long double __x) ; extern long double __tanhl (long double __x) ;




extern long double acoshl (long double __x) ; extern long double __acoshl (long double __x) ;

extern long double asinhl (long double __x) ; extern long double __asinhl (long double __x) ;

extern long double atanhl (long double __x) ; extern long double __atanhl (long double __x) ;







extern long double expl (long double __x) ; extern long double __expl (long double __x) ;


extern long double frexpl (long double __x, int *__exponent) ; extern long double __frexpl (long double __x, int *__exponent) ;


extern long double ldexpl (long double __x, int __exponent) ; extern long double __ldexpl (long double __x, int __exponent) ;


extern long double logl (long double __x) ; extern long double __logl (long double __x) ;


extern long double log10l (long double __x) ; extern long double __log10l (long double __x) ;


extern long double modfl (long double __x, long double *__iptr) ; extern long double __modfl (long double __x, long double *__iptr) ;




extern long double expm1l (long double __x) ; extern long double __expm1l (long double __x) ;


extern long double log1pl (long double __x) ; extern long double __log1pl (long double __x) ;


extern long double logbl (long double __x) ; extern long double __logbl (long double __x) ;




extern long double powl (long double __x, long double __y) ; extern long double __powl (long double __x, long double __y) ;


extern long double sqrtl (long double __x) ; extern long double __sqrtl (long double __x) ;





extern long double hypotl (long double __x, long double __y) ; extern long double __hypotl (long double __x, long double __y) ;






extern long double cbrtl (long double __x) ; extern long double __cbrtl (long double __x) ;








extern long double ceill (long double __x) __attribute__ ((__const__)); extern long double __ceill (long double __x) __attribute__ ((__const__));


extern long double fabsl (long double __x) __attribute__ ((__const__)); extern long double __fabsl (long double __x) __attribute__ ((__const__));


extern long double floorl (long double __x) __attribute__ ((__const__)); extern long double __floorl (long double __x) __attribute__ ((__const__));


extern long double fmodl (long double __x, long double __y) ; extern long double __fmodl (long double __x, long double __y) ;




extern int __isinfl (long double __value) __attribute__ ((__const__));


extern int __finitel (long double __value) __attribute__ ((__const__));





extern int isinfl (long double __value) __attribute__ ((__const__));


extern int finitel (long double __value) __attribute__ ((__const__));


extern long double dreml (long double __x, long double __y) ; extern long double __dreml (long double __x, long double __y) ;



extern long double significandl (long double __x) ; extern long double __significandl (long double __x) ;





extern long double copysignl (long double __x, long double __y) __attribute__ ((__const__)); extern long double __copysignl (long double __x, long double __y) __attribute__ ((__const__));


extern int __isnanl (long double __value) __attribute__ ((__const__));



extern int isnanl (long double __value) __attribute__ ((__const__));


extern long double j0l (long double) ; extern long double __j0l (long double) ;
extern long double j1l (long double) ; extern long double __j1l (long double) ;
extern long double jnl (int, long double) ; extern long double __jnl (int, long double) ;
extern long double y0l (long double) ; extern long double __y0l (long double) ;
extern long double y1l (long double) ; extern long double __y1l (long double) ;
extern long double ynl (int, long double) ; extern long double __ynl (int, long double) ;






extern long double erfl (long double) ; extern long double __erfl (long double) ;
extern long double erfcl (long double) ; extern long double __erfcl (long double) ;
extern long double lgammal (long double) ; extern long double __lgammal (long double) ;


extern long double gammal (long double) ; extern long double __gammal (long double) ;






extern long double lgammal_r (long double, int *__signgamp) ; extern long double __lgammal_r (long double, int *__signgamp) ;







extern long double rintl (long double __x) ; extern long double __rintl (long double __x) ;


extern long double nextafterl (long double __x, long double __y) __attribute__ ((__const__)); extern long double __nextafterl (long double __x, long double __y) __attribute__ ((__const__));





extern long double remainderl (long double __x, long double __y) ; extern long double __remainderl (long double __x, long double __y) ;



extern long double scalbnl (long double __x, int __n) ; extern long double __scalbnl (long double __x, int __n) ;



extern int ilogbl (long double __x) ; extern int __ilogbl (long double __x) ;


extern int signgam;

typedef enum
{
  _IEEE_ = -1,
  _SVID_,
  _XOPEN_,
  _POSIX_,
  _ISOC_
} _LIB_VERSION_TYPE;




extern _LIB_VERSION_TYPE _LIB_VERSION;

struct exception

  {
    int type;
    char *name;
    double arg1;
    double arg2;
    double retval;
  };




extern int matherr (struct exception *__exc);



extern __inline double __sgn (double) ; extern __inline double __sgn (double __x) { return __x == 0.0 ? 0.0 : (__x > 0.0 ? 1.0 : -1.0); } extern __inline float __sgnf (float) ; extern __inline float __sgnf (float __x) { return __x == 0.0 ? 0.0 : (__x > 0.0 ? 1.0 : -1.0); } extern __inline long double __sgnl (long double) ; extern __inline long double __sgnl (long double __x) { return __x == 0.0 ? 0.0 : (__x > 0.0 ? 1.0 : -1.0); }

extern __inline double atan2 (double __y, double __x) { register long double __value; __asm __volatile__ ("fpatan" : "=t" (__value) : "0" (__x), "u" (__y) : "st(1)"); return __value; } extern __inline float atan2f (float __y, float __x) { register long double __value; __asm __volatile__ ("fpatan" : "=t" (__value) : "0" (__x), "u" (__y) : "st(1)"); return __value; } extern __inline long double atan2l (long double __y, long double __x) { register long double __value; __asm __volatile__ ("fpatan" : "=t" (__value) : "0" (__x), "u" (__y) : "st(1)"); return __value; }
extern __inline long double __atan2l (long double __y, long double __x) { register long double __value; __asm __volatile__ ("fpatan" : "=t" (__value) : "0" (__x), "u" (__y) : "st(1)"); return __value; }


extern __inline double fmod (double __x, double __y) { register long double __value; __asm __volatile__ ("1:	fprem\n\t" "fnstsw	%%ax\n\t" "sahf\n\t" "jp	1b" : "=t" (__value) : "0" (__x), "u" (__y) : "ax", "cc"); return __value; } extern __inline float fmodf (float __x, float __y) { register long double __value; __asm __volatile__ ("1:	fprem\n\t" "fnstsw	%%ax\n\t" "sahf\n\t" "jp	1b" : "=t" (__value) : "0" (__x), "u" (__y) : "ax", "cc"); return __value; } extern __inline long double fmodl (long double __x, long double __y) { register long double __value; __asm __volatile__ ("1:	fprem\n\t" "fnstsw	%%ax\n\t" "sahf\n\t" "jp	1b" : "=t" (__value) : "0" (__x), "u" (__y) : "ax", "cc"); return __value; }

extern __inline double fabs (double __x) { return __builtin_fabs (__x); }
extern __inline float fabsf (float __x) { return __builtin_fabsf (__x); }
extern __inline long double fabsl (long double __x) { return __builtin_fabsl (__x); }
extern __inline long double __fabsl (long double __x) { return __builtin_fabsl (__x); }

extern __inline double atan (double __x) { register double __result; __asm __volatile__ ("fld1; fpatan" : "=t" (__result) : "0" (__x) : "st(1)"); return __result; } extern __inline float atanf (float __x) { register float __result; __asm __volatile__ ("fld1; fpatan" : "=t" (__result) : "0" (__x) : "st(1)"); return __result; } extern __inline long double atanl (long double __x) { register long double __result; __asm __volatile__ ("fld1; fpatan" : "=t" (__result) : "0" (__x) : "st(1)"); return __result; }

extern __inline long double __sgn1l (long double) ; extern __inline long double __sgn1l (long double __x) { __extension__ union { long double __xld; unsigned int __xi[3]; } __n = { __xld: __x }; __n.__xi[2] = (__n.__xi[2] & 0x8000) | 0x3fff; __n.__xi[1] = 0x80000000; __n.__xi[0] = 0; return __n.__xld; }

extern __inline double floor (double __x) { register long double __value; __volatile unsigned short int __cw; __volatile unsigned short int __cwtmp; __asm __volatile ("fnstcw %0" : "=m" (__cw)); __cwtmp = (__cw & 0xf3ff) | 0x0400; __asm __volatile ("fldcw %0" : : "m" (__cwtmp)); __asm __volatile ("frndint" : "=t" (__value) : "0" (__x)); __asm __volatile ("fldcw %0" : : "m" (__cw)); return __value; } extern __inline float floorf (float __x) { register long double __value; __volatile unsigned short int __cw; __volatile unsigned short int __cwtmp; __asm __volatile ("fnstcw %0" : "=m" (__cw)); __cwtmp = (__cw & 0xf3ff) | 0x0400; __asm __volatile ("fldcw %0" : : "m" (__cwtmp)); __asm __volatile ("frndint" : "=t" (__value) : "0" (__x)); __asm __volatile ("fldcw %0" : : "m" (__cw)); return __value; } extern __inline long double floorl (long double __x) { register long double __value; __volatile unsigned short int __cw; __volatile unsigned short int __cwtmp; __asm __volatile ("fnstcw %0" : "=m" (__cw)); __cwtmp = (__cw & 0xf3ff) | 0x0400; __asm __volatile ("fldcw %0" : : "m" (__cwtmp)); __asm __volatile ("frndint" : "=t" (__value) : "0" (__x)); __asm __volatile ("fldcw %0" : : "m" (__cw)); return __value; }

extern __inline double ceil (double __x) { register long double __value; __volatile unsigned short int __cw; __volatile unsigned short int __cwtmp; __asm __volatile ("fnstcw %0" : "=m" (__cw)); __cwtmp = (__cw & 0xf3ff) | 0x0800; __asm __volatile ("fldcw %0" : : "m" (__cwtmp)); __asm __volatile ("frndint" : "=t" (__value) : "0" (__x)); __asm __volatile ("fldcw %0" : : "m" (__cw)); return __value; } extern __inline float ceilf (float __x) { register long double __value; __volatile unsigned short int __cw; __volatile unsigned short int __cwtmp; __asm __volatile ("fnstcw %0" : "=m" (__cw)); __cwtmp = (__cw & 0xf3ff) | 0x0800; __asm __volatile ("fldcw %0" : : "m" (__cwtmp)); __asm __volatile ("frndint" : "=t" (__value) : "0" (__x)); __asm __volatile ("fldcw %0" : : "m" (__cw)); return __value; } extern __inline long double ceill (long double __x) { register long double __value; __volatile unsigned short int __cw; __volatile unsigned short int __cwtmp; __asm __volatile ("fnstcw %0" : "=m" (__cw)); __cwtmp = (__cw & 0xf3ff) | 0x0800; __asm __volatile ("fldcw %0" : : "m" (__cwtmp)); __asm __volatile ("frndint" : "=t" (__value) : "0" (__x)); __asm __volatile ("fldcw %0" : : "m" (__cw)); return __value; }

extern __inline double drem (double __x, double __y) { register double __value; register int __clobbered; __asm __volatile__ ("1:	fprem1\n\t" "fstsw	%%ax\n\t" "sahf\n\t" "jp	1b" : "=t" (__value), "=&a" (__clobbered) : "0" (__x), "u" (__y) : "cc"); return __value; } extern __inline float dremf (float __x, float __y) { register double __value; register int __clobbered; __asm __volatile__ ("1:	fprem1\n\t" "fstsw	%%ax\n\t" "sahf\n\t" "jp	1b" : "=t" (__value), "=&a" (__clobbered) : "0" (__x), "u" (__y) : "cc"); return __value; } extern __inline long double dreml (long double __x, long double __y) { register double __value; register int __clobbered; __asm __volatile__ ("1:	fprem1\n\t" "fstsw	%%ax\n\t" "sahf\n\t" "jp	1b" : "=t" (__value), "=&a" (__clobbered) : "0" (__x), "u" (__y) : "cc"); return __value; }

extern __inline int
__finite (double __x)
{
  return (__extension__
          (((((union { double __d; int __i[2]; }) {__d: __x}).__i[1]
             | 0x800fffffu) + 1) >> 31));
}














typedef __intptr_t intptr_t;






typedef __socklen_t socklen_t;

extern int access (__const char *__name, int __type) ;

extern __off_t lseek (int __fd, __off_t __offset, int __whence) ;

extern int close (int __fd);






extern ssize_t read (int __fd, void *__buf, size_t __nbytes);





extern ssize_t write (int __fd, __const void *__buf, size_t __n);

extern int pipe (int __pipedes[2]) ;

extern unsigned int alarm (unsigned int __seconds) ;

extern unsigned int sleep (unsigned int __seconds);






extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     ;






extern int usleep (__useconds_t __useconds);

extern int pause (void);



extern int chown (__const char *__file, __uid_t __owner, __gid_t __group)
     ;



extern int fchown (int __fd, __uid_t __owner, __gid_t __group) ;




extern int lchown (__const char *__file, __uid_t __owner, __gid_t __group)
     ;




extern int chdir (__const char *__path) ;



extern int fchdir (int __fd) ;

extern char *getcwd (char *__buf, size_t __size) ;

extern char *getwd (char *__buf) ;




extern int dup (int __fd) ;


extern int dup2 (int __fd, int __fd2) ;


extern char **__environ;







extern int execve (__const char *__path, char *__const __argv[],
                   char *__const __envp[]) ;

extern int execv (__const char *__path, char *__const __argv[]) ;



extern int execle (__const char *__path, __const char *__arg, ...) ;



extern int execl (__const char *__path, __const char *__arg, ...) ;



extern int execvp (__const char *__file, char *__const __argv[]) ;




extern int execlp (__const char *__file, __const char *__arg, ...) ;




extern int nice (int __inc) ;




extern void _exit (int __status) __attribute__ ((__noreturn__));







enum
  {
    _PC_LINK_MAX,

    _PC_MAX_CANON,

    _PC_MAX_INPUT,

    _PC_NAME_MAX,

    _PC_PATH_MAX,

    _PC_PIPE_BUF,

    _PC_CHOWN_RESTRICTED,

    _PC_NO_TRUNC,

    _PC_VDISABLE,

    _PC_SYNC_IO,

    _PC_ASYNC_IO,

    _PC_PRIO_IO,

    _PC_SOCK_MAXBUF,

    _PC_FILESIZEBITS,

    _PC_REC_INCR_XFER_SIZE,

    _PC_REC_MAX_XFER_SIZE,

    _PC_REC_MIN_XFER_SIZE,

    _PC_REC_XFER_ALIGN,

    _PC_ALLOC_SIZE_MIN,

    _PC_SYMLINK_MAX,

    _PC_2_SYMLINKS

  };


enum
  {
    _SC_ARG_MAX,

    _SC_CHILD_MAX,

    _SC_CLK_TCK,

    _SC_NGROUPS_MAX,

    _SC_OPEN_MAX,

    _SC_STREAM_MAX,

    _SC_TZNAME_MAX,

    _SC_JOB_CONTROL,

    _SC_SAVED_IDS,

    _SC_REALTIME_SIGNALS,

    _SC_PRIORITY_SCHEDULING,

    _SC_TIMERS,

    _SC_ASYNCHRONOUS_IO,

    _SC_PRIORITIZED_IO,

    _SC_SYNCHRONIZED_IO,

    _SC_FSYNC,

    _SC_MAPPED_FILES,

    _SC_MEMLOCK,

    _SC_MEMLOCK_RANGE,

    _SC_MEMORY_PROTECTION,

    _SC_MESSAGE_PASSING,

    _SC_SEMAPHORES,

    _SC_SHARED_MEMORY_OBJECTS,

    _SC_AIO_LISTIO_MAX,

    _SC_AIO_MAX,

    _SC_AIO_PRIO_DELTA_MAX,

    _SC_DELAYTIMER_MAX,

    _SC_MQ_OPEN_MAX,

    _SC_MQ_PRIO_MAX,

    _SC_VERSION,

    _SC_PAGESIZE,


    _SC_RTSIG_MAX,

    _SC_SEM_NSEMS_MAX,

    _SC_SEM_VALUE_MAX,

    _SC_SIGQUEUE_MAX,

    _SC_TIMER_MAX,




    _SC_BC_BASE_MAX,

    _SC_BC_DIM_MAX,

    _SC_BC_SCALE_MAX,

    _SC_BC_STRING_MAX,

    _SC_COLL_WEIGHTS_MAX,

    _SC_EQUIV_CLASS_MAX,

    _SC_EXPR_NEST_MAX,

    _SC_LINE_MAX,

    _SC_RE_DUP_MAX,

    _SC_CHARCLASS_NAME_MAX,


    _SC_2_VERSION,

    _SC_2_C_BIND,

    _SC_2_C_DEV,

    _SC_2_FORT_DEV,

    _SC_2_FORT_RUN,

    _SC_2_SW_DEV,

    _SC_2_LOCALEDEF,


    _SC_PII,

    _SC_PII_XTI,

    _SC_PII_SOCKET,

    _SC_PII_INTERNET,

    _SC_PII_OSI,

    _SC_POLL,

    _SC_SELECT,

    _SC_UIO_MAXIOV,

    _SC_IOV_MAX = _SC_UIO_MAXIOV,

    _SC_PII_INTERNET_STREAM,

    _SC_PII_INTERNET_DGRAM,

    _SC_PII_OSI_COTS,

    _SC_PII_OSI_CLTS,

    _SC_PII_OSI_M,

    _SC_T_IOV_MAX,



    _SC_THREADS,

    _SC_THREAD_SAFE_FUNCTIONS,

    _SC_GETGR_R_SIZE_MAX,

    _SC_GETPW_R_SIZE_MAX,

    _SC_LOGIN_NAME_MAX,

    _SC_TTY_NAME_MAX,

    _SC_THREAD_DESTRUCTOR_ITERATIONS,

    _SC_THREAD_KEYS_MAX,

    _SC_THREAD_STACK_MIN,

    _SC_THREAD_THREADS_MAX,

    _SC_THREAD_ATTR_STACKADDR,

    _SC_THREAD_ATTR_STACKSIZE,

    _SC_THREAD_PRIORITY_SCHEDULING,

    _SC_THREAD_PRIO_INHERIT,

    _SC_THREAD_PRIO_PROTECT,

    _SC_THREAD_PROCESS_SHARED,


    _SC_NPROCESSORS_CONF,

    _SC_NPROCESSORS_ONLN,

    _SC_PHYS_PAGES,

    _SC_AVPHYS_PAGES,

    _SC_ATEXIT_MAX,

    _SC_PASS_MAX,


    _SC_XOPEN_VERSION,

    _SC_XOPEN_XCU_VERSION,

    _SC_XOPEN_UNIX,

    _SC_XOPEN_CRYPT,

    _SC_XOPEN_ENH_I18N,

    _SC_XOPEN_SHM,


    _SC_2_CHAR_TERM,

    _SC_2_C_VERSION,

    _SC_2_UPE,


    _SC_XOPEN_XPG2,

    _SC_XOPEN_XPG3,

    _SC_XOPEN_XPG4,


    _SC_CHAR_BIT,

    _SC_CHAR_MAX,

    _SC_CHAR_MIN,

    _SC_INT_MAX,

    _SC_INT_MIN,

    _SC_LONG_BIT,

    _SC_WORD_BIT,

    _SC_MB_LEN_MAX,

    _SC_NZERO,

    _SC_SSIZE_MAX,

    _SC_SCHAR_MAX,

    _SC_SCHAR_MIN,

    _SC_SHRT_MAX,

    _SC_SHRT_MIN,

    _SC_UCHAR_MAX,

    _SC_UINT_MAX,

    _SC_ULONG_MAX,

    _SC_USHRT_MAX,


    _SC_NL_ARGMAX,

    _SC_NL_LANGMAX,

    _SC_NL_MSGMAX,

    _SC_NL_NMAX,

    _SC_NL_SETMAX,

    _SC_NL_TEXTMAX,


    _SC_XBS5_ILP32_OFF32,

    _SC_XBS5_ILP32_OFFBIG,

    _SC_XBS5_LP64_OFF64,

    _SC_XBS5_LPBIG_OFFBIG,


    _SC_XOPEN_LEGACY,

    _SC_XOPEN_REALTIME,

    _SC_XOPEN_REALTIME_THREADS,


    _SC_ADVISORY_INFO,

    _SC_BARRIERS,

    _SC_BASE,

    _SC_C_LANG_SUPPORT,

    _SC_C_LANG_SUPPORT_R,

    _SC_CLOCK_SELECTION,

    _SC_CPUTIME,

    _SC_THREAD_CPUTIME,

    _SC_DEVICE_IO,

    _SC_DEVICE_SPECIFIC,

    _SC_DEVICE_SPECIFIC_R,

    _SC_FD_MGMT,

    _SC_FIFO,

    _SC_PIPE,

    _SC_FILE_ATTRIBUTES,

    _SC_FILE_LOCKING,

    _SC_FILE_SYSTEM,

    _SC_MONOTONIC_CLOCK,

    _SC_MULTI_PROCESS,

    _SC_SINGLE_PROCESS,

    _SC_NETWORKING,

    _SC_READER_WRITER_LOCKS,

    _SC_SPIN_LOCKS,

    _SC_REGEXP,

    _SC_REGEX_VERSION,

    _SC_SHELL,

    _SC_SIGNALS,

    _SC_SPAWN,

    _SC_SPORADIC_SERVER,

    _SC_THREAD_SPORADIC_SERVER,

    _SC_SYSTEM_DATABASE,

    _SC_SYSTEM_DATABASE_R,

    _SC_TIMEOUTS,

    _SC_TYPED_MEMORY_OBJECTS,

    _SC_USER_GROUPS,

    _SC_USER_GROUPS_R,

    _SC_2_PBS,

    _SC_2_PBS_ACCOUNTING,

    _SC_2_PBS_LOCATE,

    _SC_2_PBS_MESSAGE,

    _SC_2_PBS_TRACK,

    _SC_SYMLOOP_MAX,

    _SC_STREAMS,

    _SC_2_PBS_CHECKPOINT,


    _SC_V6_ILP32_OFF32,

    _SC_V6_ILP32_OFFBIG,

    _SC_V6_LP64_OFF64,

    _SC_V6_LPBIG_OFFBIG,


    _SC_HOST_NAME_MAX,

    _SC_TRACE,

    _SC_TRACE_EVENT_FILTER,

    _SC_TRACE_INHERIT,

    _SC_TRACE_LOG

  };


enum
  {
    _CS_PATH,


    _CS_V6_WIDTH_RESTRICTED_ENVS,


    _CS_GNU_LIBC_VERSION,

    _CS_GNU_LIBPTHREAD_VERSION,


    _CS_LFS_CFLAGS = 1000,

    _CS_LFS_LDFLAGS,

    _CS_LFS_LIBS,

    _CS_LFS_LINTFLAGS,

    _CS_LFS64_CFLAGS,

    _CS_LFS64_LDFLAGS,

    _CS_LFS64_LIBS,

    _CS_LFS64_LINTFLAGS,


    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,

    _CS_XBS5_ILP32_OFF32_LDFLAGS,

    _CS_XBS5_ILP32_OFF32_LIBS,

    _CS_XBS5_ILP32_OFF32_LINTFLAGS,

    _CS_XBS5_ILP32_OFFBIG_CFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LIBS,

    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,

    _CS_XBS5_LP64_OFF64_CFLAGS,

    _CS_XBS5_LP64_OFF64_LDFLAGS,

    _CS_XBS5_LP64_OFF64_LIBS,

    _CS_XBS5_LP64_OFF64_LINTFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LIBS,

    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LIBS,

    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V6_LP64_OFF64_CFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LIBS,

    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS

  };



extern long int pathconf (__const char *__path, int __name) ;


extern long int fpathconf (int __fd, int __name) ;


extern long int sysconf (int __name) __attribute__ ((__const__));



extern size_t confstr (int __name, char *__buf, size_t __len) ;




extern __pid_t getpid (void) ;


extern __pid_t getppid (void) ;




extern __pid_t getpgrp (void) ;

extern __pid_t __getpgid (__pid_t __pid) ;

extern int setpgid (__pid_t __pid, __pid_t __pgid) ;

extern int setpgrp (void) ;

extern __pid_t setsid (void) ;







extern __uid_t getuid (void) ;


extern __uid_t geteuid (void) ;


extern __gid_t getgid (void) ;


extern __gid_t getegid (void) ;




extern int getgroups (int __size, __gid_t __list[]) ;

extern int setuid (__uid_t __uid) ;




extern int setreuid (__uid_t __ruid, __uid_t __euid) ;




extern int seteuid (__uid_t __uid) ;






extern int setgid (__gid_t __gid) ;




extern int setregid (__gid_t __rgid, __gid_t __egid) ;




extern int setegid (__gid_t __gid) ;

extern __pid_t fork (void) ;






extern __pid_t vfork (void) ;





extern char *ttyname (int __fd) ;



extern int ttyname_r (int __fd, char *__buf, size_t __buflen) ;



extern int isatty (int __fd) ;





extern int ttyslot (void) ;




extern int link (__const char *__from, __const char *__to) ;



extern int symlink (__const char *__from, __const char *__to) ;




extern int readlink (__const char *__restrict __path, char *__restrict __buf,
                     size_t __len) ;



extern int unlink (__const char *__name) ;


extern int rmdir (__const char *__path) ;



extern __pid_t tcgetpgrp (int __fd) ;


extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) ;






extern char *getlogin (void);

extern int setlogin (__const char *__name) ;



extern char *optarg;

extern int optind;




extern int opterr;



extern int optopt;

extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       ;








extern int gethostname (char *__name, size_t __len) ;






extern int sethostname (__const char *__name, size_t __len) ;



extern int sethostid (long int __id) ;





extern int getdomainname (char *__name, size_t __len) ;
extern int setdomainname (__const char *__name, size_t __len) ;





extern int vhangup (void) ;


extern int revoke (__const char *__file) ;







extern int profil (unsigned short int *__sample_buffer, size_t __size,
                   size_t __offset, unsigned int __scale) ;





extern int acct (__const char *__name) ;



extern char *getusershell (void) ;
extern void endusershell (void) ;
extern void setusershell (void) ;





extern int daemon (int __nochdir, int __noclose) ;






extern int chroot (__const char *__path) ;



extern char *getpass (__const char *__prompt);

extern int fsync (int __fd);






extern long int gethostid (void);


extern void sync (void) ;




extern int getpagesize (void) __attribute__ ((__const__));




extern int truncate (__const char *__file, __off_t __length) ;

extern int ftruncate (int __fd, __off_t __length) ;

extern int getdtablesize (void) ;

extern int brk (void *__addr) ;





extern void *sbrk (intptr_t __delta) ;

extern long int syscall (long int __sysno, ...) ;

extern int lockf (int __fd, int __cmd, __off_t __len);

extern int fdatasync (int __fildes) ;









extern int __sigismember (__const __sigset_t *, int);
extern int __sigaddset (__sigset_t *, int);
extern int __sigdelset (__sigset_t *, int);

extern __inline int __sigismember (__const __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return (__set->__val[__word] & __mask) ? 1 : 0; }
extern __inline int __sigaddset ( __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return ((__set->__val[__word] |= __mask), 0); }
extern __inline int __sigdelset ( __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return ((__set->__val[__word] &= ~__mask), 0); }








typedef __sig_atomic_t sig_atomic_t;





typedef void (*__sighandler_t) (int);




extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
     ;



extern __sighandler_t signal (int __sig, __sighandler_t __handler) ;



extern int kill (__pid_t __pid, int __sig) ;






extern int killpg (__pid_t __pgrp, int __sig) ;




extern int raise (int __sig) ;




extern __sighandler_t ssignal (int __sig, __sighandler_t __handler) ;
extern int gsignal (int __sig) ;




extern void psignal (int __sig, __const char *__s);

extern int __sigpause (int __sig_or_mask, int __is_sig);




extern int sigpause (int __mask) ;

extern int sigblock (int __mask) ;


extern int sigsetmask (int __mask) ;


extern int siggetmask (void) ;

typedef __sighandler_t sig_t;






















typedef union sigval
  {
    int sival_int;
    void *sival_ptr;
  } sigval_t;

typedef struct siginfo
  {
    int si_signo;
    int si_errno;

    int si_code;

    union
      {
        int _pad[((128 / sizeof (int)) - 3)];


        struct
          {
            __pid_t si_pid;
            __uid_t si_uid;
          } _kill;


        struct
          {
            int si_tid;
            int si_overrun;
            sigval_t si_sigval;
          } _timer;


        struct
          {
            __pid_t si_pid;
            __uid_t si_uid;
            sigval_t si_sigval;
          } _rt;


        struct
          {
            __pid_t si_pid;
            __uid_t si_uid;
            int si_status;
            __clock_t si_utime;
            __clock_t si_stime;
          } _sigchld;


        struct
          {
            void *si_addr;
          } _sigfault;


        struct
          {
            long int si_band;
            int si_fd;
          } _sigpoll;
      } _sifields;
  } siginfo_t;

enum
{
  SI_ASYNCNL = -60,

  SI_TKILL = -6,

  SI_SIGIO,

  SI_ASYNCIO,

  SI_MESGQ,

  SI_TIMER,

  SI_QUEUE,

  SI_USER,

  SI_KERNEL = 0x80

};



enum
{
  ILL_ILLOPC = 1,

  ILL_ILLOPN,

  ILL_ILLADR,

  ILL_ILLTRP,

  ILL_PRVOPC,

  ILL_PRVREG,

  ILL_COPROC,

  ILL_BADSTK

};


enum
{
  FPE_INTDIV = 1,

  FPE_INTOVF,

  FPE_FLTDIV,

  FPE_FLTOVF,

  FPE_FLTUND,

  FPE_FLTRES,

  FPE_FLTINV,

  FPE_FLTSUB

};


enum
{
  SEGV_MAPERR = 1,

  SEGV_ACCERR

};


enum
{
  BUS_ADRALN = 1,

  BUS_ADRERR,

  BUS_OBJERR

};


enum
{
  TRAP_BRKPT = 1,

  TRAP_TRACE

};


enum
{
  CLD_EXITED = 1,

  CLD_KILLED,

  CLD_DUMPED,

  CLD_TRAPPED,

  CLD_STOPPED,

  CLD_CONTINUED

};


enum
{
  POLL_IN = 1,

  POLL_OUT,

  POLL_MSG,

  POLL_ERR,

  POLL_PRI,

  POLL_HUP

};

typedef struct sigevent
  {
    sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;

    union
      {
        int _pad[((64 / sizeof (int)) - 3)];



        __pid_t _tid;

        struct
          {
            void (*_function) (sigval_t);
            void *_attribute;
          } _sigev_thread;
      } _sigev_un;
  } sigevent_t;






enum
{
  SIGEV_SIGNAL = 0,

  SIGEV_NONE,

  SIGEV_THREAD,


  SIGEV_THREAD_ID = 4

};




extern int sigemptyset (sigset_t *__set) ;


extern int sigfillset (sigset_t *__set) ;


extern int sigaddset (sigset_t *__set, int __signo) ;


extern int sigdelset (sigset_t *__set, int __signo) ;


extern int sigismember (__const sigset_t *__set, int __signo) ;



struct sigaction
  {


    union
      {

        __sighandler_t sa_handler;

        void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;







    __sigset_t sa_mask;


    int sa_flags;


    void (*sa_restorer) (void);
  };



extern int sigprocmask (int __how, __const sigset_t *__restrict __set,
                        sigset_t *__restrict __oset) ;






extern int sigsuspend (__const sigset_t *__set);


extern int sigaction (int __sig, __const struct sigaction *__restrict __act,
                      struct sigaction *__restrict __oact) ;


extern int sigpending (sigset_t *__set) ;






extern int sigwait (__const sigset_t *__restrict __set, int *__restrict __sig);






extern int sigwaitinfo (__const sigset_t *__restrict __set,
                        siginfo_t *__restrict __info);






extern int sigtimedwait (__const sigset_t *__restrict __set,
                         siginfo_t *__restrict __info,
                         __const struct timespec *__restrict __timeout);



extern int sigqueue (__pid_t __pid, int __sig, __const union sigval __val)
     ;

extern __const char *__const _sys_siglist[65];
extern __const char *__const sys_siglist[65];


struct sigvec
  {
    __sighandler_t sv_handler;
    int sv_mask;

    int sv_flags;

  };

extern int sigvec (int __sig, __const struct sigvec *__vec,
                   struct sigvec *__ovec) ;












struct _fpreg {
        unsigned short significand[4];
        unsigned short exponent;
};

struct _fpxreg {
        unsigned short significand[4];
        unsigned short exponent;
        unsigned short padding[3];
};

struct _xmmreg {
        unsigned long element[4];
};

struct _fpstate {

        unsigned long cw;
        unsigned long sw;
        unsigned long tag;
        unsigned long ipoff;
        unsigned long cssel;
        unsigned long dataoff;
        unsigned long datasel;
        struct _fpreg _st[8];
        unsigned short status;
        unsigned short magic;


        unsigned long _fxsr_env[6];
        unsigned long mxcsr;
        unsigned long reserved;
        struct _fpxreg _fxsr_st[8];
        struct _xmmreg _xmm[8];
        unsigned long padding[56];
};



struct sigcontext {
        unsigned short gs, __gsh;
        unsigned short fs, __fsh;
        unsigned short es, __esh;
        unsigned short ds, __dsh;
        unsigned long edi;
        unsigned long esi;
        unsigned long ebp;
        unsigned long esp;
        unsigned long ebx;
        unsigned long edx;
        unsigned long ecx;
        unsigned long eax;
        unsigned long trapno;
        unsigned long err;
        unsigned long eip;
        unsigned short cs, __csh;
        unsigned long eflags;
        unsigned long esp_at_signal;
        unsigned short ss, __ssh;
        struct _fpstate * fpstate;
        unsigned long oldmask;
        unsigned long cr2;
};




extern int sigreturn (struct sigcontext *__scp) ;

extern int siginterrupt (int __sig, int __interrupt) ;



struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };



enum
{
  SS_ONSTACK = 1,

  SS_DISABLE

};

typedef struct sigaltstack
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;


extern int sigstack (struct sigstack *__ss, struct sigstack *__oss) ;



extern int sigaltstack (__const struct sigaltstack *__restrict __ss,
                        struct sigaltstack *__restrict __oss) ;





extern int pthread_sigmask (int __how,
                            __const __sigset_t *__restrict __newmask,
                            __sigset_t *__restrict __oldmask);


extern int pthread_kill (pthread_t __threadid, int __signo) ;







extern int __libc_current_sigrtmin (void) ;

extern int __libc_current_sigrtmax (void) ;










enum __rlimit_resource
{

  RLIMIT_CPU = 0,



  RLIMIT_FSIZE = 1,



  RLIMIT_DATA = 2,



  RLIMIT_STACK = 3,



  RLIMIT_CORE = 4,






  RLIMIT_RSS = 5,



  RLIMIT_NOFILE = 7,
  RLIMIT_OFILE = RLIMIT_NOFILE,




  RLIMIT_AS = 9,



  RLIMIT_NPROC = 6,



  RLIMIT_MEMLOCK = 8,



  RLIMIT_LOCKS = 10,


  RLIMIT_NLIMITS = 11,
  RLIM_NLIMITS = RLIMIT_NLIMITS


};

typedef __rlim_t rlim_t;







struct rlimit
  {

    rlim_t rlim_cur;

    rlim_t rlim_max;
  };

enum __rusage_who
{

  RUSAGE_SELF = 0,



  RUSAGE_CHILDREN = -1,



  RUSAGE_BOTH = -2

};






struct rusage
  {

    struct timeval ru_utime;

    struct timeval ru_stime;

    long int ru_maxrss;


    long int ru_ixrss;

    long int ru_idrss;

    long int ru_isrss;


    long int ru_minflt;

    long int ru_majflt;

    long int ru_nswap;


    long int ru_inblock;

    long int ru_oublock;

    long int ru_msgsnd;

    long int ru_msgrcv;

    long int ru_nsignals;



    long int ru_nvcsw;


    long int ru_nivcsw;
  };







enum __priority_which
{
  PRIO_PROCESS = 0,

  PRIO_PGRP = 1,

  PRIO_USER = 2

};









typedef int __rlimit_resource_t;
typedef int __rusage_who_t;
typedef int __priority_which_t;





extern int getrlimit (__rlimit_resource_t __resource,
                      struct rlimit *__rlimits) ;

extern int setrlimit (__rlimit_resource_t __resource,
                      __const struct rlimit *__rlimits) ;

extern int getrusage (__rusage_who_t __who, struct rusage *__usage) ;





extern int getpriority (__priority_which_t __which, id_t __who) ;



extern int setpriority (__priority_which_t __which, id_t __who, int __prio)
     ;













struct timezone
  {
    int tz_minuteswest;
    int tz_dsttime;
  };

typedef struct timezone *__restrict __timezone_ptr_t;

extern int gettimeofday (struct timeval *__restrict __tv,
                         __timezone_ptr_t __tz) ;




extern int settimeofday (__const struct timeval *__tv,
                         __const struct timezone *__tz) ;





extern int adjtime (__const struct timeval *__delta,
                    struct timeval *__olddelta) ;




enum __itimer_which
  {

    ITIMER_REAL = 0,


    ITIMER_VIRTUAL = 1,



    ITIMER_PROF = 2

  };



struct itimerval
  {

    struct timeval it_interval;

    struct timeval it_value;
  };






typedef int __itimer_which_t;




extern int getitimer (__itimer_which_t __which,
                      struct itimerval *__value) ;




extern int setitimer (__itimer_which_t __which,
                      __const struct itimerval *__restrict __new,
                      struct itimerval *__restrict __old) ;




extern int utimes (__const char *__file, __const struct timeval __tvp[2])
     ;



extern int lutimes (__const char *__file, __const struct timeval __tvp[2])
     ;


extern int futimes (int __fd, __const struct timeval __tvp[2]) ;




















extern long int __sysconf (int);




typedef __clock_t clock_t;






struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;


  long int tm_gmtoff;
  __const char *tm_zone;




};








struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };


struct sigevent;




extern clock_t clock (void) ;


extern time_t time (time_t *__timer) ;


extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__const__));


extern time_t mktime (struct tm *__tp) ;





extern size_t strftime (char *__restrict __s, size_t __maxsize,
                        __const char *__restrict __format,
                        __const struct tm *__restrict __tp) ;





extern struct tm *gmtime (__const time_t *__timer) ;



extern struct tm *localtime (__const time_t *__timer) ;





extern struct tm *gmtime_r (__const time_t *__restrict __timer,
                            struct tm *__restrict __tp) ;



extern struct tm *localtime_r (__const time_t *__restrict __timer,
                               struct tm *__restrict __tp) ;





extern char *asctime (__const struct tm *__tp) ;


extern char *ctime (__const time_t *__timer) ;







extern char *asctime_r (__const struct tm *__restrict __tp,
                        char *__restrict __buf) ;


extern char *ctime_r (__const time_t *__restrict __timer,
                      char *__restrict __buf) ;




extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;




extern char *tzname[2];



extern void tzset (void) ;



extern int daylight;
extern long int timezone;





extern int stime (__const time_t *__when) ;

extern time_t timegm (struct tm *__tp) ;


extern time_t timelocal (struct tm *__tp) ;


extern int dysize (int __year) __attribute__ ((__const__));

extern int nanosleep (__const struct timespec *__requested_time,
                      struct timespec *__remaining);



extern int clock_getres (clockid_t __clock_id, struct timespec *__res) ;


extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) ;


extern int clock_settime (clockid_t __clock_id, __const struct timespec *__tp)
     ;

extern int timer_create (clockid_t __clock_id,
                         struct sigevent *__restrict __evp,
                         timer_t *__restrict __timerid) ;


extern int timer_delete (timer_t __timerid) ;


extern int timer_settime (timer_t __timerid, int __flags,
                          __const struct itimerspec *__restrict __value,
                          struct itimerspec *__restrict __ovalue) ;


extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     ;


extern int timer_getoverrun (timer_t __timerid) ;





typedef short idx_t;
typedef short gene;
typedef gene *chromo;
typedef double fitness_t;
typedef struct _evaluation {
    fitness_t fitness, var, mean;
} evaluation;

int generations = 0,
    gbestage = 0;
fitness_t gbest;
chromo pop[20], offspring[(20 * 1 / 2)];
evaluation eval[20], offspring_eval[(20 * 1 / 2)];
fitness_t fbest = -1.0/0.0, fworst = 1.0/0.0,
          fsum = 0, varsum = 0, meansum = 0,
          ffsum = 0, ff[20];
int fbestidx = -1,
    var0idx = -1, var0cnt = 0;
int parent1[(20 * 1 / 2)], parent2[(20 * 1 / 2)];

idx_t idx[2*(4 -1)+1][4][6];
idx_t shares[(4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1))][3][3];
char numshares[(4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1))];

void initialize_encoding() {

    idx_t i,j,C; char L,H,k;
    for (i=0, C=1, L = (i < 4 -1) ? 1 : 0, H = (i > 4 -1) ? 1 : 0; i<=2*(4 -1); i++, C += L ? +1 : -1, L = (i < 4 -1) ? 1 : 0, H = (i > 4 -1) ? 1 : 0 ) for (j=0; j<C; j++) {
        for (k=0; k<6; k++)
            idx[i][j][k] = (4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1))+1;
    }
    int gene_idx_cnt = 0;

    for (i=0, C=1, L = (i < 4 -1) ? 1 : 0, H = (i > 4 -1) ? 1 : 0; i<=2*(4 -1); i++, C += L ? +1 : -1, L = (i < 4 -1) ? 1 : 0, H = (i > 4 -1) ? 1 : 0 ) for (j=0; j<C; j++) {

        if (idx[i][j][0] > (4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1))) {
            int gene_idx = gene_idx_cnt++;
            idx_t *s = shares[gene_idx][0];
            idx[i][j][0] = gene_idx;
            (*s)[0] = i, (*s)[1] = j, (*s)[2] = 0, s++;
            if (0<=i+-1 && i+-1<=2*(4 -1) && 0<=j+-1+H && j+-1+H<C+(i+-1 -i)*(L?1:H?-1:-(i+-1 -i))) idx[i+-1][j+-1+H][4] = gene_idx;
            (*s)[0] = i+-1, (*s)[1] = j+-1+H, (*s)[2] = 4, s++;
            if (0<=i+00 && i+00<=2*(4 -1) && 0<=j+-1+0 && j+-1+0<C+(i+00 -i)*(L?1:H?-1:-(i+00 -i))) idx[i+00][j+-1+0][2] = gene_idx;
            (*s)[0] = i+00, (*s)[1] = j+-1+0, (*s)[2] = 2, s++;
        };

        if (idx[i][j][1] > (4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1))) { int gene_idx = gene_idx_cnt++; idx_t **s = shares[gene_idx]; idx[i][j][1] = gene_idx; (*s)[0] = i, (*s)[1] = j, (*s)[2] = 1, s++; if (0<=i+-1 && i+-1<=2*(4 -1) && 0<=j+00+H && j+00+H<C+(i+-1 -i)*(L?1:H?-1:-(i+-1 -i))) idx[i+-1][j+00+H][2] = gene_idx; (*s)[0] = i+-1, (*s)[1] = j+00+H, (*s)[2] = 2, s++; if (0<=i+-1 && i+-1<=2*(4 -1) && 0<=j+-1+H && j+-1+H<C+(i+-1 -i)*(L?1:H?-1:-(i+-1 -i))) idx[i+-1][j+-1+H][3] = gene_idx; (*s)[0] = i+-1, (*s)[1] = j+-1+H, (*s)[2] = 3, s++; };
        if (idx[i][j][2] > (4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1))) { int gene_idx = gene_idx_cnt++; idx_t **s = shares[gene_idx]; idx[i][j][2] = gene_idx; (*s)[0] = i, (*s)[1] = j, (*s)[2] = 2, s++; if (0<=i+00 && i+00<=2*(4 -1) && 0<=j+ +1+0 && j+ +1+0<C+(i+00 -i)*(L?1:H?-1:-(i+00 -i))) idx[i+00][j+ +1+0][0] = gene_idx; (*s)[0] = i+00, (*s)[1] = j+ +1+0, (*s)[2] = 0, s++; if (0<=i+-1 && i+-1<=2*(4 -1) && 0<=j+00+H && j+00+H<C+(i+-1 -i)*(L?1:H?-1:-(i+-1 -i))) idx[i+-1][j+00+H][4] = gene_idx; (*s)[0] = i+-1, (*s)[1] = j+00+H, (*s)[2] = 4, s++; };
        if (idx[i][j][3] > (4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1))) { int gene_idx = gene_idx_cnt++; idx_t **s = shares[gene_idx]; idx[i][j][3] = gene_idx; (*s)[0] = i, (*s)[1] = j, (*s)[2] = 3, s++; if (0<=i+ +1 && i+ +1<=2*(4 -1) && 0<=j+00+L && j+00+L<C+(i+ +1 -i)*(L?1:H?-1:-(i+ +1 -i))) idx[i+ +1][j+00+L][1] = gene_idx; (*s)[0] = i+ +1, (*s)[1] = j+00+L, (*s)[2] = 1, s++; if (0<=i+00 && i+00<=2*(4 -1) && 0<=j+ +1+0 && j+ +1+0<C+(i+00 -i)*(L?1:H?-1:-(i+00 -i))) idx[i+00][j+ +1+0][5] = gene_idx; (*s)[0] = i+00, (*s)[1] = j+ +1+0, (*s)[2] = 5, s++; };
        if (idx[i][j][4] > (4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1))) { int gene_idx = gene_idx_cnt++; idx_t **s = shares[gene_idx]; idx[i][j][4] = gene_idx; (*s)[0] = i, (*s)[1] = j, (*s)[2] = 4, s++; if (0<=i+ +1 && i+ +1<=2*(4 -1) && 0<=j+-1+L && j+-1+L<C+(i+ +1 -i)*(L?1:H?-1:-(i+ +1 -i))) idx[i+ +1][j+-1+L][2] = gene_idx; (*s)[0] = i+ +1, (*s)[1] = j+-1+L, (*s)[2] = 2, s++; if (0<=i+ +1 && i+ +1<=2*(4 -1) && 0<=j+00+L && j+00+L<C+(i+ +1 -i)*(L?1:H?-1:-(i+ +1 -i))) idx[i+ +1][j+00+L][0] = gene_idx; (*s)[0] = i+ +1, (*s)[1] = j+00+L, (*s)[2] = 0, s++; };
        if (idx[i][j][5] > (4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1))) { int gene_idx = gene_idx_cnt++; idx_t **s = shares[gene_idx]; idx[i][j][5] = gene_idx; (*s)[0] = i, (*s)[1] = j, (*s)[2] = 5, s++; if (0<=i+00 && i+00<=2*(4 -1) && 0<=j+-1+0 && j+-1+0<C+(i+00 -i)*(L?1:H?-1:-(i+00 -i))) idx[i+00][j+-1+0][3] = gene_idx; (*s)[0] = i+00, (*s)[1] = j+-1+0, (*s)[2] = 3, s++; if (0<=i+ +1 && i+ +1<=2*(4 -1) && 0<=j+-1+L && j+-1+L<C+(i+ +1 -i)*(L?1:H?-1:-(i+ +1 -i))) idx[i+ +1][j+-1+L][1] = gene_idx; (*s)[0] = i+ +1, (*s)[1] = j+-1+L, (*s)[2] = 1, s++; };




    }
}

void print_chromo(FILE *out, chromo c) {
    idx_t i, j, C;


    for (C=1, i=0; C<=4; C++, i++) {
        for (j=C; j<4; j++) fprintf(out, "    ");; for (j=0; j<C; j++) fprintf(out, "    %3d ", c[idx[i][j][1]]); fprintf(out, "\n");
        for (j=C; j<4; j++) fprintf(out, "    ");; for (j=0; j<C; j++) fprintf(out, "%3d     ", c[idx[i][j][0]]);
        fprintf(out, "%3d\n", c[idx[i][j-1][2]]);
    }
    for (C=4, i=4 -1; C>=1; C--, i++) {
        for (j=C; j<4; j++) fprintf(out, "    ");; for (j=0; j<C; j++) fprintf(out, "%3d     ", c[idx[i][j][5]]);
        fprintf(out, "%3d\n", c[idx[i][j-1][3]]);
        for (j=C; j<4; j++) fprintf(out, "    ");; for (j=0; j<C; j++) fprintf(out, "    %3d ", c[idx[i][j][4]]); fprintf(out, "\n");
    }




}


inline int hexsum(chromo c, idx_t i, idx_t j) {
    int s = 0;
    char k;
    idx_t *ij = idx[i][j];
    for (k=0; k<6; k++)
        s += c[ij[k]];
    return s;
}


void evaluate(chromo c, evaluation *e) {
    int s, sum = 0, sqsum = 0;
    idx_t i,j,C; char L,H;
    for (i=0, C=1, L = (i < 4 -1) ? 1 : 0, H = (i > 4 -1) ? 1 : 0; i<=2*(4 -1); i++, C += L ? +1 : -1, L = (i < 4 -1) ? 1 : 0, H = (i > 4 -1) ? 1 : 0 ) for (j=0; j<C; j++) {
        s = hexsum(c,i,j);
        sum += s;
        sqsum += s*s;
    }
    fitness_t mean = (fitness_t)sum / (2*(((4 -1)*((4 -1)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 4),
              meansq = (fitness_t)sqsum / (2*(((4 -1)*((4 -1)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 4);
    e->mean = mean;
    e->var = meansq - mean*mean;
    e->fitness = mean - sqrt(e->var * (4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1)));
}


inline void exhaustive_opt(chromo c) {
    idx_t i,j,C, tmp, g1,g2, *share;
    char L,H, s, m,n;
    int hsum[2*(4 -1)+1][4], p,q;
    int sqsum = 0, sum = 0, d, newsum, newsqsum;
    for (i=0, C=1, L = (i < 4 -1) ? 1 : 0, H = (i > 4 -1) ? 1 : 0; i<=2*(4 -1); i++, C += L ? +1 : -1, L = (i < 4 -1) ? 1 : 0, H = (i > 4 -1) ? 1 : 0 ) for (j=0; j<C; j++) {
        d = hexsum(c,i,j);
        hsum[i][j] = d;
        sum += d;
        sqsum += d*d;
    }
    inline fitness_t fitness(int sum, int sqsum) {
        fitness_t mean = (fitness_t)sum / (2*(((4 -1)*((4 -1)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 4);
        return mean - sqrt((fitness_t)sqsum / (2*(((4 -1)*((4 -1)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 4) - mean*mean * (4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1)));
    }
    fitness_t orig = fitness(sum, sqsum), new;
    inline int sum_of_shares(idx_t g) {
        int h = 0;
        for (s=0; s<numshares[g]; s++)
            share = shares[g][s], h += hsum[share[0]][share[1]];
        return h;
    }
the_beginning:
    for (g1=0; g1<(4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1)); g1++) {
        m = numshares[g1];
        p = sum_of_shares(g1);
        for (g2=g1+1; g2<(4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1)); g2++) {
            n = numshares[g2];
            q = sum_of_shares(g2);

            d = c[g2] - c[g1];
            newsum = sum + d*(m-n);
            newsqsum = sqsum + d*(2*(p-q) + d*(m+n));
            new = fitness(newsum, newsqsum);
            if (new > orig) {

                tmp = c[g1], c[g1] = c[g2], c[g2] = tmp;

                orig = new, sum = newsum, sqsum = newsum;



                for (s=0; s<m; s++) share = shares[g1][s], hsum[share[0]][share[1]] += +d;;
                for (s=0; s<n; s++) share = shares[g2][s], hsum[share[0]][share[1]] += -d;;

                goto the_beginning;
            }
        }
    }
}







void error(char *msg) {
    fprintf(stderr, "# " "error: %s\n", msg);
    exit(4);
}

void print_pop(FILE *out, int n) {
    evaluation *e = &eval[n];
    if (e->var == 0)
        fprintf(out, "found: ");
    fprintf(out, "sum=%8.4f var=%8.4f fitness=%8.4f\n",
            e->mean, e->var, e->fitness);
    fprintf(out, "-->8--\n");
    print_chromo(out, pop[n]);
    fprintf(out, "--8<--\n");
}

int best_pop() {
    int n, b = 0;
    fitness_t f = eval[b].fitness;
    for (n=1; n<20; n++)
        if (eval[n].fitness > f)
            b = n, f = eval[n].fitness;
    return b;
}





void ping(int x) {
    fprintf(stderr, "%d: ", generations);
    fprintf(stderr, "pop " "m=%7.3f v=%7.3f f=%7.3f", meansum / 20, varsum / 20, fsum / 20);;
    fprintf(stderr, "; ");
    int b = best_pop();
    fprintf(stderr, "best " "m=%7.3f v=%7.3f f=%7.3f", eval[b].mean, eval[b].var, fbest);
    fprintf(stderr, "\n");
}

void status(int x) {
    FILE *out = (x == 3) ? stderr : stdout;
    fprintf(out, "generation #%d: ", generations);
    fprintf(out, "pop " "m=%7.3f v=%7.3f f=%7.3f", meansum / 20, varsum / 20, fsum / 20);;
    fprintf(out, " best_age=%d\n", gbestage);

    int n, b = best_pop();
    fprintf(out, "best: ");
    print_pop(out, b);

    if (var0cnt > 0) {
        for (n=0; n<20; n++)
            if (eval[n].var == 0 && n != b)
                print_pop(out, n);
    }
    ;

}

void ga_info() {
    printf("GA: P=%d K=%d sp=%d xover_cuts=%d\n",
            20, (20 * 1 / 2), 3, 2);
}

struct timeval tbegin, tend;
void die(int x) {
    gettimeofday(&tend, ((void *)0));
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) >= 0) {



        printf("execution time:");
        printf(" real %fs", (float)(tend.tv_sec - tbegin.tv_sec) + (float)(tend.tv_usec - tbegin.tv_usec) * 1e-6);
        printf(" user "); printf("%fs", (float)usage.ru_utime.tv_sec + (float)usage.ru_utime.tv_usec * 1e-6);
        printf(" sys "); printf("%fs", (float)usage.ru_stime.tv_sec + (float)usage.ru_stime.tv_usec * 1e-6);
        printf("\n");
    }
    ping(x);
    ga_info();
    status(x);
    exit(x);
}

void xover(chromo p1, chromo p2, chromo o) {

    idx_t i = 0, j, c = 2, d = (4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1)) / 2;
    chromo p = p1;
    while (c > 0) {
        for (j=i, i+= ((unsigned int)((double)(d) * (((((double)rand())/((double)2147483647 + 1.0)) + (((double)rand())/((double)2147483647 + 1.0))) / 2.0))); j<=i; j++)
            o[j] = p[j];
        c--;
        i++;
        p = (p == p1) ? p2 : p1;
    }
    for (; i<(4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1)); i++)
        o[i] = p[i];
}

void mutate(chromo c) {

    int m, mut = (((((unsigned int)((double)(2) * (((((double)rand())/((double)2147483647 + 1.0)) + (((double)rand())/((double)2147483647 + 1.0))) / 2.0)))) < ((4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1)) / 2)) ? (((unsigned int)((double)(2) * (((((double)rand())/((double)2147483647 + 1.0)) + (((double)rand())/((double)2147483647 + 1.0))) / 2.0)))) : ((4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1)) / 2));
    for (m=0; m<mut; m++) {
        idx_t i = ((unsigned int)((double)((4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1))) * (((((double)rand())/((double)2147483647 + 1.0)) + (((double)rand())/((double)2147483647 + 1.0))) / 2.0)));
        idx_t j = (i + ((unsigned int)((double)((4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1))) * (((((double)rand())/((double)2147483647 + 1.0)) + (((double)rand())/((double)2147483647 + 1.0))) / 2.0)))) % (4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1));
        idx_t tmp = c[i];
        c[i] = c[j];
        c[j] = tmp;
    }

    mut = ((unsigned int)((double)(2) * (((((double)rand())/((double)2147483647 + 1.0)) + (((double)rand())/((double)2147483647 + 1.0))) / 2.0)));
    idx_t tmp[6];
    for (m=0; m<mut; m++) {
        idx_t i = ((unsigned int)((double)(2*(4 -1)+1) * (((((double)rand())/((double)2147483647 + 1.0)) + (((double)rand())/((double)2147483647 + 1.0))) / 2.0))),
              j = ((unsigned int)((double)(4 - abs(4 -1 - i)) * (((((double)rand())/((double)2147483647 + 1.0)) + (((double)rand())/((double)2147483647 + 1.0))) / 2.0))),
              *ij = idx[i][j],
              k, d = ((unsigned int)((double)(5) * (((((double)rand())/((double)2147483647 + 1.0)) + (((double)rand())/((double)2147483647 + 1.0))) / 2.0))) + 1;
        for (k=0; k<6; k++)
            tmp[(k+d)%6] = c[ij[k]];
        for (k=0; k<6; k++)
            c[ij[k]] = tmp[k];
    }
}

void repair(chromo c) {
    idx_t used[(4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1))] = {0}, dupl[(4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1))] = {0},
          dups = 0, i,j,k;
    short d = ((unsigned int)((double)((4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1))) * (((((double)rand())/((double)2147483647 + 1.0)) + (((double)rand())/((double)2147483647 + 1.0))) / 2.0)));

    for (i=0; i<(4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1)); i++) {
        k = (i + d) % (4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1));
        j = c[k] - 1;
        if (used[j] > 0) {
            dupl[k] = 1;
            dups++;
        } else
            used[j]++;
    }

    for (i=0, k=0; i<(4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1)) && k<dups; i++)
        if (dupl[i]) {

            d = ((unsigned int)((double)(dups) * (((((double)rand())/((double)2147483647 + 1.0)) + (((double)rand())/((double)2147483647 + 1.0))) / 2.0)));
            while (d >= 0) {
                while (used[j])
                    j = (j + 1) % (4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1));
                d--;
            }
            c[i] = j + 1;
            used[j] = 1;
            k++;
        }
    return;
}

inline void begin_generation() {
    int n;
    ffsum = 0;
    for (n=0; n<20; n++)
        ff[n] = ((eval[n].fitness - fworst) + (fbest - fworst) / (3 - 1)),
        ffsum += ff[n];
}

inline int pick() {
    fitness_t s = 0, pt = ((double)(ffsum) * (((((double)rand())/((double)2147483647 + 1.0)) + (((double)rand())/((double)2147483647 + 1.0))) / 2.0));;
    int i;
    for (i=0; i<20; i++) {
        s += ff[i];
        if (s > pt)
            return i;
    }
    return ((unsigned int)((double)(20) * (((((double)rand())/((double)2147483647 + 1.0)) + (((double)rand())/((double)2147483647 + 1.0))) / 2.0)));
}

inline void generate_offspring(int n) {

    int p1, p2;
    p1 = pick();
    do {
        p2 = pick();
    } while (p1 == p2);
    parent1[n] = p1;
    parent2[n] = p2;

    chromo o = offspring[n];
    xover(pop[p1], pop[p2], o);
    repair(o);
    mutate(o);
    exhaustive_opt(o);
    evaluate(o, &offspring_eval[n]);
}

inline void generate_offsprings();

inline void update_evaluation(int n, evaluation *new) {
    evaluation *old = &eval[n];

    fitness_t fitness = new->fitness;
    fsum -= old->fitness, fsum += fitness;
    varsum -= old->var, varsum += new->var;
    meansum -= old->mean, meansum += new->mean;
    if (fbest < fitness) {
        fbest = fitness;
        fbestidx = n;
    }
    if (fworst > fitness)
        fworst = fitness;
    if (new->var == 0) {
        var0cnt++;
        if (var0cnt == 1 || eval[var0idx].fitness < fitness)
            var0idx = n;
        print_pop(stdout, n);
    }
    if (old->var == 0)
        var0cnt--;

    *old = *new;
}

inline void replace_population() {
    int n;
    for (n=0; n<(20 * 1 / 2); n++) {
        int p1 = parent1[n],
            p2 = parent2[n],
            p = (eval[p1].fitness > eval[p2].fitness) ? p2 : p1;
        memcpy(pop[p], offspring[n], (4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1)) * sizeof(gene));
        update_evaluation(p, &offspring_eval[n]);
    }
}

inline void end_generation() {
    generations++;
    gbestage = (gbest == fbest) ? gbestage + 1 : 1;
    gbest = fbest;
}

void ga() {
    while (! (var0cnt > 0 && (var0idx != fbestidx || gbestage > 25))) {
        begin_generation();
        generate_offsprings();
        replace_population();
        end_generation();
    }
}

inline void generate_offsprings() {
    int n;
    for (n=0; n<(20 * 1 / 2); n++)
        generate_offspring(n);
}





void initialize_population() {
    evaluation e;
    int n;
    var0cnt = 20;
    for (n=0; n<20; n++) {
        chromo c = malloc((4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1)) * sizeof(gene));
        idx_t i;
        for (i=0; i<(4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1)); i++)
            c[i] = 1+((unsigned int)((double)((4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1))) * (((((double)rand())/((double)2147483647 + 1.0)) + (((double)rand())/((double)2147483647 + 1.0))) / 2.0)));
        repair(c);
        mutate(c);
        pop[n] = c;
        evaluate(c, &e);
        update_evaluation(n, &e);
    }
}

int main(int argc, char *argv[]) {
    srand((int)argv);
    gettimeofday(&tbegin, ((void *)0));

    alarm(1800);
    signal(14, die);
    signal(1, die);
    signal(15, die);
    signal(2, ping);
    signal(3, status);

    initialize_encoding();
    int n;
    for (n=0; n<(20 * 1 / 2); n++)
        offspring[n] = malloc((4*(((4)*((4)+1)/2) - ((1 -1)*((1 -1)+1)/2)) + 2*(4 -1 +1)) * sizeof(gene));
    initialize_population();
    ;

    fprintf(stderr, "# " "starting GA\n");
    ping(0);
    ga();
    die(0);
    return -1;
}
