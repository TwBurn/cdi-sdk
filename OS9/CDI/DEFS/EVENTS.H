/*
	OS-9 Event and Semaphores

*/

#define EV_SIZE		32		/* event entry size */
#define EV_ALLPROCS	0x8000	/* activate all processes in range */

typedef struct _evstr {
	unsigned short _ev_eid;		/* event id number */
	char _ev_name[12];			/* event name */
	int _ev_value;				/* current event value */
	short _ev_winc;				/* wait increment value */
	short _ev_sinc;				/* signal increment value */
	unsigned short _ev_link;	/* event use count */
	struct _evstr *queN;		/* next event in queue */
	struct _evstr *queP;		/* previous event in queue */
} event;

extern int
	_ev_create(),	_ev_link(),		_ev_signal(),	_ev_pulse(),
	_ev_set(),		_ev_setr(),		_ev_unlink(),	_ev_delete(),
	_ev_info(),		_ev_wait(),		_ev_waitr(),	_ev_read();
