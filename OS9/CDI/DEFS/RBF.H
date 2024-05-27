#ifndef _RBF_HFILE
#define _RBF_HFILE
#ifndef _sysio
#include <sysio.h>
#endif

#if !defined(SECTOR_SIZE)
#define SECTOR_SIZE		256
#endif

#define MAX_SECTORS		((0x10000 - (SECTOR_SIZE)) / (SECTOR_SIZE))
#define MAX_SEGMENTS	((((SECTOR_SIZE) - 256) / 5) + 48)
#define MAX_NAME		28		/* maximum length of pathname element */

#define RBFMAN	1
#define	rbfpvt	path.fm_pvt.rbf
#define rbfopt	path.fm_opt.rbf

/*
	RBF disk ID sector (sector zero) definition
		(Obnoxious alignment restrictions are historical to 6809 format)
*/
typedef struct sector0 {
	u_char		dd_tot[3];		/* total number of sectors on media */
	u_char		dd_tks;			/* track size in sectors */
	u_short		dd_map;			/* number of bytes in allocation map */
	u_short		dd_bit;			/* disk cluster size (sectors/bit) */
	u_char		dd_dir[3];		/* lsn of root directory */
	u_char		dd_own[2];		/* disk owner ID */
	u_char		dd_att;			/* disk attributes */
	u_short		dd_dsk;			/* disk ID */
	u_char		dd_fmt;			/* disk format (density/sides) */
#define		FMT_DS		(1<<0)		/* media is double-sided			*/
#define		FMT_DD		(1<<1)		/* media is double-density			*/
#define		FMT_DT		(1<<2)		/* media is double-track (96 tpi)	*/
	u_char		dd_spt[2];		/* sectors/track */
	u_char		dd_res[2];		/* reserved */
	u_char		dd_bt[3];		/* system bootstrap LSN */
	u_short		dd_bsz;			/* size of <64K system bootstrap (bytes) */
								/* if 0, dd_bt is ptr to bootstrap fd	*/
	u_char		dd_date[5];		/* creation date */
	u_char		dd_name[32];	/* volume name */
	u_char		dd_opt[32];		/* PD options */
	u_char		dd_res2;		/* reserved */
	u_char		dd_sync[4];		/* media integrity code */
	u_int		dd_maplsn;		/* bitmap starting lsn (valid if non-zero) */
	u_short		dd_lsnsize;		/* logical sector size (0 = 256 bytes)	*/
	u_char		dd_res3[150];	/* reserved */
} *Sector0;

/*
	RBF disk ID sector (sector zero) definition - drive table part.
	This part of sector 0 is copied by the driver into the first part
	of the "drive table" for the drive in the driver's static storage.
		(Obnoxious alignment restrictions are historical to 6809 format)
*/
typedef struct sect0std {
	u_char		dd_tot[3];		/* total number of sectors on media */
	u_char		dd_tks;			/* track size in sectors */
	u_short		dd_map;			/* number of bytes in allocation map */
	u_short		dd_bit;			/* disk cluster size (sectors/bit) */
	u_char		dd_dir[3];		/* lsn of root directory */
	u_char		dd_own[2];		/* disk owner ID */
	u_char		dd_att;			/* disk attributes */
	u_short		dd_dsk;			/* disk ID */
	u_char		dd_fmt;			/* disk format (density/sides) */
	u_char		dd_spt[2];		/* sectors/track */
	u_char		dd_res[2];		/* reserved */
} *Sect0std;

/*
    Directory entry structure
*/
typedef struct direntry {
	char	dir_name[28];		/* directory name */
	u_int	dir_addr;			/* file descriptor address */
} *Direntry;

/*
   File descriptor structure
*/
typedef struct fd {
	u_char	fd_att;				/* file attributes */
	union {
		struct {
			u_char	group;		/* file owner (group) */
			u_char	user;		/* file owner (user) */
		} owner;
		u_char own[2];
	} fd_own;
	u_char	fd_date[5];			/* data last modified */
	u_char	fd_link;			/* link count */
	u_int	fd_fsize;			/* file size */
	u_char	fd_dcr[3];			/* data created */
	struct {
			/* segment entry structure */
			u_char	addr[3];	/* segment begin LSN */
			u_char	size[2];	/* segment size in sectors */
	} fdseg[MAX_SEGMENTS];
} *Fd;

