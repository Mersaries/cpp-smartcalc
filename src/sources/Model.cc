#include "../headers/Model.h"

s21::Model::Model() noexcept {};

s21::Model::~Model() noexcept {
  rawString.clear();
  postfixString.clear();
};

std::string s21::Model::baseCalculate(std::string &rawString,
                                      std::string &xstr) {
  double result = 0;
  std::ostringstream ss;
  try {
    this->rawString = rawString;
    this->postfixString = parse(rawString);
    if (xstr.length() == 0) {
      xstr = "0";
    }
    double x = std::stod(xstr);
    result = calc(postfixString, x);
  } catch (std::invalid_argument const &ex) {
    std::string exception(ex.what());
    if (exception == "stod") {
      exception = "Invalid x value!";
    }
    return exception;
  }
  ss.precision(7);
  ss << result;
  std::string resultStr = ss.str();
  return resultStr;
}

std::string s21::Model::parse(std::string rawString) {
  /*
  cos - c
  sin - s
  tan - t
  acos - o
  asin - i
  atan - a
  sqrt - q
  ln - n
  log - g
  mod - m
  */

  if (rawString.length() > 255)
    throw std::invalid_argument("String length exceeded!");

  // operators stack
  std::stack<Operator> st = {};
  std::string result = "";
  std::size_t pos = 0;  // current position of element in string
  // rawString.tolower();
  while (rawString.length() > pos) {
    if (rawString.find_first_of("1234567890x", pos) == pos) {
      isNumber(rawString, result, pos);
    } else if (rawString.find_first_of("()", pos) == pos) {
      isBracket(rawString, result, st, pos);
      ++pos;
    } else if (rawString.find_first_of("cstal", pos) == pos) {
      isFunc(rawString, result, st, pos);
    } else if (rawString.find_first_of("+-", pos) == pos) {
      isAddSub(rawString, result, st, pos);
      ++pos;
    } else if (rawString.find_first_of("*/^m", pos) == pos) {
      isOtherOperation(rawString, result, st, pos);
      ++pos;
    } else if (rawString.find_first_of("\t\n ", pos) == pos) {
      ++pos;
    } else {
      throw std::invalid_argument("Invalid expression!");
    }
  }

  if (!st.empty()) {
    if (st.top().priority == BRACKET) {
      throw std::invalid_argument("Invalid expression!");
    }
    while (!st.empty()) {
      auto element = st.top();
      st.pop();
      result.append(" ");
      result.append(element.name);
    }
  }

  return result;
}

void s21::Model::isNumber(std::string &rawString, std::string &result,
                          std::size_t &pos) {
  if (result.length() != 0) result.append(" ");
  if (rawString[pos] == 'x') {
    ++pos;
    result.append("x");
  } else {
    std::size_t offset = 0;
    double number = std::stod(&rawString[pos], &offset);
    pos += offset;
    result.append(std::to_string(number));
  }
}

void s21::Model::isBracket(std::string &rawString, std::string &result,
                           std::stack<Operator> &st, std::size_t &pos) {
  Operator element = {};
  if (rawString[pos] == '(') {
    element.name = "(";
    element.priority = BRACKET;
    st.push(element);
  } else if (rawString[pos] == ')') {
    element = st.top();
    st.pop();
    bool flag = true;
    while (flag) {
      if (element.name == "(") {
        flag = false;
      } else if (!st.empty()) {
        result.append(" ");
        result.append(element.name);
        element = st.top();
        st.pop();
      } else {
        throw std::invalid_argument("Invalid expression!");
      }
    }
    if (!flag && !st.empty()) {
      element = st.top();
      if (element.priority == FUNC) {
        st.pop();
        result.append(" ");
        result.append(element.name);
      }
    }
  } else {
    throw std::invalid_argument("Invalid expression!");
  }
}

void s21::Model::isAddSub(std::string &rawString, std::string &result,
                          std::stack<Operator> &st, std::size_t &pos) {
  Operator element = {};

  if (pos == 0 || (pos > 0 && rawString[pos - 1] == '(')) {
    if (rawString[pos] == '-') {
      element.priority = UNOMINUS;
      element.name = "~";
      addOperator(element, st, result);
    } else if (rawString[pos] == '+') {
      element.priority = UNOPLUS;
      element.name = "#";
      addOperator(element, st, result);
    } else {
      throw std::invalid_argument("Invalid expression!");
    }
  } else {
    if (rawString[pos] == '-') {
      element.priority = MINUS;
      element.name = "-";
      addOperator(element, st, result);
    } else if (rawString[pos] == '+') {
      element.priority = PLUS;
      element.name = "+";
      addOperator(element, st, result);
    }
  }
}

