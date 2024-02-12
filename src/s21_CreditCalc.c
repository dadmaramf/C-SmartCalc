#include "s21_SmartCalc.h"

long double MonthlyPaymentAnnuity(long double sum_total, int term,
                                  long double inter_rate) {
  double p_procent = inter_rate / 100 / 12;
  double payment_part = powl((1 + p_procent), term) - 1;
  double payment = sum_total * (p_procent + (p_procent / payment_part));
  return payment;
}

long double TotalPayment(long double annuity, int term) {
  return annuity * term;
}

long double Overpayment(long double total_pay, long double sum_total) {
  return total_pay - sum_total;
}

long double TotalPaymentDiff(long double sum_total, int term,
                             long double inter_rate) {
  long double total_pay = 0;
  long double principal = sum_total / term;
  for (int month = 0; month < term; month++) {
    long double balanc_deb = sum_total - (principal * month);
    long double intere_pay = balanc_deb * (inter_rate / 100 / 12);
    long double monthly_payment = principal + intere_pay;
    total_pay += monthly_payment;
  }
  return total_pay;
}
long double MonthlyPaymentDiff(long double total_pay, int term) {
  return total_pay / term;
}
