/*
	System I/O static storage definitions
*/

#ifndef _types
#include <types.h>
#endif
#ifndef MODSYNC
#include <module.h>
#endif

/* System device table entry */
typedef struct devicetbl {
	struct modhcom 	*V_driv;		/* device driver module ptr */
	u_char			*V_stat;		/* device driver static storage base */
	mod_dev		 	*V_desc;		/* device descriptor module ptr */
	struct modhcom	*V_fmgr;		/* file manager module ptr */
	u_short			V_usrs;			/* use count */
} *Devicetbl;

/* The is required by the kernel in static storage of all devices */
typedef struct sysiost {
	u_char		*v_port;		/* device base port address */
	u_short		v_lprc;			/* last active process ID */
	u_short		v_busy;			/* current process ID (0=not busy) */
	u_short		v_wake;			/* active process ID for driver to wake */
	union pathdesc *v_paths;	/* list of open paths on device */
	u_int		v_dumm1[8];		/* reserved */
} sysioStatic;
#define _sysio	1

/* device driver entry offsets */

#define D_INIT	0			/* initialize */
#define D_READ	2			/* read */
#define D_WRIT	4			/* write */
#define D_GSTA	6			/* getstat */
#define D_PSTA	8			/* putstat */
#define D_TERM	10			/* terminate */
#define D_TRAP	12			/* trap */

/* file open mode and access permission values */
#define READ_	1
#define WRITE_	2
#define EXEC_	4
#define UPDAT_	(READ_|WRITE_)
#define PREAD_	8
#define PWRIT_	16
#define PEXEC_	32
#define PUPDAT_	(PREAD_|PWRIT_)
#define ISIZE_	32
#define SHARE_	64
#define DIR_	128

