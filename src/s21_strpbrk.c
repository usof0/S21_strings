#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  while (*str1 && !s21_strchr(str2, *str1)) str1++;
  return *str1 ? (char *)str1 : s21_NULL;
}
