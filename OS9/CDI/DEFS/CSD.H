/* Copyright 1988 by Microware Systems Corporation */

#ifndef _csd_h
#define _csd_h

/* Base Case Devices */
#define DT_SYSTEM	0	/* CD-RTOS */
#define DT_CDC		1	/* CD-Control Unit */
#define DT_AUDIO	2	/* Audio Processor */
#define DT_VIDEO	3	/* Video Output Processor */
#define DT_NVRAM 	4	/* Non-volatile Random Access memory */
#define DT_PTR	 	5	/* Pointing Device */

/* Base Case Peripherals */
#define DT_CDPLAY 	6	/* CD-Player */
#define DT_AUDSET	7	/* Audio Set */
#define DT_DISPLY	8	/* Display Monitor */

/* Base Case Devices */
#define DT_PIPEDEV  9   /* Pipe Device */

/* Peripheral Extensions */
#define DT_KEYBRD	10	/* Keyboard */

/* MPEG Extensions */
#define DT_MPEGV        90
#define DT_MPEGA        91

/* Type of return values from functions */
char *csd_devname(),*csd_devparam();

#endif
