#include "test.h"

START_TEST(sscanf_test_char_1) {
  char *src = "a b c d";
  char *format = "%c %c %c %c";
  char a1 = 'f', a2 = 'f', a3 = 'f', a4 = 'f';
  char b1 = 'f', b2 = 'f', b3 = 'f', b4 = 'f';

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3, &a4);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3, &b4);

  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_char_2) {
  char *src = "a b c-d";
  char *format = "%c %c-%c%c";
  char a1 = 'f', a2 = 'f', a3 = 'f', a4 = 'f';
  char b1 = 'f', b2 = 'f', b3 = 'f', b4 = 'f';

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3, &a4);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3, &b4);

  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_char_3) {
  char *src = "a b c d e";
  char *format = "%c %*c %c %c %c";
  char a1 = 'f', a2 = 'f', a3 = 'f', a4 = 'f';
  char b1 = 'f', b2 = 'f', b3 = 'f', b4 = 'f';

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3, &a4);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3, &b4);

  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_char_4) {
  char *src = "a b c d e";
  char *format = "%*c %1c %c %c %c";
  char a1 = 'f', a2 = 'f', a3 = 'f', a4 = 'f';
  char b1 = 'f', b2 = 'f', b3 = 'f', b4 = 'f';

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3, &a4);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3, &b4);

  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_char_5) {
  char *src = "a b c d e";
  char *format = "%*c %c %c %c %c";
  char a1 = 'f', a2 = 'f', a3 = 'f', a4 = 'f';
  char b1 = 'f', b2 = 'f', b3 = 'f', b4 = 'f';

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3, &a4);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3, &b4);

  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_decimal_1) {
  char *src = "1 -2 +3 -4";
  char *format = "%d %d %d %d";
  int a[] = {0, 0, 0, 0};
  int b[] = {0, 0, 0, 0};

  int32_t vr_a = s21_sscanf(src, format, &a[0], &a[1], &a[2], &a[3]);
  int32_t vr_b = sscanf(src, format, &b[0], &b[1], &b[2], &b[3]);

  ck_assert_int_eq(a[0], b[0]);
  ck_assert_int_eq(a[1], b[1]);
  ck_assert_int_eq(a[2], b[2]);
  ck_assert_int_eq(a[3], b[3]);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_decimal_2) {
  char *src = "1 -2 +3 -4";
  char *format = "%hd %d %ld %lld";

  short int a1 = 0, b1 = 0;
  int a2 = 0, b2 = 0;
  long int a3 = 0, b3 = 0;
  long long int a4 = 0, b4 = 0;

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3, &a4);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3, &b4);

  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_decimal_3) {
  char *src = "23 228 1337 04112000";
  char *format = "%1d %2d %3d %4d";

  int a[] = {0, 0, 0, 0};
  int b[] = {0, 0, 0, 0};

  int32_t vr_a = s21_sscanf(src, format, &a[0], &a[1], &a[2], &a[3]);
  int32_t vr_b = sscanf(src, format, &b[0], &b[1], &b[2], &b[3]);

  ck_assert_int_eq(a[0], b[0]);
  ck_assert_int_eq(a[1], b[1]);
  ck_assert_int_eq(a[2], b[2]);
  ck_assert_int_eq(a[3], b[3]);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_unspec_1) {
  char *src = "12345 +12345 -12345 12345";
  char *format = "%i %i %i %i";

  long long a1 = 0, a2 = 0, a3 = 0, a4 = 0;
  long long b1 = 0, b2 = 0, b3 = 0, b4 = 0;

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3, &a4);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3, &b4);

  ck_assert_int_eq(b1, a1);
  ck_assert_int_eq(b2, a2);
  ck_assert_int_eq(b3, a3);
  ck_assert_int_eq(b4, a4);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_unspec_2) {
  char *src = "0x4 0x43 0xFAFA";
  char *format = "%i %i %i";

  long long a1 = 0, a2 = 0, a3 = 0;
  long long b1 = 0, b2 = 0, b3 = 0;

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3);

  ck_assert_int_eq(b1, a1);
  ck_assert_int_eq(b2, a2);
  ck_assert_int_eq(b3, a3);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_unspec_3) {
  char *src = "012345 07777 0227";
  char *format = "%i %i %i";

  long long a1 = 0, a2 = 0, a3 = 0;
  long long b1 = 0, b2 = 0, b3 = 0;

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3);

  ck_assert_int_eq(b1, a1);
  ck_assert_int_eq(b2, a2);
  ck_assert_int_eq(b3, a3);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_unspec_4) {
  char *src = "0x4 0x43 0xFAFA";
  char *format = "%i %i %i";

  long long a1 = 0, a2 = 0, a3 = 0;
  long long b1 = 0, b2 = 0, b3 = 0;

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3);

  ck_assert_int_eq(b1, a1);
  ck_assert_int_eq(b2, a2);
  ck_assert_int_eq(b3, a3);

  ck_assert_int_eq(vr_a, vr_b);
}

