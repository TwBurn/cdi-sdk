/* Copyright 1988 by Microware Systems Corporation */

#ifndef _cdi_h
#define _cdi_h

/* ------------------------------------------------------------	+
|	"cdi.h" file												|
| edition history												|
| ###	date		comments								by	|
| ---	--------	---------------------------------------	---	|
| 001	86/10/15	created 								ebm	|
| 002   90/10/10    removed reference to Boot Record        ebm |
+ ------------------------------------------------------------ */

#ifndef _types
#include <types.h>
#endif

/* physical sector sync/header/subheader, followed by Form1/2 sector	*/
typedef struct {
	char  _h_sync[12],		/* header sync bytes */
		  _h_header[4],		/* header bytes */
		  _h_subhead[8];	/* subheader */
} _header;

/* byte positions for _h_header in HEADER */

#define	MINUTES	0			/* minutes for sector */
#define	SECONDS 1			/* seconds for sector */
#define SECTORS 2           /* sectors for sector */
#define MODE	3			/* mode of sector */

/* byte positions for _h_subhead in HEADER */
#define FILENUM 0
#define CHANNUM 1
#define SUBMODE 2
#define CODINFO	3

/* subheader/submode byte values - bit patterns	*/
#define	SUB_EOF	0x80	/* subheader EOF bit				*/
#define	SUB_RTS	0x40	/* realtime sector					*/
#define	SUB_FM2	0x20	/* bit on, then Form2, else Form1	*/
#define	SUB_TRG	0x10	/* trigger							*/
#define	SUB_DAT	0x08	/* data sector						*/
#define	SUB_AUD	0x04	/* audio sector						*/
#define	SUB_VID	0x02	/* video sector						*/
#define	SUB_EOR	0x01	/* EOR								*/

/* general Form1/2 sector data format	*/
typedef struct {		/* Form1 sector body */
	char	data[2048];	/* form1 data body	*/
	char	trail[280];	/* EDC/ECC fields	*/
} _form1;

typedef struct {			/* Form2 sector body				*/
	char	data[2324];
	char	trail[4];
} _form2;

/* Volume File Structure Decriptor Record sits on on Form1->data	*/
typedef struct {
	char	_vt_type,			/* Disk Label Record Type			*/
			_vt_vid[5],			/* Vol struct std ID "CD-I "		*/
			_vt_version,		/* Vol struct version #1			*/
			_vt_flags,			/* not yet defined, 0/1 ?			*/
			_vt_system[32],		/* "CD-RTOS..."						*/
			_vt_volume[32],		/* Vol Identifier, name of this CDI	*/
			_vt_rsv2[12];
	long	_vt_size;			/* Vol size in blocks			*/
	char	_vt_charset[32],	/* Coded Character Set Identifier	*/
			_vt_rsv3[2];
	short	_vt_nvol,			/* # of Volumes in album		*/
			_vt_rsv4,
			_vt_vseq,			/* album sequence #				*/
			_vt_rsv5,
			_vt_blksz;			/* logical block size, 2048		*/
	char	_vt_rsv6[4];
	long	_vt_pthtblsz;		/* Path table size, in bytes	*/
	char	_vt_rsv7[8];
	long	_vt_pathtbl;		/* block address of path table	*/
	char    _vt_res8[38];		
	char	_vt_album[128],		/* album identifier				*/
			_vt_publisher[128],	/* publisher idenfifier			*/
			_vt_preparer[128],	/* data preparer identifier		*/
			_vt_applicat[128],	/* application identifier		*/
			_vt_copyright[32],	/* copyright file name			*/
			_vt_res9[5],		
			_vt_abstract[32],	/* abstract file name			*/
			_vt_res10[5],
			_vt_biblio[32],		/* bibloigraphy file name		*/
			_vt_res11[5],
			_vt_credatim[16],	/* creation date/time, ASCII	*/
			_vt_res12,
			_vt_moddatim[16],	/* modificatio date/time, ASCII	*/
			_vt_res13,
			_vt_expdatim[16],	/* expiration date/time, ASCII	*/
			_vt_res14,
			_vt_effdatim[16],	/* effective date/time, ASCII	*/
			_vt_res15,
			_vt_filvrsn,		/* file structure version #, 1	*/
			_vt_rsv9[1166];		/* reserved/cleared to 0		*/
} _vtoc;

/* Terminator Record */
typedef struct {
	char 	_tr_type,			/* Disk Label Record Type, 255		*/
			_tr_vid[5],			/* vol struct std ID "CD-I "		*/
			_tr_version,		/* vol struct version #				*/
			_tr_rsv[2041];		/* reserved */
} _termrec;

/* now, general CDI physical format:	*/
typedef struct {
	_header	header;				/* every sector has sync/header/subheader */
	union {	_vtoc	 vtoc;		/* VTOC			*/
			_termrec termrec;	/* TERMINATOR RECORD */
			_form1	 form1;		/* Form1 sector	*/
			_form2	 form2;		/* Form2 sector	*/
	} datasect;
} _cdisec;

