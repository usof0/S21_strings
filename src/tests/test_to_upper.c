#include "test.h"

START_TEST(to_upper_test_1) {
  char s[] = "empty";
  char res[] = "EMPTY";
  char *s_upper = s21_to_upper(s);
  ck_assert_str_eq(s_upper, res);
  if (s_upper != NULL) free(s_upper);
}
END_TEST

START_TEST(to_upper_test_2) {
  char s[] = "2";
  char res[] = "2";
  char *s_upper = s21_to_upper(s);
  ck_assert_str_eq(s_upper, res);
  if (s_upper != NULL) free(s_upper);
}
END_TEST

START_TEST(to_upper_test_3) {
  char s[] = "   ";
  char res[] = "   ";
  char *s_upper = s21_to_upper(s);
  ck_assert_str_eq(s_upper, res);
  if (s_upper != NULL) free(s_upper);
}
END_TEST

START_TEST(to_upper_test_4) {
  char s[] = "$$a$";
  char res[] = "$$A$";
  char *s_upper = s21_to_upper(s);
  ck_assert_str_eq(s_upper, res);
  if (s_upper != NULL) free(s_upper);
}
END_TEST

START_TEST(to_upper_test_5) {
  char s[] = "";
  char res[] = "";
  char *s_upper = s21_to_upper(s);
  ck_assert_str_eq(s_upper, res);
  if (s_upper != NULL) free(s_upper);
}
END_TEST

START_TEST(to_upper_test_6) {
  char s[] = "EmPtY";
  char res[] = "EMPTY";
  char *s_upper = s21_to_upper(s);
  ck_assert_str_eq(s_upper, res);
  if (s_upper != NULL) free(s_upper);
}
END_TEST

Suite *s21_to_upper_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_to_upper\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_to_upper_core");
  tcase_add_test(tc_core, to_upper_test_1);
  tcase_add_test(tc_core, to_upper_test_2);
  tcase_add_test(tc_core, to_upper_test_3);
  tcase_add_test(tc_core, to_upper_test_4);
  tcase_add_test(tc_core, to_upper_test_5);
  tcase_add_test(tc_core, to_upper_test_6);

  suite_add_tcase(s, tc_core);
  return s;
}