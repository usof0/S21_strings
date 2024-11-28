#include "test.h"

START_TEST(strlen_test_1) {
  char src[] = "empty";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_test_2) {
  char src[] = "";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_test_3) {
  char src[] = "1321454";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_test_4) {
  char src[] = "g90ewrsg08sdfg98hdfgd";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_test_5) {
  char src[] = "g90ewrsg08sdf)(*#)(%#)*T()#%)(*#()g98hdfgd";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_test_6) {
  char src[] = "HEY BRO";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_test_7) {
  char src[] = "HEY\0BRO";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

Suite *s21_strlen_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_strlen\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_strlen_core");
  tcase_add_test(tc_core, strlen_test_1);
  tcase_add_test(tc_core, strlen_test_2);
  tcase_add_test(tc_core, strlen_test_3);
  tcase_add_test(tc_core, strlen_test_4);
  tcase_add_test(tc_core, strlen_test_5);
  tcase_add_test(tc_core, strlen_test_6);
  tcase_add_test(tc_core, strlen_test_7);

  suite_add_tcase(s, tc_core);
  return s;
}