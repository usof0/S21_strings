#include "test.h"

START_TEST(strstr_test_1) {
  char str1[] = "";
  char str2[] = "";

  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_2) {
  char str1[] = "empty";
  char str2[] = "";

  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_3) {
  char str1[] = "";
  char str2[] = "empty";

  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_4) {
  char str1[] = "emptyemptyemptyemptyemptyempty";
  char str2[] = "empty";

  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_5) {
  char str1[] = "emptyemptY!emptyemptyemptY!empty";
  char str2[] = "emptY";

  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_6) {
  char str1[] = "EMPTY EMPTY EMPTY";
  char str2[] = "EMPTY";

  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_7) {
  char str1[] = "EMPTY EMPTY EMPTY";
  char str2[] = "EMPTY";

  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

Suite *s21_strstr_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_strstr\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_strstr_core");
  tcase_add_test(tc_core, strstr_test_1);
  tcase_add_test(tc_core, strstr_test_2);
  tcase_add_test(tc_core, strstr_test_3);
  tcase_add_test(tc_core, strstr_test_4);
  tcase_add_test(tc_core, strstr_test_5);
  tcase_add_test(tc_core, strstr_test_6);
  tcase_add_test(tc_core, strstr_test_7);

  suite_add_tcase(s, tc_core);
  return s;
}