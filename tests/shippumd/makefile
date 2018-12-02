LDFLAGS=../../runtime/vectors.o ../../runtime/start.o -nostdlib -T ../../ldscript/mahoudai.ld
CC=m68k-elf-gcc
OBJCOPY=m68k-elf-objcopy

all: test1.bin

%.bin: %.elf
	rm -f $@
	$(OBJCOPY) -O binary $< $@
	../../tools/romutils expand $@ 1048576
	../../tools/romutils split $@ $(basename $@).rom1 $(basename $@).rom0

test1.elf: test1.c
	$(CC) -mcpu=68000 -o $@ $< $(LDFLAGS)
