#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  const char *p = format;
  char *buf_ptr = str;
  Flags flags;
  char *string = s21_NULL;
  while (*p) {
    if (*p == '%') {
      p++;
      parse_flags(&p, &flags, args);
      if (*p == '%')
        *buf_ptr++ = '%';
      else if (flags.type == 'd' || flags.type == 'i') {
        long long value = get_int_arg(args, flags);
        process_int(value, &flags, string, &buf_ptr);
      } else if (flags.type == 'f') {
        long double value =
            (flags.ld) ? va_arg(args, long double) : va_arg(args, double);
        process_float(value, &flags, string, &buf_ptr);
      } else if (flags.type == 'u') {
        unsigned long long value = get_uint_arg(args, flags);
        string = int_to_string_wrapper(value, string);
        if (string != s21_NULL) {
          format_string(&buf_ptr, string, s21_strlen(string), &flags);
          free(string);
        }
      } else if (flags.type == 'c') {
        char chr[1] = {va_arg(args, int)};
        format_string(&buf_ptr, chr, 1, &flags);
      } else if (flags.type == 's') {
        string = va_arg(args, char *);
        process_string(&string, &buf_ptr, &flags);
      }
    } else {
      *buf_ptr++ = *p;
    }
    p++;
  }
  *buf_ptr = '\0';
  va_end(args);
  return buf_ptr - str;
}

void clear_flags(Flags *flags) {
  flags->type = 0;
  flags->align = 0;
  flags->sign = 0;
  flags->space = 0;
  flags->sharp = 0;
  flags->zero = 0;
  flags->width = 0;
  flags->accuracy = 0;
  flags->width_value = 0;
  flags->accuracy_value = -1;
  flags->si = 0;
  flags->li = 0;
  flags->ld = 0;
  flags->len_arg = 0;
  flags->is_negative = 0;
  flags->sign_printed = 0;
}

void set_accurate(Flags *flags) {
  if (flags->accuracy_value == -1) {
    s21_strchr("diouxX", flags->type) ? flags->accuracy_value = 1 : 0;  // TODO
    s21_strchr("eEfgG", flags->type) ? flags->accuracy_value = 6 : 0;
    s21_strchr("p", flags->type) ? flags->accuracy_value = 16 : 0;
  }
}

char *int_to_string(long long value, char *str) {
  int i = 0;
  int capacity = 1;
  str = realloc(str, capacity);
  if (str != s21_NULL) {
    do {
      str = realloc(str, capacity + 1);
      str[i] = (char)((value % 10) + '0');
      value /= 10;
      i++;
      capacity++;
    } while (value > 0);
    str = realloc(str, capacity + 1);
    str[i] = '\0';
    int start = 0;
    int end = i - 1;
    while (start < end) {
      char temp = str[start];
      str[start] = str[end];
      str[end] = temp;
      start++;
      end--;
    }
  }
  return str;
}

char *float_to_string(long double value, char *str, int accuracy) {
  if (value < 0) {
    value = -value;
  }
  long long int_part = (long long)value;
  long double frac_part = value - int_part;
  str = int_to_string(int_part, str);
  if (str != s21_NULL) {
    s21_size_t int_str_len = s21_strlen(str);
    str = realloc(str, int_str_len + 2);
    if (str != s21_NULL) {
      str[int_str_len] = '.';
      s21_size_t index = int_str_len + 1;

      for (int i = 0; i < accuracy; i++) {
        frac_part *= 10;
        int digit = (int)frac_part;
        str = realloc(str, index + 2);
        str[index++] = '0' + digit;
        frac_part -= digit;
      }
      str[index] = '\0';
      if (frac_part >= 0.5) {
        for (int i = index - 1; i >= 0; --i) {
          if (str[i] == '.') {
            continue;
          }
          if (str[i] < '9') {
            str[i]++;
            break;
          } else {
            str[i] = '0';
          }
        }
      }
    }
  }
  return str;
}

int is_specifier(char chr) { return s21_strchr(SPECIFIERS, chr) != s21_NULL; }

int is_digit(char chr) { return s21_strchr(DIGITS, chr) != s21_NULL; }

int parse_int(const char **pchr) {
  int result = 0;
  while (is_digit(**pchr)) {
    result = result * 10 + (**pchr - '0');
    (*pchr)++;
  }
  return result;
}

void parse_flags(const char **pchr, Flags *flags, va_list args) {
  clear_flags(flags);
  while (**pchr) {
    char chr = **pchr;
    if (chr == '-')
      flags->align = 1;
    else if (chr == '+')
      flags->sign = 1;
    else if (chr == ' ')
      flags->space = 1;
    else if (chr == '#')
      flags->sharp = 1;
    else if (chr == '0')
      flags->zero = 1;
    else if (chr == 'L')
      flags->ld = 1;
    else if (chr == 'l')
      flags->li = 1;
    else if (chr == 'h')
      flags->si = 1;
    else if (is_digit(chr) || chr == '*') {
      flags->width = 1;
      if (**pchr == '*') {
        flags->width_value = va_arg(args, int);
        (*pchr)++;
      } else {
        flags->width_value = parse_int(pchr);
      }
      continue;
    } else if (chr == '.') {
      *pchr += 1;
      flags->accuracy = 1;
      if (**pchr == '*') {
        flags->accuracy_value = va_arg(args, int);
        (*pchr)++;
      } else if (is_digit(**pchr)) {
        flags->accuracy_value = parse_int(pchr);
      } else {
        flags->accuracy = -1;
      }
      continue;
    } else if (is_specifier(chr)) {
      flags->type = chr;
      break;
    }
    (*pchr)++;
  }
  if (flags->align && flags->zero) flags->zero = 0;
  if (flags->sign && flags->space) flags->space = 0;
  set_accurate(flags);
}

