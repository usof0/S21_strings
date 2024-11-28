#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *ptr = (const unsigned char *)str;
  int flag = 0;
  if (ptr) {
    for (s21_size_t i = 0; i < n; i++) {
      if (ptr[i] == c) {
        ptr = ptr + i;
        flag = 1;
        break;
      }
    }
  }
  return flag == 1 ? (void *)(ptr) : s21_NULL;
}