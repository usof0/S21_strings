#include "s21_string.h"

long double s21_strtod(const char *str) {  // переписать
  long double result = 0.0;
  int sign = 1;
  int found_digits = 0;
  if (*str == '-') {
    sign = -1;
    str++;
  } else if (*str == '+')
    str++;

  while (*str >= '0' && *str <= '9') {
    found_digits = 1;
    result = result * 10.0 + (*str - '0');
    str++;
  }
  if (*str == '.') {
    str++;
    long double multiplier = 0.1;
    while (*str >= '0' && *str <= '9') {
      found_digits = 1;
      result += (*str - '0') * multiplier;
      multiplier *= 0.1;
      str++;
    }
  }
  if ((*str == 'e' || *str == 'E') && found_digits) {
    str++;
    int exp_sign = 1;
    if (*str == '-') {
      exp_sign = -1;
      str++;
    } else if (*str == '+') {
      str++;
    }
    long long int exponent = 0;
    while (*str >= '0' && *str <= '9') {
      exponent = exponent * 10 + (*str - '0');
      str++;
    }

    result *= pow(10, exp_sign * exponent);
  }
  return sign * result;
}
