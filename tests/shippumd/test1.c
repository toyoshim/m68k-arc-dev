#include <stdint.h>
#include <mahoudai/port.h>
#include <mahoudai/text.h>

void put_char(uint8_t x, uint8_t y, uint8_t palette, uint16_t c) {
  uint16_t px = 44 - y;
  uint16_t py = x;
  uint16_t data = (palette << 10) | c;
  text_vram[py * 64 + px] = data;
}

void put_string(uint8_t x, uint8_t y, uint8_t palette, const char* s) {
  while (*s)
    put_char(x++, y, palette, *s++);
}

void show_bits(uint8_t y, uint16_t data) {
  uint8_t x = 10;
  int bit;
  for (bit = 15; bit >= 0; bit--)
    put_char(x++, y, 0, (data & (1 << bit)) ? '1' : '0');
}

void main() {
  int i;
  for (i = 0; i < 256; ++i) {
    text_line_select[i] = 0x9000 | i;
    text_line_scroll[i] = 0;
  }

  static const uint16_t palette[16] = {
    0x0120, 0x7c00, 0x7fff, 0x7fff, 0x7fff, 0x7fff, 0x7fff, 0x03ff,
    0x03ff, 0x03ff, 0x03ff, 0x7fff, 0x7fff, 0x7fff, 0x7fff, 0x7c1f,
  };
  for (i = 0; i < 16; ++i)
    text_palette[i] = palette[i];

  for (;;) {
    put_string(4, 16, 0, "Hello, Mahou Daisakusen!");
    put_string(10, 21, 0, "FEDCBA9876543210");
    put_string(5, 22, 0, "P1  :");
    put_string(5, 23, 0, "P2  :");
    put_string(5, 24, 0, "SYS :");
    put_string(5, 25, 0, "DIP1:");
    put_string(5, 26, 0, "DIP2:");
    put_string(5, 27, 0, "JMPR:");
    show_bits(22, *port_in1);
    show_bits(23, *port_in2);
    show_bits(24, *port_sys);
    show_bits(25, *port_dsw_a);
    show_bits(26, *port_dsw_b);
    show_bits(27, *port_jmpr);
  }
}
