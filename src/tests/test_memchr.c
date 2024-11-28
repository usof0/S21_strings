#include "test.h"

START_TEST(memchr_test_1) {
  s21_size_t n_byte = 0;
  char str[10] = "";
  int fine_byte = '\0';
  ck_assert_ptr_eq(s21_memchr(str, fine_byte, n_byte),
                   memchr(str, fine_byte, n_byte));
}
END_TEST

START_TEST(memchr_test_2) {
  s21_size_t n_byte = 6;
  char str[10] = "empty";
  int fine_byte = '\0';
  ck_assert_ptr_eq(s21_memchr(str, fine_byte, n_byte),
                   memchr(str, fine_byte, n_byte));
}
END_TEST

START_TEST(memchr_test_3) {
  s21_size_t n_byte = 6;
  char str[10] = "emptY";
  int fine_byte = 'Y';
  ck_assert_ptr_eq(s21_memchr(str, fine_byte, n_byte),
                   memchr(str, fine_byte, n_byte));
}
END_TEST

START_TEST(memchr_test_4) {
  s21_size_t n_byte = 6;
  char str[10] = "Empty";
  int fine_byte = 'E';
  ck_assert_ptr_eq(s21_memchr(str, fine_byte, n_byte),
                   memchr(str, fine_byte, n_byte));
}
END_TEST

START_TEST(memchr_test_5) {
  s21_size_t n_byte = 8;
  char str[10] = "Emp66ty";
  int fine_byte = '6';
  ck_assert_ptr_eq(s21_memchr(str, fine_byte, n_byte),
                   memchr(str, fine_byte, n_byte));
}
END_TEST

START_TEST(memchr_test_6) {
  s21_size_t n_byte = 6;
  char str[10] = "empty";
  int fine_byte = 'i';
  ck_assert_ptr_eq(s21_memchr(str, fine_byte, n_byte),
                   memchr(str, fine_byte, n_byte));
}
END_TEST

START_TEST(memchr_test_7) {
  int arr[] = {1, 2, 3, 4, 5};
  s21_size_t n_byte = sizeof(int) * 5;
  int fine_byte = 5;
  ck_assert_ptr_eq(s21_memchr(arr, fine_byte, n_byte),
                   memchr(arr, fine_byte, n_byte));
}
END_TEST

START_TEST(memchr_test_8) {
  float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  s21_size_t n_byte = sizeof(float) * 5;
  float fine_byte = 5.5;
  ck_assert_ptr_eq(s21_memchr(arr, fine_byte, n_byte),
                   memchr(arr, fine_byte, n_byte));
}
END_TEST

Suite *s21_memchr_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_memchr\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_memchr_core");
  tcase_add_test(tc_core, memchr_test_1);
  tcase_add_test(tc_core, memchr_test_2);
  tcase_add_test(tc_core, memchr_test_3);
  tcase_add_test(tc_core, memchr_test_4);
  tcase_add_test(tc_core, memchr_test_5);
  tcase_add_test(tc_core, memchr_test_6);
  tcase_add_test(tc_core, memchr_test_7);
  tcase_add_test(tc_core, memchr_test_8);
  suite_add_tcase(s, tc_core);
  return s;
};