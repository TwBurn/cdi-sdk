#ifndef _sysio
#include <sysio.h>
#endif

/*
	SBF drive table static storage.  One for each drive.
*/

typedef	struct	sbfdrv {
	u_short		sbf_dflg,		/* drive flag */
				sbf_nbuf;		/* number of buffers */
	u_long		sbf_ibh,		/* pointer to top of input buffer list */
				sbf_ibt,		/* pointer to end of input buffer list */
				sbf_obh,		/* pointer to top of output buffer list */
				sbf_obt,		/* pointer to end of output buffer list */
				sbf_wait,		/* pointer to waiting process */
				sbf_serr,		/* number of recoverable errors */
				sbf_herr,		/* number of non-recoverable errors */
				sbf_rsv3[8];	/* 8 unused long words */
} *Sbfdrv;

/*
	SBF static storage.  Required in every SBF driver.
*/
typedef struct sbfstatic {
	sysioStatic	sbf_sysio;		/* kernel static storage variables	*/
	u_short		sbf_rsv0;		/* reserved 						*/
	u_char		sbf_ndrv,		/* number of drives					*/
				sbf_rsv1;		/* reserved							*/
	u_short		sbf_flag;		/* driver flags						*/
	u_char		*sbf_drvr,		/* driver module pointer			*/
				*sbf_dprc,		/* driver process pointer			*/
				*sbf_iprc;		/* interrupt process pointer		*/
	u_char		sbf_rsv2[64];	/* reserved 						*/
#ifndef	SBF_MAXDRIVE
#define	SBF_MAXDRIVE	1
#endif
	struct sbfdrv	drv[SBF_MAXDRIVE];	/* SBF drive table(s) */
} sbfstatic, *Sbfstatic;

/*
	Sequential block file manager PD definitions
*/
struct sbf_opt {
	u_char		pd_dtp;			/* device type						*/
	u_char		pd_tdrv;		/* logical drive number				*/
	u_char		pd_sbf;			/* reserved 						*/
	u_char		pd_numblk;		/* maximum # of blocks to allocate	*/
	u_int		pd_blksiz;		/* size of blocks allocated			*/
	u_short		pd_prior;		/* driver process priority			*/
	u_short		pd_flags;		/* SBF/driver capability flags		*/
	u_short		pd_dmamode;		/* DMA type/usage					*/
	u_char		pd_scsiid;		/* SCSI controller ID				*/
	u_char		pd_scsilun;		/* SCSI controller drive LUN		*/
	u_int		pd_scsiopt;		/* SCSI options flags */
#ifndef		_SCSI_OPTS
#define		SCSI_ATN		(1<<0)	/* assert ATN supported */
#define		SCSI_TARGET		(1<<1)	/* target mode supported */
#define		SCSI_SYNCHR		(1<<2)	/* synchronous transfers supported */
#define		SCSI_PARITY		(1<<3)	/* enable SCSI parity */
#define		_SCSI_OPTS
#endif
};

/*
 * dummy structure to make path.h happy
 */
 
struct sbf_pvt {
	char		unused;
};

#define SBFMAN	1
#define sbfopt	path.fm_opt.sbf
