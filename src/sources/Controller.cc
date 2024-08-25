#include "../headers/Controller.h"

s21::Controller::Controller(s21::Model &m) : model(m){};

s21::Controller::~Controller() noexcept {};

std::string s21::Controller::getBaseResult(std::string rawString,
                                           std::string xstr) {
  std::string result = model.baseCalculate(rawString, xstr);
  return result;
};

std::vector<double> s21::Controller::getCreditAut(double sum, int months,
                                                  double perc) {
  std::vector<double> resultVector = model.creditAut(sum, months, perc);
  return resultVector;
};

std::vector<double> s21::Controller::getCreditDiff(double sum, int months,
                                                   double perc) {
  std::vector<double> resultVector = model.creditDiff(sum, months, perc);
  return resultVector;
};

std::tuple<std::vector<double>, std::vector<double>, std::string>
s21::Controller::getDataGraph(std::string &rawString, double &xStart,
                              double &xStop, int &N) {
  // std::vector<double> xVect = {};
  // std::vector<double> yVect = {};
  // std::string err = {};

  // std::tie(xVect, yVect, err) =

  std::tuple<std::vector<double>, std::vector<double>, std::string>
      resultTuple = model.getCoordinates(rawString, xStart, xStop, N);
  return resultTuple;
};