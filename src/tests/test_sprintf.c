#include "test_sprintf.h"

#include "../s21_sprintf.h"

START_TEST(sprintf_test_1) {
  char s1[BUFFER];
  char s2[BUFFER];

  char *result = "Empty text: %d";
  int val = 11;
  ck_assert_int_eq(s21_sprintf(s1, result, val), sprintf(s2, result, val));
  ck_assert_str_eq(s1, s2);
}

END_TEST

START_TEST(sprintf_test_2) {
  char s1[BUFFER];
  char s2[BUFFER];

  char *result = "%.2i";
  int val = 11;
  ck_assert_int_eq(s21_sprintf(s1, result, val), sprintf(s2, result, val));
  ck_assert_str_eq(s1, s2);
}

END_TEST

START_TEST(sprintf_test_3) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *result = "%f";
  double value = 21.21;
  ck_assert_int_eq(s21_sprintf(s1, result, value), sprintf(s2, result, value));
  ck_assert_str_eq(s1, s2);
}

END_TEST

START_TEST(sprintf_test_4) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *result = "%f";
  float value = 0.71;
  ck_assert_int_eq(s21_sprintf(s1, result, value), sprintf(s2, result, value));
  ck_assert_str_eq(s1, s2);
}

END_TEST

START_TEST(sprintf_test_5) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *result = "%c";
  char value = 'b';
  ck_assert_int_eq(s21_sprintf(s1, result, value), sprintf(s2, result, value));
  ck_assert_str_eq(s1, s2);
}

END_TEST
START_TEST(sprintf_test_6) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *result = "%s";
  char *string = "My string";
  ck_assert_int_eq(s21_sprintf(s1, result, string),
                   sprintf(s2, result, string));
  ck_assert_str_eq(s1, s2);
}

END_TEST
START_TEST(sprintf_test_7) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *result = "%s";
  char *string = NULL;
  ck_assert_int_eq(s21_sprintf(s1, result, string),
                   sprintf(s2, result, string));
  ck_assert_str_eq(s1, s2);
}

END_TEST

END_TEST

START_TEST(sprintf_test_8) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *result = "%u";
  unsigned int value = 1231241231;
  ck_assert_int_eq(s21_sprintf(s1, result, value), sprintf(s2, result, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(sprintf_test_9) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *result = "%f";
  float value = -0.71;
  ck_assert_int_eq(s21_sprintf(s1, result, value), sprintf(s2, result, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(sprintf_test_10) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%-f";
  float value = -0.71;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(sprintf_test_11) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%-lf";
  float value = -0.71;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(sprintf_test_12) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%-hf";
  double value = -0.71;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(sprintf_test_13) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%10.12d";
  int value = 123;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(sprintf_test_14) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%+- 0#10.12Ld";
  int value = 123;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(sprintf_test_15) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%.*f";
  float value = 123;
  int v2 = 10;
  ck_assert_int_eq(s21_sprintf(s1, format, value, v2),
                   sprintf(s2, format, value, v2));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(sprintf_test_17) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%%";
  int value = -123;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(sprintf_test_16) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%d";
  int value = -123;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

Suite *s21_sprintf_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_sprintf\033[0m");

  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sprintf_test_1);
  tcase_add_test(tc_core, sprintf_test_2);
  tcase_add_test(tc_core, sprintf_test_3);
  tcase_add_test(tc_core, sprintf_test_4);
  tcase_add_test(tc_core, sprintf_test_5);
  tcase_add_test(tc_core, sprintf_test_6);
  tcase_add_test(tc_core, sprintf_test_7);
  tcase_add_test(tc_core, sprintf_test_8);
  tcase_add_test(tc_core, sprintf_test_9);
  tcase_add_test(tc_core, sprintf_test_10);
  tcase_add_test(tc_core, sprintf_test_11);
  tcase_add_test(tc_core, sprintf_test_12);
  tcase_add_test(tc_core, sprintf_test_13);
  tcase_add_test(tc_core, sprintf_test_14);
  tcase_add_test(tc_core, sprintf_test_15);
  tcase_add_test(tc_core, sprintf_test_16);
  tcase_add_test(tc_core, sprintf_test_17);
  suite_add_tcase(s, tc_core);
  return s;
}