/*
	Drive table structure in device driver's static storage
*/
typedef	struct rbfdrive {
	struct sect0std	v_0;	/* standard sector zero stuff */
			/* --> note alignment here <-- */
	u_short		v_trak;		/* current track */
	union pathdesc*
				v_filehd;	/* list of open files on drive */
	u_short		v_diskid;	/* disk ID number */
	u_short		v_bmapsz;	/* bitmap size */
	u_short		v_mapsct;	/* lowest bitmap byte to search */
	u_short		v_bmb;		/* bitmap in use flag */
	Sector0		v_sczero;	/* pointer to sector zero buffer */
	u_char		v_zerord;	/* sector zero read flag */
	u_char		v_init;		/* drive initialized flag */
	u_short		v_resbit;	/* reserved bitmap sector number (if any) */
	u_int		v_softerr;	/* recoverable error count */
	u_int		v_harderr;	/* non-recoverable error count */
	struct cachedriv
				*v_cache;	/* drive cache information pointer */
	u_int		v_dtext;	/* drive table extension pointer */
	u_short		v_maxmap;	/* maximum bitmap sector number */
	u_short		v_dumm2;	/* reserved */
	u_int		v_dumm1[5];	/* reserved */
} *Rbfdrive;

/*
	Disk static storage global variable definitions
    required in static storage of all RBF device drivers
*/
typedef struct rbfstatic {
	sysioStatic		v_sysio;		/* kernel static storage variables */
	u_char			v_ndrv;			/* number of drives */
	u_char			v_dumm1[7];		/* reserved */
#ifndef RBF_MAXDRIVE
#define RBF_MAXDRIVE 1
#endif
	struct rbfdrive	drv[RBF_MAXDRIVE];	/* rbf drive table */
} *Rbfstatic;
		

/*
	Random block file manager PD definitions
*/
struct rbf_pvt {
	u_char		pd_smf;			/* state flags */
#define		BUFMOD		(1<<0)		/* buffer modified */
#define 	SINBUF		(1<<1)		/* sector in buffer */
#define 	FDBUF		(1<<2)		/* file descriptor in buffer */
#define		DIRIO		(1<<3)		/* I/O requests on behalf of SchDir */
#define		BUFBUSY		(1<<4)		/* buffer is busy; may not be swapped */
#define 	InDriver	(1<<5)		/* in device driver */
#define		IODirect	(1<<6)		/* I/O to caller's buffer; don't swap */
	u_char		pd_lock;		/* path lockout status */
#define		B_rcdlock	(1<<0)		/* record from lolock to hilock is locked */
#define		B_filelock	(1<<1)		/* entire file is locked */
#define		B_eoflock	(1<<2)		/* end of file is locked */
	u_char		pd_req;			/* requested lockout status */
	u_char		pd_clsbt;		/* disk cluster size (bit number) */
	u_char		*pd_fdbuf;		/* FD buffer pointer */
	u_int		pd_cp;			/* current logical byte position */
	u_int		pd_siz;			/* file size */
	u_int		pd_sbl;			/* segment beginning LSN */
	u_int		pd_sbp;			/* segment beginning PSN */
	u_int		pd_ssz;			/* segment size */
	u_short		pd_dsk;			/* disk ID */
	Rbfdrive	pd_dtb;			/* drive table pointer */
	union pathdesc
				*pd_nxfil,		/* drive open file list pointer */
				*pd_confl;		/* file conflict list pointer */
	u_short		pd_owner;		/* process ID of owner of desired segment */
	u_int		pd_lolck;		/* low locked logical address */
	u_int		pd_hilck;		/* high locked logical address */
	union pathdesc
				*pd_wait;		/* pointer to next locked out pathdesc */
	u_int		pd_tmout;		/* maximum ticks to wait for locked segment */
	u_int		pd_prior;		/* temp for process priority while in driver */
	u_char		pd_accs;		/* allowable file access permissions */
	u_char		pd_openok;		/* path opened flag */
	u_char		pd_append;		/* writing in append mode */
	u_char		pd_resv[2];
	u_char		pd_sctbt;		/* sector-byte conversion shift */
	u_int		pd_sctsiz;		/* sector size */
	u_int		pd_sctmsk;		/* sector offset mask */
};

