#include "s21_sscanf.h"

int s21_sscanf(const char *buf, const char *format, ...) {
  int str_eof = s21_isEmptyString(buf);
  int flag = 0, spec_len = 0, result_count = 0;

  // Если строка не пустая, заходим в функцию
  if (str_eof == 0) {
    va_list val;
    va_start(val, format);

    // ставим указатель форматной строки по которому будет иттерироваться
    // иттерация от fstr до '\0' иттерируемся fstr++
    char *fstr = (char *)format;

    // ставим указатель входной строки, по нему будем итттерироваться
    // иттерация от src до '\0' иттерируемся fstr++
    char *src = (char *)buf;

    // массив спецификаторов
    spec specificators[BS] = {0};

    while (*fstr != '\0' && flag == 0) {
      spec sp = {0};
      flag = parse_spec(&fstr, &sp, &val);

      // Если спецификатор спарсился без ошибок - заносим в массив,
      // если ошибки есть - выходим из цикла
      if (flag == 0) {
        specificators[spec_len] = sp;
        spec_len++;
      } else {
        break;
      }
    }

    record_values_in_arguments(specificators, spec_len, &src, &result_count);
    va_end(val);

    // print_array_of_struct(spec_len,
    //                       specificators);  // TODO убрать debug функцию
  }

  return result_count;
}

// return 1 if char is space, \n or \t, else return 0
int s21_isspace(char c) {
  int isSpace = 0;

  if (c == ' ' || c == '\n' || c == '\t') isSpace = 1;

  return isSpace;
}

// return 1 if string is empty or 0 if isn't
int s21_isEmptyString(const char *src) {
  int isEmpty = 1;

  // цикл по всей строке до ноль-терминанта
  for (int i = 0; src[i] != '\0'; i++) {
    char x = src[i];
    // Если находим символ который не является пробелом и ноль-терминантом
    if (s21_isspace(x) == 0 && x != '\0') {
      isEmpty = 0;
      break;
    }
  }

  return isEmpty;
}

// return 0 if all is good, else return 1
int parse_spec(char **fstr, spec *sp, va_list *val) {
  int somethingIsWrong = 0;

  if (parse_skip_char(fstr, sp) == 0 && parse_wigth(fstr, sp) == 0 &&
      parse_lenght(fstr, sp) == 0) {
    parse_specificator_char(fstr, sp);
    if (sp->hasStarSpec == 0) {
      sp->addr = va_arg(*val, void *);
    }
  } else {
    sp->hasErrors = 1;
    somethingIsWrong = 1;
  }

  return somethingIsWrong;
}

// return 0 if all skip character is parsed and % was found, else return 1
int parse_skip_char(char **fstr, spec *sp) {
  int percentIsntFound = 1;
  int i = 0;

  // цикл пока не найдем % или '\0'
  while (**fstr != '\0' && percentIsntFound == 1) {
    // пропускаем один процент %, остальные символы заносим в sp->skip
    if (**fstr == '%') {
      percentIsntFound = 0;
    } else if (**fstr != '\0') {
      sp->skip[i] = **fstr;
    }
    i++;
    (*fstr)++;
  }

  return percentIsntFound;
}

// %*20d - is okay
// %20*d - isnt okay, skip all remain fstr
// return 0 if wigth is parsed success, else return 1
int parse_wigth(char **fstr, spec *sp) {
  int result = 0;

  char wigth[BS] = {0};
  int i = 0;

  // записываем все числовые символы в строку, * записываем в спецификатор
  while (s21_isDigit(**fstr) || **fstr == '*') {
    // Если найдена * то указываем это в спецификаторе
    if (i == 0 && **fstr == '*') {
      sp->hasStarSpec = 1;
    } else if (i != 0 && **fstr == '*') {
      result = 1;
      break;
    } else {
      wigth[i] = **fstr;
      i++;
    }

    (*fstr)++;
  }

  if (i > 0 && result == 0) {
    sp->s21_width = s21_atoi(wigth);
  }

  return result;
}

