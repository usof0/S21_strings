#include "test.h"

START_TEST(test_strspn_1) {
  char *str_1 = "abcdef012345";
  char *spn_1 = "012345";

  ck_assert_int_eq(strspn(str_1, spn_1), s21_strspn(str_1, spn_1));
}
END_TEST

START_TEST(test_strspn_2) {
  char *str_2 = "012345abcdef";
  char *spn_2 = "012345";

  ck_assert_int_eq(strspn(str_2, spn_2), s21_strspn(str_2, spn_2));
}
END_TEST

Suite *s21_strspn_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_strspn\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_strspn_core");
  tcase_add_test(tc_core, test_strspn_1);
  tcase_add_test(tc_core, test_strspn_2);
  suite_add_tcase(s, tc_core);
  return s;
};