#if !defined(__STRING_H__)
#define __STRING_H__

#include <stdint.h>

inline void* memset(void* b, int c, uint32_t len) {
  char* dst = (char*)b;
  int i;
  for (i = 0; i < len; ++i) dst[i] = c;
}

#endif  // !defined(__STRING_H__)
