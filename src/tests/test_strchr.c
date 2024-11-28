#include "test.h"

START_TEST(strchr_test_1) {
  char string[] = " +123456789";
  char x = '9';

  ck_assert_ptr_eq(s21_strchr(string, x), strchr(string, x));
}

START_TEST(strchr_test_2) {
  char string[] = " +123456789";
  char x = '+';

  ck_assert_ptr_eq(s21_strchr(string, x), strchr(string, x));
}

START_TEST(strchr_test_3) {
  char string[] = " +123456789";
  char x = '\0';

  ck_assert_ptr_eq(s21_strchr(string, x), strchr(string, x));
}

START_TEST(strchr_test_4) {
  char string[] = " +123456789";
  char x = 'P';

  ck_assert_ptr_eq(s21_strchr(string, x), strchr(string, x));
}

START_TEST(strchr_test_5) {
  char string[] = " +123456789";
  char x = '1';
  char y = '+';

  ck_assert_ptr_ne(s21_strchr(string, x), strchr(string, y));
}

Suite *s21_strchr_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_strchr\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_strchr_core");
  tcase_add_test(tc_core, strchr_test_1);
  tcase_add_test(tc_core, strchr_test_2);
  tcase_add_test(tc_core, strchr_test_3);
  tcase_add_test(tc_core, strchr_test_4);
  tcase_add_test(tc_core, strchr_test_5);
  suite_add_tcase(s, tc_core);
  return s;
};