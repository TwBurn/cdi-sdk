/************************************************************************
* ma.h - include file for MPEG audio software
************************************************************************/

typedef struct _mamapdesc {
	unsigned	short	MD_Id;		/*ID of the map*/
	unsigned	short	MD_Type;	/*type of this map*/
	unsigned	short	MD_Stream;	/*MPEG stream number*/
	unsigned	int	MD_StLoop;	/*startaddress of loop*/
	unsigned	int	MD_EnLoop;	/*endaddress of loop*/
	unsigned	short	MD_LpCnt;	/*loopcounter*/
	unsigned	short	MD_LCntr;	/*current value of loopcounter*/
	unsigned	char	MD_At_LL;	/*attenuator left to left*/
	unsigned	char	MD_At_LR;	/*attenuator left to right*/
	unsigned	char 	MD_At_RR;	/*attenuator right to right*/
	unsigned	char	MD_At_RL;	/*attenuator right to left*/
	unsigned	char	MD_res[10];	/*reserved*/
} MAmapDesc ;


typedef struct _audiostatus {
	unsigned	short	MAS_Stream;	/*actually decoded stream*/
	unsigned	int	MAS_Att;	/*actual attenuator status*/
	unsigned	int	MAS_Head;	/*audio frame header*/
	unsigned	int	MAS_CurAdr;	/*current pointer in audio map*/
			int	MAS_DSC;	/*decoder system clock value*/
	unsigned	char	MAS_res[14];	/*reserved*/
} MA_status;

extern	int	ma_abort();
extern	int	ma_close();
extern	int	ma_cntrl();
extern	int	ma_continue();
extern	int	ma_create();
extern	MAmapDesc	*ma_info();
extern	int	ma_loop();
extern	int	ma_pause();
extern	int	ma_cdplay();
extern	int	ma_hostplay();
extern	int	ma_release();
extern	int	ma_status();
extern	int	ma_trigger();
extern	int	ma_slink();
extern	int	ma_jump();
