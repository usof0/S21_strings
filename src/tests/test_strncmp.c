#include "test.h"

START_TEST(s21_strncmp_test) {
  char str1[] = "hella 1";
  char str2[] = "hello 3";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5) < 0, strncmp(str1, str2, 5) < 0);
  ck_assert_int_eq(s21_strncmp(str1, str2, 3) == 0,
                   strncmp(str1, str2, 3) == 0);
}
END_TEST

Suite *s21_strncmp_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_strncmp\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_strncmp_core");
  tcase_add_test(tc_core, s21_strncmp_test);

  suite_add_tcase(s, tc_core);
  return s;
}