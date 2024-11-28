#include "s21_string.h"

s21_size_t s21_strspn(const char *str, const char *spn) {
  unsigned int res = 0;

  while (*str != '\0' && str_include_char(*str, spn)) {
    res++;
    str++;
  }

  return (size_t)res;
}
int str_include_char(char str, const char *spn) {
  int flag = 0;

  while (*spn != '\0') {
    if (*spn == str) {
      flag = 1;
      break;
    }
    spn++;
  }

  return flag;
}