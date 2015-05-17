/* Enable to make ^Z dump the inode table for debug */
#undef CONFIG_IDUMP
/* Enable to make ^A drop back into the monitor */
#undef CONFIG_MONITOR
/* Profil syscall support (not yet complete) */
#undef CONFIG_PROFIL
/* Multiple processes in memory at once */
#define CONFIG_MULTI
/* Single tasking - for now while we get it booting */
#undef CONFIG_SINGLETASK
/* Pure swap */
#undef CONFIG_SWAP_ONLY
/* Banked Kernel: need to fix GCC first */
#define CONFIG_BANK_FIXED
#define MAX_MAPS 4
#define MAP_SIZE 0x7C00U
#define CONFIG_BANKS	1
/* And swapping */
#define SWAPDEV 2049		/* DriveWire drive 1 */
#define SWAP_SIZE   0x80	/* 64K blocks */
#define SWAPBASE    0x8000	/* We swap the lot in one, include the */
#define SWAPTOP     0xFF00	/* uarea so its a round number of sectors */
#define MAX_SWAPS   32

/* Permit large I/O requests to bypass cache and go direct to userspace */
#define CONFIG_LARGE_IO_DIRECT

/* Video terminal, not a serial tty */
#define CONFIG_VT
/* Simple text mode */
#define CONFIG_VT_SIMPLE
/* Vt definitions */
#define VT_BASE		(uint8_t *)0x0400	/* Default video text mode base */
#define VT_WIDTH	32
#define VT_HEIGHT	16
#define VT_RIGHT	31
#define VT_BOTTOM	15
#define VT_INITIAL_LINE	4

extern unsigned char vt_mangle_6847(unsigned char c);
#define VT_MAP_CHAR(x)	vt_mangle_6847(x)

/* RS/Tandy Color Computer keyboard */
#undef CONFIG_COCO_KBD

#define TICKSPERSEC 50   /* Ticks per second */
/* FIXME: This will move once we put the display in the kernel bank and
   sort the banker out */
#define PROGBASE    0x8000  /* also data base */
#define PROGLOAD    0x8000  /* also data base */
#define PROGTOP     0xFC00  /* Top of program */

#define BOOT_TTY (512 + 1)   /* Set this to default device for stdio, stderr */
                          /* In this case, the default is the first TTY device */
                            /* Temp FIXME set to serial port for debug ease */

/* We need a tidier way to do this from the loader */
#define CMDLINE	NULL	  /* Location of root dev name */

/* Device parameters */
#define NUM_DEV_TTY 2
#define NDEVS    2        /* Devices 0..NDEVS-1 are capable of being mounted */
                          /*  (add new mountable devices to beginning area.) */
#define TTYDEV   BOOT_TTY /* Device used by kernel for messages, panics */
#define NBUFS    6       /* Number of block buffers */
#define NMOUNTS	 2	  /* Number of mounts at a time */
#define swap_map(x)	((uint8_t *)(x))