void fill_with_char(char **buf_ptr, char fill_char, int count) {
  while (count > 0) {
    **buf_ptr = fill_char;
    (*buf_ptr)++;
    count--;
  }
}

s21_size_t get_count_zeros(Flags flags, s21_size_t str_len) {
  s21_size_t count_zeros = 0;
  if (flags.accuracy && str_len < (s21_size_t)flags.accuracy_value) {
    count_zeros = flags.accuracy_value - str_len;
  }
  return count_zeros;
}

void format_string(char **buf_ptr, const char *string, s21_size_t str_len,
                   Flags *flags) {
  char fill_char = ' ';
  s21_size_t count_zeros = 0;
  if (s21_strchr("idouxX", flags->type) != s21_NULL) {  // TODO
    fill_char = (flags->width && !flags->align && !flags->accuracy) ? '0' : ' ';
    count_zeros = get_count_zeros(*flags, str_len);
  }
  if (s21_strchr("eEf", flags->type) != s21_NULL) {  // TODO
    fill_char = (flags->width && !flags->align && !flags->accuracy) ? '0' : ' ';
    if (flags->zero && flags->sign) {
      **buf_ptr = (flags->is_negative) ? '-' : '+';
      (*buf_ptr)++;
      flags->sign_printed = 1;
    }

    count_zeros = get_count_zeros(*flags, str_len);
  }
  if (flags->accuracy && str_len > (s21_size_t)flags->accuracy_value &&
      flags->type == 's') {
    str_len = flags->accuracy_value;
  }
  if (flags->width && !flags->align) {
    fill_with_char(buf_ptr, fill_char,
                   flags->width_value - str_len - count_zeros);
  }

  if (flags->sign && !flags->is_negative && flags->type != 'u' &&
      !flags->zero && !flags->sign_printed) {
    **buf_ptr = '+';
    (*buf_ptr)++;
    flags->len_arg++;
    if (flags->width) flags->width_value--;
  } else if (flags->space) {
    **buf_ptr = ' ';
    (*buf_ptr)++;
    flags->len_arg++;
    if (flags->width) flags->width_value--;
  } else if (flags->width && !flags->align && flags->type == 'f' &&
             flags->is_negative && !flags->sign_printed) {
    **buf_ptr = '-';
    (*buf_ptr)++;
  }
  fill_with_char(buf_ptr, '0', count_zeros);
  for (s21_size_t i = 0; i < str_len; i++) {
    **buf_ptr = *string++;
    (*buf_ptr)++;
  }
  if (flags->width && flags->align) {
    fill_with_char(buf_ptr, fill_char,
                   flags->width_value - str_len - count_zeros);
  }
}

long long int get_int_arg(va_list args, Flags flags) {
  long long value;
  if (flags.li || flags.si) {
    value = va_arg(args, long);
    if (flags.si) {
      value = (short)va_arg(args, int);
    }
  } else
    value = va_arg(args, int);
  return value;
}

unsigned long long get_uint_arg(va_list args, Flags flags) {
  unsigned long long value;
  if (flags.li || flags.si) {
    value = va_arg(args, unsigned long);
    if (flags.si) {
      value = (unsigned short)va_arg(args, unsigned int);
    }
  } else {
    value = va_arg(args, unsigned int);
  }
  return value;
}
void process_int(long long value, Flags *flags, char *string, char **buf_ptr) {
  if (value < 0) {
    flags->is_negative = 1;
    if (flags->width && !flags->align)
      flags->width_value--;
    else {
      *(*buf_ptr)++ = '-';
      value = -value;
      flags->width_value--;
      flags->sign_printed = 1;
    }
  }
  string = int_to_string(value, string);
  if (string != s21_NULL) {
    format_string(buf_ptr, string, s21_strlen(string), flags);
    free(string);
  }
}

void process_float(long double value, Flags *flags, char *string,
                   char **buf_ptr) {
  if (value < 0) {
    flags->is_negative = 1;
    if (flags->width && !flags->align)
      flags->width_value--;
    else {
      *(*buf_ptr)++ = '-';
      value = -value;
      flags->width_value--;
      flags->sign_printed = 1;
    }
  }

  string = float_to_string(value, string, flags->accuracy_value);

  if (string != s21_NULL) {
    if (flags->sign && !flags->is_negative) {
      flags->len_arg++;
      if (flags->accuracy_value) flags->width_value--;
    }

    format_string(buf_ptr, string, s21_strlen(string), flags);

    if (flags->sharp && string[s21_strlen(string)] != '.') {
      *(*buf_ptr)++ = '.';
    } else if (flags->accuracy_value == 0) {
      *(*buf_ptr)-- = '\0';
    }

    free(string);
  }
}

void process_string(char **string, char **buf_ptr, Flags *flags) {
  if (*string == s21_NULL) {
    if (flags->accuracy_value >= 6 || flags->accuracy == 0) {
      *string = "(null)";
    } else {
      *string = "";
    }
  }
  format_string(buf_ptr, *string, s21_strlen(*string), flags);
}
