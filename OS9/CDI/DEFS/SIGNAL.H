/* OS-9 signals */
#define		SIGKILL		0	/* sytem abort (cannot be caught or ignored) */
#define		SIGWAKE		1	/* wake up */
#define		SIGQUIT		2	/* keyboard abort */
#define		SIGINT		3	/* keyboard interrupt */
#define		SIGHUP		4	/* modem hangup signal */
#define		SIGDEADLY	32	/* lower signal codes may abort i/o */

/* special addresses */
#define		SIG_DFL		0
#define		SIG_IGN		1

