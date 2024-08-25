#ifndef SOURCES_VIEW_H_
#define SOURCES_VIEW_H_

#include <QMainWindow>

#include "Controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(s21::Controller &c, QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  s21::Controller controller;

 private slots:
  void delSyms();
  void addNumbers();
  void addOperators();
  void connectAllFunc();
  void startCalc();
  void startCredit();
  void getGraph();
};
};      // namespace s21
#endif  // SOURCES_VIEW_H_
