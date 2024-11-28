#include "s21_string.h"

char *s21_strchr(const char *string, int symbol) {
  int exit = 0, i = 0, isFounded = 0;

  while (!exit) {
    if (string[i] == symbol) {
      exit = 1;
      isFounded = 1;
    } else if (string[i] == '\0') {
      exit = 1;
    } else {
      i++;
    }
  }

  return isFounded == 1 ? (char *)string + i : s21_NULL;
}