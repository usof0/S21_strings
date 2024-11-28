#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  if (!src || !trim_chars) return s21_NULL;
  char *res = s21_NULL;
  s21_size_t src_len = s21_strlen(src);
  const char *end = src + src_len - 1;
  while (*src && s21_strchr(trim_chars, *src)) src++;
  while (end > src && s21_strchr(trim_chars, *end)) end--;
  s21_size_t res_len = end - src + 1;
  res = malloc(res_len + 1);
  res = s21_strncpy(res, src, res_len);
  *(res + res_len) = '\0';
  return (void *)res;
}