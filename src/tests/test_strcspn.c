#include "test.h"

START_TEST(strcspn_test_1) {
  char src[] = "empty";
  char res[] = "empty";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_test_2) {
  char src[] = "empty";
  char res[] = "";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_test_3) {
  char src[] = "";
  char res[] = "empty";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_test_4) {
  char src[] = "";
  char res[] = "";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_test_5) {
  char src[] = "emYty";
  char res[] = "empty";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_test_6) {
  char src[] = "111";
  char res[] = "111";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_test_7) {
  char src[] = "1";
  char res[] = "111";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_test_8) {
  char src[] = "111";
  char res[] = "1";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_test_9) {
  char src[] = "1S1SF1";
  char res[] = "1F";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_test_10) {
  char src[] = "1S1SF1";
  char res[] = "SF";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_test_11) {
  char src[] = "1S1SF1";
  char res[] = "F1";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_test_12) {
  char src[] = ":LKFGDJSKLGJFPHKGJSDFOIHGJSIOTH#*(%Y)(#*&WETENGISD";
  char res[] = ":LKFGDJSKLGJFPHKGJ         SDFOIHGJSIOTH#*(%Y)(#*&WETENGISD";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_test_13) {
  char src[] =
      ":LKF2GDJSK345LGJFPHK343545G2JSDFOIHGJ23434534SIOTH2#*(%Y)(#*&WETENGISD";
  char res[] =
      ":LKFGDJS345KLGJFPHKGJ         SDFOIHGJSIOTH#*(%Y)345345(#*&WETENGISD";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_test_14) {
  char src[] =
      "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
      "A";
  char res[] =
      "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"
      "Z";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_test_15) {
  char src[] = "111111111111111111111111111111111111111111111";
  char res[] = "222222222222222222222222222222222222222222222";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

Suite *s21_strcspn_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_strcspn\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_strcspn_core");
  tcase_add_test(tc_core, strcspn_test_1);
  tcase_add_test(tc_core, strcspn_test_2);
  tcase_add_test(tc_core, strcspn_test_3);
  tcase_add_test(tc_core, strcspn_test_4);
  tcase_add_test(tc_core, strcspn_test_5);
  tcase_add_test(tc_core, strcspn_test_6);
  tcase_add_test(tc_core, strcspn_test_7);
  tcase_add_test(tc_core, strcspn_test_8);
  tcase_add_test(tc_core, strcspn_test_9);
  tcase_add_test(tc_core, strcspn_test_10);
  tcase_add_test(tc_core, strcspn_test_11);
  tcase_add_test(tc_core, strcspn_test_12);
  tcase_add_test(tc_core, strcspn_test_13);
  tcase_add_test(tc_core, strcspn_test_14);
  tcase_add_test(tc_core, strcspn_test_15);

  suite_add_tcase(s, tc_core);
  return s;
}