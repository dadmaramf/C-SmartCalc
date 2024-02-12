
#include "controller_tests.h"

START_TEST(api_calc_opt_1) {
  char *input = "5+10+97+0*log(12)";
  long double res = 0;
  SmartCalc(input, &res);
  ck_assert_ldouble_eq(res, 112.000000);
}
END_TEST

START_TEST(api_calc_opt_2) {
  char *input = "2^2^3";
  long double res = 0;
  SmartCalc(input, &res);
  ck_assert_ldouble_eq(res, 256.000000);
}
END_TEST

START_TEST(api_calc_opt_3) {
  char *input = "((1 * 2) - 1)";
  long double res = 0;
  SmartCalc(input, &res);
  int test_res = fabsl(res - (1)) < 1e-6 ? OK : FAILURE;
  ck_assert_ldouble_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_4) {
  char *input = "cos(3-1)/sin(5)*tan(1)";
  long double res = 0;
  SmartCalc(input, &res);
  int test_res = fabsl(res - (0.675872)) < 1e-6 ? OK : FAILURE;
  ck_assert_ldouble_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_5) {
  char *input = "9mod(5)-(-1)";
  long double res = 0;
  SmartCalc(input, &res);
  ck_assert_ldouble_eq(res, 5.000000);
}
END_TEST

START_TEST(api_calc_opt_6) {
  char *input =
      "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
      "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))";
  long double res = 0;
  SmartCalc(input, &res);
  int test_res = fabsl(res - (-30.0722)) < 1e-4 ? OK : FAILURE;
  ck_assert_ldouble_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_7) {
  char *input = "cos(3-1)/sin(5)*tan(1)";
  long double res = 0;
  SmartCalc(input, &res);
  int test_res = fabsl(res - (0.675872)) < 1e-6 ? OK : FAILURE;
  ck_assert_ldouble_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_8) {
  char *input = "100000+10000/0.1";
  long double res = 0;
  SmartCalc(input, &res);
  ck_assert_ldouble_eq(res, 200000.000000);
}
END_TEST

START_TEST(api_calc_opt_9) {
  char *input = "ln(10)-(-log(2))";
  long double res = 0;
  SmartCalc(input, &res);
  int test_res = fabsl(res - (2.603615)) < 1e-4 ? OK : FAILURE;
  ck_assert_ldouble_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_10) {
  char *input = "(-1 +(4 / 2))";
  long double res = 0;
  SmartCalc(input, &res);
  int test_res = fabsl(res - (1)) < 1e-6 ? OK : FAILURE;
  ck_assert_ldouble_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_11) {
  char *input = "pussy_test";
  long double res = 0;
  int res_test = SmartCalc(input, &res);
  ck_assert_int_eq(res_test, FAILURE);
}
END_TEST

START_TEST(api_calc_opt_12) {
  char *input = "(cos(()))";
  long double res = 0;
  int res_test = SmartCalc(input, &res);
  ck_assert_int_eq(res_test, FAILURE);
}
END_TEST

START_TEST(api_calc_opt_13) {
  char *input = "1+(-1 +(1 * 2))";
  long double res = 0;
  SmartCalc(input, &res);
  int test_res = fabsl(res - 2.0000000) < 1e-6 ? OK : FAILURE;
  ck_assert_ldouble_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_14) {
  long double res = 0;
  char input[] = "(-1 +(1 * 2))-2";
  SmartCalc(input, &res);
  int test_res = fabsl(res - (-1.0000000)) < 1e-6 ? OK : FAILURE;
  ck_assert_ldouble_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_15) {
  long double res = 0;
  char input[] = "sin(2-1) + cos(1 * 2) + tan(3)";
  SmartCalc(input, &res);

  int test_res = fabsl(res - (0.2827776)) < 1e-6 ? OK : FAILURE;
  ck_assert_ldouble_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_16) {
  long double res = 0;
  char input[] = "asin(2-1) + acos(0.33) + atan(3)";
  SmartCalc(input, &res);

  int test_res = fabsl(res - (4.0543349)) < 1e-6 ? OK : FAILURE;
  ck_assert_ldouble_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_17) {
  long double res = 0;
  char input[] = "(log(100000) + 2) mod sqrt(4)+ ln(2.3)";
  SmartCalc(input, &res);

  int test_res = fabsl(res - (1.8329091)) < 1e-6 ? OK : FAILURE;
  ck_assert_ldouble_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_18) {
  long double res = 0;
  char input[] = "1.1+2.0+(3.0*4.0)+(5.0+6.8)--4+34--3";
  SmartCalc(input, &res);

  int test_res = fabsl(res - (67.9)) < 1e-6 ? OK : FAILURE;
  ck_assert_ldouble_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_19) {
  long double res = 0;
  char input[] = "(-4+6) * 1.10+2.0+(3.0-5.5)*(1.5-6.5)";
  SmartCalc(input, &res);

  int test_res = fabsl(res - (16.7)) < 1e-6 ? OK : FAILURE;
  ck_assert_ldouble_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_20) {
  long double res = 0;
  char input[] = "(sin(45)+cos(30)+tan(45)+tan(90))*2";
  SmartCalc(input, &res);

  int test_res = fabsl(res - (1.25946)) < 1e-6 ? OK : FAILURE;
  ck_assert_ldouble_eq(test_res, OK);
}
END_TEST

