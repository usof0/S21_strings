#include "s21_string.h"

unsigned long long int s21_strtoull(char **src, int width, int base,
                                    int *error_flag) {
  unsigned long long int res = 0;
  int sign = 1, stop = 0;

  if (**src == '-') {
    sign = -1;
    (*src)++;
  }

  if (**src == '0' && (*(*src + 1) == 'x' || *(*src + 1) == 'X')) {
    if (base == 16) {
      *src += 2;
    } else {
      *error_flag = 1;
    }
  }

  long long val = 0;
  char dictionary[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  while (which_is_the_char(**src) >= 1 && stop == 0) {
    char x = 0;

    if (which_is_the_char(**src) == 1) {  // если пришла маленькая буква
      x = **src - 32;
    } else if (which_is_the_char(**src) >= 2) {
      x = **src;
    } else {
      *error_flag = 1;
    }

    char *pos = s21_strchr(dictionary, (int)x);
    if (pos == s21_NULL || (pos - dictionary) > base) *error_flag = 1;

    val = pos - dictionary;
    res = res * base + val;
    (*src)++;
    width--;
    if (width == 0) stop = 1;
  }

  return res * sign;
}

// return 1 if 'a' - 'z'
// return 2 if 'A' - 'Z'
// return 3 if '0' - '9'
// return -1 if something else
int which_is_the_char(char x) {
  int flag = -1;

  if (x >= 'a' && x <= 'z') {
    flag = 1;
  } else if (x >= 'A' && x <= 'Z') {
    flag = 2;
  } else if (x >= '0' && x <= '9') {
    flag = 3;
  }

  return flag;
}