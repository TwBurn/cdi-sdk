/* System call error numbers.
 * May be found in 'errno' after an error has occurred.
 *
 * These should be obtained from sys.l somehow.
 *
 */

#define E_ILLFNC	0x40	/* illegal function code				*/
#define E_FMTERR	0x41	/* format error							*/
#define E_NOTNUM	0x42	/* number not found/not a number		*/
#define E_ILLARG	0x43	/* illegal argument						*/

#define E_BUSERR	0x66	/* bus error TRAP 2 occurred			*/
#define E_ADRERR	0x67	/* address error TRAP 3 occurred		*/
#define E_ILLINS	0x68	/* illegal instruction TRAP 4 occurred	*/
#define E_ZERDIV	0x69	/* zero divide TRAP 5 occurred			*/
#define E_CHK		0x6a	/* CHK instruction TRAP 6 occurred		*/
#define E_TRAPV		0x6b	/* TrapV instruction TRAP 7 occurred	*/
#define E_VIOLAT	0x6c	/* privelage violation TRAP 8 occurred	*/
#define E_TRACE		0x6d	/* Uninitialized Trace TRAP 9 occurred	*/
#define E_1010		0x6e	/* Uninitialized 1010 TRAP 10 occurred	*/
#define E_1111		0x6f	/* Uninitialized 1111 TRAP 11 occurred	*/
#define E_TRAP		0x85	/* user traps 1-15 E_TRAP+n				*/
#define E_FPUNORDC	0x94	/* FP unordered condition error			*/
#define E_FPINXACT	0x95	/* FP inexact result					*/
#define E_FPDIVZER	0x96	/* FP zero divisor						*/
#define E_FPUNDRFL	0x97	/* FP underflow							*/
#define E_FPOPRERR	0x98	/* FP operand error						*/
#define E_FPOVERFL	0x99	/* FP overflow							*/
#define E_FPNOTNUM	0x9a	/* FP not a number						*/

#define E_PERMIT	0xa4	/* You must be super user to do that	*/
#define E_DIFFER	0xa5	/* Arguments to F$ChkNam are different	*/
#define E_STKOVF	0xa6	/* Stack overflow (ChkNam)				*/
#define E_EVNTID	0xa7	/* Invalid or Illegal event ID number	*/
#define E_EVNF		0xa8	/* Event (name) not found				*/
#define E_EVBUSY	0xa9	/* The event is busy (can't be deleted)	*/
#define E_EVPARM	0xaa	/* Impossible Event parameters supplied	*/
#define E_DAMAGE	0xab	/* System data structures are damaged	*/
#define E_BADREV	0xac	/* Incompatible revision				*/
#define E_PTHLOST	0xad	/* Path Lost (net node was down)		*/
#define E_BADPART	0xae	/* Bad partition data or no active		*/
							/* partition							*/
#define E_HARDWARE	0xaf	/* Hardware is damaged					*/

