OUTPUT_ARCH(m68k)
MEMORY
{
    rom (rx) : ORIGIN = 0x000000, LENGTH = 0x100000
    ram (rwx) : ORIGIN = 0x300000, LENGTH = 0x010000
}
SECTIONS
{
  .text : ALIGN(4) {
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

  _init_data_start = LOADADDR(.data);

  .data : ALIGN(4) {
    _data_start = .;
    KEEP(*(.data))
    _data_end = .;
  } > ram AT > rom

  .bss : ALIGN(4) {
    _bss_start = .;
    KEEP(*(.bss))
    _bss_end = .;
  } > ram

  _ram_start = 0x300000;
  _stack_top = 0x308000;
}
