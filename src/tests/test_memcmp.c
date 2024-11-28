#include "test.h"

START_TEST(memcmp_test_1) {
  char s1[] = "empty";
  char s2[] = "empty";
  int n = 2;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(memcmp_test_2) {
  char s1[] = "empty";
  char s2[] = "empty";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(memcmp_test_3) {
  char s1[] = "emptY";
  char s2[] = "empty";
  int n = 5;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(memcmp_test_4) {
  char s1[] = "1";
  char s2[] = "1";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}

START_TEST(memcmp_test_5) {
  char s1[] = "3210";
  char s2[] = "3210";
  int n = 2;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}

START_TEST(memcmp_test_6) {
  char s1[] = "3";
  char s2[] = "3210";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}

START_TEST(memcmp_test_7) {
  char s1[] = "30";
  char s2[] = "3210";
  int n = 2;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}

START_TEST(memcmp_test_8) {
  char s1[] = "99999999999999999995759999999999212";
  char s2[] = "99999999999999999995759969999999212";
  int n = 35;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

Suite *s21_memcmp_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_memcmp\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_memcmp_core");
  tcase_add_test(tc_core, memcmp_test_1);
  tcase_add_test(tc_core, memcmp_test_2);
  tcase_add_test(tc_core, memcmp_test_3);
  tcase_add_test(tc_core, memcmp_test_4);
  tcase_add_test(tc_core, memcmp_test_5);
  tcase_add_test(tc_core, memcmp_test_6);
  tcase_add_test(tc_core, memcmp_test_7);
  tcase_add_test(tc_core, memcmp_test_8);
  suite_add_tcase(s, tc_core);
  return s;
};
