#if !defined(__MAHOUDAI_TEXT_H__)
#define __MAHOUDAI_TEXT_H__

#include <stdint.h>

/*
 *          ^
 * 0x50007e |
 *    ^     | 0x50004e  0x500ece
 *    |     +---------+
 *    |     | ^       |
 * 64 tiles | | View  |
 *    |     | 40      |
 *    v     | |       |
 *  (+0x02) | +--32-->| 0x500e80
 *          +---------+--------->
 * 0x500000  <---- 64 tiles ----> 0x501f80
 *       (+0x80)
 *
 * 16-bit tile data format
 * ---- --xx xxxx xxxx = Tile number
 * xxxx xx-- ---- ---- = Palette number
 */
#define text_vram ((volatile uint16_t* const)(0x500000))

/*
 * ---- ---x xxxx xxxx = Line select for each line
 * ---x ---- ---- ---- = ?
 * x--- ---- ---- ---- = X flip for each line
 *
 * Should be initialized to be [line] = 0x9000 | line for a normal use.
 */
#define text_line_select ((volatile uint16_t* const)(0x502000))

/*
 * ---- ---x xxxx xxxx = X scroll for each line
 *
 * From -256 to 255 value, -32 is the value to start from the first tile.
 */
#define text_line_scroll ((volatile int16_t* const)(0x503000))

/*
 * -xxx xx-- ---- ---- = Blue
 * ---- --xx xxx- ---- = Green
 * ---- ---- ---x xxxx = Red
 *
 * 16 colors x 64 set palettes.
 */
#define text_palette ((volatile uint16_t* const)(0x400800))

#endif  // !defined(__MAHOUDAI_TEXT_H__)
