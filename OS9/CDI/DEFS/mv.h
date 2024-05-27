/* file:  MV.H */

/* type definitions */

#define	PLAYHOST	0x0000
#define	PLAYCD		0x0001
#define	STILLHOST	0x0800
#define	STILLCD		0x0801


/* resolution definitions */

#define NORMALRES	0
#define DOUBLERES	1
#define HIGHRES		3

/* structures */

typedef struct _motionstatus {
	unsigned	short	MVS_LCntr;		/* loops remaining */
				char	*MVS_CurAdr;	/* address to retrieve data */
	unsigned	long	MVS_Speed;		/* display speed */
	unsigned	long	MVS_ImgSz;		/* image size of current stream */
	unsigned	long	MVS_TimeCd;		/* timecode of current picture */
	unsigned	short	MVS_TmpRef;		/* temporal reference */
	unsigned	short	MVS_Stream;		/* current stream number */
	unsigned	char	MVS_PicRt,		/* picture rate */
						MVS_Res1;		/* reserved */
	unsigned	long	MVS_DSC,		/* Video decoder system clock */
						MVS_Res2;		/* reserved */
} MotionStatus;

typedef struct _mvmapdesc {
	unsigned	short	MD_Id;			/* Id of the MVM */
	unsigned	short	MD_Type;		/* type of this map */
	unsigned	short	MD_Stream;		/* Current stream number */
	unsigned	long	MD_StLoop;		/* Start address of loop */
	unsigned	long	MD_EnLoop;		/* End address of loop */
	unsigned	short	MD_LpCnt;		/* Initial loopback count */
	unsigned	short	MD_LCntr;		/* Remaining loops */
	unsigned	long	MD_ImgSz;		/* Image size (W:H) */
	unsigned	long	MD_DecWin;		/* Window in the image (W:H) */
	unsigned	long	MD_DecOff;		/* Offset window to decode (H:V) */
	unsigned	long	MD_ScrOrg;		/* Origin offset window (H:V) */
	unsigned	long	MD_ScrOff;		/* Offset within screen (H:V) */
	unsigned	long	MD_BCol;		/* Border color */
	unsigned	long	MD_Speed;		/* Display speed */
	unsigned	long	MD_TimeCd;		/* timecode of current picture */
	unsigned	short	MD_TmpRef;		/* temporal reference */
	unsigned	char	MD_PicRt,		/* picture rate */
						MD_Res1[11];	/* reserved */
} MVmapDesc;

typedef struct _mv_table {
	unsigned short ep_type ;
	unsigned int   ep_size ;
	unsigned short ep_time1 ;
	unsigned short ep_time2 ;
	unsigned short ep_offset ;
	unsigned short ep_delay ;
} MV_TABLE ;

extern MVmapDesc *mv_info();
