/* Jump register save buffer */

#ifdef OSK
typedef int jmp_buf[16];		/* for 68000 */
#else
typedef int jmp_buf[4];			/* for 6809 */
#endif
