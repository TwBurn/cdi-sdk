/* Copyright 1988 by Microware Systems Corporation */

/* ucm.h - User Communications File Manager Definitions */

#ifndef _ucm_h
#define _ucm_h

/*****************************************************************************
*
* Drawmap Defintions
*
*/

/* drawmap descriptor */
typedef struct drawmapdesc {
	short	dm_dnum;		/* Drawmap number */
	unsigned short	dm_dtype;		/* Data type and flags */
	char	*dm_map1;		/* Pointer to drawmap memory */
	int		*dm_lnatbl1,	/* Pointer to line address table */
			dm_mapsz1;		/* Absolute size of drawmap in bytes */
	short	dm_plane,		/* Plane number */
			dm_pxlsz;		/* Number of bits/pixel for drawmap */
	short	dm_pmapw,		/* Physical width of drawmap in pixels */
			dm_pmaph,		/* Physical height of drawmap in pixels */
			dm_xorg,		/* Origin offset in X direction (logical) */
			dm_yorg;		/* Origin offset in Y direction (logical) */
	short	dm_cminx,		/* Minimum X of default clipping rectangle */
			dm_cmaxx,		/* Maximum X of default clipping rectangle */
			dm_cminy,		/* Minimum Y of default clipping rectangle */
			dm_cmaxy,		/* Maximum Y of default clipping rectangle */
			dm_penw,		/* Pen width in pixels-1 */
			dm_penh;		/* Pen heigth in pixels-1 */
	int		dm_psstr;		/* Pen style bit string */
	short	dm_pscnt;		/* Pen style pixel repeat count */
	unsigned short	dm_tcol1;		/* Transparency color */
	char	*dm_patt;		/* Pointer to true pattern block */
	short	dm_pmode,		/* Pattern mode */
			dm_poffx,		/* X offset to pattern hit point */
			dm_poffy;		/* Y offset to pattern hit point */
	unsigned short	dm_crtbl[16];	/* Color register table */
	short	dm_mpmthd;		/* Mapping method for non-standard text */
	short	dm_afbeg0,		/* Beginning glyph value for 1st active font */
			dm_afend0;		/* Ending glyph value for 1st active font */
	char	*dm_afdata0;	/* Pointer to beginning of 1st active font data */
	short	dm_afbeg1,		/* Beginning glyph value for 2nd active font */
			dm_afend1;		/* Ending glyph value for 2nd active font */
	char	*dm_afdata1; 	/* Pointer to beginning of 2nd active font data */
	short	dm_afbeg2,		/* Beginning glyph value for 3rd active font */
			dm_afend2;		/* Ending glyph value for 3rd active font */
	char	*dm_afdata2; 	/* Pointer to beginning of 3rd active font data */
	short	dm_afbeg3,		/* Beginning glyph value for 4th active font */
			dm_afend3;		/* Ending glyph value for 4th active font */
	char	*dm_afdata3; 	/* Pointer to beginning of 4th active font data */
	short	dm_rgnid;		/* Region identifier of current clipping region */
	char	*dm_map2;		/* Pointer to 2nd drawmap memory for RBG mode */
	int		*dm_lnatbl2,	/* Pointer to 2nd line address table for RGB mode */
			dm_mapsz2;		/* Absolute size of gb drawmap in bytes */
	unsigned short	dm_tcol2;		/* Transparency color gb value */
	char	dm_rsrvd[116];	/* Reserved space */
} DrawmapDesc;

DrawmapDesc *dm_create(),*viq_dminfo(),*dm_dupe();

/* video data type definitions */
#define D_TYPE		0x000F	/* Drawmap type isolation mask */
#define D_OFF		0		/* Disable plane */
#define D_CLUT4		3		/* CLUT4 mode */
#define D_CLUT7		4		/* CLUT7 mode */
#define D_CLUT8 	5		/* CLUT8 mode */
#define D_RL3		6		/* Run-length 3 mode */
#define D_RL7		7		/* Run-length 7 mode */
#define D_DYUV		8		/* Delta-YUV mode */
#define D_RGB		9		/* RGB555 mode */
#define D_QHY		11		/* DYUV+QHY mode */
#define RES_MASK 0x0030		/* mask for resolution bits */
#define RES_HIGH 0x0030		/* high resolution mode */
#define RES_DOUBLE 0x0010 	/* double resolution mode */
#define RES_NORMAL 0x0000	/* normal resolution mode */
#define LN_SEPARATE 0x8000	/* odd/even lines separated */

