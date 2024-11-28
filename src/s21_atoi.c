#include "s21_string.h"

int s21_atoi(const char* str) {
  int num = 0;
  int sign = 1;
  int overflow = 0;

  while (*str == ' ') str++;

  if (*str == '-') {
    str++;
    sign = -1;
  }

  if (*str == '+') {
    str++;
  }

  while (*str && *str >= '0' && *str <= '9') {
    num = num * 10 + (*str - '0');
    if (num < 0) {
      overflow = 1;
      break;
    }
    str++;
  }
  if (overflow)
    num = sign > 0 ? __INT_MAX__ : -__INT_MAX__ - 1;
  else
    num *= sign;

  return num;
}