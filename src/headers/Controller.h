#ifndef SOURCES_CONTROLLER_H_
#define SOURCES_CONTROLLER_H_

#include <string>

#include "../headers/Model.h"

namespace s21 {
class Controller {
 public:
  Controller(s21::Model &m);
  ~Controller() noexcept;

  std::string getBaseResult(std::string rawString, std::string xstr);
  std::vector<double> getCreditAut(double sum, int months, double perc);
  std::vector<double> getCreditDiff(double sum, int months, double perc);
  std::tuple<std::vector<double>, std::vector<double>, std::string>
  getDataGraph(std::string &rawString, double &xStart, double &xStop, int &N);

 private:
  s21::Model model;
};
}  // namespace s21

#endif  // SOURCES_CONTROLLER_H_