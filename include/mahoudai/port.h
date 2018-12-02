#if !defined(__MAHOUDAI_PORT_H__)
#define __MAHOUDAI_PORT_H__

#include <stdint.h>

/*
 * ---- ---- ---- ---x up
 * ---- ---- ---- --x- down
 * ---- ---- ---- -x-- left
 * ---- ---- ---- x--- right
 * ---- ---- ---x ---- button 1
 * ---- ---- --x- ---- button 2
 * ---- ---- -x-- ---- button 3
 *
 * Controller inputs for player 1 and 2.
 */
#define port_in1 ((const volatile uint16_t* const)(0x21c020))
#define port_in2 ((const volatile uint16_t* const)(0x21c024))


#define port_sys ((const volatile uint16_t* const)(0x21c028))
#define port_dsw_a ((const volatile uint16_t* const)(0x21c02c))
#define port_dsw_b ((const volatile uint16_t* const)(0x21c030))
#define port_jmpr ((const volatile uint16_t* const)(0x21c034))

#endif  // !defined(__MAHOUDAI_PORT_H__)
