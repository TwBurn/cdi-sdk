/*
	File manager path descriptor definitions
*/

typedef union pathdesc *Pathdesc;

union pathdesc {
	struct pathcom {
		u_short		pd_pd;			/* path number */
		u_char		pd_mod;			/* mode (read/write/update) */
		u_char		pd_cnt;			/* number of original open images */
		Devicetbl	pd_dev;			/* device table entry ptr */
		u_short		pd_cpr;			/* current process ID */
		REGISTERS	*pd_rgs;		/* caller's register stack ptr */
		u_char 		*pd_buf;		/* buffer address */
		u_int		pd_user;		/* group number of path's creator */
		Pathdesc	pd_paths;		/* list of open paths on device */
		u_short		pd_count;		/* actual number of open images */
		u_short		pd_lproc;		/* last active process ID */
		u_int		pd_errno;		/* global errno for C filemanagers */
		u_int		pd_sysglob;		/* system globals for C filemanagers */
		u_short		pd_dumm[2];		/* reserved */
		union {
#ifdef RBFMAN
			struct rbf_pvt rbf;
#endif
#ifdef SCFMAN
			struct scf_pvt scf;
#endif
#ifdef SBFMAN
			struct sbf_pvt sbf;
#endif
#ifdef ENPMAN
			struct enp_pvt enp;
#endif
#ifdef PKMAN
			struct pkm_pvt pkm;
#endif
#ifdef NRFMAN
			struct nrf_pvt nrf;
#endif
#ifdef IFMAN
			struct ifm_pvt ifm;
#endif
#ifdef SOCKMAN
			struct sock_pvt sock;
#endif
 			char dumm[128-42];		/* pad above stuff to 128 bytes */
		} fm_pvt;
		union {
#ifdef RBFMAN
			struct rbf_opt rbf;
#endif
#ifdef SCFMAN
			struct scf_opt scf;
#endif
#ifdef SBFMAN
			struct sbf_opt sbf;
#endif
#ifdef ENPMAN
			struct enp_opt enp;
#endif
#ifdef PKMAN
			struct pkm_opt pkm;
#endif
#ifdef NRFMAN
			struct nrf_opt nrf;
#endif
#ifdef IFMAN
			struct ifm_opt ifm;
#endif
#ifdef SOCKMAN
			struct sock_opt sock;
#endif
			char dumm[128];
		} fm_opt;
	} path;
	char pd_dumz1[128];
};

