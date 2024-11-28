#include "test.h"

START_TEST(strpbrk_test_1) {
  char s1[] = "";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_test_2) {
  char s1[] = "empty";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_test_3) {
  char s1[] = "";
  char s2[] = "empty";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_test_4) {
  char s1[] = "empty";
  char s2[] = "e";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_test_5) {
  char s1[] = "e1mpty";
  char s2[] = "e1";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_test_6) {
  char s1[] = "e1Mpty";
  char s2[] = "eM";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_test_7) {
  char s1[] = "e1Mpty";
  char s2[] = "\0";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

Suite *s21_strpbrk_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_strpbrk\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_strpbrk_core");
  tcase_add_test(tc_core, strpbrk_test_1);
  tcase_add_test(tc_core, strpbrk_test_2);
  tcase_add_test(tc_core, strpbrk_test_3);
  tcase_add_test(tc_core, strpbrk_test_4);
  tcase_add_test(tc_core, strpbrk_test_5);
  tcase_add_test(tc_core, strpbrk_test_6);
  tcase_add_test(tc_core, strpbrk_test_7);

  suite_add_tcase(s, tc_core);
  return s;
}