// incorrect
START_TEST(smartCalc_incorrect_1) {
  long double dst = 0;
  const char str[] = "(--1 +(1 * 2))-2";
  int res = SmartCalc(str, &dst);
  ck_assert_ldouble_eq(dst, 1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(smartCalc_incorrect_2) {
  long double dst = 0;
  const char str[] = "()-1 +(1 /)) 2))-2";
  int res = SmartCalc(str, &dst);

  ck_assert_ldouble_eq(dst, 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(smartCalc_incorrect_3) {
  long double dst = 0;
  const char str[] = "()";
  int res = SmartCalc(str, &dst);

  ck_assert_ldouble_eq(dst, 0);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(smartCalc_incorrect_4) {
  long double dst = 0;
  const char str[] = "(1 * -1 + (1 * 2))-2";
  int res = SmartCalc(str, &dst);

  ck_assert_ldouble_eq(dst, 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(smartCalc_incorrect_5) {
  long double dst = 0;
  const char str[] = "(1 * [1 + (1 * 2))-2";
  int res = SmartCalc(str, &dst);

  ck_assert_ldouble_eq(dst, 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(smartCalc_incorrect_6) {
  long double dst = 0;
  const char str[] = "(1 * 1 3 (1 * 2))-2";
  int res = SmartCalc(str, &dst);

  ck_assert_ldouble_eq(dst, 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(smartCalc_incorrect_7) {
  long double dst = 0;
  const char str[] = "(1 * 1 +(1 * 2))-2 - ";
  int res = SmartCalc(str, &dst);

  ck_assert_ldouble_eq(dst, 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(smartCalc_incorrect_8) {
  long double dst = 0;
  const char str[] = "(1 * 1 (1 * 2)))-2";
  int res = SmartCalc(str, &dst);

  ck_assert_ldouble_eq(dst, 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(smartCalc_incorrect_9) {
  long double dst = 0;
  char str[] = ". + 1";
  int res = SmartCalc(str, &dst);

  ck_assert_ldouble_eq(dst, 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(smartCalc_incorrect_10) {
  long double dst = 0;
  char str[] = "* 3 + 2";
  int res = SmartCalc(str, &dst);

  ck_assert_ldouble_eq(dst, 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(smartCalc_incorrect_11) {
  long double dst = 0;
  char str[] = "3 * + 2";
  int res = SmartCalc(str, &dst);

  ck_assert_ldouble_eq(dst, 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(smartCalc_incorrect_12) {
  long double dst = 0;
  char str[] = "3 +* 2";
  int res = SmartCalc(str, &dst);

  ck_assert_ldouble_eq(dst, 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(smartCalc_incorrect_13) {
  long double dst = 0;
  char str[] = "3 + 2)";
  int res = SmartCalc(str, &dst);

  ck_assert_ldouble_eq(dst, 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(smartCalc_incorrect_14) {
  long double dst = 0;
  char str[] = "3.10.0 + 1";
  int res = SmartCalc(str, &dst);

  ck_assert_ldouble_eq(dst, 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(smartCalc_incorrect_15) {
  long double dst = 0;
  char str[] = "3.10 5 + 1";
  int res = SmartCalc(str, &dst);

  ck_assert_ldouble_eq(dst, 0);
  ck_assert_int_eq(res, 0);
}
END_TEST
START_TEST(api_calc_with_x_opt_1) {
  char *input = "x*x*x";
  long double res = 0;
  SmartCalcX(input, -2, &res);
  ck_assert_ldouble_eq(res, -8.000000);
}
END_TEST

START_TEST(api_calc_with_x_opt_2) {
  char *input = "x-cos(x)";
  long double res = 0;
  SmartCalcX(input, -2, &res);
  int test_res = fabsl(res - (-1.58385316345286)) < 1e-4 ? OK : FAILURE;
  ck_assert_int_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_with_x_opt_3) {
  char *input = "ln(10)-(-log(2*x*x))";
  long double res = 0;
  SmartCalcX(input, -2, &res);
  int test_res = fabsl(res - (3.20567507999)) < 1e-4 ? OK : FAILURE;
  ck_assert_int_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_with_x_opt_4) {
  char *input = "ln(10*x*x)-x*(-log(2))";
  long double res = 0;
  SmartCalcX(input, -2, &res);
  int test_res = fabsl(res - (3.08681946279)) < 1e-4 ? OK : FAILURE;
  ck_assert_int_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_with_x_opt_5) {
  char *input = "x+5";
  long double res = 0;
  SmartCalcX(input, -2, &res);
  int test_res = fabsl(res - (3)) < 1e-4 ? OK : FAILURE;
  ck_assert_int_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_with_x_opt_6) {
  char *input = "sin(130)+x-x*x*(x)";
  long double res = 0;
  SmartCalcX(input, -2, &res);
  int test_res = fabsl(res - (5.06989404981)) < 1e-4 ? OK : FAILURE;
  ck_assert_int_eq(test_res, OK);
}
END_TEST

START_TEST(credit_calc_1) {
  long double sum_total = 100000;
  int term = 10;
  long double inter_rate = 12;
  long double mothly = MonthlyPaymentAnnuity(sum_total, term, inter_rate);
  long double total = TotalPayment(mothly, term);
  long double over = Overpayment(total, sum_total);
  bool res = fabsl(mothly - (10558.21)) < 1e-1 &&
                     fabsl(total - (105582.10)) < 1e-1 &&
                     fabsl(over - (5582.1)) < 1e-1
                 ? 1
                 : 0;
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(credit_calc_2) {
  long double sum_total = 564723.23;
  int term = 3;
  long double inter_rate = 6;
  long double mothly = MonthlyPaymentAnnuity(sum_total, term, inter_rate);
  long double total = TotalPayment(mothly, term);
  long double over = Overpayment(total, sum_total);
  bool res = fabsl(mothly - (190126.6)) < 1e-1 &&
                     fabsl(total - (570379.9)) < 1e-1 &&
                     fabsl(over - (5656.621)) < 1e-1
                 ? 1
                 : 0;
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(credit_calc_3) {
  long double sum_total = 564723.23;
  int term = 3;
  long double inter_rate = 6;
  long double total = TotalPaymentDiff(sum_total, term, inter_rate);
  long double mothly = MonthlyPaymentDiff(total, term);
  long double over = Overpayment(total, sum_total);
  bool res = fabsl(mothly - (190123.5)) < 1e-1 &&
                     fabsl(total - (570370.5)) < 1e-1 &&
                     fabsl(over - (5647.232)) < 1e-1
                 ? 1
                 : 0;
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(deb_calc_1) {
  long double deposit_amount = 10000;
  int period_plac = 12;
  int period_pay = 12;
  long double inter_rate = 12;
  long double tax_rate = 0;
  bool type = 0;
  long double replen = 10000;
  long double withdrawals = 0;
  long double inter = InterChanges(&deposit_amount, period_plac, period_pay,
                                   inter_rate, type, replen, withdrawals);
  long double tax = TaxAmount(inter, tax_rate);
  long double term = AmountTerm(inter, deposit_amount, tax);
  bool res = fabsl(term - (137800)) < 1e-1 && fabsl(tax - (0)) < 1e-1 &&
                     fabsl(inter - (7800)) < 1e-1
                 ? 1
                 : 0;
  ck_assert_int_eq(res, OK);
}
END_TEST

Suite *api_calc_suit(void) {
  Suite *suite = suite_create("api_calc");
  TCase *tc_core = tcase_create("core_of_api_calc");
  tcase_add_test(tc_core, api_calc_opt_1);
  tcase_add_test(tc_core, api_calc_opt_2);
  tcase_add_test(tc_core, api_calc_opt_3);
  tcase_add_test(tc_core, api_calc_opt_4);
  tcase_add_test(tc_core, api_calc_opt_5);
  tcase_add_test(tc_core, api_calc_opt_6);
  tcase_add_test(tc_core, api_calc_opt_7);
  tcase_add_test(tc_core, api_calc_opt_8);
  tcase_add_test(tc_core, api_calc_opt_9);
  tcase_add_test(tc_core, api_calc_opt_10);
  tcase_add_test(tc_core, api_calc_opt_11);
  tcase_add_test(tc_core, api_calc_opt_12);
  tcase_add_test(tc_core, api_calc_opt_13);
  tcase_add_test(tc_core, api_calc_opt_14);
  tcase_add_test(tc_core, api_calc_opt_15);
  tcase_add_test(tc_core, api_calc_opt_16);
  tcase_add_test(tc_core, api_calc_opt_17);
  tcase_add_test(tc_core, api_calc_opt_18);
  tcase_add_test(tc_core, api_calc_opt_19);
  tcase_add_test(tc_core, api_calc_opt_20);
  tcase_add_test(tc_core, smartCalc_incorrect_1);
  tcase_add_test(tc_core, smartCalc_incorrect_2);
  tcase_add_test(tc_core, smartCalc_incorrect_3);
  tcase_add_test(tc_core, smartCalc_incorrect_4);
  tcase_add_test(tc_core, smartCalc_incorrect_5);
  tcase_add_test(tc_core, smartCalc_incorrect_6);
  tcase_add_test(tc_core, smartCalc_incorrect_7);
  tcase_add_test(tc_core, smartCalc_incorrect_8);
  tcase_add_test(tc_core, smartCalc_incorrect_9);
  tcase_add_test(tc_core, smartCalc_incorrect_10);
  tcase_add_test(tc_core, smartCalc_incorrect_11);
  tcase_add_test(tc_core, smartCalc_incorrect_12);
  tcase_add_test(tc_core, smartCalc_incorrect_13);
  tcase_add_test(tc_core, smartCalc_incorrect_14);
  tcase_add_test(tc_core, smartCalc_incorrect_15);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *api_calc_with_x_suit(void) {
  Suite *suite = suite_create("api_calc_with_x");
  TCase *tc_core = tcase_create("core_of_api_calc_with_x");
  tcase_add_test(tc_core, api_calc_with_x_opt_1);
  tcase_add_test(tc_core, api_calc_with_x_opt_2);
  tcase_add_test(tc_core, api_calc_with_x_opt_3);
  tcase_add_test(tc_core, api_calc_with_x_opt_4);
  tcase_add_test(tc_core, api_calc_with_x_opt_5);
  tcase_add_test(tc_core, api_calc_with_x_opt_6);
  suite_add_tcase(suite, tc_core);
  return suite;
}

Suite *api_calc_credit(void) {
  Suite *suite = suite_create("calc");
  TCase *tc_core = tcase_create("credit_calc");
  tcase_add_test(tc_core, credit_calc_1);
  tcase_add_test(tc_core, credit_calc_2);
  tcase_add_test(tc_core, credit_calc_3);
  tcase_add_test(tc_core, deb_calc_1);
  // tcase_add_test(tc_core, credit_calc_5);
  suite_add_tcase(suite, tc_core);
  return suite;
}
void s21_suit_execution(Suite *suite, int *failed_count, char *suite_name) {
  SRunner *suite_runner = srunner_create(suite);
  srunner_set_log(suite_runner, suite_name);
  srunner_run_all(suite_runner, CK_NORMAL);
  *failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
}

/*  TESTS MAIN */

int main(void) {
  int failed_count = 0;

  s21_suit_execution(api_calc_suit(), &failed_count,
                     "tests/logs/api_calc_tests.log");
  s21_suit_execution(api_calc_with_x_suit(), &failed_count,
                     "tests/logs/api_calc_with_x_tests.log");
  s21_suit_execution(api_calc_credit(), &failed_count,
                     "tests/logs/api_credit.log");

  return failed_count == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
