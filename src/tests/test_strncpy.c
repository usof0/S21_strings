#include "test.h"

START_TEST(strncpy_test_1) {
  char src[] = "";
  char func1[] = "";
  char func2[] = "";
  s21_size_t n_byte = 0;

  s21_strncpy(func1, src, n_byte);
  strncpy(func2, src, n_byte);

  ck_assert_str_eq(func1, func2);
}
END_TEST

START_TEST(strncpy_test_2) {
  char src[] = "";
  char func1[] = "empty";
  char func2[] = "empty";
  s21_size_t n_byte = 0;

  s21_strncpy(func1, src, n_byte);
  strncpy(func2, src, n_byte);

  ck_assert_str_eq(func1, func2);
}
END_TEST

START_TEST(strncpy_test_3) {
  char src[] = "empty";
  char func1[] = "empty";
  char func2[] = "empty";
  s21_size_t n_byte = 0;

  s21_strncpy(func1, src, n_byte);
  strncpy(func2, src, n_byte);

  ck_assert_str_eq(func1, func2);
}
END_TEST

START_TEST(strncpy_test_4) {
  char src[] = "empty";
  char func1[11] = "empty";
  char func2[11] = "empty";
  s21_size_t n_byte = 6;

  s21_strncpy(func1, src, n_byte);
  strncpy(func2, src, n_byte);

  ck_assert_str_eq(func1, func2);
}
END_TEST

START_TEST(strncpy_test_5) {
  char src[] = "empty";
  char func1[7] = "empty";
  char func2[7] = "empty";
  s21_size_t n_byte = 1;

  s21_strncpy(func1, src, n_byte);
  strncpy(func2, src, n_byte);

  ck_assert_str_eq(func1, func2);
}
END_TEST

Suite *s21_strncpy_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_strncpy\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_strncpy_core");
  tcase_add_test(tc_core, strncpy_test_1);
  tcase_add_test(tc_core, strncpy_test_2);
  tcase_add_test(tc_core, strncpy_test_3);
  tcase_add_test(tc_core, strncpy_test_4);
  tcase_add_test(tc_core, strncpy_test_5);

  suite_add_tcase(s, tc_core);
  return s;
}