// [%p]
START_TEST(sscanf_test_pointer_1) {
  char *src = "0x4 0x43 0xFAFA";
  char *format = "%p %p %p";

  int *a1 = 0, *a2 = 0, *a3 = 0;
  int *b1 = 0, *b2 = 0, *b3 = 0;

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3);

  ck_assert_ptr_eq(b1, a1);
  ck_assert_ptr_eq(b2, a2);
  ck_assert_ptr_eq(b3, a3);

  ck_assert_int_eq(vr_a, vr_b);
}

// [%x %X]
START_TEST(sscanf_test_hex_1) {
  char *src = "0xFFFF 0XAAAA 0x7123";
  char *format = "%x %X %x";

  long long a1 = 0, a2 = 0, a3 = 0;
  long long b1 = 0, b2 = 0, b3 = 0;

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3);

  ck_assert_int_eq(b1, a1);
  ck_assert_int_eq(b2, a2);
  ck_assert_int_eq(b3, a3);

  ck_assert_int_eq(vr_a, vr_b);
}

// [%x %X]
START_TEST(sscanf_test_hex_2) {
  char *src = "0xFFFF 0XAAAA 0x7123";
  char *format = "%*X %x %i %x";

  long long a1 = 0, a2 = 0, a3 = 0, a4 = 0;
  long long b1 = 0, b2 = 0, b3 = 0, b4 = 0;

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3);

  ck_assert_uint_eq(b1, a1);
  ck_assert_uint_eq(b2, a2);
  ck_assert_uint_eq(b3, a3);
  ck_assert_uint_eq(b4, a4);

  ck_assert_int_eq(vr_a, vr_b);
}

// [%u]
// define var > int to %u is undefined behaviour
// atoi return int value which cannot be large than int
START_TEST(sscanf_test_unsigned_dec_1) {
  char *src = "-1234 1234567890 228 0556677";
  char *format = "%5u %lu %*u %3u";

  unsigned long a1 = 0, a2 = 0, a3 = 0;
  unsigned long b1 = 0, b2 = 0, b3 = 0;

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3);

  ck_assert_uint_eq(b1, a1);
  ck_assert_uint_eq(b2, a2);
  ck_assert_uint_eq(b3, a3);

  ck_assert_int_eq(vr_a, vr_b);
}

// [%o]
START_TEST(sscanf_test_octal_1) {
  char *src = "012345 0123";
  char *format = "%o %o";

  unsigned long a1 = 0, a2 = 0;
  unsigned long b1 = 0, b2 = 0;

  int32_t vr_b = sscanf(src, format, &b1, &b2);
  int32_t vr_a = s21_sscanf(src, format, &a1, &a2);

  ck_assert_uint_eq(b1, a1);
  ck_assert_uint_eq(b2, a2);

  ck_assert_int_eq(vr_a, vr_b);
}

