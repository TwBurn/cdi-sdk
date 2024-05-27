#ifndef __REG_H
#define __REG_H
 
/* Machine related definitions (68000-specific for now) */
typedef struct {
    u_int d[8];				/* data registers */
    void *a[8];				/* address registers */
    u_short sr;				/* status register */
    u_int pc;				/* status register/program counter */
    u_int ssp,usp,isp,msp;	/* stack pointers */
    u_int vbr,cacr,caar;	/* cache control registers */
    u_int sfc,dfc;			/* alternate function registers */
	u_short xxx;			/* <unused> to make this struct%4==0 */
} REGISTERS;

typedef u_char freg[12];	/* 68881 80-bit (96 external) floating register */

typedef struct  {
	freg fp[8];				/* 68881 registers */
	u_int fpcr, fpsr, fpiar;/* fpu control registers */
	u_char fpstate;			/* coprocessor frame state flag */
} FLOATREGS;
#endif
