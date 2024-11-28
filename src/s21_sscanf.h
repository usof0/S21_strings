#ifndef S21_SSCANF_H
#define S21_SSCANF_H
#include "s21_string.h"

#define BS 512

typedef enum s21_length {
  NONE_LENGTH,         // n\a - 4 byte
  LENGTH_SHORT,        // h - 2 byte
  LENGTH_LONG,         // l - 8 byte
  LENGTH_LONG_LONG,    // ll - 8 byte
  LENGTH_LONG_DOUBLE,  // L - 8 byte
} s21_length;

// %[*][ширина][длина]спецификатор.
typedef struct spec {
  void *addr;       // Address of vararg pointer
  int hasStarSpec;  // true if * is detected

  int s21_width;      // size of width
  s21_length lenght;  // size of lenght
  char skip[BS];      // array of char to skip
  char spec;          // type of specificator
  int hasErrors;      // if true - skip all of next spec
} spec;

int s21_isspace(char c);

int s21_isEmptyString(const char *src);

int parse_spec(char **fstr, spec *sp, va_list *val);

int parse_skip_char(char **fstr, spec *sp);

int parse_wigth(char **fstr, spec *sp);

int s21_isDigit(char x);

int parse_lenght(char **fstr, spec *sp);

void parse_specificator_char(char **fstr, spec *sp);

void record_values_in_arguments(spec *specificators, int spec_len, char **src,
                                int *result_count);

void skip_character(char **src, spec *sp);

void write_char(spec *specificators, char **src, int *error_flag,
                int *result_count);

void write_int(spec *sp, char **src, int *error_flag, int *result_count);

void write_float(spec *sp, char **src, int *error_flag, int *result_count);

void write_float_with_lenght(spec *sp, long double result);

int write_int_with_lenght(spec *sp, long long int x, int sign);

void detect_write_decimal_or_pointer(spec *sp, char **src, int *error_flag,
                                     int *result_count);

void write_hex_or_oct(spec *sp, char **src, int *error_flag, int *result_count,
                      int basis);

int hex_oct_check_char(char **src);

void write_unsign_with_lenght(spec *sp, unsigned long long int result);

void parse_unsigned_decimal(spec *sp, char **src, int *error_flag,
                            int *result_count);

int parse_unsigned_helper(spec *sp, char **src, char *sign);

void parse_and_write_string(spec *sp, char **src, int *result_count);
#endif