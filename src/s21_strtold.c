#include "s21_sscanf.h"
#include "s21_string.h"

// 53. with width 3 parse to 53
// inf or nan with width <3 parse to 0
// func parsing one float of nan\inf, if error -> stop parsed sscanf
long double s21_strtold(char **src, int *error_flag, int width) {
  if (width == 0) {
    width = s21_strlen(*src);
  }
  long double result = 0.0;
  int sign = detect_sign(src, &width);
  int inf_nan_flag = s21_detect_inf_nan(src, error_flag, sign, &width);

  if (inf_nan_flag == 0) {
    result = s21_atof(src, sign, &width, error_flag);

    if (*error_flag == 0 && width && s21_has_exponent(**src) == 1)
      s21_exec_exponent(&result, src, error_flag, &width);

  } else if (inf_nan_flag > 0) {
    result = s21_return_inf_nan(inf_nan_flag);
  }
  return result;
}

int detect_sign(char **src, int *width) {
  int sign = 1;
  if (*width && **src == '-') {
    (*src)++;
    (*width)--;
    sign = -1;
  } else if (*width && **src == '+') {
    (*src)++;
    (*width)--;
  }
  return sign;
}
// return -1 if error, 0 if inf and nan not detected
// return 1 if +inf detect, 2 if -inf detect
// return 3 if nan detect
int s21_detect_inf_nan(char **src, int *error_flag, int sign, int *width) {
  int error = 0, result = 0;

  if (*width && (**src == 'i' || **src == 'I')) {
    error = 1;
    (*src)++;
    (*width)--;
    if (*width && (**src == 'n' || **src == 'N')) {
      (*src)++;
      (*width)--;
      if (*width && (**src == 'f' || **src == 'F')) (*src)++;
      (*width)--;
      error = 0;
      result = sign == 1 ? 1 : 2;
    }
  }

  if ((result == 0 && *width) && (**src == 'n' || **src == 'N')) {
    error = 1;
    (*src)++;
    (*width)--;
    if (*width && (**src == 'a' || **src == 'A')) {
      (*src)++;
      (*width)--;
      if (*width && (**src == 'n' || **src == 'N')) {
        (*src)++;
        (*width)--;
        error = 0;
        result = 3;
      }
    }
  }

  *error_flag = error;
  return result;
}

// сюда приходит 53.00034
long double s21_atof(char **src, int sign, int *width, int *error_flag) {
  int count_of_zeros = 0;
  long double res = 0.0, fract = 0.0;

  if (s21_isDigit(**src) == 0) {
    *error_flag = 1;
  } else {
    res = (long double)parse_and_atoi(
        src, width);  // парсим целую часть до точки (-53).00034

    if (*width && **src == '.') {  // парсим точку (-53.)00034
      (*src)++;
      (*width)--;
    }

    // парсим все нули которые неверно обработает atoi
    while (*width && **src == '0') {  // (-53.000)34
      count_of_zeros++;
      (*src)++;
      (*width)--;
    }

    fract = parse_and_atoi(src, width);  // парсим оставшиеся цифры, fract = 34
    fract = move_int_under_dot(fract);  // делаем перевод 34 -> 0.34
    fract = append_counted_zeros(
        fract, count_of_zeros);  // добавляем разряды 0.34 -> 0.00034
  }

  return (res + fract) * sign;  // (53 + 0.00034) * -1
}

// return atoi res after parsing char array (while break after find non-digit)
// move src pointer after parsed int
int parse_and_atoi(char **src, int *width) {
  char buff[BS] = {0};
  int i = 0;

  while (*width && s21_isDigit(**src) == 1) {  // парсим цифры до точки в массив
    buff[i] = **src;
    (*src)++;
    (*width)--;
    i++;
  }

  return s21_atoi(buff);
}

// move integer under dot (34 -> 0.34)
double long move_int_under_dot(int source) {
  double long result = (double long)source;

  while (result >= 1.0) {
    result /= 10;
  }

  return result;
}

double long append_counted_zeros(double long source, int count_of_zeros) {
  for (int i = 0; i < count_of_zeros; i++) {
    source /= 10;
  }

  return source;
}

// return +INFINITY if 1
// return -INFINITY if 2
// return NAN if 3
double long s21_return_inf_nan(int inf_nan_flag) {
  double long result = 0;

  if (inf_nan_flag == 1) {
    result = INFINITY;
  } else if (inf_nan_flag == 2) {
    result = INFINITY * -1;
  } else if (inf_nan_flag == 3) {
    result = NAN;
  }

  return result;
}

// return 0 if exponent not detected
// return 1 if exponent detected
int s21_has_exponent(char src) {
  int res = 0;
  if (src == 'e' || src == 'E') {
    res = 1;
  }
  return res;
}

// in func we put char* with garantee E or e first character and width != 0
// 53.444eh-5 -> skip exponent
// 53.444e-h5 -> skip exponent
// 53.444e-5h parsing okay
void s21_exec_exponent(double long *result, char **src, int *error_flag,
                       int *width) {
  int step = 0, exponent_val = 0, negative = 0;
  (*src)++;  // skip e or E
  (*width)--;

  if (*width && **src == '-') {
    step++;
    (*src)++;
    (*width)--;
    negative = 1;
  } else if (*width && **src == '+') {
    step++;
    (*src)++;
    (*width)--;
  }

  if (step == 1 && s21_isDigit(**src)) {
    exponent_val = parse_and_atoi(src, width);
    step++;
  }

  while (step == 2 && exponent_val) {
    if (negative == 0) {
      *result *= 10;
    } else {
      *result /= 10;
    }
    exponent_val--;
  }

  if (exponent_val != 0 || step != 2) {
    *error_flag = 1;
  }
}