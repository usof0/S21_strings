#include "test.h"

int main(void) {
  int failed = 0;
  Suite *suite[] = {
      s21_sscanf_suite(),   s21_sprintf_suite(),  s21_strcpy_suite(),
      s21_memchr_suite(),   s21_memcmp_suite(),   s21_memcpy_suite(),
      s21_memset_suite(),   s21_strncat_suite(),  s21_strchr_suite(),
      s21_strncmp_suite(),  s21_strncpy_suite(),  s21_strerror_suite(),
      s21_strcspn_suite(),  s21_strlen_suite(),   s21_strpbrk_suite(),
      s21_strchr_suite(),   s21_strstr_suite(),   s21_strtok_suite(),
      s21_to_lower_suite(), s21_to_upper_suite(), s21_trim_suite(),
      s21_insert_suite(),   s21_atoi_suite(),     s21_strspn_suite(),
      s21_strchr_suite(),   s21_strrchr_suite(),  NULL};

  for (int i = 0; suite[i] != NULL; i++) {
    SRunner *sr = srunner_create(suite[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  printf("========= FAILED: %d =========\n", failed);
  return failed == 0 ? 0 : 1;
}