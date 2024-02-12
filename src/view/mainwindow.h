#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <pathwindow.h>

#include <QMainWindow>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  PathWindow *path;
  bool val_x = false;
  void PassingForValueX();
  // credit and debit private
  void CreditFunValidat();
  void DepitFunValidat();
  QDoubleValidator loan_amount_validator;
 signals:
  void PathlineSignal(QString str);
 private slots:
  void digits_num();
  void on_pushButton_mul_clicked();
  void on_pushButton_div_clicked();
  void on_pushButton_equals_clicked();
  void on_pushButton_c_clicked();
  void on_pushButton_graph_clicked();
  void on_pushButton_x_clicked();
  void on_pushButton_credit_clicked();
  void on_pushButton_depos_clicked();
  void on_pushButton_annuit_clicked();
  void on_pushButton_diff_clicked();
  void on_pushButton_backcredit_clicked();
  void on_pushButton_resdepos_clicked();
  void on_pushButton_backdepos_clicked();
};
#endif  // MAINWINDOW_H
