/* structure for manipulating OS-9 directories in a (more)
	transportable manner.  The method and names work like
	the BSD4.2 directory calls
*/

#define MAXNAMLEN 32
#define DIRBLKSIZ 256

struct direct {
	long	d_addr;				/* fildes address (no inodes on OS-9) */
	short	d_reclen;			/* (not used) */
	short	d_namlen;			/* (not used) */
	char	d_name[MAXNAMLEN+1];/* directory entry name */
};

typedef struct _dirdesc {
	int		dd_fd;				/* fd for open directory */
	long	dd_loc;				/* (not used) */
	long	dd_size;			/* (not used) */
	char	dd_buf[DIRBLKSIZ];	/* buffer for directory entry */
} DIR;

extern DIR *opendir();
extern struct direct *readdir();
extern long telldir();
extern /* void */ seekdir(),rewinddir(),closedir();