// [%f %G %g]
// inf - ck_assert_ldouble_eq(a1, a2);
// nan - ck_assert_float_nan(c1);
// float 1.31e+4 - ck_assert_double_eq(b1, b2);
// float 53.1 - ck_assert_float_eq(a1, a2);
// long double - ck_assert_double_eq
START_TEST(sscanf_test_float_1) {
  char src[] = "53.00043 -4.1135 +2.0001 -inf inf nan";
  char format[] = "%f %f %f %f %f %f";

  float a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0;
  float b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0;

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3, &a4, &a5, &a6);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3, &b4, &b5, &b6);

  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_ldouble_eq(a5, b5);
  ck_assert_float_nan(a6);
  ck_assert_float_nan(b6);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_float_2) {
  char src[] = "53.00043 -4.1135 +2.0001 -inf inf nan";
  char format[] = "%lg %lg %lg %lg %lg %lg";

  double a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0;
  double b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0;

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3, &a4, &a5, &a6);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3, &b4, &b5, &b6);

  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_ldouble_eq(a5, b5);
  ck_assert_double_nan(a6);
  ck_assert_double_nan(b6);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_float_3) {
  char src[] = "53.00043 -4.1135 +2.0001 -inf inf nan";
  char format[] = "%LG %LG %LG %LG %LG %LG";

  long double a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0;
  long double b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0;

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3, &a4, &a5, &a6);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3, &b4, &b5, &b6);

  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_ldouble_eq(a5, b5);
  ck_assert_double_nan(a6);
  ck_assert_double_nan(b6);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_float_4) {
  char src[] =
      "iNf           -INF                   -0.1111         INF1e-10         "
      "nAN";
  char format[] = "%G %G %G %G %G %G";

  float a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0;
  float b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0;

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3, &a4, &a5, &a6);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3, &b4, &b5, &b6);

  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_double_eq(a5, b5);
  ck_assert_double_nan(a6);
  ck_assert_double_nan(b6);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_float_5) {
  char src[] = "53.414      53.424e-2   53.434he-2    53.444eh-2";
  char format[] = "%4G %f   %9G         %8f  %f       %G";

  float a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0;
  float b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0;

  int32_t vr_a = s21_sscanf(src, format, &a1, &a2, &a3, &a4, &a5, &a6);
  int32_t vr_b = sscanf(src, format, &b1, &b2, &b3, &b4, &b5, &b6);

  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_float_eq(a5, b5);
  ck_assert_float_eq(a6, b6);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_string_1) {
  char *src = "hello,world!";
  char *format = "%s";
  char buff_a[BS] = {0};
  char buff_b[BS] = {0};

  int32_t vr_a = sscanf(src, format, buff_a);
  int32_t vr_b = s21_sscanf(src, format, buff_b);

  ck_assert_str_eq(buff_a, buff_b);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_string_2) {
  char *src = "hello, world!";
  char *format = "%6s %s";
  char buff_a1[BS] = {0};
  char buff_a2[BS] = {0};

  char buff_b1[BS] = {0};
  char buff_b2[BS] = {0};

  int32_t vr_a = sscanf(src, format, buff_a1, buff_a2);
  int32_t vr_b = s21_sscanf(src, format, buff_b1, buff_b2);

  ck_assert_str_eq(buff_a1, buff_b1);
  ck_assert_str_eq(buff_a2, buff_b2);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_string_3) {
  char *src = "hello,-world!";
  char *format = "%6s-%s";
  char buff_a1[BS] = {0};
  char buff_a2[BS] = {0};

  char buff_b1[BS] = {0};
  char buff_b2[BS] = {0};

  int32_t vr_a = sscanf(src, format, buff_a1, buff_a2);
  int32_t vr_b = s21_sscanf(src, format, buff_b1, buff_b2);

  ck_assert_str_eq(buff_a1, buff_b1);
  ck_assert_str_eq(buff_a2, buff_b2);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_test_num_1) {
  char *src = "50 60 70 80";
  char *format = "%lli %lli %n %lli %lli";
  long long a1 = 0, b1 = 0, c1 = 0, d1 = 0;
  long long a2 = 0, b2 = 0, c2 = 0, d2 = 0;
  int n1 = 0, n2 = 5;

  int32_t vr_a = s21_sscanf(src, format, &a1, &b1, &n1, &c1, &d1);
  int32_t vr_b = sscanf(src, format, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);

  ck_assert_int_eq(n1, n2);

  ck_assert_int_eq(vr_a, vr_b);
}