/*****************************************************************************
*
* Drawing Opcode Definitions
*
*/
#define OP_CLPOFF 0x0000		/* Clipping off */
#define OP_CLPON 0x8000			/* Clipping on */

#define OP_FMOUT 0x0000			/* Outlined */
#define OP_FMFIL 0x4000			/* Filled */

#define OP_PMSLD 0x0000			/* Solid Color */
#define OP_PMPAT 0x2000			/* Pattern On */

#define OP_DSSLD 0x0000			/* Solid Style */
#define OP_DSDSH 0x1000			/* Dashed Style */

#define OP_DTVIS 0x0000			/* Visable, i.e. Not Transparent */
#define OP_DTTRA 0x0800			/* Transparent */

#define OP_TMVIS 0x0000			/* Visable, i.e. Not Transparent */
#define OP_TMTRA 0x0200			/* Transparent */

#define OP_CR0	0x0000			/* Color Register Zero */
#define OP_CR1	0x0020			/* Color Register One */
#define OP_CR2	0x0040			/* Color Register Two */
#define OP_CR3	0x0060			/* Color Register Three */
#define OP_CR4	0x0080			/* Color Register Four */
#define OP_CR5	0x00A0			/* Color Register Five */
#define OP_CR6	0x00C0			/* Color Register Six */
#define OP_CR7	0x00E0			/* Color Register Seven */
#define OP_CR8	0x0100			/* Color Register Eight */
#define OP_CR9	0x0120			/* Color Register Nine */
#define OP_CR10	0x0140			/* Color Register Ten */
#define OP_CR11 0x0160			/* Color Register Eleven */
#define OP_CR12 0x0180			/* Color Register Twelve */
#define OP_CR13 0x01A0			/* Color Register Thirteen */
#define OP_CR14 0x01C0			/* Color Register Fourteen */
#define OP_CR15 0x01E0			/* Color Register Fifteen */

#define OP_ZERO 0x0000			/* Write Zeros */
#define OP_SAD 0x0001			/* Source And Destination */
#define OP_SAND 0x0002			/* Source And Not Destination */
#define OP_RPLC 0x0003			/* Replace */
#define OP_NSAD 0x0004			/* Not Source And Destination */
#define OP_NMOD 0x0005			/* Do Not Modify */
#define OP_SXD 0x0006			/* Source Xor Destination */
#define OP_SOD 0x0007			/* Source Or Destination */
#define OP_N_SOD 0x0008			/* Not (Source Or Destination) */
#define OP_N_SXD 0x0009			/* Not (Source Xor Destination) */
#define OP_ND 0x000A			/* Not Destination */
#define OP_SOND 0x000B			/* Source Or Not Destination */
#define OP_NS 0x000C			/* Not Source */
#define OP_NSOD 0x000D			/* Not Source Or Destination */
#define OP_N_SAD 0x000E			/* Not (Source And Destination) */
#define OP_ONES 0x000F			/* Write Ones */
#define OP_SPD 0x0010			/* Source Plus Destination */
#define OP_SMD 0x0011			/* Source Minus Destination */
#define OP_DMS 0x0012			/* Destination Minus Source */

/*****************************************************************************
*
* Font Definitions
*
*/
#define FNT_1BIT 	0		/* 1-bit/pixel font */
#define FNT_2BIT 	1		/* 2-bits/pixel font */
#define FNT_4BIT 	2		/* 4-bits/pixel font */
#define FNT_CLUT4 	3		/* CLUT4 font */
#define FNT_CLUT7 	4		/* CLUT7 font */
#define FNT_CLUT8 	5		/* CLUT8 font */
#define FNT_RGB 	9		/* RGB font */

#define FNT_PROP 	0x8000	/* Proportionally-spaced font */
#define FNT_MONO	0		/* Mono-spaced font */

