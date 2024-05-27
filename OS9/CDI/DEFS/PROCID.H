/* OS-K process descriptor definitions */
#ifndef VHPCNT
#include <module.h>
#endif

/* The pointer definitions herein are generally (unsigned char *) */

typedef struct pdsc {
	unsigned short
		_id,				/* process id */
		_pid,				/* parent's id */
		_sid,				/* sibling's id */
		_cid;				/* child's id */
	unsigned char
		*_sp,				/* system stack ptr */
		*_usp,				/* user stack ptr */
		*_pagcnt;			/* memory size */
	unsigned short
		_group,				/* group number */
		_user,				/* user number */
		_prior,				/* priority */
		_age,				/* age */
		_state,				/* status */
		_task;				/* process task number */
	unsigned char
		_queueid,			/* current queue id */
		_scall,				/* last user state system call executed */
		_baked,				/* non-zero if process created by fork */
		_resvd1;			/* (reserved for alignment) */
	unsigned short
		_deadlk,			/* dominant process id if I/O locked */
		_signal;			/* signal code */
	unsigned char
		*_sigvec,			/* signal intercept vector */
		*_sigdat;			/* signal intercept data address */
	struct pdsc
		*_queueN,			/* queue next ptr */
		*_queueP;			/* queue prev ptr */
	mod_exec
		*_pmodul;			/* primary module */
	unsigned char
		*_except[10],		/* program error exception vectors */
		*_exstk[10],		/* program error exception stack frame ptrs */
		*_traps[15],		/* user's trap vector table */
		*_trpmem[15];		/* user's trap static memory block ptrs */
	unsigned int
		_trpsiz[15];		/* trap handler static memory sizes */
	unsigned char
		*_excpsp,			/* system state except. recovery stack */
		*_excppc;			/* system state except. recovery program counter */
	char
		_dio[32];			/* default i/o data */
	unsigned short
 		_path[32];			/* i/o path table */
	unsigned char
		*_memimg[32];		/* allocated memory block ptrs */
	unsigned int
		_blksiz[32];		/* size of each allocated memory block */
	unsigned char
		*_dbgreg;			/* debugged process register stack frame */
	struct pdsc
		*_dbgpar;			/* debugged process parent pd */
	unsigned  int
		_dbgins,			/* debug instruction count */
		_uticks,			/* user state ticks elapsed */
		_sticks,			/* system state tick elapsed */
		_datbeg,			/* julian date when forked */
		_timbeg,			/* julian time when forked */
		_fcalls,			/* number of system calls exec */
		_icalls,			/* number of I/O calls execd */
		_rbytes,			/* number of bytes read */
		_wbytes;			/* number of bytes written */
	unsigned short
		_ioqp,				/* I/O queue prev ptr */
		_ioqn;				/* I/O queue next ptr */
	unsigned char
		*_frag, *_fragg;	/* free memory fragment ptrs */
	unsigned int
		_sched;				/* process scheduling constant */
	unsigned char
		*_spuimg;			/* ptr to process SPU image */
	unsigned int
		_bkptcnt;			/* number of breakpoints set */
	unsigned short
		_bpvalue[16];		/* breakpoint save area */
	unsigned int
		_acct[8];			/* reserved for user accounting module */
	unsigned char
		*_data;				/* ptr to process primary data area */
	unsigned int
		_datasz;			/* size of primary data area */
	unsigned char
		*FPUsave;			/* ptr to 68881 save area */
	unsigned char
		*FPExcpt[7],		/* 68881 exception vectors */
		*FPExStk[7];		/* 68881 exception stack frame ptrs*/
	unsigned char
		_siglvl,			/* signal interrupt level */
		_sigflg;			/* signal flag */
	unsigned short
		_sigxs;				/* number of excess signal blocks allocated */
	unsigned int
		_sigmask,			/* mask to disable signals 2 - 31 */
		_sigcnt;			/* number of signals pending */
	unsigned char
		*_sigque,			/* ptr to head of signal queue */
		_defsig[16],		/* default initial signal queue element */
		*_thread[2],		/* doubly linked thread queue */
		*_cfrag[2];			/* new-style mem color lists */
	unsigned int
		_mown;				/* original owner of primary module (security) */
	unsigned char
		*_expstk;			/* reserved for more stack space */
	unsigned int
		resvd2;				/* reserved for more stack space (size) */
	unsigned char
		_procstk[1108];		/* system state stack for process */
} procid;

