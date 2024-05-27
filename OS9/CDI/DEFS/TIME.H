/*
 * time.h -- time-related stuff
 *
 * We include both the OS-9 time structure and the ANSI time structures,
 * to try to make everybody happy.  There may be some name clashes
 * induced thereby, however.
 */

/* structure for the 'setime()' and 'getime()' calls */

struct sgtbuf {
	char    t_year,
			t_month,
			t_day,
			t_hour,
			t_minute,
			t_second;
};

#ifndef ctime

#ifndef D_TckSec
#include <setsys.h>
#endif

typedef long	clock_t;
typedef long	time_t;

/* X3J11 Draft says *nowhere* that CLK_TCK is a constant! */

#define CLK_TCK	((clock_t) _getsys(D_TckSec, 2))

struct tm {
	int	tm_sec;		/* seconds after the minute -- [0, 59]  */
	int	tm_min;		/* minutes after the hour   -- [0, 59]  */
	int	tm_hour;	/* hours since midnight		-- [0, 23]  */
	int	tm_mday;	/* day of the month			-- [1, 31]  */
	int	tm_mon;		/* months since January		-- [0, 11]  */
	int	tm_year;	/* years since 1900						*/
	int	tm_wday;	/* days since Sunday		-- [0, 6]   */
	int	tm_yday;	/* days since 1 January		-- [0, 365] */
	int	tm_isdst;	/* Daylight Savings Time flag			*/
					/* 0 = no, 1 = yes, -1 = unknown		*/
};

clock_t		clock();
time_t		time(), mktime();
double		difftime();
char		*asctime();
struct tm	*gmtime();
struct tm	*localtime();
extern		togmtime();

#define	ctime(t)			asctime(localtime((t)))
#define difftime(t1, t0)	((double) ((t1) - (t0)))

#endif
