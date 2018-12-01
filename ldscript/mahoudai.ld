OUTPUT_ARCH(m68k)
MEMORY
{
    rom (rx) : ORIGIN = 0x000000, LENGTH = 0x080000
    ram (rwx) : ORIGIN = 0x100000, LENGTH = 0x010000
}
SECTIONS
{
  .text : ALIGN(2) {
    . = 0x000000;
    _vector_start = .;
    KEEP(*(.vectors))
    _vector_end = .;

    . = 0x000400;
    _text_start = .;
    KEEP(*(.text))
    _text_end = .;

    _rodata_start = .;
    KEEP(*(.rodata))
    _rodata_end = .;
  } > rom

  .data : ALIGN(2) {
    _data_start = .;
    KEEP(*(.data))
    _data_end = .;
  } > ram

  .bss : ALIGN(2) {
    _bss_start = .;
    KEEP(*(.bss))
    _bss_end = .;
  } > ram

  _ram_start = 0x100000;
  _stack_top = 0x110000;
}
