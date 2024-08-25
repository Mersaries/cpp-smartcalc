#include <gtest/gtest.h>

#include "../headers/Model.h"

TEST(ModelTest, BaseCalculateTest_1) {
  std::string rawString = "x/x";
  std::string x = "1";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_EQ(std::stod(result), 1);
}

TEST(ModelTest, BaseCalculateTest_2) {
  std::string rawString = "sin(0.5)";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  std::cout << result << std::endl;
  EXPECT_FLOAT_EQ(std::stod(result), 0.479425538604);
}

TEST(ModelTest, BaseCalculateTest_3) {
  std::string rawString = "cos(0.5)";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 0.87758256189);
}

TEST(ModelTest, BaseCalculateTest_4) {
  std::string rawString = "tan(0.5)";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 0.54630248984);
}

TEST(ModelTest, BaseCalculateTest_5) {
  std::string rawString = "asin(0.5)";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 0.523598776);
}

TEST(ModelTest, BaseCalculateTest_6) {
  std::string rawString = "acos(0.5)";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 1.04719755);
}

TEST(ModelTest, BaseCalculateTest_7) {
  std::string rawString = "sqrt(0.5)";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 0.70710678118);
}

TEST(ModelTest, BaseCalculateTest_8) {
  std::string rawString = "ln(0.5)";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), -0.69314718056);
}

TEST(ModelTest, BaseCalculateTest_9) {
  std::string rawString = "log(0.5)";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), -0.30102999566);
}

TEST(ModelTest, BaseCalculateTest_10) {
  std::string rawString = "10mod7";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 3);
}

TEST(ModelTest, BaseCalculateTest_11) {
  std::string rawString = "3.76^4.3";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 297.377244656);
}

TEST(ModelTest, BaseCalculateTest_12) {
  std::string rawString = "567.32-(3.5^2*(3)+8.923)";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 521.647);
}

TEST(ModelTest, BaseCalculateTest_13) {
  std::string rawString = "8mod4";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 0);
}

TEST(ModelTest, BaseCalculateTest_14) {
  std::string rawString = "1023.456-(-123.45)*3^2.13+(32+(+2)-4)/sin(0.6)";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 2358.20723);
}

TEST(ModelTest, BaseCalculateTest_15) {
  std::string rawString = "8mod((((3))))";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 2);
}

TEST(ModelTest, BaseCalculateTest_16) {
  std::string rawString = "log(0)";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), -INFINITY);
}

TEST(ModelTest, BaseCalculateTest_17) {
  std::string rawString = "ln(0)";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), -INFINITY);
}

TEST(ModelTest, BaseCalculateTest_18) {
  std::string rawString =
      "111223432432532342342353415243523423402352950234023492032342342234243234"
      "235235235555555555555555555555555555555555555555555553243243421223432432"
      "532342342353415243523423402352950234023492032342342234243234235235235555"
      "55555555555555555555555555555555555555555";
  std::string x = "0";
  s21::Model model;
  std::string ex = model.baseCalculate(rawString, x);
  EXPECT_EQ(ex, "String length exceeded!");
}

TEST(ModelTest, BaseCalculateTest_19) {
  std::string rawString = "sin(3)+sin(1+2/4)/log(10)-ln(2.3^4)";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), -2.19302149708);
}

TEST(ModelTest, BaseCalculateTest_20) {
  std::string rawString =
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 128);
}

TEST(ModelTest, BaseCalculateTest_21) {
  std::string rawString = "atan(x)";
  std::string x = "0.5";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 0.4636476);
}

TEST(ModelTest, BaseCalculateTest_22) {
  std::string rawString = "atan (x)";
  std::string x = "0.5";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 0.4636476);
}

TEST(ModelTest, BaseCalculateTest_23) {
  std::string rawString = "atan(0.5)";
  std::string x = "";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 0.4636476);
}

TEST(ModelTest, BaseCalculateTest_24) {
  std::string rawString = "atan(x)";
  std::string x = "asd";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_EQ(result, "Invalid x value!");
}

TEST(ModelTest, BaseCoordinatesCalculate_1) {
  std::string rawString = "cos(x)";
  double xstart = 0, xstop = 10;
  int N = 8;
  s21::Model model;
  std::vector<double> x = {};
  std::vector<double> y = {};
  std::string error = "";
  std::tie(x, y, error) = model.getCoordinates(rawString, xstart, xstop, N);
  EXPECT_EQ(error, "");
  EXPECT_EQ(x.size(), 10);
  EXPECT_EQ(y.size(), 10);
  EXPECT_FLOAT_EQ(x[0], 0);
  EXPECT_FLOAT_EQ(x[9], 10);
}

TEST(ModelTest, BaseCoordinatesCalculate_2) {
  std::string rawString = "cos(x)";
  double xstart = 0, xstop = 0;
  int N = 8;
  s21::Model model;
  std::vector<double> x = {};
  std::vector<double> y = {};
  std::string error = "";
  std::tie(x, y, error) = model.getCoordinates(rawString, xstart, xstop, N);
  EXPECT_EQ(error, "");
  EXPECT_EQ(x.size(), 2);
  EXPECT_EQ(y.size(), 2);
}

TEST(ModelTest, BaseCoordinatesCalculate_3) {
  std::string rawString = "cosx)";
  double xstart = 0, xstop = 0;
  int N = 8;
  s21::Model model;
  std::vector<double> x = {};
  std::vector<double> y = {};
  std::string error = "";
  std::tie(x, y, error) = model.getCoordinates(rawString, xstart, xstop, N);
  EXPECT_EQ(error, "Error during the calculation of coordinates!");
}

