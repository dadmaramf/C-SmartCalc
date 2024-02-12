#include "s21_SmartCalc.h"

long double InterChanges(long double* deposit_amount, int period_plac,
                         int period_pay, long double inter_rate, bool type,
                         long double replen, long double withdrawals) {
  long double inter_changes = 0;
  for (int month = 0; month < period_pay; month++) {
    long double inter_changes_buf = 0;
    if (period_plac == 12)
      inter_changes_buf = *deposit_amount * inter_rate / 100 / period_plac;
    if (period_plac == 1 && (month % 11) == 0 && month != 0)
      inter_changes_buf = *deposit_amount * inter_rate / 100 / period_plac;

    if (period_plac == 12 || ((month % 11) == 0 && month != 0)) {
      *deposit_amount += replen;
      *deposit_amount -= withdrawals;
    }
    if (type == true) *deposit_amount += inter_changes_buf;
    inter_changes += inter_changes_buf;
  }
  return inter_changes;
}

long double TaxAmount(long double inter_changes, long double tax_rate) {
  return inter_changes * tax_rate / 100;
}

long double AmountTerm(long double inter_changes, long double deposit_amount,
                       long double tax_amount) {
  return deposit_amount + inter_changes - tax_amount;
}