void s21::Model::isFunc(std::string &rawString, std::string &result,
                        std::stack<Operator> &st, std::size_t &pos) {
  Operator element = {};
  element.priority = FUNC;
  size_t len = 0;

  if (rawString.find("cos", pos) == pos) {
    element.name = "c";
    len = 3;
  } else if (rawString.find("sin", pos) == pos) {
    element.name = "s";
    len = 3;
  } else if (rawString.find("tan", pos) == pos) {
    element.name = "t";
    len = 3;
  } else if (rawString.find("acos", pos) == pos) {
    element.name = "o";
    len = 4;
  } else if (rawString.find("asin", pos) == pos) {
    element.name = "i";
    len = 4;
  } else if (rawString.find("atan", pos) == pos) {
    element.name = "a";
    len = 4;
  } else if (rawString.find("sqrt", pos) == pos) {
    element.name = "q";
    len = 4;
  } else if (rawString.find("ln", pos) == pos) {
    element.name = "n";
    len = 2;
  } else if (rawString.find("log", pos) == pos) {
    element.name = "g";
    len = 3;
  } else {
    throw std::invalid_argument("Invalid expression!");
  }

  addOperator(element, st, result);
  pos = pos + len;
}

void s21::Model::isOtherOperation(std::string &rawString, std::string &result,
                                  std::stack<Operator> &st, std::size_t &pos) {
  Operator element = {};

  if (rawString[pos] == '*') {
    element.priority = MULT;
    element.name = "*";
    addOperator(element, st, result);
  } else if (rawString[pos] == '/') {
    element.priority = DIV;
    element.name = "/";
    addOperator(element, st, result);
  } else if (rawString[pos] == '^') {
    element.priority = POWER;
    element.name = "^";
    addOperator(element, st, result);
  } else if (rawString.find("mod", pos) == pos) {
    element.priority = REM;
    element.name = "m";
    addOperator(element, st, result);
    pos = pos + 2;
  } else {
    throw std::invalid_argument("Invalid expression!");
  }
}

void s21::Model::addOperator(Operator element, std::stack<Operator> &st,
                             std::string &result) {
  bool flag = true;
  Operator topElement = {};

  while (flag) {
    if (st.empty()) {
      st.push(element);
      flag = false;
    } else {
      topElement = st.top();
      if (topElement.priority < element.priority) {
        st.push(element);
        flag = false;
      } else {
        st.pop();
        result.append(" ");
        result.append(topElement.name);
      }
    }
  }
}

double s21::Model::calc(std::string postfixString, double x) {
  // char sep = ' ';
  std::size_t pos = 0;
  std::size_t offset = 0;
  double number = 0;
  std::stack<double> resultStack = {};

  while (postfixString.length() > pos) {
    if (postfixString.find_first_of(" ", pos) == pos) {
      ++pos;
    } else if (postfixString.find_first_of("1234567890", pos) == pos) {
      number = std::stod(&postfixString[pos], &offset);
      pos += offset;
      resultStack.push(number);
    } else if (postfixString.find_first_of("x", pos) == pos) {
      ++pos;
      resultStack.push(x);
    } else if (postfixString.find_first_of("~#", pos) == pos) {
      if (postfixString[pos] == '~') {
        double topNumber = resultStack.top();
        resultStack.pop();
        resultStack.push(topNumber * (-1));
      }
      ++pos;
    } else if (postfixString.find_first_of("+-*/m^", pos) == pos) {
      calcOtherOperation(resultStack, postfixString, pos);
      ++pos;
    } else if (postfixString.find_first_of("cstoiaqng", pos) == pos) {
      calcFunc(resultStack, postfixString, pos);
      ++pos;
    } else {
      throw std::invalid_argument("Invalid polish notation (postfix) string!");
    }
  }

  if (resultStack.size() == 1) {
    number = resultStack.top();
    resultStack.pop();

  } else {
    throw std::invalid_argument("Invalid polish notation (postfix) string!");
  }

  return number;
}

void s21::Model::calcOtherOperation(std::stack<double> &resultStack,
                                    std::string &postfixString,
                                    std::size_t &pos) {
  double num2 = resultStack.top();
  resultStack.pop();
  if (resultStack.size() == 0) {
    throw std::invalid_argument("Invalid expression!");
  }
  double num1 = resultStack.top();
  resultStack.pop();

  if (postfixString[pos] == 'm') {
    resultStack.push(fmod(num1, num2));
  } else if (postfixString[pos] == '+') {
    resultStack.push(num1 + num2);
  } else if (postfixString[pos] == '-') {
    resultStack.push(num1 - num2);
  } else if (postfixString[pos] == '/') {
    resultStack.push(num1 / num2);
  } else if (postfixString[pos] == '*') {
    resultStack.push(num1 * num2);
  } else if (postfixString[pos] == '^') {
    resultStack.push(pow(num1, num2));
  } else {
    throw std::invalid_argument("Invalid polish notation (postfix) string!");
  }
}