/* Font data header definition. */
/* note: the offset variables are offsets from the beginning of the font */
/* header and NOT from the module header. */
typedef struct FontData  {
	unsigned short fnt_type,		/* Font type and flags */
		fnt_width,					/* Maximum Glyph cell width */
		fnt_height,					/* Glyph cell height (ascent+descnt) */
		fnt_ascent,					/* Ascent of character cell above baseline */
		fnt_descent,				/* Descent of character cell below baseline */
		fnt_pxlsz,					/* Pixel size in bits */
		fnt_frstch,					/* First character value of font */
		fnt_lastch;					/* Last character value of font */
	unsigned int fnt_lnlen,			/* Line length of font bitmap in bytes */
		fnt_offstbl,				/* Offset to glyph offset table */
		fnt_datatbl,				/* Offset to glyph data table */
		fnt_map1off,				/* Offset to first bitmap */
		fnt_map2off;				/* Offset to second bitmap (RGB only) */
}FONTDATA;								

/* Definitions for character code mapping methods */
#define CMM_8BIT	0
#define CMM_7_15BIT 1
#define CMM_16BIT	2

/*****************************************************************************
*
* Pattern Definitions
*
*/
#define PTN_1BIT 	0
#define PTN_2BIT 	1
#define PTN_4BIT 	2
#define PTN_CLUT4 	3
#define PTN_CLUT7 	4
#define PTN_CLUT8 	5
#define PTN_RGB 	9

/*****************************************************************************
*
* Region Definitions
*
*/
typedef struct _rgdesc {
	short rg_id;	/* region id */
	char  rg_type,	/* region type flag (-1=Null region) */
		  rg_reserve[3]; /* reserved */
	short rg_size,	/* region definition size */
		  rg_lftx,	/* Left X of boundry rectangle */
		  rg_rgtx,	/* Right X of boundry rectangle */
		  rg_topy,	/* Top Y of boundry rectangle */
		  rg_boty,	/* Bottom Y of boundry rectangle */
		  rg_offs;	/* Offset to transition data for 1st line */
} RegionDesc;

RegionDesc *viq_rinfo();

/* shape definitions */
#define D_NULL -1
#define D_RECT 0
#define D_ERECT 1
#define D_POLY 2
#define D_CIRC 3
#define D_CWDG 4
#define D_ELPS 5
#define D_EWDG 6
#define D_RGN  7
#define D_BFIL 8
#define D_FFIL 9 
#define D_CMPLX 10

/*****************************************************************************
*
* Special Effects Definitions
*
*/

/* Definitions for arguments to cp_dprm command */
#define RMS_NORMAL		0x00			/* normal */
#define RMS_RL			0x02			/* run-length */
#define RMS_MOSAIC		0x03			/* mosaic */
#define PRF_X2			0x00			/* pixel repeat factor = 2 */
#define PRF_X4			0x01			/* pixel repeat factor = 4 */
#define PRF_X8			0x02			/* pixel repeat factor = 8 */
#define PRF_X16			0x03			/* pixel repeat factor = 16 */
#define BP_NORMAL		0x00			/* 8 bits/pixel, normal resolution */
#define BP_DOUBLE		0x01			/* 4 bits/pixel, double or high res */
#define BP_HIGH			0x02			/* 8 bits/pixel, high resolution */

/* Definitions for arguments to cp_icm (select image coding method) command */
#define ICM_OFF			0x00			/* Disable plane */
#define ICM_RGB			0x01			/* RGB555 mode */
#define ICM_CLUT8 		0x01			/* CLUT8 mode */
#define ICM_CLUT7		0x03			/* CLUT7 mode */
#define ICM_CLUT77		0x04			/* CLUT7 or 7 mode */
#define ICM_DYUV		0x05			/* Delta-YUV mode */
#define ICM_CLUT4		0x0b			/* CLUT4 mode */
#define CS_A			0x00			/* use plane A clut for 7 or 7 mode */
#define CS_B			0x01			/* use plane A clut for 7 or 7 mode */
#define NM_1			0x00			/* number of mattes = 1 */
#define NM_2			0x01			/* number of mattes = 2 */
#define EV_OFF			0x00			/* external video off */
#define EV_ON			0x01			/* external video on */

/* Definitions for arguments to cp_tci (load transparency control information)
   command. */
