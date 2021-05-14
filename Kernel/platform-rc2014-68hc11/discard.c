#include <kernel.h>
#include <devide.h>
#include <devsd.h>

/* Onboard I/O */
static volatile uint8_t *cpuio = (volatile uint8_t *)0xF000;

/*
 * Map handling: allocate 3 banks per process for now
 */

void pagemap_init(void)
{
    uint8_t i;
    for (i = 0x20; i <= 0x3D; i+= 3)
        pagemap_add(i);
}

void map_init(void)
{
}

uint8_t platform_param(char *p)
{
    return 0;
}


/*
 *	Do the device initialization
 */

void device_init(void)
{
#ifdef CONFIG_IDE
	devide_init();
#endif
#ifdef CONFIG_SD
        devsd_init();
#endif
        /* RTI isn't really that useful but it's ok as an
          event timer that will do nicely for bring up */
	/* RTI interrupt enable */
//	cpuio[0x24] |= 0x40;
}
