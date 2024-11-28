#include "test.h"

START_TEST(strrchr_test_1) {
  char src[] = "emptey";
  char find = 'e';

  ck_assert_pstr_eq(s21_strrchr(src, find), strrchr(src, find));
}
END_TEST

START_TEST(strrchr_test_2) {
  char src[] = "em3pt3y";
  char find = '3';

  ck_assert_pstr_eq(s21_strrchr(src, find), strrchr(src, find));
}
END_TEST

START_TEST(strrchr_test_3) {
  char src[] = "em3pYtY";
  char find = 'Y';

  ck_assert_pstr_eq(s21_strrchr(src, find), strrchr(src, find));
}
END_TEST

START_TEST(strrchr_test_4) {
  char src[] = "em3ptY";
  char find = '9';

  ck_assert_pstr_eq(s21_strrchr(src, find), strrchr(src, find));
}
END_TEST

START_TEST(strrchr_test_5) {
  char src[] = "em$3ptY";
  char find = '$';

  ck_assert_pstr_eq(s21_strrchr(src, find), strrchr(src, find));
}
END_TEST

START_TEST(strrchr_test_6) {
  char src[] = "e$m3pt$Y";
  char find = '$';

  ck_assert_pstr_eq(s21_strrchr(src, find), strrchr(src, find));
}
END_TEST

START_TEST(strrchr_test_7) {
  char src[] = "em3pt$Y";
  char find = ' ';

  ck_assert_pstr_eq(s21_strrchr(src, find), strrchr(src, find));
}
END_TEST

START_TEST(strrchr_test_8) {
  char src[] = "";
  char find = '6';

  ck_assert_pstr_eq(s21_strrchr(src, find), strrchr(src, find));
}
END_TEST

START_TEST(strrchr_test_9) {
  char src[] = "";
  char find = '\0';

  ck_assert_pstr_eq(s21_strrchr(src, find), strrchr(src, find));
}
END_TEST

START_TEST(strrchr_test_10) {
  char src[] = "EEEEEEEEEEMMMMMMMPPPPPTTTTTYYYYYYY";
  char find = 'M';

  ck_assert_pstr_eq(s21_strrchr(src, find), strrchr(src, find));
}
END_TEST

START_TEST(strrchr_test_11) {
  char src[] = "EEEEEEEEEEMMMMMMMPPPPPTTTTTYYYYYYY";
  char find = '1';

  ck_assert_pstr_eq(s21_strrchr(src, find), strrchr(src, find));
}
END_TEST

Suite *s21_strrchr_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_strrchr\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_strrchr_core");
  tcase_add_test(tc_core, strrchr_test_1);
  tcase_add_test(tc_core, strrchr_test_2);
  tcase_add_test(tc_core, strrchr_test_3);
  tcase_add_test(tc_core, strrchr_test_4);
  tcase_add_test(tc_core, strrchr_test_5);
  tcase_add_test(tc_core, strrchr_test_6);
  tcase_add_test(tc_core, strrchr_test_7);
  tcase_add_test(tc_core, strrchr_test_8);
  tcase_add_test(tc_core, strrchr_test_9);
  tcase_add_test(tc_core, strrchr_test_10);
  tcase_add_test(tc_core, strrchr_test_11);

  suite_add_tcase(s, tc_core);
  return s;
}