#include <QApplication>

#include "../headers/Model.h"
#include "../headers/View.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Model model;
  s21::Controller controller(model);
  s21::MainWindow w(controller);
  w.show();
  return a.exec();
}
