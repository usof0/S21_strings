#include "test.h"

START_TEST(strerror_test_1) {
  for (int i = 0; i < 40; i++) {
    char *s21_error = s21_strerror(i);
    char *std_error = strerror(i);
    ck_assert_str_eq(s21_error, std_error);
  }
}
END_TEST

Suite *s21_strerror_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_strerror\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_strerror_core");
  tcase_add_test(tc_core, strerror_test_1);
  suite_add_tcase(s, tc_core);
  return s;
}