#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t n_src = s21_strlen(src);
  if (n > n_src) {
    n = n_src;
  }
  if (*dest || *src) {  // if (dest != null || src != null)
    s21_size_t dest_len = s21_strlen(dest);
    if (dest_len + n + 1 > s21_strlen(dest) + 1) {
      s21_strncpy(dest + dest_len, src, n);

      dest[dest_len + n] = '\0';
    }
  }
  return dest;
}
