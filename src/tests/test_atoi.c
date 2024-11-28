#include "test.h"

START_TEST(atoi_test_1) {
  char s[] = " +123456789";
  ck_assert_int_eq(s21_atoi(s), atoi(s));
}

START_TEST(atoi_test_2) {
  char s[] = " 1234hah56789";
  ck_assert_int_eq(s21_atoi(s), atoi(s));
}

START_TEST(atoi_test_3) {
  char s[] = "-123456789";
  ck_assert_int_eq(s21_atoi(s), atoi(s));
}

Suite *s21_atoi_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_atoi\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_atoi_core");
  tcase_add_test(tc_core, atoi_test_1);
  tcase_add_test(tc_core, atoi_test_2);
  tcase_add_test(tc_core, atoi_test_3);
  suite_add_tcase(s, tc_core);
  return s;
};