/* each entry on path table */
typedef struct {
	u_char 	_pt_namelen,		/* length of directory name */
			_pt_attrsz;			/* extended attr block size	*/
	long	_pt_dirblock;		/* location of directory */
	short	_pt_parentdir;		/* parent dir # on pathtbl	*/
	char	_pt_name[32];		/* note: VARIABLE length	*/
} _pathtbl;

/* FD											*/
/*	Green Book III.3	Disc Directory			*/
/*			   III.3.2	Directory Structure		*/
typedef struct {
    u_char _fd_rlen,			/* record length				*/
    	  _fd_ealen;		/* extended attr record length	*/
	long  _fd_rsv1,
		  _fd_fileaddr,		/* logical block #				*/
		  _fd_rsv2,
		  _fd_filesize;		/* file size in bytes			*/
	char  _fd_datetime[6], 	/* bin YYMMDDHHMMSS				*/
		  _fd_rsv3,
		  _fd_flags;		/* hidden						*/
	short _fd_ilvfact;		/* interleave factor A:B		*/
	short _fd_rsv4;
	short _fd_album;		/* album # of the file or 0		*/
	u_char _fd_namelen,		/* file name length				*/
		  _fd_name[1];		/* note: VARIABLE length		*/
} _fdhead; 					/*		 fake 1 just for align	*/

/* extended fd info - after _fd_name[?] */
typedef struct {
	long  _efd_owner;		/* group/user					*/
	short _efd_attr,		/* attr, four bytes				*/
	      _efd_protcod;		/* file protect code 			*/
	char  _efd_filenum,		/* file # for interleaved files	*/
		  _efd_rsv5;
} _fdtail;

/* CDIFD/FDTAIL/_efd_attr directory bit	*/
#define	CFD_READ	0x0001		/* ---- ---- ---- ---r	*/
#define	CFD_EXEC	0x0004		/* ---- ---- ---- -e--	*/
#define	CFD_PREAD	0x0010		/* ---- ---- ---r ----	*/
#define	CFD_PEXEC	0x0040		/* ---- ---- -e-- ----	*/
#define	CFD_WREAD	0x0100		/* ---- ---r ---- ----	*/
#define	CFD_WEXEC	0x0400		/* ---- -e-- ---- ----	*/
#define	CFD_CDDA	0x4000		/* -a-- ---- ---- ----	*/
#define	CFD_DIR		0x8000		/* d--- ---- ---- ----	*/

/* ------------------------------------------------	*/
/* CDI-FD just a perspective:						*/
/* notice the size of _cdifd.head is variable, so	*/
/*		sizeof( _cdifd )							*/
/* would not work properly							*/

typedef struct{
		_fdhead	head;
		_fdtail	tail;
} _cdifd;

#define		nextfd(fd)		((_cdifd *)((int)fd +fd->head._fd_rlen))

/*--------------------------------------------------*/
/* Structures for the TOC, used to locate CD-DA     */
/* tracks on a RED disc or on a CD-I disc with		*/
/* RED tracks.										*/
/*													*/
/* TOC Packet structure for each RED track on a disc */
typedef struct _toc_packet {
	char tp_ctrl,	/* control data */
		 tp_tno,	/* track number */
		 tp_smin,	/* start minute */
		 tp_ssec,	/* start second */
		 tp_sblk;	/* start block */
} _tocpacket;

/* TOC structure */
typedef struct {
	char toc_ctrl0,	/* control word 0 */
		 toc_a0,	/* $a0 byte */
		 toc_stno,	/* last data track number + 1 (CD-I) */
		 			/* first READ track number (CD-I w/RED tracks) */
		 			/* start track number (CD-DA & CD-ROM */
		 toc_type,	/* $10 for CD-I or CD-I w/RED tracks */
		 			/* $00 for CD-DA or CD-ROM */
		 toc_pblk0,	/* $00 */
		 toc_ctrl1,	/* control word 1 */
		 toc_a1,	/* $a1 byte */
		 toc_ltno,	/* last track number, for CD-I last track no + 1 */
		 toc_psec1,	/* $00 */
		 toc_pblk1,	/* $00 */
		 toc_ctrl2,	/* control word 2 */
		 toc_a2,	/* $a2 byte */
		 toc_lmin,	/* start minute of LEAD-OUT area */
		 toc_lsec,	/* start second of LEAD-OUT area */
		 toc_lblk;	/* start block of LEAD-OUT area */
	struct _toc_packet 
		 toc_packets[99];	/* track packets for up to 99 tracks */
} _toc;

#define TOC_SIZE 510 		/* total size of the TOC for CD-DA */

		 
#endif _cdi_h
