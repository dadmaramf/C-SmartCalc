/* created by sheritsh // Oleg Polovinko ※ School 21, Kzn */
#ifndef MODULE_TESTS_H
#define MODULE_TESTS_H

#include <check.h>
// #include <math.h>

#include "../s21_SmartCalc.h"

enum test_res { FAILURE, OK };

void s21_suit_execution(Suite *suite, int *failed_count, char *suite_name);

#endif  // UNIT_TESTS_H
