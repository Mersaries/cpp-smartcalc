#include "../headers/View.h"

#include "../design/ui_mainwindow.h"

s21::MainWindow::MainWindow(s21::Controller &c, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller(c) {
  ui->setupUi(this);
  connectAllFunc();
}

s21::MainWindow::~MainWindow() { delete ui; }

void s21::MainWindow::connectAllFunc() {
  connect(ui->one_button, SIGNAL(clicked()), this, SLOT(addNumbers()));
  connect(ui->two_button, SIGNAL(clicked()), this, SLOT(addNumbers()));
  connect(ui->three_button, SIGNAL(clicked()), this, SLOT(addNumbers()));
  connect(ui->four_button, SIGNAL(clicked()), this, SLOT(addNumbers()));
  connect(ui->five_button, SIGNAL(clicked()), this, SLOT(addNumbers()));
  connect(ui->six_button, SIGNAL(clicked()), this, SLOT(addNumbers()));
  connect(ui->seven_button, SIGNAL(clicked()), this, SLOT(addNumbers()));
  connect(ui->eight_button, SIGNAL(clicked()), this, SLOT(addNumbers()));
  connect(ui->nine_button, SIGNAL(clicked()), this, SLOT(addNumbers()));
  connect(ui->zero_button, SIGNAL(clicked()), this, SLOT(addNumbers()));
  connect(ui->dot_button, SIGNAL(clicked()), this, SLOT(addNumbers()));
  connect(ui->x_button, SIGNAL(clicked()), this, SLOT(addNumbers()));

  connect(ui->del_button, SIGNAL(clicked()), this, SLOT(delSyms()));
  connect(ui->ac_button, SIGNAL(clicked()), this, SLOT(delSyms()));

  connect(ui->plus_button, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->minus_button, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->mult_button, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->div_button, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->mod_button, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->pow_button, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->sqrt, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->sin, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->asin, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->cos, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->acos, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->tan, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->atan, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->ln, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->log, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->close_button, SIGNAL(clicked()), this, SLOT(addOperators()));
  connect(ui->open_button, SIGNAL(clicked()), this, SLOT(addOperators()));

  connect(ui->calc_button, SIGNAL(clicked()), this, SLOT(startCalc()));

  connect(ui->credit_start, SIGNAL(clicked()), this, SLOT(startCredit()));

  connect(ui->graph_button, SIGNAL(clicked()), this, SLOT(getGraph()));
}

void s21::MainWindow::addOperators() {
  QPushButton *clickButton = qobject_cast<QPushButton *>(sender());
  QString textButton = clickButton->text();
  QString text = ui->lineEdit->text();
  ui->lineEdit->setText(text + textButton);
}

void s21::MainWindow::addNumbers() {
  QPushButton *clickButton = qobject_cast<QPushButton *>(sender());
  QString text = ui->lineEdit->text() + clickButton->text();
  ui->lineEdit->setText(text);
}

void s21::MainWindow::delSyms() {
  QPushButton *clickButton = qobject_cast<QPushButton *>(sender());
  QString nameButton = clickButton->objectName();
  if (nameButton == "del_button") {
    QString text = ui->lineEdit->text();
    text.chop(1);
    ui->lineEdit->setText(text);
  } else if (nameButton == "ac_button") {
    ui->lineEdit->setText("");
  }
}

void s21::MainWindow::startCalc() {
  // считать данные и запустить в контроллер и затем вернуть результат
  std::string rawString = ui->lineEdit->text().toStdString();
  std::string xstr = ui->xv_edit->text().toStdString();

  std::string result = controller.getBaseResult(rawString, xstr);
  ui->lineEdit->setText(QString::fromUtf8(result.c_str()));
}

void s21::MainWindow::startCredit() {
  int precision = 2;
  int months = ui->credit_months->value();
  double sum = ui->credit_sum->value(), perc = ui->credit_perc->value();

  if (ui->aut_radio->isChecked()) {
    std::vector result = controller.getCreditAut(sum, months, perc);
    ui->month_pay->setText(QString::number(result[0], 'L', precision));
    ui->perc_pay->setText(QString::number(result[2], 'L', precision));
    ui->all_pay->setText(QString::number(result[1], 'L', precision));
  } else if (ui->dif_radio->isChecked()) {
    std::vector result = controller.getCreditDiff(sum, months, perc);
    ui->month_pay->setText(QString::number(result[0], 'L', precision) + "..." +
                           QString::number(result[1], 'L', precision));
    ui->perc_pay->setText(QString::number(result[2], 'L', precision));
    ui->all_pay->setText(QString::number(result[3], 'L', precision));
  }
}

void s21::MainWindow::getGraph() {
  std::vector<double> xVect = {};
  std::vector<double> yVect = {};
  std::string err = {};

  int N = ui->nspin->value();
  double xStart, xStop, yStart, yStop;
  if (ui->xspin_start->value() < ui->xspin_stop->value()) {
    xStart = ui->xspin_start->value();
    xStop = ui->xspin_stop->value();
  } else {
    xStop = ui->xspin_start->value();
    xStart = ui->xspin_stop->value();
  }
  if (ui->yspin_start->value() < ui->yspin_stop->value()) {
    yStart = ui->yspin_start->value();
    yStop = ui->yspin_stop->value();
  } else {
    yStop = ui->yspin_start->value();
    yStart = ui->yspin_stop->value();
  }

  ui->graph->clearGraphs();
  ui->graph->xAxis->setRange(xStart, xStop);
  ui->graph->yAxis->setRange(yStart, yStop);

  std::string rawString = ui->lineEdit->text().toStdString();
  std::tie(xVect, yVect, err) =
      controller.getDataGraph(rawString, xStart, xStop, N);

  if (err.length() == 0) {
    QVector<double> x = QVector<double>(xVect.begin(), xVect.end());
    QVector<double> y = QVector<double>(yVect.begin(), yVect.end());
    ui->graph->addGraph();
    ui->graph->graph(0)->addData(x, y);
    ui->graph->replot();
  } else {
    ui->lineEdit->setText(QString::fromUtf8(err.c_str()));
  }
}