#include "test.h"

START_TEST(test_s21_trim_normal) {
  char *src = "   Hello World   ";
  char *trim_chars = " ";
  char *expected = "Hello World";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_leading_and_trailing) {
  char *src = "###Hello World###";
  char *trim_chars = "#";
  char *expected = "Hello World";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_all_trimmed) {
  char *src = "   ";
  char *trim_chars = " ";
  char *expected = "";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_null_src) {
  char *src = NULL;
  char *trim_chars = " ";
  ck_assert_ptr_eq(s21_trim(src, trim_chars), NULL);
}
END_TEST

START_TEST(test_s21_trim_only_trim_chars) {
  char *src = "###";
  char *trim_chars = "#";
  char *expected = "";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

Suite *s21_trim_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_trim\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_trim_core");
  tcase_add_test(tc_core, test_s21_trim_normal);
  tcase_add_test(tc_core, test_s21_trim_leading_and_trailing);
  tcase_add_test(tc_core, test_s21_trim_all_trimmed);
  tcase_add_test(tc_core, test_s21_trim_null_src);
  tcase_add_test(tc_core, test_s21_trim_only_trim_chars);

  suite_add_tcase(s, tc_core);
  return s;
}