void s21::Model::calcFunc(std::stack<double> &resultStack,
                          std::string &postfixString, std::size_t &pos) {
  double num = resultStack.top();
  resultStack.pop();

  if (postfixString[pos] == 'c') {
    resultStack.push(cos(num));
  } else if (postfixString[pos] == 's') {
    resultStack.push(sin(num));
  } else if (postfixString[pos] == 't') {
    resultStack.push(tan(num));
  } else if (postfixString[pos] == 'o') {
    resultStack.push(acos(num));
  } else if (postfixString[pos] == 'i') {
    resultStack.push(asin(num));
  } else if (postfixString[pos] == 'a') {
    resultStack.push(atan(num));
  } else if (postfixString[pos] == 'q') {
    resultStack.push(sqrt(num));
  } else if (postfixString[pos] == 'n') {
    resultStack.push(log(num));
  } else if (postfixString[pos] == 'g') {
    resultStack.push(log10(num));
  } else {
    throw std::invalid_argument("Invalid polish notation (postfix) string!");
  }
}

// bonus #1
std::vector<double> s21::Model::creditAut(double sum, int months, double perc) {
  std::vector<double> result = {};

  // monthPay, overPay, totalPay
  double P = perc / 12 * 0.01;
  double monthPay = sum * (P + P / (pow(1 + P, months) - 1));
  double totalPay = monthPay * months;
  double overPay = totalPay - sum;

  result.push_back(monthPay);
  result.push_back(totalPay);
  result.push_back(overPay);

  return result;
}

std::vector<double> s21::Model::creditDiff(double sum, int months,
                                           double perc) {
  std::vector<double> result = {};

  double P = perc / 12 * 0.01, baseMonthPay = sum / months, rest = sum,
         percMonth = rest * P;

  double totalPay = 0, monthPayMin = 0, overPay = 0;
  double monthPayMax = percMonth + baseMonthPay;
  for (int i = 0; i < months; i++) {
    percMonth = rest * P;
    rest -= baseMonthPay;
    monthPayMin = percMonth + baseMonthPay;
    totalPay += monthPayMin;
  }
  overPay = totalPay - sum;

  result.push_back(monthPayMax);
  result.push_back(monthPayMin);
  result.push_back(overPay);
  result.push_back(totalPay);

  return result;
}

std::tuple<std::vector<double>, std::vector<double>, std::string>
s21::Model::getCoordinates(std::string &rawString, double &xStart,
                           double &xStop, int &N) {
  std::vector<double> xVect = {};
  std::vector<double> yVect = {};
  double X = 0, Y = 0;
  std::string result = {}, xstr = {}, err = {};

  double h = (xStop - xStart) / (N + 1.0);

  if (h != 0.0) {
    for (X = xStart; X <= xStop; X += h) {
      xstr = std::to_string(X);
      try {
        result = baseCalculate(rawString, xstr);
        Y = std::stod(result);
        xVect.push_back(X);
        yVect.push_back(Y);
      } catch (std::invalid_argument &ex) {
        // throw std::invalid_argument("Error during the calculation of
        // coordinates!");
        err = "Error during the calculation of coordinates!";
      }
    }
  } else {
    for (int i = 0, X = xStart; i < 2; ++i) {
      xstr = std::to_string(X);
      try {
        result = baseCalculate(rawString, xstr);
        Y = std::stod(result);
        xVect.push_back(X);
        yVect.push_back(Y);
      } catch (std::invalid_argument &ex) {
        // throw std::invalid_argument("Error during the calculation of
        // coordinates!");
        err = "Error during the calculation of coordinates!";
      }
      X = xStop;
    }
  }

  return std::tuple(xVect, yVect, err);
}

// bonus #2
// std::tuple<std::string, std::string, std::string>
// s21::Model::calcualteDeposit() {
//   DepositInit initials = {};
//   initials.sum = 100000;
//   initials.dateDeposit = 12;
//   initials.typeDateDeposit = "Месяцев";
//   initials.startDate = "03/03/2024";
//   initials.percentRate = 12;
//   initials.percentRateType = "Фиксированная";
//   initials.taxRate = 13;
//   initials.capitalize = false;
//   initials.periodPayments = "В конце срока";
// }