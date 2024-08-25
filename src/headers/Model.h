#ifndef SOURCES_MODEL_H_
#define SOURCES_MODEL_H_

#include <cmath>
#include <exception>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

namespace s21 {

enum Priority {
  NUMBER = 0,
  X = 0,
  BRACKET = 1,
  PLUS = 2,
  MINUS = 2,
  MULT = 3,
  DIV = 3,
  REM = 4,
  POWER = 4,
  UNOPLUS = 5,
  UNOMINUS = 5,
  FUNC = 6,
};

// struct for operations stack
struct Operator {
  Priority priority;
  std::string name;
};

class Model {
 public:
  Model() noexcept;
  ~Model() noexcept;

  // public methods
  // method for basic calculation
  std::string baseCalculate(std::string &rawString, std::string &xstr);

  // bonus #1 credit aut
  std::vector<double> creditAut(double sum, int months, double perc);

  // bonus #1 credit diff
  std::vector<double> creditDiff(double sum, int months, double perc);

  std::tuple<std::vector<double>, std::vector<double>, std::string>
  getCoordinates(std::string &rawString, double &xStart, double &xStop, int &N);

  // std::tuple<std::string, std::string, std::string> calcualteDeposit();

 private:
  // raw string
  std::string rawString = {};

  // reverse polish notation string
  std::string postfixString = {};

  // method for parsing infix string
  std::string parse(std::string rawString);

  // method for get result number
  double calc(std::string postfixString, double x);

  // isNumber
  void isNumber(std::string &rawString, std::string &result, std::size_t &pos);

  // isBracket
  void isBracket(std::string &rawString, std::string &result,
                 std::stack<Operator> &st, std::size_t &pos);

  // isAddSub
  void isAddSub(std::string &rawString, std::string &result,
                std::stack<Operator> &st, std::size_t &pos);

  // isFunc
  void isFunc(std::string &rawString, std::string &result,
              std::stack<Operator> &st, std::size_t &pos);

  // isOtherOperation
  void isOtherOperation(std::string &rawString, std::string &result,
                        std::stack<Operator> &st, std::size_t &pos);

  // addOperator
  void addOperator(Operator element, std::stack<Operator> &st,
                   std::string &result);
  // static inline bool exists;

  // calc operations +-*/m^
  void calcOtherOperation(std::stack<double> &resultStack,
                          std::string &postfixString, std::size_t &pos);

  // calc func operations
  void calcFunc(std::stack<double> &resultStack, std::string &postfixString,
                std::size_t &pos);

  // bonus #2 deposit
  //  struct DepositInit {
  //    long double sum; // сумма вклада
  //    int dateDeposit; // срок размещения
  //    std::string typeDateDeposit; // тип размещения
  //    std::string startDate; // начало срока
  //    double percentRate; // процентная ставка
  //    std::string percentRateType; // тип процентной ставки
  //    double taxRate; // налоговая ставка
  //    bool capitalize; // капитализация процентов
  //    std::string periodPayments; // периодичность выплат

  //   std::string accuredPercents; // начисленные проценты
  //   std::string sumTax; // сумма налога
  //   std::string sumOnDeposit; // сумма на вкладе к концу срока

  //   void calculate();
  // };
};
}  // namespace s21

#endif  // SOURCES_MODEL_H_