START_TEST(sscanf_strtoull_1) {
  char *src = "10000";
  int32_t error_flag = 0, width = 0;
  unsigned long long expected = 10000;

  if (width == 0) {
    width = s21_strlen(src);
  }

  unsigned long long test = s21_strtoull(&src, 7, 10, (int *)&error_flag);

  ck_assert_uint_eq(test, expected);
  ck_assert_int_eq(error_flag, 0);
}

START_TEST(sscanf_strtoull_2) {
  char *src = "012345";
  int32_t error_flag = 0, width = 0;
  unsigned long long expected = 012345;

  if (width == 0) {
    width = s21_strlen(src);
  }

  unsigned long long test = s21_strtoull(&src, 7, 8, (int *)&error_flag);

  ck_assert_uint_eq(test, expected);
  ck_assert_int_eq(error_flag, 0);
}

START_TEST(sscanf_strtoull_3) {
  char *src = "0xfF";
  int32_t error_flag = 0, width = 0;
  unsigned long long expected = 0xFF;

  if (width == 0) {
    width = s21_strlen(src);
  }

  unsigned long long test = s21_strtoull(&src, 5, 16, (int *)&error_flag);

  ck_assert_uint_eq(test, expected);
  ck_assert_int_eq(error_flag, 0);
}

START_TEST(sscanf_strtoull_4) {
  char *src = "0XFF";
  int32_t error_flag = 0, width = 0;
  unsigned long long expected = 0xFF;

  if (width == 0) {
    width = s21_strlen(src);
  }

  unsigned long long test = s21_strtoull(&src, 5, 16, (int *)&error_flag);

  ck_assert_uint_eq(test, expected);
  ck_assert_int_eq(error_flag, 0);
}

START_TEST(sscanf_strtoull_5) {
  char *src = "-10000";
  int32_t error_flag = 0, width = 0;
  unsigned long long expected = -10000;

  if (width == 0) {
    width = s21_strlen(src);
  }

  unsigned long long test = s21_strtoull(&src, 7, 10, (int *)&error_flag);

  ck_assert_uint_eq(test, expected);
  ck_assert_int_eq(error_flag, 0);
}

START_TEST(sscanf_strtold_1) {
  char *src_1 = "0.00014";
  char *src_2 = "1.4E-4";
  int32_t error_flag = 0, width = 0;

  double long test_b1 = strtold(src_1, s21_NULL);
  double long test_b2 = strtold(src_2, s21_NULL);

  double long test_a1 = s21_strtold(&src_1, (int *)&error_flag, width);
  double long test_a2 = s21_strtold(&src_2, (int *)&error_flag, width);

  ck_assert_double_eq(test_b1, test_a1);
  ck_assert_double_eq(test_b2, test_a2);
  ck_assert_int_eq(error_flag, 0);
}

START_TEST(sscanf_strtold_2) {
  char *src_1 = "-0.00014";
  char *src_2 = "-1.4E-4";
  int32_t error_flag = 0, width = 0;

  double long test_b1 = strtold(src_1, s21_NULL);
  double long test_b2 = strtold(src_2, s21_NULL);

  double long test_a1 = s21_strtold(&src_1, (int *)&error_flag, width);
  double long test_a2 = s21_strtold(&src_2, (int *)&error_flag, width);

  ck_assert_double_eq(test_b1, test_a1);
  ck_assert_double_eq(test_b2, test_a2);
  ck_assert_int_eq(error_flag, 0);
}

START_TEST(sscanf_strtold_3) {
  char *src = "-0.00014 -1.4E-4";
  int32_t error_flag = 0, width = 0;

  double long test_b1 = strtold(src, s21_NULL);
  double long test_b2 = strtold(src + 9, s21_NULL);

  double long test_a1 = s21_strtold(&src, (int *)&error_flag, width);
  src++;
  double long test_a2 = s21_strtold(&src, (int *)&error_flag, width);

  ck_assert_double_eq(test_b1, test_a1);
  ck_assert_double_eq(test_b2, test_a2);
  ck_assert_int_eq(error_flag, 0);
}

