#include <stdint.h>
#include <string.h>
#include <heberpop/port.h>
#include <heberpop/vdp.h>

void initialize_palette() {
  int pal;
  int col;
  for (pal = 0; pal < NUM_PALETTE; ++pal) {
    for (col = 0; col < NUM_COLOR; ++col) {
      palette_table[pal].entry[col].code = 0;
      palette_table[pal].entry[col].color.r = col ? 31 : 0;
      palette_table[pal].entry[col].color.g = col ? 31 : 0;
      palette_table[pal].entry[col].color.b = col ? 31 : 0;
    }
  }
}

void screen_clear() {
  struct vdp_command* cmd = vdp_command_queue_end;

  int x;
  int y;
  for (int y = 0; y < (SCREEN_HEIGHT / 16); ++y) {
    for (int x = 0; x < (SCREEN_WIDTH / 16); ++x) {
      memset(cmd, 0, sizeof(struct vdp_command));
      cmd->tile = 1;
      cmd->dest_left = (x << 8);
      cmd->dest_top = ((y + 1) << 8);
      cmd->palette = 0;
      cmd->width = 15;
      cmd->height = 15;
      cmd->zoom_x = 0x100;
      cmd->zoom_y = 0x100;
      --cmd;
    }
  }
  run_vdp_commands(++cmd);
}

void screen_puts(int x, int y, const char*s) {
  struct vdp_command* cmd = vdp_command_queue_end;
  for (; *s; --cmd) {
    memset(cmd, 0, sizeof(struct vdp_command));
    cmd->tile = *s++;
    cmd->dest_left = (x++ << 7);
    cmd->dest_top = (y + 2) << 7;
    cmd->palette = 0;
    cmd->width = 7;
    cmd->height = 7;
    cmd->zoom_x = 0x100;
    cmd->zoom_y = 0x100;
  }
  run_vdp_commands(++cmd);
}

void main() {
  initialize_palette();
  screen_clear();
  screen_puts(18, 12, "HELLO, WORLD");

  for (;;) {
    char buf[9];
    buf[8] = 0;
    uint16_t last_port = 0xff;
    while (port_in1 & 0x80);
    uint16_t port = port_in1;
    uint16_t changed = last_port ^ port;
    last_port = port;
    if (!changed)
      continue;
    int i;
    for (i = 0; i < 8; ++i)
      buf[7 - i] = 1;
    screen_puts(20, 14, buf);
    for (i = 0; i < 8; ++i)
      buf[7 - i] = (port & (1 << i)) ? '1' : '0';
    screen_puts(20, 14, buf);
    uint32_t addr = 0x00080000 + ((port & 3) << 1);
    buf[0] = *(char*)addr;
  }
}
