
CSRCS = devtty.c devinput.c devgpio.c
CSRCS += devices.c main.c libc.c ppide.c tms9918.c 

ASRCS = p68000.S crt0.S
ASRCS += tricks.S spi.S ds1302io.S

DSRCS = ../dev/devide.c ../dev/mbr.c ../dev/blkdev.c ../dev/devide_discard.c
DSRCS += ../dev/devsd.c ../dev/devsd_discard.c
DSRCS += ../dev/ds1302.c ../dev/ds1302_discard.c
DSRCS += ../dev/ps2bitbang.c ../dev/ps2bitbang_rc2014.c ../dev/ps2kbd.c
DOBJS = $(patsubst ../dev/%.c,%.o, $(DSRCS))

LSRCS = ../lib/68000exception.c
LOBJS = $(patsubst ../lib/%.c,%.o, $(LSRCS))

RSRCS = ../dev/rc2014/zxkey.c ../dev/rc2014/zxkeyboard.c
ROBJS = $(patsubst ../dev/rc2014/%.c,%.o, $(RSRCS))

COBJS = $(CSRCS:.c=.o)
AOBJS = $(ASRCS:.S=.o)
OBJS  = $(COBJS) $(AOBJS) $(DOBJS) $(LOBJS) $(ROBJS)

CROSS_CCOPTS += -I../dev/ -I../dev/rc2014/

all:	$(OBJS)

$(COBJS): %.o: %.c
	$(CROSS_CC) $(CROSS_CCOPTS) -c $<

$(AOBJS): %.o: %.S
	$(CROSS_AS) $(ASOPTS) $< -o $*.o

$(DOBJS): %.o: ../dev/%.c
	$(CROSS_CC) $(CROSS_CCOPTS) -c $<

$(ROBJS): %.o: ../dev/rc2014/%.c
	$(CROSS_CC) $(CROSS_CCOPTS) -c $<

$(LOBJS): %.o: ../lib/%.c
	$(CROSS_CC) $(CROSS_CCOPTS) -c $<

tricks.S: ../lib/68000flat.S

clean:
	rm -f *.o fuzix.elf loader.elf loader.map loader.bin core *~ 

image:
	$(CROSS_LD) -M -o fuzix.elf -T fuzix.ld \
	p68000.o ../start.o ../version.o ../lowlevel-68000.o \
	tricks.o main.o ../timer.o ../kdata.o 68000exception.o devices.o \
	../devio.o ../filesys.o ../process.o ../inode.o ../syscall_fs.o \
	../syscall_proc.o ../syscall_other.o ../mm.o ../flat.o \
	../tty.o ../vt.o ../devsys.o ../usermem.o ../syscall_fs2.o \
	../syscall_fs3.o ../syscall_exec32.o ../font6x8.o \
	blkdev.o devide.o devide_discard.o mbr.o zxkey.o zxkeyboard.o \
	../usermem_std-68000.o devtty.o libc.o ../malloc.o ppide.o \
	devsd.o devsd_discard.o spi.o ds1302.o ds1302_discard.o ds1302io.o \
	devinput.o ../devinput.o devgpio.o tms9918.o \
	ps2kbd.o ps2bitbang.o ps2bitbang_rc2014.o \
	../level2.o ../syscall_level2.o ../select.o > ../fuzix.map
	m68k-uclinux-objcopy fuzix.elf -O binary ../fuzix.bin

	$(CROSS_CC) -c loader.S
	$(CROSS_LD) -M -o loader.elf -T loader.ld loader.o >loader.map
	m68k-uclinux-objcopy loader.elf -O binary loader.bin
