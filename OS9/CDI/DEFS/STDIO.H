/* type lengths regardless of compiler in use:
    "char" for 8 bits
    "WORD" for 16 bits
    "long" for 32 bits */

typedef short WORD;     /* always 16 bits */

/*#ifdef OSK*/
#   define BUFSIZ 512
#   define _NFILE 32
/*
#else
#   ifdef OS9
#       define BUFSIZ 256
#       define _NFILE 16
#   endif
#endif
*/

typedef struct _iobuf {
    char *_ptr,		/* buffer pointer */
         *_base,	/* buffer base address */
         *_end;		/* buffer end address */
    WORD _flag;		/* file status */
    WORD _fd;		/* file path number */
    char _save;		/* for 'ungetc' when unbuffered */
    WORD _bufsiz;	/* size of data buffer */
	int (*_ifunc)();/* function to use for input */
	int (*_ofunc)();/* function to use for output */
} FILE;

extern FILE _iob[_NFILE];

/*	the following are fake pointer variable defintions  */
#define stdin	(&_iob[0])
#define stdout	(&_iob[1])
#define stderr	(&_iob[2])

#define _READ		1
#define _WRITE		2
#define _UNBUF		4
#define _BIGBUF		8
#define _EOF		0x10
#define _ERR		0x20
#define _SCF		0x40
#define _RBF		0x80
#define _DEVMASK	0xc0
#define _WRITTEN	0x0100		/*	buffer written in update mode  */
#define _MYBUF		0x0200		/*	system allocated buffer  */
#define _INIT		0x8000		/*	_iob initialized  */

#define EOF (-1)
#define EOL 13
#define NULL 0

#ifdef OSK
#define PMODE READ|WRITE    /* r/w for owner */
#else
#define PMODE  0xb          /* r/w for owner, r for others */
#endif

#define fgetc           getc
#define putchar(c)      putc(c,stdout)
#define getchar()       getc(stdin)
#define ferror(p)       ((p)->_flag&_ERR)
#define feof(p)         ((p)->_flag&_EOF)
#define clearerr(p)     ((p)->_flag&=~_ERR)
#define cleareof(p)     ((p)->_flag&=~_EOF)
#define fileno(p)       ((p)->_fd)

extern FILE *fopen(), *fdopen(), *freopen();
extern char *fgets(), *gets();
extern long ftell();
