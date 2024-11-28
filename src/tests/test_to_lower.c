#include "test.h"

START_TEST(to_lower_test_1) {
  char s[] = "EMPTY";
  char res[] = "empty";
  char *s_res = s21_to_lower(s);
  ck_assert_str_eq(s_res, res);
  if (s_res != NULL) free(s_res);
}
END_TEST

START_TEST(to_lower_test_2) {
  char s[] = "2";
  char res[] = "2";
  char *s_res = s21_to_lower(s);
  ck_assert_str_eq(s_res, res);
  if (s_res != NULL) free(s_res);
}
END_TEST

START_TEST(to_lower_test_3) {
  char s[] = "   ";
  char res[] = "   ";
  char *s_res = s21_to_lower(s);
  ck_assert_str_eq(s_res, res);
  if (s_res != NULL) free(s_res);
}
END_TEST

START_TEST(to_lower_test_4) {
  char s[] = "$$A$";
  char res[] = "$$a$";
  char *s_res = s21_to_lower(s);
  ck_assert_str_eq(s_res, res);
  if (s_res != NULL) free(s_res);
}
END_TEST

START_TEST(to_lower_test_5) {
  char s[] = "";
  char res[] = "";
  char *s_res = s21_to_lower(s);
  ck_assert_str_eq(s_res, res);
  if (s_res != NULL) free(s_res);
}
END_TEST

START_TEST(to_lower_test_6) {
  char s[] = "EmPtY";
  char res[] = "empty";
  char *s_res = s21_to_lower(s);
  ck_assert_str_eq(s_res, res);
  if (s_res != NULL) free(s_res);
}
END_TEST

Suite *s21_to_lower_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_to_lower\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_to_lower_core");
  tcase_add_test(tc_core, to_lower_test_1);
  tcase_add_test(tc_core, to_lower_test_2);
  tcase_add_test(tc_core, to_lower_test_3);
  tcase_add_test(tc_core, to_lower_test_4);
  tcase_add_test(tc_core, to_lower_test_5);
  tcase_add_test(tc_core, to_lower_test_6);

  suite_add_tcase(s, tc_core);
  return s;
}