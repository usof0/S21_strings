#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t haystack_len = s21_strlen(haystack);
  s21_size_t needle_len = s21_strlen(needle);

  if (needle_len == 0) return (char *)haystack;
  if (haystack_len == 0 || needle_len > haystack_len) return s21_NULL;

  for (s21_size_t i = 0; i <= haystack_len - needle_len; i++) {
    s21_size_t j;
    for (j = 0; j < needle_len; j++) {
      if (haystack[i + j] != needle[j]) {
        break;
      }
    }
    if (j == needle_len) {
      return (char *)(haystack + i);
    }
  }
  return s21_NULL;
}