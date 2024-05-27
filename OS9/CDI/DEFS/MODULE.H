/* OS-9/68k module header definitions */

#define VHPCNT  (sizeof(struct modhcom)-2)  /* sizeof common header */
#define MODSYNC 0x4afc      /* module header sync code */
#define CRCCON	0x800fe3	/* crc polynomial constant */

/* Module access permission values */
#define MP_OWNER_READ	0x0001
#define MP_OWNER_WRITE	0x0002
#define MP_OWNER_EXEC	0x0004
#define MP_GROUP_READ	0x0010
#define MP_GROUP_WRITE	0x0020
#define MP_GROUP_EXEC	0x0040
#define MP_WORLD_READ	0x0100
#define MP_WORLD_WRITE	0x0200
#define MP_WORLD_EXEC	0x0400
#define MP_OWNER_MASK	0x000f
#define MP_GROUP_MASK	0x00f0
#define MP_WORLD_MASK	0x0f00
#define MP_SYSTM_MASK	0xf000

/* Module Type/Language values */
#define MT_ANY		0
#define MT_PROGRAM	1
#define MT_SUBROUT	2
#define MT_MULTI	3
#define MT_DATA		4
#define MT_CSDDATA	5
#define MT_TRAPLIB	11
#define MT_SYSTEM	12
#define MT_FILEMAN	13
#define MT_DEVDRVR	14
#define MT_DEVDESC	15

#define ML_ANY		0
#define ML_OBJECT	1
#define ML_ICODE	2

#define mktypelang(type,lang)	(((type)<<8)|(lang))

/* Module Attribute values */
#define MA_REENT	0x80
#define MA_GHOST	0x40
#define MA_SUPER	0x20

#define mkattrevs(attr, revs)	(((attr)<<8)|(revs))

/* configuration module:  version smoothing definitions (_mcompat field) */
#define	CP_SLOWIRQ		(1<<0)	/* save all regs during IRQ processing */
#define	CP_NOSTOP		(1<<1)	/* don't use STOP instruction */
#define	CP_NOGHOST		(1<<2)	/* don't retain ghost/sticky modules */
#define	CP_NOBURST		(1<<3)	/* don't enable 68030 burst-fill */
#define	CP_ZAPMEM		(1<<4)	/* patternize memory when allocated & freed */
#define	CP_NOCLOCK		(1<<5)	/* don't start system clock during coldstart */

typedef unsigned short ushort;

struct modhcom {
    short       _msync,     /* sync bytes ($4afc) */
				_msysrev;	/* system revision check value */
    long        _msize,     /* module size */
                _mowner,    /* owner id */
				_mname;		/* offset to module name */
	short		_maccess,   /* access permission */
                _mtylan,    /* type/lang */
                _mattrev,   /* rev/attr */
                _medit;     /* edition */
	long		_musage,	/* comment string offset */
				_msymbol;	/* symbol table offset */
	short		_mident;	/* ident code for ident program */
	char		_mspare[12];/* reserved bytes */
	short		_mparity;   /* header parity */
};

/* Executable memory module */
typedef struct {
    struct modhcom _mh;     /* common header info */
    long        _mexec,     /* offset to execution entry point */
				_mexcpt,	/* offset to exception entry point */
                _mdata,     /* data storage requirement */
                _mstack,    /* stack size */
                _midata,    /* offset to initialized data */
                _midref;    /* offset to data reference lists */
} mod_exec;

/* device driver module */
typedef struct {
    struct modhcom _mh;     /* common header info */
    long        _mexec,     /* offset to execution entry point */
				_mexcpt,	/* offset to exception entry point */
                _mdata;     /* data storage requirement */
    short		_mdinit,	/* offset to init routine */
    			_mdread,	/* offset to read routine */
    			_mdwrite,	/* offset to write routine */
    			_mdgetstat,	/* offset to getstat routine */
    			_mdsetstt,	/* offset to setstat routine */
    			_mdterm,	/* offset to terminate routine */
    			_mderror;	/* offset to exception error routine */
} mod_driver;

/* Device descriptor module */
typedef struct {
    struct modhcom	_mh;     /* common header info */
	char *			_mport;		/* device port address */
	unsigned char	_mvector;	/* trap vector number */
	unsigned char	_mirqlvl;	/* irq interrupt level */
	unsigned char	_mpriority;	/* irq polling priority */
	unsigned char	_mmode;		/* device mode capabilities */
	short			_mfmgr;		/* file manager name offset */
	short			_mpdev;		/* device driver name offset */
	short			_mdevcon;	/* device configuration offset */
	unsigned short	_mdscres[4];/* (reserved) */
	unsigned short	_mopt;		/* option table size */
	unsigned char	_mdtype;	/* device type code */
} mod_dev;

/* Configuration module */
typedef struct {
    struct modhcom _mh;     	/* common header info */
	long		_mmaxmem;		/* top limit of free ram (unused) */
	ushort		_mpollsz,		/* number of IRQ polling tbl entries */
				_mdevcnt,		/* number of device table entries */
				_mprocs,		/* number of process table entries */
				_mpaths,		/* number of path table entries */
				_msysparam,		/* offset to parameter string for _msysgo */
				_msysgo,		/* offset to initial module name */
				_msysdrive,		/* offset to system device name */
				_mconsol,		/* offset to system consol terminal name */
				_mextens,		/* offset to customization module name list */
				_mclock,		/* offset to clock module name */
				_mslice,		/* number of clock ticks per time slice */
				_mip_id;		/* interprocessor identification */
	long		_msite;			/* installation site code */
	ushort		_minstal;		/* installation name offset */
	long		_mcputyp;		/* cpu class (68000/010/020/030/3XX/040/070) */
	char		_mos9lvl[4];	/* operating system level/version/edition */
	ushort		_mos9rev,		/* offset to OS-9 level/revision string */
				_msyspri,		/* initial system priority */
				_mminpty,		/* initial minimum executable priority */
				_maxage;		/* initial maximum natural process age */
	long		_mmdirsz;		/* number of module dir entries (unused) */
	ushort		_mevents;		/* number of system event table entries */
	char		_mcompat,		/* version change smooth byte */
				_mres1;			/* reserved */
	ushort		_mmemlist,		/* offset to (colored) memory list */
				_mstacksz,		/* IRQ stack size (in lomgwords) */
				_mcoldretrys,	/* coldstart's "chd" retry counter */
				_mreserved[10]; /* reserved space */
} mod_config;

