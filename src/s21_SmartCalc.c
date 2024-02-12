#include "s21_SmartCalc.h"

#include <stdio.h>

int SmartCalcX(const char* arr, long double x, long double* res) {
  if (arr == NULL || res == NULL) return 0;
  char* str = (char*)arr;
  *res = 0;
  StackN* steckVal = createListN();
  StackO* steckOper = createListO();
  int error = Parser(steckOper, steckVal, str, res, x);
  if (error && (!isEmptyOper(steckOper) || !isEmptyVal(steckVal))) {
    error = 0;
    *res = 0;
  }
  clearStack(steckVal, steckOper);
  return error;
}

int SmartCalc(const char* arr, long double* res) {
  if (arr == NULL || res == NULL) return 0;
  char* str = (char*)arr;
  *res = 0;
  StackN* steckVal = createListN();
  StackO* steckOper = createListO();
  int error = Parser(steckOper, steckVal, str, res, 0);
  if (error && (!isEmptyOper(steckOper) || !isEmptyVal(steckVal))) {
    error = 0;
    *res = 0;
  }
  clearStack(steckVal, steckOper);
  return error;
}

int Parser(StackO* newSteckO, StackN* newSteckN, char* str, long double* res,
           long double X) {
  int error = 1;
  for (; *str && error; str++) {
    if (*str == ' ') continue;
    int priori;
    if (strchr("1234567890", *str) != NULL) {
      str = LineToNumConversion(newSteckN, str, UnaryMinus(newSteckO));
    } else if ((priori = Priority(*str)) != -1)
      error = PutOperationStack(newSteckO, newSteckN, priori, &str);
    else if (*str == ')')
      error = SpecialCase(newSteckO, newSteckN);
    else if (*str == 'x')
      pushVal(newSteckN, (UnaryMinus(newSteckO) * X));
    else
      error = 0;
  }
  while (!isEmptyOper(newSteckO) && error)
    if (peekOper(newSteckO) == '(')
      error = 0;
    else
      error = Calculation(newSteckO, newSteckN);
  if (error) *res = popVal(newSteckN);
  return error;
}

int SpecialCase(StackO* newSteckO, StackN* newSteckN) {
  int error = 1, priority = 0;
  while ((priority = Priority(peekOper(newSteckO))) != 0 && error)
    error = Calculation(newSteckO, newSteckN);
  if (priority == -1) error = 0;
  if (error) popOper(newSteckO);
  return error;
}

int UnaryMinus(StackO* newSteckO) {
  int minus = 1;
  while (peekOper(newSteckO) == '~') {
    popOper(newSteckO);
    minus *= -1;
  }
  return minus;
}

int PutOperationStack(StackO* newSteckO, StackN* newSteckN, int priori,
                      char** str) {
  int error = 1;
  if ((isEmptyVal(newSteckN) == true || strchr("+-/*(", *(*str - 1)) != NULL) &&
      (**str == '-' || **str == '+')) {
    if (**str == '-') pushOper(newSteckO, '~');
  } else {
    int priorilast;
    if (!isEmptyOper(newSteckO) &&
        ((priorilast = Priority(peekOper(newSteckO))) | priori) > 1) {
      bool step = priorilast == 2 && priori == 2;
      if (step == false) {
        while (priori >= priorilast && error && priorilast > 0) {
          error = Calculation(newSteckO, newSteckN);
          priorilast = Priority(peekOper(newSteckO));
        }
      }
    }
    *str = PushOperForString(*str, newSteckO);
  }
  return error;
}

char* PushOperForString(char* str, StackO* newSteckO) {
  char ch = 0;
  int size = 1;
  if (strchr("cstalm", *str) != NULL) {
    if (strncmp(str, "ln", ++size) == 0)
      ch = 'n';
    else if (strncmp(str, "sin", ++size) == 0)
      ch = 's';
    else if (strncmp(str, "cos", size) == 0)
      ch = 'c';
    else if (strncmp(str, "tan", size) == 0)
      ch = 't';
    else if (strncmp(str, "log", size) == 0)
      ch = 'd';
    else if (strncmp(str, "mod", size) == 0)
      ch = 'm';
    else if (strncmp(str, "asin", ++size) == 0)
      ch = 'S';
    else if (strncmp(str, "acos", size) == 0)
      ch = 'C';
    else if (strncmp(str, "atan", size) == 0)
      ch = 'T';
    else if (strncmp(str, "sqrt", size) == 0)
      ch = 'q';
  } else
    ch = *str;
  pushOper(newSteckO, ch);
  return str + (size - 1);
}

int Calculation(StackO* newSteckO, StackN* newSteckN) {
  int error = 1;
  if (strchr("sctSCTqnd", peekOper(newSteckO)) != NULL &&
      isEmptyOper(newSteckO) != true) {
    long double number_1 = 0;
    isEmptyVal(newSteckN) == true ? (error = 0)
                                  : (number_1 = popVal(newSteckN));
    if (error) {
      number_1 =
          returnFunction(popOper(newSteckO))(number_1) * UnaryMinus(newSteckO);
      pushVal(newSteckN, number_1);
    }
  } else if (strchr("+-^m*/", peekOper(newSteckO)) != NULL) {
    long double number_2 = 0, number_1 = 0;
    isEmptyVal(newSteckN) == true ? (error = 0)
                                  : (number_2 = popVal(newSteckN));
    isEmptyVal(newSteckN) == true ? (error = 0)
                                  : (number_1 = popVal(newSteckN));
    if (error)
      pushVal(newSteckN,
              OperationResult(number_1, number_2, popOper(newSteckO)));
  } else
    error = 0;
  return error;
}

long double (*returnFunction(char operation))(long double) {
  long double (*funcType)(long double) = NULL;
  if (operation == 's')
    funcType = &sinl;
  else if (operation == 'c')
    funcType = &cosl;
  else if (operation == 't')
    funcType = &tanl;
  else if (operation == 'S')
    funcType = &asinl;
  else if (operation == 'C')
    funcType = &acosl;
  else if (operation == 'T')
    funcType = &atanl;
  else if (operation == 'q')
    funcType = &sqrtl;
  else if (operation == 'n')
    funcType = &logl;
  else if (operation == 'd')
    funcType = &log10l;
  return funcType;
}

long double OperationResult(long double number_1, long double number_2,
                            char operation) {
  long double result = 0;
  if (operation == '+')
    result = number_1 + number_2;
  else if (operation == '-')
    result = number_1 - number_2;
  else if (operation == '*')
    result = number_1 * number_2;
  else if (operation == '/') {
    if (number_2 == 0.0) return INF;
    result = number_1 / number_2;
  } else if (operation == '^') {
    result = powl(number_1, number_2);
  } else if (operation == 'm') {
    result = fmodl(number_1, number_2);
  }
  return result;
}

char* LineToNumConversion(StackN* newSteckN, char* str, int minus) {
  pushVal(newSteckN, strtold(str, &str) * (minus));
  return str - 1;
}

int Priority(char ch) {
  int prior;
  if (ch == 0)
    return -1;
  else if (ch == '(')
    prior = 0;
  else if (ch == '^')
    prior = 2;
  else if (strchr("cstalCSTdqn", ch) != NULL)
    prior = 1;
  else if (strchr("*/m", ch) != NULL)
    prior = 3;
  else if (ch == '+' || ch == '-')
    prior = 4;
  else if (ch == '~')
    prior = 5;
  else
    prior = -1;
  return prior;
}
