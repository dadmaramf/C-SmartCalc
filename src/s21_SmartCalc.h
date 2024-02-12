
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define INF 1.0 / 0.0

typedef struct NodeO {
  struct NodeO* nextPtr;
  char calc_oper;
} NodeO;

typedef struct NodeN {
  struct NodeN* nextPtr;
  long double value;
} NodeN;

typedef struct StackO {
  NodeO* head;
} StackO;
typedef struct StackN {
  NodeN* head;
} StackN;

StackN* createListN();
void pushVal(StackN* newSteckN, long double val);
long double popVal(StackN* newSteckN);
bool isEmptyVal(StackN* newSteckN);

StackO* createListO();
void pushOper(StackO* newSteckO, char ch);
char popOper(StackO* newSteckO);
bool isEmptyOper(StackO* newSteckO);
char peekOper(StackO* newSteckO);
void clearStack(StackN* newSteckN, StackO* newSteckO);
// long double peekVal(StackN* newSteckN);

int SmartCalc(const char* arr, long double* res);
int SmartCalcX(const char* arr, long double x, long double* res);
int Parser(StackO* newSteckO, StackN* newSteckN, char* str, long double* res,
           long double X);
char* PushOperForString(char* str, StackO* newSteckO);
int Calculation(StackO* newSteckO, StackN* newSteckN);
long double (*returnFunction(char operation))(long double);
long double OperationResult(long double number_1, long double number_2,
                            char operation);
char* LineToNumConversion(StackN* newSteckN, char* str, int minus);
int Priority(char ch);
int SpecialCase(StackO* newSteckO, StackN* newSteckN);
int PutOperationStack(StackO* newSteckO, StackN* newSteckN, int priori,
                      char** str);
int UnaryMinus(StackO* newSteckO);
void exponentiation(long double* number_1, long double* number_2,
                    StackO* newSteckO, StackN* newSteckN);

long double MonthlyPaymentAnnuity(long double sum_total, int term,
                                  long double inter_rate);
long double TotalPayment(long double annuity, int term);
long double Overpayment(long double total_pay, long double sum_total);
long double TotalPaymentDiff(long double sum_total, int term,
                             long double inter_rate);
long double MonthlyPaymentDiff(long double total_pay, int term);

long double InterChanges(long double* deposit_amount, int period_plac,
                         int period_pay, long double inter_rate, bool type,
                         long double replen, long double withdrawals);
long double TaxAmount(long double inter_changes, long double tax_rate);
long double AmountTerm(long double inter_changes, long double deposit_amount,
                       long double tax_amount);
