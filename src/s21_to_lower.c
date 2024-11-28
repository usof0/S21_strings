#include "s21_string.h"
char *s21_to_lower(const char *str) {
  size_t len = s21_strlen(str);

  char *lowercase_str = malloc(len + 1);

  if (!lowercase_str) {
    lowercase_str = s21_NULL;
  } else {
    for (size_t i = 0; i < len; ++i) {
      if (str[i] >= 65 && str[i] <= 90) {
        lowercase_str[i] = (str[i] + 32);
      } else {
        lowercase_str[i] = str[i];
      }
    }

    lowercase_str[len] = '\0';
  }

  return lowercase_str;
}
