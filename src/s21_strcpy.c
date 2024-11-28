#include "s21_string.h"

char* s21_strcpy(char* destination, const char* source) {
  char* start = destination;

  while (*source != '\0') {
    *destination = *source;
    destination++;
    source++;
  }

  *destination = '\0';

  return start;
}