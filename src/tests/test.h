#ifndef TEST_HED
#define TEST_HED

#define BUFFER 512

#ifndef CHECK_HED
#define CHECK_HED
#include <check.h>
#endif

#ifndef STRING_HED
#define STRING_HED
#include <string.h>
#endif

#ifndef SRC_S21_STRING_H_
#include "../s21_string.h"
#endif

int main();
Suite *s21_sscanf_suite(void);
Suite *s21_memchr_suite(void);
Suite *s21_memcpy_suite(void);
Suite *s21_memcmp_suite(void);
Suite *s21_memset_suite(void);
Suite *s21_strcat_suite(void);
Suite *s21_strchr_suite(void);
Suite *s21_strcmp_suite(void);
Suite *s21_strcpy_suite(void);
Suite *s21_strcspn_suite(void);
Suite *s21_strerror_suite(void);
Suite *s21_strlcat_suite(void);
Suite *s21_strlcpy_suite(void);
Suite *s21_strlen_suite(void);
Suite *s21_strncat_suite(void);
Suite *s21_strncmp_suite(void);
Suite *s21_strncpy_suite(void);
Suite *s21_strpbrk_suite(void);
Suite *s21_strrchr_suite(void);
Suite *s21_strspn_suite(void);
Suite *s21_strstr_suite(void);
Suite *s21_strtok_suite(void);
Suite *s21_to_upper_suite(void);
Suite *s21_to_lower_suite(void);
Suite *s21_insert_suite(void);
Suite *s21_trim_suite(void);
Suite *s21_sprintf_suite(void);
Suite *s21_atoi_suite(void);

#endif