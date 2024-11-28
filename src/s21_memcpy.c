#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  const unsigned char *srcPtr = (const unsigned char *)src;
  unsigned char *destPtr = (unsigned char *)dest;

  if (srcPtr || destPtr) {
    for (s21_size_t i = 0; i < n; i++) {
      destPtr[i] = srcPtr[i];
    }
  }
  return dest == s21_NULL ? s21_NULL : dest;
}
