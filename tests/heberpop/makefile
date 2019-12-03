LDFLAGS=../../runtime/vectors.o ../../runtime/start.o -nostdlib -T ../../ldscript/heberpop.ld
CC=m68k-elf-gcc
OBJCOPY=m68k-elf-objcopy

all: test1.bin

%.bin: %.elf
	rm -f $@
	$(OBJCOPY) -O binary $< $@
	../../tools/romutils expand $@ 1048576
	../../tools/romutils split $@ $(basename $@).ic31 $(basename $@).ic32

test1.elf: test1.c
	$(CC) -mcpu=68000 -o $@ $< $(LDFLAGS)