TEST(ModelTest, BaseCoordinatesCalculate_4) {
  std::string rawString = "cosx)";
  double xstart = 0, xstop = 10;
  int N = 8;
  s21::Model model;
  std::vector<double> x = {};
  std::vector<double> y = {};
  std::string error = "";
  std::tie(x, y, error) = model.getCoordinates(rawString, xstart, xstop, N);
  EXPECT_EQ(error, "Error during the calculation of coordinates!");
}

TEST(ModelTest, BaseCalculateTestX_1) {
  std::string rawString = "x+4*4^x";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 4);
}

TEST(ModelTest, BaseCalculateTestX_2) {
  std::string rawString = "sin(x)-cos(x)^2";

  std::string x = std::to_string(3.14159265359 / 2.0);
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  std::cout << result << std::endl;
  EXPECT_FLOAT_EQ(std::stod(result), 1);
}

TEST(ModelTest, BaseCalculateTestX_3) {
  std::string rawString = "log(x+1/x)*1/25";
  std::string x = "4.5";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 0.026965857);
}

TEST(ModelTest, BaseCalculateTestX_4) {
  std::string rawString = "x+x-x";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_FLOAT_EQ(std::stod(result), 0);
}

TEST(ModelTest, BaseCalculateTestX_5) {
  std::string rawString = "x+x---------";
  std::string x = "0";
  s21::Model model;
  std::string ex = model.baseCalculate(rawString, x);
  EXPECT_EQ(ex, "Invalid expression!");
}

TEST(ModelTest, BaseCalculateTestX_6) {
  std::string rawString = "asdwx+x---------";
  std::string x = "3.14159265359 / 2.0";
  s21::Model model;
  std::string ex = model.baseCalculate(rawString, x);
  EXPECT_EQ(ex, "Invalid expression!");
}

TEST(ModelTest, BaseCalculateTestX_7) {
  std::string rawString = "123+4-x*(123-s(21))";
  std::string x = "3.14159265359 / 2.0";
  s21::Model model;
  std::string ex = model.baseCalculate(rawString, x);
  EXPECT_EQ(ex, "Invalid expression!");
}

TEST(ModelTest, BaseCalculateTestX_8) {
  std::string rawString = "asdwx+x---------";
  std::string x = "3.14159265359 / 2.0";
  s21::Model model;
  std::string ex = model.baseCalculate(rawString, x);
  EXPECT_EQ(ex, "Invalid expression!");
}

TEST(ModelTest, BaseCalculateTestX_9) {
  std::string rawString = "x/x";
  std::string x = "0";
  s21::Model model;
  std::string result = model.baseCalculate(rawString, x);
  EXPECT_TRUE(std::isnan(std::stod(result)));
}

TEST(ModelTest, BonusOneCalculate_1) {
  double sum = 234560, perc = 15;
  int months = 32;
  s21::Model model;
  std::vector<double> result = model.creditAut(sum, months, perc);
  EXPECT_FLOAT_EQ(result[0], 8938.59);   // monthPay
  EXPECT_FLOAT_EQ(result[1], 286035);    // totalPay
  EXPECT_FLOAT_EQ(result[2], 51474.89);  // overPay
}

TEST(ModelTest, BonusOneCalculate_2) {
  double sum = 103123.34, perc = 23;
  int months = 30;
  s21::Model model;
  std::vector<double> result = model.creditAut(sum, months, perc);
  EXPECT_FLOAT_EQ(result[0], 4551.8574);  // monthPay
  EXPECT_FLOAT_EQ(result[1], 136555.72);  // totalPay
  EXPECT_FLOAT_EQ(result[2], 33432.38);   // overPay
}

TEST(ModelTest, BonusOneCalculate_3) {
  double sum = 234560, perc = 15;
  int months = 32;
  s21::Model model;
  std::vector<double> result = model.creditAut(sum, months, perc);
  EXPECT_FLOAT_EQ(result[0], 8938.59);   // monthPay
  EXPECT_FLOAT_EQ(result[1], 286035);    // totalPay
  EXPECT_FLOAT_EQ(result[2], 51474.89);  // overPay
}

TEST(ModelTest, BonusTwoCalculate_1) {
  double sum = 100321.93, perc = 44;
  int months = 56;
  s21::Model model;
  std::vector<double> result = model.creditDiff(sum, months, perc);
  EXPECT_FLOAT_EQ(result[0], 5469.9336);  // monthPayMax
  EXPECT_FLOAT_EQ(result[1], 1857.15);    // monthPayMin
  EXPECT_FLOAT_EQ(result[2], 104836.42);  // overPay
  EXPECT_FLOAT_EQ(result[3], 205158.35);  // totalPay
}

TEST(ModelTest, BonusTwoCalculate_2) {
  double sum = 1000000, perc = 12;
  int months = 12;
  s21::Model model;
  std::vector<double> result = model.creditDiff(sum, months, perc);
  EXPECT_FLOAT_EQ(result[0], 93333.33);    // monthPayMax
  EXPECT_FLOAT_EQ(result[1], 84166.67);    // monthPayMin
  EXPECT_FLOAT_EQ(result[2], 65000.00);    // overPay
  EXPECT_FLOAT_EQ(result[3], 1065000.00);  // totalPay
}