START_TEST(sscanf_strtold_4) {
  char *src_1 = "53.444eh-5";
  char *src_2 = "53.444e-h5";
  int32_t error_flag = 0, width = 0;

  double long test_b1 = strtold(src_1, s21_NULL);
  double long test_b2 = strtold(src_2, s21_NULL);

  double long test_a1 = s21_strtold(&src_1, (int *)&error_flag, width);
  ck_assert_int_eq(error_flag, 1);
  error_flag = 0;

  double long test_a2 = s21_strtold(&src_2, (int *)&error_flag, width);

  ck_assert_double_eq(test_b1, test_a1);
  ck_assert_double_eq(test_b2, test_a2);
  ck_assert_int_eq(error_flag, 1);
}

START_TEST(sscanf_strtold_5) {
  char *src = "53.4435";
  char *src_2 = "53.";
  int32_t error_flag = 0, width = 3;

  double long test_b1 =
      strtold(src_2, s21_NULL);  // TODO переделать под S21_s21_NULL
  double long test_a1 = s21_strtold(&src, (int *)&error_flag, width);

  ck_assert_double_eq(test_b1, test_a1);
  ck_assert_int_eq(error_flag, 0);
}

Suite *s21_sscanf_suite(void) {
  Suite *s;
  s = suite_create("\033[33ms21_sscanf\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("s21_sscanf_core");
  tcase_add_test(tc_core, sscanf_test_char_1);
  tcase_add_test(tc_core, sscanf_test_char_2);
  tcase_add_test(tc_core, sscanf_test_char_3);
  tcase_add_test(tc_core, sscanf_test_char_4);
  tcase_add_test(tc_core, sscanf_test_char_5);

  tcase_add_test(tc_core, sscanf_test_decimal_1);
  tcase_add_test(tc_core, sscanf_test_decimal_2);
  tcase_add_test(tc_core, sscanf_test_decimal_3);

  tcase_add_test(tc_core, sscanf_test_unspec_1);
  tcase_add_test(tc_core, sscanf_test_unspec_2);
  tcase_add_test(tc_core, sscanf_test_unspec_3);
  tcase_add_test(tc_core, sscanf_test_unspec_4);

  tcase_add_test(tc_core, sscanf_test_pointer_1);

  tcase_add_test(tc_core, sscanf_test_hex_1);
  tcase_add_test(tc_core, sscanf_test_hex_2);

  tcase_add_test(tc_core, sscanf_test_unsigned_dec_1);

  tcase_add_test(tc_core, sscanf_test_octal_1);

  tcase_add_test(tc_core, sscanf_test_float_1);
  tcase_add_test(tc_core, sscanf_test_float_2);
  tcase_add_test(tc_core, sscanf_test_float_3);
  tcase_add_test(tc_core, sscanf_test_float_4);
  tcase_add_test(tc_core, sscanf_test_float_5);

  tcase_add_test(tc_core, sscanf_test_string_1);
  tcase_add_test(tc_core, sscanf_test_string_2);
  tcase_add_test(tc_core, sscanf_test_string_3);

  tcase_add_test(tc_core, sscanf_test_num_1);

  tcase_add_test(tc_core, sscanf_strtoull_1);
  tcase_add_test(tc_core, sscanf_strtoull_2);
  tcase_add_test(tc_core, sscanf_strtoull_3);
  tcase_add_test(tc_core, sscanf_strtoull_4);
  tcase_add_test(tc_core, sscanf_strtoull_5);

  tcase_add_test(tc_core, sscanf_strtold_1);
  tcase_add_test(tc_core, sscanf_strtold_2);
  tcase_add_test(tc_core, sscanf_strtold_3);
  tcase_add_test(tc_core, sscanf_strtold_4);
  tcase_add_test(tc_core, sscanf_strtold_5);

  suite_add_tcase(s, tc_core);
  return s;
}