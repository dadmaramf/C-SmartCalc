#ifndef PATHWINDOW_H
#define PATHWINDOW_H

#include <QDialog>
#include <QVector>

#include "qcustomplot.h"

extern "C" {
#include "../s21_SmartCalc.h"
}
namespace Ui {
class PathWindow;
}

class PathWindow : public QDialog {
  Q_OBJECT

 public:
  explicit PathWindow(QWidget *parent = nullptr);
  ~PathWindow();

 private:
  Ui::PathWindow *ui;
  double xBegin, xEnd, h;
  long double X;
  int N;
  QVector<double> x, y;
  char *line_res;
 signals:
  void mainWindow();
  void PathlineSignal(QString str);
 private slots:
  void sloatPathSignal(QString str);
  void WidgetGraph();
  void on_pushButton_back_clicked();
};

#endif  // PATHWINDOW_H
