#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *last_occurrence = s21_NULL;
  char ch = (char)c;

  while (*str) {
    if (*str == ch) {
      last_occurrence = str;
    }
    str++;
  }

  if (ch == '\0') {
    return (char *)str;
  }

  return (char *)last_occurrence;
}
