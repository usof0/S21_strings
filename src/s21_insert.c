#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (!src || !str) return s21_NULL;
  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);
  char *result_str = s21_NULL;
  if (start_index <= src_len) {
    result_str = (char *)malloc(src_len + str_len + 1);
    s21_strncpy(result_str, src, start_index);
    s21_strncpy(result_str + start_index, str, str_len);
    s21_strncpy(result_str + start_index + str_len, src + start_index,
                src_len - start_index);
    *(result_str + src_len + str_len) = '\0';
  }
  return result_str;
}
