#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *static_str = s21_NULL;
  char *token;

  if (str != s21_NULL) {
    static_str = str;
  }

  if (static_str == s21_NULL) {
    return s21_NULL;
  }

  static_str += s21_strspn(static_str, delim);

  if (*static_str == '\0') {
    return s21_NULL;
  }

  token = static_str;
  static_str = s21_strpbrk(static_str, delim);

  if (static_str != s21_NULL) {
    *static_str = '\0';
    static_str++;
  }

  return token;
}