// return 1 if char is digit, else return 0
int s21_isDigit(char x) { return ('0' <= x && x <= '9') ? 1 : 0; }

// return 0 if lenght parsed success, else return 1
int parse_lenght(char **fstr, spec *sp) {
  int result = 0;
  char l = **fstr;

  switch (l) {
    case 'h':
      sp->lenght = LENGTH_SHORT;
      (*fstr)++;
      break;

    case 'l':
      sp->lenght = LENGTH_LONG;
      (*fstr)++;
      if (**fstr == 'l') {
        sp->lenght = LENGTH_LONG_LONG;
        (*fstr)++;
      }
      break;
    case 'L':
      sp->lenght = LENGTH_LONG_DOUBLE;
      (*fstr)++;
      break;
  }

  // Проверяем символ после парсинга длины, он не должен быть другой длиной
  // иначе ошибка
  char remain = **fstr;
  if (remain == 'h' || remain == 'l' || remain == 'L') {
    sp->hasErrors = 1;
    result = 1;
  }

  return result;
}

void parse_specificator_char(char **fstr, spec *sp) {
  sp->spec = **fstr;
  (*fstr)++;
}

void record_values_in_arguments(spec *specificators, int spec_len, char **src,
                                int *result_count) {
  int i = 0;
  int error_flag = 0;
  char *start_n = *src;

  // цикл по всем спецификаторам, как только получаем ошибку записи или
  // находим спецификатор с ошибкой - выходим из него
  while (i < spec_len && error_flag == 0 && specificators[i].hasErrors == 0) {
    char spec = specificators[i].spec;
    skip_character(src, &specificators[i]);
    if (specificators[i].hasErrors == 1) {
      error_flag = 1;
      break;
    } else if (spec == 'c') {
      write_char(&specificators[i], src, &error_flag, result_count);
    } else if (spec == 'd') {
      write_int(&specificators[i], src, &error_flag, result_count);
    } else if (spec == 'i' || spec == 'p') {
      detect_write_decimal_or_pointer(&specificators[i], src, &error_flag,
                                      result_count);
    } else if (spec == 'g' || spec == 'G' || spec == 'f') {
      write_float(&specificators[i], src, &error_flag, result_count);
    } else if (spec == 's') {
      parse_and_write_string(&specificators[i], src, result_count);
    } else if (spec == 'u') {
      parse_unsigned_decimal(&specificators[i], src, &error_flag, result_count);
    } else if (spec == 'x' || spec == 'X') {
      write_hex_or_oct(&specificators[i], src, &error_flag, result_count, 16);
    } else if (spec == 'o') {
      write_hex_or_oct(&specificators[i], src, &error_flag, result_count, 8);
    } else if (spec == 'n') {
      *((int *)specificators[i].addr) = (*src) - start_n;
    }
    i++;
  }
}

void skip_character(char **src, spec *sp) {
  char *buf = sp->skip;
  // сначала обрезаем все пробелы слева
  while (**src == ' ') {
    (*src)++;
  }
  while (*buf == ' ') {
    buf++;
  }

  while (**src != '\0' && *buf != '\0') {
    if (**src == *buf) {
      (*src)++;
      buf++;
    } else {
      sp->hasErrors = 1;
      break;
    }
  }
}

void write_char(spec *sp, char **src, int *error_flag, int *result_count) {
  if (**src != '\0') {
    if (sp->hasStarSpec == 0) {
      *(char *)sp->addr = **src;
      (*result_count)++;
    }
    (*src)++;
  } else {
    *error_flag = 1;
  }
}

