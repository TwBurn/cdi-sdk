#ifndef _sysio
#include <sysio.h>
#endif

/*
	SCF static storage.  Required in every SCF driver.
*/
typedef struct scfstatic {
	sysioStatic		v_sysio;/* kernel static storage variables */
	struct scfstatic
				*v_dev2;	/* attached device's static storage ptr */
	char		v_type,		/* device type or parity */
				v_line,		/* lines left until end of page */
				v_pause,	/* immediate pause request */
				v_intr,		/* keyboard interrupt char */
				v_quit,		/* keyboard quit char */
				v_pchr,		/* pause character */
				v_err,		/* accumulated errors */
				v_xon,		/* x-on character */
				v_xoff;		/* x-off character */
	short		v_resv1[5];	/* reserved (used by pipeman) */
	u_char		v_hangup;	/* set to non-zero when data carrier is lost */
	u_char		v_pad1;		/* spare */
	short		v_resv2[6];	/* reserved */
} *Scfstatic;
		
/*
	Sequential character file manager PD definitions
*/
struct scf_pvt {
	Devicetbl	pd_dev2;		/* device tbl ptr for echo device */
	u_short		pd_max;			/* readline high byte count */
	u_char		pd_raw;			/* read/write or Rdlin/wrlin mode */
	u_char		pd_min;			/* devices are owned if clear */
	u_char		pd_lost;		/* non zero if path is dead */
};

struct scf_opt {
	u_char		pd_dtp;			/* device type */
	u_char		pd_upc;			/* case (0=both, 1=upper only) */
	u_char		pd_bso;			/* backsp (0=bse, 1=bse,sp,bse) */
	u_char		pd_dlo;			/* delete (0=bse over line, 1=crlf) */
	u_char		pd_eko;			/* echo (0=no echo) */
	u_char		pd_alf;			/* autolf (0=no auto lf) */
	u_char		pd_nul;			/* end of line null count */
	u_char		pd_pau;			/* pause (0=no end of page pause) */
	u_char		pd_pag;			/* lines per page */
	u_char		pd_bsp;			/* backspace character */
	u_char		pd_del;			/* delete line character */
	u_char		pd_eor;			/* end of record char (read only) */
	u_char		pd_eof;			/* end of file char */
	u_char		pd_rpr;			/* reprint line char */
	u_char		pd_dup;			/* dup last line char */
	u_char		pd_psc;			/* pause char */
	u_char		pd_int;			/* kbd intr char (ctl c) */
	u_char		pd_qut;			/* kbd quit char (ctl q) */
	u_char		pd_bse;			/* backspace echo character */
	u_char		pd_ovf;			/* line overflow char (bell) */
	u_char		pd_par;			/* parity code */
	u_char		pd_bau;			/* acia baud rate (color computer) */
	short		pd_d2p;			/* dev2 output name offset */
	u_char		pd_xon;			/* x-on char */
	u_char		pd_xoff;		/* x-off char */
	u_char		pd_Tab;			/* Tab character (0=none) */
	u_char		pd_Tabs;		/* Tab field size */
	Devicetbl	pd_tbl;			/* Device table addr (copy) */
	u_short		pd_Col;			/* current column number */
	u_char		pd_err;			/* most recent I/O error status */
};

#define SCFMAN	1
#define	scfpvt	path.fm_pvt.scf
#define scfopt	path.fm_opt.scf

