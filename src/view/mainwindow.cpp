#include "mainwindow.h"

#include "ui_mainwindow.h"
//#include "pathwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      loan_amount_validator(0, 100000000, 7, this) {
  ui->setupUi(this);
  path = new PathWindow;
  QLocale locale(QLocale::English);
  loan_amount_validator.setNotation(QDoubleValidator::StandardNotation);
  loan_amount_validator.setLocale(locale);
  ui->valx->setValidator(&loan_amount_validator);
  ui->stackedWidget->setCurrentIndex(2);
  connect(path, &PathWindow::mainWindow, this, &MainWindow::show);
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_open, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_closed, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_root, SIGNAL(clicked()), this, SLOT(digits_num()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(digits_num()));

  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_num()));

  //    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_num()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_num() {
  QPushButton *button = (QPushButton *)sender();
  QByteArray button_text = button->text().toLocal8Bit();
  const char *str = button_text.data();

  if (ui->result->text() == '0' && !strpbrk(str, "+/*.^"))
    ui->result->setText("");
  if (strpbrk(str, "1234567890+-()^.m"))
    ui->result->setText(ui->result->text() + button->text());
  else if (strpbrk(str, "√"))
    ui->result->setText(ui->result->text() + "sqrt(");
  else
    ui->result->setText(ui->result->text() + button->text() + "(");
}

void MainWindow::on_pushButton_mul_clicked() {
  ui->result->setText(ui->result->text() + "*");
}

void MainWindow::on_pushButton_div_clicked() {
  ui->result->setText(ui->result->text() + "/");
}

void MainWindow::on_pushButton_equals_clicked() {
  long double x = ui->valx->text().toDouble();
  std::string str = ui->result->text().toStdString();
  const char *ptrStr = str.c_str();
  long double res = 0;
  int error = 1;
  error = x == 0 ? SmartCalc(ptrStr, &res) : SmartCalcX(ptrStr, x, &res);
  if (error) {
    QString result = QString::number(res, 'g', 15);
    ui->result->setText(result);
  } else
    ui->result->setText("Error¡");
}

void MainWindow::on_pushButton_c_clicked() {
  QString res = ui->result->text();
  res.chop(1);
  ui->result->setText(res);
  if (ui->result->text() == "") {
    ui->result->setText("0");
  }
}

void MainWindow::on_pushButton_graph_clicked() {
  QString text = ui->result->text();
  connect(this, SIGNAL(PathlineSignal(QString)), path,
          SIGNAL(PathlineSignal(QString)));
  emit PathlineSignal(text);
  path->show();
  ui->result->setText("0");
  this->close();
}

void MainWindow::PassingForValueX() {
  ui->result->setText("Enter a value for the x:");
}

void MainWindow::on_pushButton_x_clicked() {
  ui->result->setText(ui->result->text() + "x");
  val_x = true;
}

void MainWindow::on_pushButton_credit_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
  CreditFunValidat();
}

void MainWindow::on_pushButton_depos_clicked() {
  ui->stackedWidget->setCurrentIndex(1);
  DepitFunValidat();
}
void MainWindow::CreditFunValidat() {
  ui->lineEdit_totalamoutcredit->setValidator(&loan_amount_validator);
  ui->lineEdit_creditterm->setValidator(&loan_amount_validator);
  ui->lineEdit_intrate->setValidator(&loan_amount_validator);
}
void MainWindow::DepitFunValidat() {
  ui->lineEdit_deposam->setValidator(&loan_amount_validator);
  ui->lineEdit_termplac->setValidator(&loan_amount_validator);
  ui->lineEdit_taxrate->setValidator(&loan_amount_validator);
  ui->lineEdit_intrate->setValidator(&loan_amount_validator);
  ui->lineEdit_repl->setValidator(&loan_amount_validator);
  ui->lineEdit_with->setValidator(&loan_amount_validator);
}