#define MIX_ON			0x00			/* mixing enabled */
#define MIX_OFF			0x01			/* mixing disabled */
#define TR_ON			0x00			/* the plane is all transparent */
#define TR_CKEY_T		0x01			/* color key = true */
#define TR_TBIT_1		0x02			/* transparent bit = 1 */
#define TR_MAT0_T		0x03			/* matte flag 0 = true */
#define TR_MAT1_T		0x04			/* matte flag 1 = true */
#define TR_M0CK_T		0x05			/* matte flag 0 or color key = true */
#define TR_M1CK_T		0x06			/* matte flag 1 or color key = true */
#define TR_OFF			0x08			/* the plane has no transparent area */
#define TR_CKEY_F		0x09			/* color key = false */
#define TR_TBIT_F		0x0a			/* transparent bit = 0 */
#define TR_MAT0_F		0x0b			/* matte flag 0 bit = false */
#define TR_MAT1_F		0x0c			/* matte flag 1 bit = false */
#define TR_M0CK_F		0x0d			/* matte flag 0 or color key = false */
#define TR_M1CK_F		0x0e			/* matte flag 1 or color key = false */

/* Definitions for arguments to cp_po (plane order) command */
#define	PR_AB			0x00			/* plane A in front of plane B */
#define	PR_BA			0x01			/* plane B in front of plane A */

/* Definitions for arguments to cp_matte (load matte register) command */
#define MF_MF0			0x00			/* matte flag to be changed = 0 */
#define MF_MF1			0x01			/* matte flag to be changed = 1 */
#define MO_END			0x00			/* disregard cmds in higher registers */
#define MO_ICF_A		0x04			/* change ICF for plane A */
#define MO_ICF_B		0x06			/* change ICF for plane B */
#define MO_RES			0x08			/* reset matte flag to false */
#define MO_SET			0x09			/* set matte flag to true */
#define MO_RES_ICFA		0x0c			/* reset matte flag and change ICF A */
#define MO_SET_ICFA		0x0d			/* set matte flag and change ICF A */
#define MO_RES_ICFB		0x0e			/* reset matte flag and change ICF B */
#define MO_SET_ICFB		0x0f			/* set matte flag and change ICF B */

/* Definitions for arguments to cp_bkcol (backdrop color) command */
#define BK_HIGH			0x01			/* high intensity */
#define BK_LOW			0x00			/* low intensity */
#define BK_BLACK		0x00			/* backdrop color is black */
#define BK_BLUE			0x01			/* backdrop color is blue */
#define BK_GREEN		0x02			/* backdrop color is green */
#define BK_CYAN			0x03			/* backdrop color is cyan */
#define BK_RED			0x04			/* backdrop color is red */
#define BK_MAGENTA		0x05			/* backdrop color is magenta */
#define BK_YELLOW		0x06			/* backdrop color is yellow */
#define BK_WHITE		0x07			/* backdrop color is white */

/* Definitions for arguments to cp_phld (load mosaic pixel-hold factor)
   command */
#define PH_OFF			0x00			/* pixel hold enable off */
#define PH_ON			0x01			/* pixel hold enable on */

/* Definitions for arguments to cp_icf (load image contribution factor) 
   command */
#define ICF_MIN			0x00			/* minimum icf */
#define ICF_MAX			0x3f			/* maximum icf */

/* Miscellaneous Definitions */
#define PA				0x00			/* plane A (0) */
#define PB				0x01			/* plane B (1) */
#define DPA				0x00			/* drawmap plane A */
#define DPB				0x01			/* drawmap plane B (only RGB555) */

/* Definitions for DCP Op Codes */
#define _OP_ICM		0xc0001010			/* image coding method */
#define _OP_TCI		0xc1000000			/* transparency coding information */
#define _OP_PO 		0xc2000000			/* plane order */
#define _OP_TCOL_0	0xc4000000			/* transparency color - plane 0 */
#define _OP_TCOL_1	0xc6000000			/* transparency color - plane 1 */
#define _OP_MCOL_0	0xc7000000			/* mask color - plane 0 */
#define _OP_MCOL_1	0xc9000000			/* mask color - plane 1 */
#define _OP_YUV_0	0xca000000			/* YUV start value - plane 0 */
#define _OP_YUV_1	0xcb000000			/* YUV start value - plane 1 */
#define _OP_BKCOL	0xd8000000			/* backdrop color */
#define _OP_MPH_0	0xd9000000			/* mosaic pixel hold - plane 0 */
#define _OP_MPH_1	0xda000000			/* mosaic pixel hold - plane 1 */
#define _OP_ICF_0	0xdb000000			/* image contribution - plane 0 */
#define _OP_ICF_1	0xdc000000			/* image contribution - plane 1 */
#define _OP_END		0x00000000			/* end of control sequence */
#define _OP_NOP		0x10000000			/* No operation */
#define _OP_DADR	0x40000000			/* set display address */
#define _OP_SIG		0x60000000			/* signal when scan hits this line */
#define _OP_DPRM	0x78000400			/* load display parameters */
#define _OP_CLUT	0x80000000			/* load CLUT color */
#define _OP_CBNK	0xc3000000			/* set CLUT bank */
#define _OP_MATTE	0xd0000000			/* load matte register */