#define E_PTHFUL	0xc8	/* Path Table full						*/
#define E_BPNUM		0xc9	/* Bad Path Number						*/
#define E_POLL		0xca	/* Polling Table Full					*/
#define E_BMODE		0xcb	/* Bad Mode								*/
#define E_DEVOVF	0xcc	/* Device Table Overflow				*/
#define E_BMID		0xcd	/* Bad Module ID						*/
#define E_DIRFUL	0xce	/* Module Directory Full				*/
#define E_MEMFUL	0xcf	/* Process Memory Full					*/
#define E_UNKSVC	0xd0	/* Unknown Service Code					*/
#define E_MODBSY	0xd1	/* Module Busy							*/
#define E_BPADDR	0xd2	/* Bad Page Address						*/
#define E_EOF		0xd3	/* End of File							*/
#define E_VCTBSY	0xd4	/* IRQ Vector is already used			*/
#define E_NES		0xd5	/* Non-Existing Segment					*/
#define E_FNA		0xd6	/* File Not Accesible					*/
#define E_BPNAM		0xd7	/* Bad Path Name						*/
#define E_PNNF		0xd8	/* Path Name Not Found					*/
#define E_SLF		0xd9	/* Segment List Full					*/
#define E_CEF		0xda	/* Creating Existing File				*/
#define E_IBA		0xdb	/* Illegal Block Address				*/
#define E_HANGUP	0xdc	/* Phone hangup occurred (modem)		*/
#define E_MNF		0xdd	/* Module Not Found						*/
#define E_NOCLK		0xde	/* System has no clock running			*/
#define E_DELSP		0xdf	/* Deleting Stack Pointer memory		*/
#define E_IPRCID	0xe0	/* Illegal Process ID					*/
#define E_PARAM		0xe1	/* Impossible polling parameter specified*/
#define E_NOCHLD	0xe2	/* No Children							*/
#define E_ITRAP		0xe3	/* Invalid or unavailable Trap code		*/
#define E_PRCABT	0xe4	/* Process Aborted						*/
#define E_PRCFUL	0xe5	/* Process Table Full					*/
#define E_IFORKP	0xe6	/* Illegal Fork Parameter				*/
#define E_KWNMOD	0xe7	/* Known Module							*/
#define E_BMCRC		0xe8	/* Bad Module CRC						*/
#define E_USIGP		0xe9	/* Unprocessed Signal Pending (obsolescent)*/
#define E_SIGNAL	0xe9	/* Signal Error (replaces E_USIGP)		*/
#define E_NEMOD		0xea	/* Non Existing Module					*/
#define E_BNAM		0xeb	/* Bad Name								*/
#define E_BMHP		0xec	/* bad module header parity				*/
#define E_NORAM		0xed	/* No Ram Available						*/
#define E_DNE		0xee	/* Directory not empty					*/
#define E_NOTASK	0xef	/* No available Task number				*/
#define E_UNIT		0xf0	/* Illegal Unit (drive)					*/
#define E_SECT		0xf1	/* Bad SECTor number					*/
#define E_WP		0xf2	/* Write Protect						*/
#define E_CRC		0xf3	/* Bad Check Sum						*/
#define E_READ		0xf4	/* Read Error							*/
#define E_WRITE		0xf5	/* Write Error							*/
#define E_NOTRDY	0xf6	/* Device Not Ready						*/
#define E_SEEK		0xf7	/* Seek Error							*/
#define E_FULL		0xf8	/* Media Full							*/
#define E_BTYP		0xf9	/* Bad Type (incompatible) media		*/
#define E_DEVBSY	0xfa	/* Device Busy							*/
#define E_DIDC		0xfb	/* Disk ID Change						*/
#define E_LOCK		0xfc	/* Record is busy (locked out)			*/
#define E_SHARE		0xfd	/* Non-sharable file busy				*/
#define E_DEADLK	0xfe	/* I/O Deadlock error					*/
#define E_FORMAT	0xff	/* Device is format protected			*/
#define ERANGE		0x100	/* ANSI C number out of range error		*/

/* 0x600 is for RAVE */
#define E_GFM_BASE	0x600	/* GFM error code base					*/
#define E_GSL_BASE	0x664	/* GSL error code base					*/

/* 0x700 is for Ethernet */
#define EWOULDBLOCK		0x701	/* I/O operation would block */
#define EINPROGRESS		0x702	/* I/O operation now in progress */
#define EALREADY		0x703	/* operation already in progress */
#define EDESTADDRREQ	0x704	/* destination address required */
#define EMSGSIZE		0x705	/* message too long */
#define EPROTOTYPE		0x706	/* protocol wrong type for socket */
#define ENOPROTOOPT		0x707	/* bad protocol option */
#define EPROTONOSUPPORT 0x708	/* protocol not supported */
#define ESOCKNOSUPPORT	0x709	/* socket type not supported */
#define EOPNOTSUPP		0x70a	/* operation not supported on socket */
#define EPFNOSUPPORT	0x70b	/* protocol family not supported */
#define EAFNOSUPPORT	0x70c	/* address family not supported by protocol */
#define EADDRINUSE		0x70d	/* address already in use */
#define EADDRNOTAVAIL	0x70e	/* can't assign requested address */
#define ENETDOWN		0x70f	/* network is down */
#define ENETUNREACH		0x710	/* network is unreachable */
#define ENETRESET		0x711	/* network dropped connection on reset */
#define ECONNABORTED	0x712	/* software caused connection abort */
#define ECONNRESET		0x713	/* connection reset by peer */
#define ENOBUFS			0x714	/* no buffer space available */
#define EISCONN			0x715	/* socket is already connected */
#define ENOTCONN		0x716	/* socket is not connected */
#define ESHUTDOWN		0x717	/* can't send after socket shutdown */
#define ETOOMANYREFS	0x718	/* too many references */
#define ETIMEDOUT		0x719	/* connection timed out */
#define ECONNREFUSED	0x71a	/* connection refused by target */
#define EBUFTOOSMALL	0x71b	/* mbuf too small for mbuf operation	*/
#define ESMODEXISTS		0x71c	/* socket module already attached		*/
#define ENOTSOCK		0x71d	/* path is not a socket					*/

extern int errno;
