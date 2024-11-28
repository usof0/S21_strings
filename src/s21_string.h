#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#define BS 512

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define s21_NULL ((void *)0)
typedef unsigned long s21_size_t;

int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(const void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strcpy(char *destination, const char *source);
char *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
int s21_atoi(const char *str);
s21_size_t s21_strlen(const char *str);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strchr(const char *string, int symbol);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
void *s21_insert(const char *sub_str, const char *str, s21_size_t index);
void *s21_trim(const char *src, const char *trim_chars);

int s21_sprintf(char *str, const char *format, ...);
int s21_sscanf(const char *buf, const char *format, ...);

// func for strtoull
unsigned long long int s21_strtoull(char **src, int width, int base,
                                    int *error_flag);
int which_is_the_char(char x);

// func for strtold
long double s21_strtold(char **src, int *error_flag, int width);
long double s21_atof(char **src, int sign, int *width, int *error_flag);
int parse_and_atoi(char **src, int *width);
double long move_int_under_dot(int source);
double long append_counted_zeros(double long source, int count_of_zeros);
int s21_detect_inf_nan(char **src, int *error_flag, int sign, int *width);
double long s21_return_inf_nan(int inf_nan_flag);
void s21_exec_exponent(double long *result, char **src, int *error_flag,
                       int *width);
int s21_has_exponent(char src);
int detect_sign(char **src, int *width);
s21_size_t s21_strspn(const char *str, const char *spn);

int str_include_char(char str, const char *spn);
#endif
