#include "pathwindow.h"

#include "ui_pathwindow.h"

PathWindow::PathWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::PathWindow) {
  ui->setupUi(this);
  connect(this, SIGNAL(PathlineSignal(QString)), this,
          SLOT(sloatPathSignal(QString)));
}

PathWindow::~PathWindow() { delete ui; }

void PathWindow::on_pushButton_back_clicked() {
  this->close();
  emit mainWindow();
}

void PathWindow::sloatPathSignal(QString text) {
  QByteArray ba = text.toLocal8Bit();
  line_res = ba.data();
  ui->widget->clearGraphs();
  WidgetGraph();
}

void PathWindow::WidgetGraph() {
  h = 0.1;
  xBegin = -10000;
  xEnd = 10000 + h;
  y.clear();
  x.clear();
  QPen my_pen;
  my_pen.setColor(QColor(255, 192, 203));
  my_pen.setWidthF(2);
  N = (xEnd - xBegin) / h + 2;
  if (N > 1000000) N = 1000000;
  for (X = xBegin; X <= xEnd; X += h) {
    long double x_calc = 0;
    SmartCalcX(line_res, X, &x_calc);
    x.push_back(X);
    y.push_back((double)x_calc);
  }
  ui->widget->addGraph();
  ui->widget->graph(0)->setData(x, y);
  ui->widget->graph(0)->setPen(my_pen);
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
  ui->widget->replot();
}
