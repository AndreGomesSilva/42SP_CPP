#include "ScalarConverter.hpp"
#include <limits>

ScalarConverter::ScalarConverter() {
  std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
  std::cout << "ScalarConverter copy constructor called" << std::endl;
  *this = src;
}
ScalarConverter::~ScalarConverter() {
  std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
  (void)rhs;
  std::cout << "ScalarConverter copy assignment operator called" << std::endl;
  return *this;
}

// verifying types

static bool isChar(const std::string &str) {
  if (str.length() == 1 && !std::isdigit(str[0]))
    return true;
  return false;
}

static bool isInteger(const std::string &str) {
  if (str.empty())
    return false;
  std::istringstream iss(str);
  int num;
  iss >> std::noskipws >> num;
  return iss.eof() && !iss.fail();
}

static bool isFloat(const std::string &str) {
  if (!str.empty() && str.find('.') != std::string::npos &&
      str.end()[-1] == 'f') {
    std::string floatPart = str.substr(0, str.length() - 1);
    std::istringstream issFloat(floatPart);
    float num;
    issFloat >> std::noskipws >> num;
    return issFloat.eof() && !issFloat.fail();
  }
  return false;
}

static bool isDouble(const std::string &str) {
  if (!str.empty() && str.find('.') != std::string::npos) {
    std::string floatPart = str.substr(0, str.length() - 1);
    std::istringstream issFloat(floatPart);
    double num;
    issFloat >> std::noskipws >> num;
    return issFloat.eof() && !issFloat.fail();
  }
  return false;
}

// print types
static void printValidChar(char c) {
  if (c < 32 || c > 126)
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: '" << c << "'" << std::endl;
}

static void printValidInt(int value) {
  if (value < std::numeric_limits<int>::min() ||
      value > std::numeric_limits<int>::max())
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << value << std::endl;
}

static void printValidFloat(float value) {
  if (value < std::numeric_limits<float>::min() ||
      value > std::numeric_limits<float>::max() ||
      value == std::numeric_limits<float>::infinity() ||
      value == -std::numeric_limits<float>::infinity())
    std::cout << "float: impossible" << std::endl;
  else
    std::cout << "float: " << value << std::endl;
}

static void printValidDouble(double value) {
  if (value < std::numeric_limits<double>::min() ||
      value > std::numeric_limits<double>::max() ||
      value == std::numeric_limits<double>::infinity() ||
      value == -std::numeric_limits<double>::infinity())
    std::cout << "double: impossible" << std::endl;
  else
    std::cout << "double: " << value << std::endl;
}

// convert types
static char strToChar(const std::string &str) { return str[0]; }

static void charToIntFloatDouble(char input) {
  printValidChar(input);
  printValidInt(static_cast<int>(input));
  printValidFloat(static_cast<float>(input));
  printValidDouble(static_cast<double>(input));
}

static int strToInt(const std::string &str) {
  std::istringstream iss(str);
  int num;
  iss >> std::noskipws >> num;
  return num;
}

static void intToCharFloatDouble(int input) {
  printValidChar(static_cast<char>(input));
  printValidInt(input);
  printValidFloat(static_cast<float>(input));
  printValidDouble(static_cast<double>(input));
}

static float strToFloat(const std::string &str) {
  std::istringstream iss(str);
  float num;
  iss >> std::noskipws >> num;
  return num;
}

static void floatToCharIntDouble(float input) {
  printValidChar(static_cast<char>(input));
  printValidInt(static_cast<int>(input));
  printValidFloat(input);
  printValidDouble(static_cast<double>(input));
}

static double strToDouble(const std::string &str) {
  std::istringstream iss(str);
  double num;
  iss >> std::noskipws >> num;
  return num;
}

static void doubleToCharIntFloat(double input) {
  printValidChar(static_cast<char>(input));
  printValidInt(static_cast<int>(input));
  printValidFloat(static_cast<float>(input));
  printValidDouble(input);
}

static void convertByType(std::string input) {
  if (isChar(input)) {
    char inputChar = strToChar(input);
    charToIntFloatDouble(inputChar);
  } else if (isInteger(input)) {
    int inputInt = strToInt(input);
    intToCharFloatDouble(inputInt);
  } else if (isFloat(input)) {
    float inputFloat = strToFloat(input);
    floatToCharIntDouble(inputFloat);
  } else if (isDouble(input)) {
    double inputDouble = strToDouble(input);
    doubleToCharIntFloat(inputDouble);
  } else if (input == "nan" || input == "nanf") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
  } else if (input == "+inf" || input == "+inff") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
  } else if (input == "-inf" || input == "-inff") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
  } else
    std::cout << "Invalid input" << std::endl;
}

void ScalarConverter::convert(std::string input) { convertByType(input); }
