/* Copyright 1988 by Microware Systems Corporation */

/* cdfm.h - Compact Disc File Manager Structure Definitions 
 History:
 Date     Ed  Comment                                                  Who
 -------------------------------------------------------------------------
 		  00  created                                                  rg
 88/06/27 01  converted PCB to use array of pointers to PCL's          tah
*/

#ifndef _cdfm_h
#define _cdfm_h

/* Status Block Format */
typedef struct _stat_blk {
	short	asy_stat;	/* Current status of the operation */
	short	asy_sig;	/* Signal to be sent on termination */
} STAT_BLK;


/* play error buffer */
typedef struct {
	int		Err_BufSiz;		/* Size of error buffer */
	char	Err_Res,		/* Resolution of error information */
			Err_Rsv1;		/* reserved */
	short	Err_Cnt,		/* Number of blocks containing errors */
			Err_Offset;		/* Offset of first error data block */
	char	Err_Sys[8],		/* Reserved for system use */
			Err_App[8];		/* Reserved for application use */
	int		Err_Blocks;		/* Block error map */
} PL_ERR;

/* play control list */
typedef struct __pcl {
	char	PCL_Ctrl,		/* Control byte */
			PCL_Rsv1,		/* reserved */
			PCL_Smode,		/* Submode byte */
			PCL_Type;		/* Coding information byte */
	short 	PCL_Sig;		/* Signal to be sent on buffer full */
	struct __pcl *PCL_Nxt;		/* Pointer to next PCL */
	char   *PCL_Buf;		/* Pointer to buffer */
	int		PCL_BufSz;		/* Size of buffer */
	PL_ERR *PCL_Err;		/* Pointer to error buffer */
	short	PCL_Rsv2;		/* reserved */
	int		PCL_Cnt;		/* Current offset in buffer */
} PCL;

/* play control block */
typedef struct {
	short  	PCB_Stat, 		/* Current status of the play */
		   	PCB_Sig;		/* Signal to be sent on termination */
	int 	PCB_Rec,		/* Maximum number of records to play */
			PCB_Chan;		/* Channel selection mask */
	short	PCB_AChan;		/* Audio to memory selection mask */
	PCL	   **PCB_Video,		/* pointer to array of PCL pointers for video sectors */
		   **PCB_Audio,		/* pointer to array of PCL pointers for audio sectors */
		   **PCB_Data;		/* pointer to array of PCL pointers for data sectors */
} PCB;


/* defines for PCB_Stat bits */
#define SBM_ER	0x8000	/* error has occured */
#define SBM_EOR	0x0001	/* end of record */
#define SBM_VD	0x0002	/* video sector last read */
#define SBM_AD	0x0004	/* audio sector last read */
#define SBM_DT	0x0008	/* data sector last read */
#define SBM_TRG 0x0010	/* trigger bit */
#define SBM_FRM 0x0020  /* form 2 bit */
#define SBM_RT	0x0040	/* real-time file bit */
#define SBM_EOF	0x0080	/* end of file */
#define SBM_DN	0x0100	/* play is done */


/* audio.h - audio data types */

#define D_AMONO 0x00
#define D_ASTRO 0x01
#define D_BMONO 0x02
#define D_BSTRO 0x03
#define D_CMONO 0x04
#define D_CSTRO 0x05
#define D_EMPH  0x08

/* channel selector codes for stereo mixing */
#define MIX_L1L2 0x00
#define MIX_L1R2 0x01
#define MIX_R1L2 0x02
#define MIX_R1R2 0x03

typedef struct _SoundmapDesc {
	short 	smd_id,					/* id of soundmap */
			smd_stloop,				/* start soundgroup for looping */
			smd_enloop,				/* end soundgroup for looping */
			smd_lpcnt,				/* actual loop count */
			smd_lcntr;				/* counter for looping */
	int		smd_smaddr,				/* address to soundmap */
			smd_smsize,				/* size of soundmap */
			smd_curaddr,			/* current address of playing soundmap */
			smd_asyblk;				/* pointer to ASY block */
	short	smd_nogrps,				/* number of sound groups in sm */
			smd_grpnum;				/* group which started sector's play */
	char 	smd_coding,				/* coding information for sm */
			smd_res1;				/* reserved */
	long	smd_lpaddr,				/* start address of loop */
			smd_res2,				/* reserved */
			smd_res3,
			smd_res4;
} SoundmapDesc;

SoundmapDesc *sm_info();

/* structure for soundmap status */
typedef struct _AudioStatus {
	short 	sms_sctnum,				/* current playing sector */
			sms_totsec,				/* total number of sectors */
			sms_lpcnt,				/* current loop count */
			sms_res;				/* reserved bytes */
} AudioStatus;


#endif _cdfm_h

