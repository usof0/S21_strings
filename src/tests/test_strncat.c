#include "test.h"

START_TEST(strncat_test_1) {
  char src[] = "";
  char func1[] = "";
  char func2[] = "";
  s21_size_t n = 0;

  s21_strncat(func1, src, n);
  strncat(func2, src, n);

  ck_assert_mem_ge(func1, func2, n);
}
END_TEST

START_TEST(strncat_test_2) {
  char src[] = "empty";
  char func1[10] = "";
  char func2[10] = "";
  s21_size_t n = 0;

  s21_strncat(func1, src, n);
  strncat(func2, src, n);

  ck_assert_mem_ge(func1, func2, n);
}
END_TEST

START_TEST(strncat_test_3) {
  char src[] = "";
  char func1[10] = "empty";
  char func2[10] = "empty";
  s21_size_t n = 4;

  s21_strncat(func1, src, n);
  strncat(func2, src, n);

  ck_assert_mem_ge(func1, func2, n);
}
END_TEST

START_TEST(strncat_test_4) {
  char src[] = "hey";
  char func1[10] = "empty";
  char func2[10] = "empty";
  s21_size_t n = 4;

  s21_strncat(func1, src, n);
  strncat(func2, src, n);

  ck_assert_mem_ge(func1, func2, n);
}
END_TEST

START_TEST(strncat_test_5) {
  char src[] = "HEY";
  char func1[10] = "EMPTY";
  char func2[10] = "EMPTY";
  s21_size_t n = 4;

  s21_strncat(func1, src, n);
  strncat(func2, src, n);

  ck_assert_mem_ge(func1, func2, n);
}
END_TEST

START_TEST(strncat_test_6) {
  char src[] = "HEY";
  char func1[10] = "EMPTY";
  char func2[10] = "EMPTY";
  s21_size_t n = 1;

  char *res_1 = s21_strncat(func1, src, n);
  char *res_2 = strncat(func2, src, n);

  ck_assert_mem_ge(res_1, res_2, 9);
  ck_assert_mem_ge(func1, func2, n);
}
END_TEST

START_TEST(strncat_test_7) {
  char src_1[10] = "HEY";
  char src_2[10] = "HEY";
  char func1[10] = "EMPTY";
  char func2[10] = "EMPTY";

  char *res_2 = strncat(func2, src_2, 5);
  char *res_1 = s21_strncat(func1, src_1, 5);

  ck_assert_mem_ge(res_1, res_2, 5);
  ck_assert_mem_ge(func1, func2, 5);
}
END_TEST

START_TEST(strncat_test_8) {
  char src[] = "\0";
  char func1[10] = "EMPTY";
  char func2[10] = "EMPTY";
  s21_size_t n = 5;

  s21_strncat(func1, src, n);
  strncat(func2, src, n);

  ck_assert_mem_ge(func1, func2, n);
}
END_TEST

START_TEST(strncat_test_9) {
  char src[] = "HEY";
  char func1[10] = "\0";
  char func2[10] = "\0";
  s21_size_t n = 5;

  s21_strncat(func1, src, n);
  strncat(func2, src, n);

  ck_assert_mem_ge(func1, func2, n);
}
END_TEST

Suite *s21_strncat_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_strncat\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_strncat_core");
  tcase_add_test(tc_core, strncat_test_1);
  tcase_add_test(tc_core, strncat_test_2);
  tcase_add_test(tc_core, strncat_test_3);
  tcase_add_test(tc_core, strncat_test_4);
  tcase_add_test(tc_core, strncat_test_5);
  tcase_add_test(tc_core, strncat_test_6);
  tcase_add_test(tc_core, strncat_test_7);
  tcase_add_test(tc_core, strncat_test_8);
  tcase_add_test(tc_core, strncat_test_9);

  suite_add_tcase(s, tc_core);
  return s;
}