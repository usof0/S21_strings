#include "test.h"

START_TEST(memcpy_test_1) {
  char s[] = "empty";
  s21_size_t n = 6;
  char res[n + 8];
  char func[n + 8];

  s21_memcpy(res, s, n);
  memcpy(func, s, n);

  ck_assert_mem_eq(res, func, n);
}
END_TEST

START_TEST(memcpy_test_2) {
  char s[] = "empty";
  s21_size_t n = 0;
  char res[n + 8];
  char func[n + 8];

  s21_memcpy(res, s, n);
  memcpy(func, s, n);

  ck_assert_mem_eq(res, func, n);
}
END_TEST

START_TEST(memcpy_test_3) {
  char s[] = "";
  s21_size_t n = 0;
  char res[n + 8];
  char func[n + 8];

  s21_memcpy(res, s, n);
  memcpy(func, s, n);

  ck_assert_mem_eq(res, func, n);
}
END_TEST

START_TEST(memcpy_test_4) {
  char s[] = "empty";
  s21_size_t n = 0;
  char res[n + 8];
  char func[n + 8];

  s21_memcpy(res, s, n);
  memcpy(func, s, n);

  ck_assert_mem_eq(res, func, n);
}
END_TEST

START_TEST(memcpy_test_5) {
  char s[] = "12345";
  s21_size_t n = 3;
  char res[n + 8];
  char func[n + 8];

  s21_memcpy(res, s, n);
  memcpy(func, s, n);

  ck_assert_mem_eq(res, func, n);
}
END_TEST

START_TEST(memcpy_test_6) {
  char s[] = "empty";
  s21_size_t n = 1;
  char res[n + 8];
  char func[n + 8];

  s21_memcpy(res, s, n);
  memcpy(func, s, n);

  ck_assert_mem_eq(res, func, n);
}
END_TEST

START_TEST(memcpy_test_7) {
  char s[] = "Empty";
  s21_size_t n = 1;
  char res[n + 8];
  char func[n + 8];

  s21_memcpy(res, s, n);
  memcpy(func, s, n);

  ck_assert_mem_eq(res, func, n);
}
END_TEST

START_TEST(memcpy_test_8) {
  char s[] = "Empty";
  s21_size_t n = 1;
  char res[n + 8];
  char func[n + 8];

  s21_memcpy(res, s, n);
  memcpy(func, s, n);

  ck_assert_mem_eq(res, func, n);
}
END_TEST

START_TEST(memcpy_test_9) {
  char s[] = "zxcvbnm asdfghjkl qwertyuiop";
  s21_size_t n = 28;
  char res[n + 8];
  char func[n + 8];

  s21_memcpy(res, s, n);
  memcpy(func, s, n);

  ck_assert_mem_eq(res, func, n);
}
END_TEST

START_TEST(memcpy_test_10) {
  char s[] = "zxcvbnm asdfghjkl qwertyuiop ZXCVBNMASDFGHJKL QWERTYUIOP";
  s21_size_t n = 56;
  char res[n + 8];
  char func[n + 8];

  s21_memcpy(res, s, n);
  memcpy(func, s, n);

  ck_assert_mem_eq(res, func, n);
}
END_TEST

START_TEST(memcpy_test_11) {
  char s[] =
      "zxcvbnm O(&)(&()<>?:SF)|))*&^*^%#%$%^^&**(asdfghjkl qwertyuiop "
      "ZXCVBNMASDFGHJKL QWERTYUIOP";
  s21_size_t n = 56;
  char res[n + 8];
  char func[n + 8];

  s21_memcpy(res, s, n);
  memcpy(func, s, n);

  ck_assert_mem_eq(res, func, n);
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_memcpy\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_memcpy_core");
  tcase_add_test(tc_core, memcpy_test_1);
  tcase_add_test(tc_core, memcpy_test_2);
  tcase_add_test(tc_core, memcpy_test_3);
  tcase_add_test(tc_core, memcpy_test_4);
  tcase_add_test(tc_core, memcpy_test_5);
  tcase_add_test(tc_core, memcpy_test_6);
  tcase_add_test(tc_core, memcpy_test_7);
  tcase_add_test(tc_core, memcpy_test_8);
  tcase_add_test(tc_core, memcpy_test_9);
  tcase_add_test(tc_core, memcpy_test_10);
  tcase_add_test(tc_core, memcpy_test_11);

  suite_add_tcase(s, tc_core);
  return s;
};