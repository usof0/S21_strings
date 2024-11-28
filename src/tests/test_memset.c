#include "test.h"

START_TEST(memset_test_1) {
  char res[] = "empty";
  char func[] = "empty";
  char replace = '!';
  s21_size_t n = 3;

  s21_memset(res, replace, n);
  memset(func, replace, n);

  ck_assert_str_eq(res, func);
}
END_TEST

START_TEST(memset_test_2) {
  char res[] = "empty";
  char func[] = "empty";
  char replace = '!';
  s21_size_t n = 0;

  s21_memset(res, replace, n);
  memset(func, replace, n);

  ck_assert_str_eq(res, func);
}
END_TEST

START_TEST(memset_test_3) {
  char res[] = "";
  char func[] = "";
  char replace = '\0';
  s21_size_t n = 0;

  s21_memset(res, replace, n);
  memset(func, replace, n);

  ck_assert_str_eq(res, func);
}
END_TEST

START_TEST(memset_test_4) {
  char res[] = "empty";
  char func[] = "empty";
  char replace = '1';
  s21_size_t n = 3;

  s21_memset(res, replace, n);
  memset(func, replace, n);

  ck_assert_str_eq(res, func);
}
END_TEST

START_TEST(memset_test_5) {
  char res[] = "empty";
  char func[] = "empty";
  char replace = '1';
  s21_size_t n = 4;

  s21_memset(res, replace, n);
  memset(func, replace, n);

  ck_assert_str_eq(res, func);
}
END_TEST

START_TEST(memset_test_6) {
  char res[] = "empty";
  char func[] = "empty";
  char replace = 'O';
  s21_size_t n = 2;

  s21_memset(res, replace, n);
  memset(func, replace, n);

  ck_assert_str_eq(res, func);
}
END_TEST

START_TEST(memset_test_7) {
  char res[] =
      "LJHDFGOUSJIFDUHOGUYSGBCOIVJDghuiydfrsgyuhasduigiashfdiasufjiwe8t34956237"
      "f8sduv)*(324634";
  char func[] =
      "LJHDFGOUSJIFDUHOGUYSGBCOIVJDghuiydfrsgyuhasduigiashfdiasufjiwe8t34956237"
      "f8sduv)*(324634";
  char replace = 'L';
  s21_size_t n = 7;

  s21_memset(res, replace, n);
  memset(func, replace, n);

  ck_assert_str_eq(res, func);
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_memset\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_memset_core");
  tcase_add_test(tc_core, memset_test_1);
  tcase_add_test(tc_core, memset_test_2);
  tcase_add_test(tc_core, memset_test_3);
  tcase_add_test(tc_core, memset_test_4);
  tcase_add_test(tc_core, memset_test_5);
  tcase_add_test(tc_core, memset_test_6);
  tcase_add_test(tc_core, memset_test_7);

  suite_add_tcase(s, tc_core);
  return s;
}