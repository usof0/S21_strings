#include "test.h"

START_TEST(s21_strtok_test) {
  char str_strtok1[] = "one/two/three(four)five";
  char delim1[] = "/()";

  char str_strtok2[] = "one/two/three(four)five";
  char delim2[] = "/()";
  char *my_strtok = s21_strtok(str_strtok1, delim1);
  char *origin_strtok = strtok(str_strtok2, delim2);
  while (my_strtok != s21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(s21_NULL, delim1);
    origin_strtok = strtok(s21_NULL, delim2);
  }
}
END_TEST

Suite *s21_strtok_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_strtok\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_strtok_core");
  tcase_add_test(tc_core, s21_strtok_test);

  suite_add_tcase(s, tc_core);
  return s;
}