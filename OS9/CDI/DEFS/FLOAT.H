/* ANSI/IEEE for single and double precision normalized numbers */

#if !defined(_float)
#define _float
#define	FLT_RADIX		2
#define	FLT_MANT_DIG	24
#define	FLT_EPSILON		1.119209290e-07f
#define	FLT_DIG			6
#define	FLT_MIN_EXP		-125
#define	FLT_MIN			1.17549435e-38f
#define	FLT_MIN_10_EXP	-37
#define	FLT_MAX_EXP		128
#define	FLT_MAX			3.40282347e38f
#define	FLT_MAX_10_EXP	38
#define	DBL_MANT_DIG	53
#define	DBL_EPSILON		2.2204460492503131e-16
#define	DBL_DIG			15
#define	DBL_MIN_EXP		-1021
#define	DBL_MIN			2.2250738585072016e-308
#define	DBL_MIN_10_EXP	-307
#define	DBL_MAX_EXP		1024
#define	DBL_MAX			1.7976931348623157e308
#define	DBL_MAX_10_EXP	308

/* Extensions */
#define _DBL_MAX_FRAC		.17976931348623157
#define	_DBL_MIN_FRAC		.22250738585072016
#define _DBL_EXP_BIAS		1023
#define _DBL_MAX_BIAS_EXP	2047
#endif
