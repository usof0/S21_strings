#ifndef C2_S21_STRINGPLUS_3_S21_SPRINTF_H
#define C2_S21_STRINGPLUS_3_S21_SPRINTF_H
#define SPECIFIERS "cdieEfgGosuxXpn%"
#define DIGITS "0123456789"

#include "s21_string.h"
#define int_to_string_wrapper(value, str)                         \
  _Generic((value),                                               \
      int: int_to_string((long long)(value), str),                \
      unsigned int: int_to_string((long long)(value), str),       \
      long: int_to_string((long long)(value), str),               \
      unsigned long: int_to_string((long long)(value), str),      \
      long long: int_to_string((long long)(value), str),          \
      unsigned long long: int_to_string((long long)(value), str), \
      short: int_to_string((long long)(value), str),              \
      unsigned short: int_to_string((long long)(value), str))

typedef struct Flags {
  char type;
  int align;
  int sign;
  int space;
  int sharp;
  int zero;
  int width;
  int accuracy;
  int width_value;
  int accuracy_value;
  int si;
  int li;
  int ld;
  int len_arg;
  int is_negative;
  int sign_printed;
} Flags;

void set_accurate(Flags *flags);
char *int_to_string(long long value, char *str);
char *float_to_string(long double value, char *str, int accuracy);
int is_specifier(char chr);
int is_digit(char chr);
void parse_flags(const char **pchr, Flags *flags, va_list args);
void fill_with_char(char **buf_ptr, char fill_char, int count);
s21_size_t get_count_zeros(Flags flags, s21_size_t str_len);
void format_string(char **buf_ptr, const char *string, s21_size_t str_len,
                   Flags *flags);
long long int get_int_arg(va_list args, Flags flags);
unsigned long long get_uint_arg(va_list args, Flags flags);
int s21_sprintf(char *str, const char *format, ...);
void process_int(long long value, Flags *flags, char *string, char **buf_ptr);
void process_float(long double value, Flags *flags, char *string,
                   char **buf_ptr);
void process_string(char **string, char **buf_ptr, Flags *flags);
#endif  // C2_S21_STRINGPLUS_3_S21_SPRINTF_H