void MainWindow::on_pushButton_annuit_clicked() {
  if (!(ui->lineEdit_totalamoutcredit->text().isEmpty() ||
        ui->lineEdit_creditterm->text().isEmpty() ||
        ui->lineEdit_intratecredit->text().isEmpty())) {
    long double sum_total = ui->lineEdit_totalamoutcredit->text().toDouble();
    int term = ui->lineEdit_creditterm->text().toInt();
    long double inter_rate = ui->lineEdit_intratecredit->text().toDouble();
    long double annuity_calc =
        MonthlyPaymentAnnuity(sum_total, term, inter_rate);
    long double total_pay = TotalPayment(annuity_calc, term);
    long double overpayment = Overpayment(total_pay, sum_total);
    QString mp = QString::number(annuity_calc, 'g', 7);
    QString tp = QString::number(total_pay, 'g', 7);
    QString ovp = QString::number(overpayment, 'g', 7);
    ui->lineEdit_monthly->setText(mp);
    ui->lineEdit_totalpaycredit->setText(tp);
    ui->lineEdit_overpay->setText(ovp);
  }
}

void MainWindow::on_pushButton_diff_clicked() {
  long double sum_total = ui->lineEdit_totalamoutcredit->text().toDouble();
  int term = ui->lineEdit_creditterm->text().toInt();
  long double inter_rate = ui->lineEdit_intratecredit->text().toDouble();
  long double total_pay = TotalPaymentDiff(sum_total, term, inter_rate);
  long double monthly_pay = MonthlyPaymentDiff(total_pay, term);
  long double overpayment = Overpayment(total_pay, sum_total);
  QString mp = QString::number(monthly_pay, 'g', 7);
  QString tp = QString::number(total_pay, 'g', 7);
  QString ovp = QString::number(overpayment, 'g', 7);
  ui->lineEdit_monthly->setText(mp);
  ui->lineEdit_totalpaycredit->setText(tp);
  ui->lineEdit_overpay->setText(ovp);
}

void MainWindow::on_pushButton_backcredit_clicked() {
  ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_resdepos_clicked() {
  if (!(ui->lineEdit_deposam->text().isEmpty() ||
        ui->lineEdit_termplac->text().isEmpty() ||
        ui->lineEdit_taxrate->text().isEmpty() ||
        ui->lineEdit_intrate->text().isEmpty() ||
        ui->lineEdit_repl->text().isEmpty() ||
        ui->lineEdit_with->text().isEmpty())) {
    long double deposit_amount = ui->lineEdit_deposam->text().toDouble();
    int period_plac = ui->comboBox_period->currentIndex() ? 1 : 12;

    int period_pay = ui->lineEdit_termplac->text().toInt();
    long double inter_rate = ui->lineEdit_intrate->text().toDouble();
    bool type = ui->radioButton_capital->isChecked();
    long double replen = ui->lineEdit_repl->text().toDouble();
    long double withdrawals = ui->lineEdit_with->text().toDouble();
    long double tax_rate = ui->lineEdit_taxrate->text().toDouble();
    long double inter_changes =
        InterChanges(&deposit_amount, period_plac, period_pay, inter_rate, type,
                     replen, withdrawals);
    long double tax_amount = TaxAmount(inter_changes, tax_rate);
    long double amout_term =
        AmountTerm(inter_changes, deposit_amount, tax_amount);
    printf("%Lf, %d, %Lf, %Lf, %Lf, %Lf, %d, %d", deposit_amount, period_pay,
           inter_rate, tax_rate, replen, withdrawals, type, period_plac);
    QString tot_e = QString::number(inter_changes, 'g', 7);
    QString tax_a = QString::number(tax_amount, 'g', 7);
    QString tot_a = QString::number(amout_term, 'g', 7);
    ui->lineEdit_intcharg->setText(tot_e);
    ui->lineEdit_TaxAm->setText(tax_a);
    ui->lineEdit_final->setText(tot_a);
  }
}

void MainWindow::on_pushButton_backdepos_clicked() {
  ui->stackedWidget->setCurrentIndex(2);
}