void write_int(spec *sp, char **src, int *error_flag, int *result_count) {
  int isNegative = 0, i = 0;
  char buf[BS] = {0};

  // парсим знаки перед числом
  if (**src == '-') {
    isNegative = 1;
    (*src)++;
  } else if (**src == '+') {
    (*src)++;
  } else if (s21_isDigit(**src) == 0) {
    *error_flag = 1;
    sp->hasErrors = 1;
  }

  // парсим все символы которые являются цифрами, обращая внимание на ширину
  while (s21_isDigit(**src) && *error_flag == 0 &&
         (i < sp->s21_width || sp->s21_width == 0)) {
    buf[i] = **src;
    (*src)++;
    i++;
  }

  char *buf_ptr = buf;

  // обработка парсинга указателя
  if (sp->spec == 'p' && sp->hasStarSpec == 0 && *error_flag == 0) {
    int width = (sp->s21_width == 0)
                    ? (int)s21_strlen(buf)
                    : sp->s21_width;  // TODO заменить на s21_strlen
    unsigned long long int ptr = s21_strtoull(&buf_ptr, width, 16, error_flag);
    *(int *)sp->addr = (int)ptr;
  } else if (s21_isEmptyString(buf) == 0) {  // обработка парсинга интов
    long long int x = s21_atoi(buf);  // TODO заменить на s21_atoi
    int sign = 1;

    if (isNegative == 1) {
      sign = -1;
    }
    *error_flag = write_int_with_lenght(sp, x, sign);
  } else {
    *error_flag = 1;
    sp->hasErrors = 1;
  }

  if (*error_flag == 0) {
    (*result_count)++;
  }
}

int write_int_with_lenght(spec *sp, long long int x, int sign) {
  int flag = 0;
  x *= sign;
  if (sp->lenght == NONE_LENGTH) {
    *(int *)sp->addr = (int)x;
  } else if (sp->lenght == LENGTH_SHORT) {
    *(short int *)sp->addr = (short int)x;
  } else if (sp->lenght == LENGTH_LONG) {
    *(long int *)sp->addr = (long int)x;
  } else if (sp->lenght == LENGTH_LONG_LONG) {
    *(long long int *)sp->addr = (long long int)x;
  } else {
    flag = 1;
    sp->hasErrors = 1;
  }
  return flag;
}

// address 0x7ffe9fbeabb0
// decimal +/- 123456
// hex 0x43
// oct 01234

void detect_write_decimal_or_pointer(spec *sp, char **src, int *error_flag,
                                     int *result_count) {
  *error_flag = 1;

  if (hex_oct_check_char(src) == 8) {  // "octal"
    *error_flag = 0;
    write_hex_or_oct(sp, src, error_flag, result_count, 8);
  } else if (hex_oct_check_char(src) == 16) {  // "hexadecimal" or "ptr"
    *error_flag = 0;
    write_hex_or_oct(sp, src, error_flag, result_count, 16);
  } else if (hex_oct_check_char(src) == 10) {  // "dec"
    *error_flag = 0;
    write_int(sp, src, error_flag, result_count);
  }
}

void write_hex_or_oct(spec *sp, char **src, int *error_flag, int *result_count,
                      int basis) {
  int hasWidth = sp->s21_width ? 1 : 0;
  if (hasWidth == 0) {
    sp->s21_width = s21_strlen(*src);
  }

  int sign = 1;
  if (sp->spec == 'p') {
    basis = 16;
  }

  if (**src == '-') {
    sign = -1;
    (*src)++;
    sp->s21_width--;
  }

  if (basis == 16 && hex_oct_check_char(src) == 16) {
    sp->s21_width -= 2;
  }

  if (hex_oct_check_char(src) == 16 || hex_oct_check_char(src) == 8) {
    unsigned long long int result =
        s21_strtoull(src, sp->s21_width, basis, error_flag);

    if (sp->hasStarSpec == 0) {
      (*result_count)++;

      if (sp->spec == 'p') {
        *(int *)sp->addr = (int)result;
      } else {
        result *= sign;
        write_unsign_with_lenght(sp, result);
      }
    }
  } else {
    *error_flag = 1;
  }
}

// return -1 if it isnt number or error
// return 16 if hex detected
// return 10 if dec detected
// return 8 if oct detected
int hex_oct_check_char(char **src) {
  int basis = 0;
  char c1 = 0, c2 = 0;
  if (**src == '\0' || *(*src + 1) == '\0') {
    basis = -1;
  } else {
    c1 = **src;
    c2 = *(*src + 1);
  }

  if (c1 == '0' && (c2 != 'x' && c2 != 'X')) {  // "octal"
    basis = 8;
  } else if (c1 == '0' && (c2 == 'x' || c2 == 'X')) {  // "hexadecimal"
    basis = 16;
  } else if (s21_strspn(*src, "+-0123456789")) {  // "dec"
    basis = 10;
  } else {
    basis = -1;
  }

  return basis;
}

