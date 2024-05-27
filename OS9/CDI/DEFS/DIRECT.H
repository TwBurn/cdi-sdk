#ifndef NULL
#include <stdio.h>
#endif

struct dirent {
	char	dir_name[28];	/* directory name */
	long	dir_addr;		/* file descriptor address */
};

struct fildes {
	char	fd_att,			/* file attributes */
			fd_own[2],		/* file owner */
			fd_date[5],		/* date last modified */
			fd_link,		/* link count */
			fd_fsize[4],	/* file size */
			fd_dcr[3];		/* date created */
	struct {
			char	addr[3],	/* segment begin LSN */
					size[2];	/* segment size (sectors) */
	} fdseg[48];
};

struct ddsect {
	char	dd_tot[3];		/* total number of sectors on media */
	char	dd_tks;			/* track size in sectors */
	WORD	dd_map;			/* number of bytes in allocation map */
	WORD	dd_bit;			/* disk cluster size (sectors/bit */
	char	dd_dir[3];		/* lsn of root directory */
	char	dd_own[2];		/* disk owner ID */
	char	dd_att;			/* disk attributes */
	WORD	dd_dsk;			/* disk ID */
	char	dd_fmt;			/* disk format (density/sides) */
	char	dd_spt[2];		/* sectors/track */
	char	dd_res[2];		/* reserved */
	char	dd_bt[3];		/* system bootstrap LSN */
	WORD	dd_bsz;			/* size of system bootstrap (bytes) */
	char	dd_date[5];		/* creation date */
	char	dd_name[32];	/* volume name */
	char	dd_opt[32];		/* PD options */
	u_char	dd_res2;		/* reserved */
	u_char	dd_sync[4];		/* media integrity code */
	u_int	dd_maplsn;		/* bitmap starting lsn (valid if non-zero) */
	u_short	dd_lsnsize;		/* logical sector size (0 = 256 bytes)	*/
	char	dd_null[150];	/* reserved */
};


