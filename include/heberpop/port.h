#if !defined(__HEBERPOP_PORT_H__)
#define __HEBERPOP_PORT_H__

#include <stdint.h>

enum {
  CTRL_RIGHT = (1 << 0),
  CTRL_LEFT  = (1 << 1),
  CTRL_DOWN  = (1 << 2),
  CTRL_UP    = (1 << 3),
  CTRL_B1    = (1 << 4),
  CTRL_B2    = (1 << 5),
  CTRL_B3    = (1 << 6),
  CTRL_VBLANK     = (1 << 7),
};
#define port_in1 (*((const volatile uint16_t* const)(0x200000)) >> 0)
#define port_in2 (*((const volatile uint16_t* const)(0x200000)) >> 8)

enum {
  SYS_COIN1    = (1 << 0),
  SYS_COIN2    = (1 << 1),
  SYS_SERVICE1 = (1 << 2),
  SYS_START1   = (1 << 3),
  SYS_START2   = (1 << 4),
};
#define port_sys ((const volatile uint16_t* const)(0x200002))

#endif  // !defined(__HEBERPOP_PORT_H__)