void write_unsign_with_lenght(spec *sp, unsigned long long int result) {
  if (sp->lenght == NONE_LENGTH) {
    *(unsigned int *)sp->addr = (unsigned int)result;
  } else if (sp->lenght == LENGTH_SHORT) {
    *(unsigned short int *)sp->addr = (unsigned short int)result;
  } else if (sp->lenght == LENGTH_LONG) {
    *(unsigned long int *)sp->addr = (unsigned long int)result;
  } else if (sp->lenght == LENGTH_LONG_LONG) {
    *(unsigned long long int *)sp->addr = (unsigned long long int)result;
  }
}

// 0xF - error, 012345 - parsed as 12345
void parse_unsigned_decimal(spec *sp, char **src, int *error_flag,
                            int *result_count) {
  int flag = 0, i = 1, hasWidth = sp->s21_width ? 1 : 0;
  char sign = '+', buf[BS] = {0};
  if (hasWidth == 0) sp->s21_width = s21_strlen(*src);

  // Первый символ в buf - знак, по умолчанию +
  flag = parse_unsigned_helper(sp, src, &sign);
  buf[0] = sign;

  while (**src != '\0' && **src != ' ' && sp->s21_width != 0) {
    buf[i] = **src;
    i++;
    (*src)++;
    sp->s21_width--;
  }

  // atoi возвращает int, мы его преобразовываем в unsigned long long int с
  // переполнением
  unsigned long long int result = s21_atoi(buf);

  if (sp->hasStarSpec == 0 && flag == 0) {
    write_unsign_with_lenght(sp, result);
    (*result_count)++;
  } else if (flag == 1) {
    *error_flag = 1;
  }
}

// return 0 if all is ok, else return 1
// parsing unsigned (+\- dec or oct, not hex)
int parse_unsigned_helper(spec *sp, char **src, char *sign) {
  int flag = 0;
  if (sp->s21_width && **src == '-') {
    *sign = '-';
    (*src)++;
    sp->s21_width--;
  }

  if (sp->s21_width && **src == '+') {
    (*src)++;
    sp->s21_width--;
  }

  if (sp->s21_width && **src == '0' &&
      (*(*src + 1) == 'x' || *(*src + 1) == 'X')) {
    flag = 1;
  } else if (sp->s21_width && **src == '0') {
    sp->s21_width--;
    (*src)++;
  }

  return flag;
}

void write_float(spec *sp, char **src, int *error_flag, int *result_count) {
  long double result = 0.0;
  int width = sp->s21_width == 0 ? 0 : sp->s21_width;

  result = s21_strtold(src, error_flag, width);

  if (*error_flag == 0 && sp->hasStarSpec == 0) {
    write_float_with_lenght(sp, result);
    (*result_count)++;
  }
}

void write_float_with_lenght(spec *sp, long double result) {
  if (sp->lenght == NONE_LENGTH) {
    *(float *)sp->addr = (float)result;
  } else if (sp->lenght == LENGTH_LONG) {
    *(double *)sp->addr = (double)result;
  } else if (sp->lenght == LENGTH_LONG_DOUBLE) {
    *(long double *)sp->addr = (long double)result;
  }
}

void parse_and_write_string(spec *sp, char **src, int *result_count) {
  int width = sp->s21_width == 0 ? (int)s21_strlen(*src) : sp->s21_width;
  int i = 0;
  char buff[BS] = {0};

  while (**src != ' ' && **src != '\0' && width) {
    buff[i] = **src;
    (*src)++;
    width--;
    i++;
  }

  if (sp->hasStarSpec == 0) {
    s21_strncpy((char *)sp->addr, buff, s21_strlen(buff));
    (*result_count)++;
  }
}