struct rbf_opt {
	u_char		pd_dtp;			/* device type */
	u_char		pd_drv;			/* drive number */
	u_char		pd_stp;			/* step rate */
	u_char		pd_typ;			/* disk device type (5", 8", other) */
#define		TYP_HARD	(1<<7)		/* hard disk type				*/
#define		TYP_DDTRK0	(1<<5)		/* floppy disk is d/d trk 0		*/
#define		TYP_8INCH	(1<<0)		/* device is 8" floppy			*/
	u_char		pd_dns;			/* density capabilities */
#define		DNS_DD		(1<<0)		/* double density				*/
#define		DNS_DT		(1<<1)		/* double track density			*/
	u_char		pd_res1;		/* reserved */
	u_short		pd_cyl;			/* number of cylinders */
	u_char		pd_sid;			/* number of surfaces */
	u_char		pd_vfy;			/* 0=verify disk writes */
	u_short		pd_sct;			/* default sectors/track */
	u_short		pd_t0s;			/* default sectors/track for trk0/sec0 */
	u_short		pd_sas;			/* segment allocation size */
	u_char		pd_ilv;			/* sector interleave offset */
	u_char		pd_tfm;			/* DMA transfer mode */
	u_char		pd_toffs;		/* track base offset */
	u_char		pd_soffs;		/* sector base offset */
	u_short		pd_ssize;		/* size of sector in bytes */
	u_short		pd_cntl;		/* control word */
#define		CNTL_NOFMT		(1<<0)	/* device is format protected		*/
#define		CNTL_MULTSECT	(1<<1)	/* multi-sector transfer capable	*/
#define		CNTL_STABID		(1<<2)	/* device has stable id				*/
#define		CNTL_AUTOSIZE	(1<<3)	/* device tells size (SS_DSize),	*/
#define		CNTL_FMTTRK		(1<<4)	/* device allows "format track"		*/
	u_char		pd_trys;		/* # tries */
	u_char		pd_lun;			/* SCSI unit number of drive */
	u_short		pd_wpc;			/* first write precomp cylinder */
	u_short		pd_rwr;			/* first reduced write current cylinder */
	u_short		pd_park;		/* park cylinder for hard disks */
	u_int		pd_lsnoffs;		/* LSN offset for partition */
	u_short		pd_totcyls;		/* total cylinders on device */
	u_char		pd_ctrlrid;		/* SCSI controller id */
	u_char		pd_res2;		/* reserved (alignment) */
	u_int		pd_scsiopt;		/* SCSI options flags */
#ifndef		_SCSI_OPTS
#define		SCSI_ATN		(1<<0)	/* assert ATN supported				*/
#define		SCSI_TARGET		(1<<1)	/* target mode supported			*/
#define		SCSI_SYNCHR		(1<<2)	/* synchronous transfers supported	*/
#define		SCSI_PARITY		(1<<3)	/* enable SCSI parity				*/
#define		_SCSI_OPTS
#endif
	u_int		pd_maxcnt;		/* maximum byte count passable to driver */
	u_char		pd_res4[5];		/* reserved */
	u_char		pd_att;			/* file attributes */
	u_int		pd_fd;			/* LSN of file descriptor */
	u_int		pd_dfd;			/* directory file descriptor LSN */
	u_int		pd_dcp;			/* directory entry pointer */
	u_int		pd_dvt;			/* device table pointer (copy) */
	u_char		pd_res3[26];	/* reserved */
	char		pd_name[32];	/* filename */
};

#endif


