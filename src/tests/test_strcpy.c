#include "test.h"

START_TEST(strcpy_test_1) {
  char src[] = "empty_12..";
  char func1[3 + 15] = "hey ";
  char func2[3 + 15] = "hey ";

  s21_strcpy(func1, src);
  strcpy(func2, src);

  ck_assert_str_eq(func1, func2);
}
END_TEST

START_TEST(strcpy_test_2) {
  char src[] = "empty_12..";
  char func1[3 + 15] = "";
  char func2[3 + 15] = "";

  s21_strcpy(func1, src);
  strcpy(func2, src);

  ck_assert_str_eq(func1, func2);
}
END_TEST

START_TEST(strcpy_test_3) {
  char src[] = "";
  char func1[3 + 15] = "hey ";
  char func2[3 + 15] = "hey ";

  s21_strcpy(func1, src);
  strcpy(func2, src);

  ck_assert_str_eq(func1, func2);
}
END_TEST

START_TEST(strcpy_test_4) {
  char src[] = "";
  char func1[3 + 15] = "";
  char func2[3 + 15] = "";

  s21_strcpy(func1, src);
  strcpy(func2, src);

  ck_assert_str_eq(func1, func2);
}
END_TEST

START_TEST(strcpy_test_5) {
  char src[] = " bro";
  char func1[3 + 15] = "hey";
  char func2[3 + 15] = "hey";

  s21_strcpy(func1, src);
  strcpy(func2, src);

  ck_assert_str_eq(func1, func2);
}
END_TEST

START_TEST(strcpy_test_6) {
  char src[] = " 1";
  char func1[3 + 15] = "2";
  char func2[3 + 15] = "2";

  s21_strcpy(func1, src);
  strcpy(func2, src);

  ck_assert_str_eq(func1, func2);
}
END_TEST

Suite *s21_strcpy_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_strcpy\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_strcpy_core");
  tcase_add_test(tc_core, strcpy_test_1);
  tcase_add_test(tc_core, strcpy_test_2);
  tcase_add_test(tc_core, strcpy_test_3);
  tcase_add_test(tc_core, strcpy_test_4);
  tcase_add_test(tc_core, strcpy_test_5);
  tcase_add_test(tc_core, strcpy_test_6);

  suite_add_tcase(s, tc_core);
  return s;
}