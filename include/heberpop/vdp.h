#if !defined(__HEBERPOP_VDP_H__)
#define __HEBERPOP_VDP_H__

#include <stdint.h>

struct vdp_command {
  uint16_t unknown_0;
  uint16_t tile;
  uint16_t dest_left;  // X x16
  uint16_t dest_top;   // (Y+1) x16
  uint16_t flags;
  uint16_t palette;
  uint16_t width;   // actual width - 1 (can be 0 or 16N-1?)
  uint16_t height;  // actual height - 1
  uint16_t src_left;  // for TILECODE
  uint16_t src_top;   // ditto
  uint16_t zoom_x;  // 0x100 = x1, 0x80 => x2
  uint16_t rotation_0;
  uint16_t rotation_1;
  uint16_t zoom_y;
  uint16_t unknown_1;
  uint16_t unknown_2;
};

#define FLAGS_FLIP_X (1 << 0)
#define FLAGS_FLIP_Y (1 << 1)
#define FLAGS_8x8TILE (1 << 2)
#define FLAGS_TILECODE (1 << 3)

#define vdp_command_queue_end ((struct vdp_command*)(0x30ffe0))
#define run_vdp_commands(addr) {*((uint16_t*)(0x360000)) = (((uint32_t)(addr) & 0xffff) >> 4); *((uint16_t*)(0x200008)) = 0;}

// 16-bits(R5G5B5X1) x 16 colors x 128 palette
struct palette {
  union {
    uint16_t code;
    struct {
      uint16_t r : 5;
      uint16_t g : 5;
      uint16_t b : 5;
      uint16_t na : 1;
    } color;
  } entry[16];
};
#define palette_table ((volatile struct palette*)(0x100000))
#define NUM_PALETTE 128
#define NUM_COLOR 16

#define SCREEN_WIDTH (24 * 16)
#define SCREEN_HEIGHT (16 * 16)

#endif  // !defined(__HEBERPOP_VDP_H__)
