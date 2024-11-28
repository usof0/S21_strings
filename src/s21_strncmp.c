#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t digit;
  int result = 0;
  for (digit = 0; *str1 && *str2 && digit < n; digit++) {
    result = *(str1++) - *(str2++);
    if (result != 0) break;
  }
  return *str1 && *str2 ? result : *str1 - *str2;
}