/* The following low-level functions are implemented as macro's */
#define cp_nop() \
		(_OP_NOP)
#define cp_icm(cm0,cm1,nm,ev,cs) \
		(_OP_ICM + (((cs)&0x01)<<22) | (((nm)&0x01)<<19) | (((ev)&0x01)<<18) | \
		(((cm1)&0x0f)<<8) | ((cm0)&0x0f))
#define cp_dadr(address) \
		(_OP_DADR | ((address) & 0x00ffffff))
#define cp_sig() \
		(_OP_SIG)
#define cp_dprm(rms,prf,bp) \
		(_OP_DPRM | ((rms) & 0x03) | (((prf) & 0x03)<<2) | \
		(((bp) & 0x03)<<8))
#define cp_clut(clut,r,g,b) \
		(_OP_CLUT + (((clut)&0x3f)<<24) | (((r)&0xff)<<16) | \
		(((g)&0xff)<<8) | ((b)&0xff))
#define cp_tci(mix,ta,tb) \
		(_OP_TCI | (((mix)&1)<<23) | ((ta)&0x0f) | (((tb)&0x0f)<<8))
#define cp_po(order) \
		(_OP_PO | ((order)&0x07))
#define cp_cbnk(bank) \
		(_OP_CBNK | ((bank) & 0x03))
#define cp_tcol(plane,r,g,b) \
		(((plane)==PA ? _OP_TCOL_0 : _OP_TCOL_1) | (((r)&0xff)<<16) | \
		(((g)&0xff)<<8) | ((b)&0xff))
#define cp_mcol(plane,r,g,b) \
		(((plane)==PA ? _OP_MCOL_0 : _OP_MCOL_1) | (((r)&0xff)<<16) | \
		(((g)&0xff)<<8) | ((b)&0xff))
#define cp_yuv(plane,y,u,v) \
		(((plane)==PA ? _OP_YUV_0 : _OP_YUV_1) | (((y)&0xff)<<16) | \
		(((u)&0xff)<<8) | ((v)&0xff))
#define cp_matte(reg,op,mf,icf,x) \
		(_OP_MATTE | (((reg)&0x07)<<24) | (((op)&0x0f)<<20) | \
		(((mf)&1)<<16) | (((icf)&0x3f)<<10) | ((x)&0x03ff))
#define cp_bkcol(intensity,color) \
		(_OP_BKCOL | ((intensity&0x01)<<3) | ((color)&0x07))
#define cp_phld(plane,en,factor) \
		(((plane)==PA ? _OP_MPH_0 : _OP_MPH_1) | (((en)&0x01)<<23) | \
		((factor)&0xff))
#define cp_icf(plane,icf) \
		(((plane)==PA ? _OP_ICF_0: _OP_ICF_1) | ((icf)&0x3f))



/*****************************************************************************
*
* Error Defintions
*
*/
#define E_UCM_BASE ((6<<8)+0)			/* base error code 006:000 for UCM */
#define	E_ILLPRM	(E_UCM_BASE+0)		/* illegal parameter */
#define	E_IDFULL	(E_UCM_BASE+1)		/* identifier table full */
#define	E_BADSIZ	(E_UCM_BASE+2)		/* bad size error */
#define	E_RGFULL	(E_UCM_BASE+3)		/* region definition full */
#define	E_UNID		(E_UCM_BASE+4)		/* unallocated identifier number */
#define	E_NULLRG	(E_UCM_BASE+5)		/* null region */
#define	E_BADMOD	(E_UCM_BASE+6)		/* bad drawmap / pattern mode */
#define	E_NOFONT	(E_UCM_BASE+7)		/* no active font */
#define	E_NODM		(E_UCM_BASE+8)		/* no drawmap */
#define	E_NOPLAY	(E_UCM_BASE+9)		/* no audio play in progress*/
#define	E_ABORT		(E_UCM_BASE+10)		/* asynchronous operation aborted */

#endif
