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
  for (size_t i = 0; i < str.length(); i++) {
    if (i == 0 && (str[i] == '-' || str[i] == '+') && str.length() > 1)
      continue;
    if (!std::isdigit(str[i]))
      return false;
  }
  return true;
}

static bool isFloat(const std::string &str) {
  int dotCount = 0;
  for (size_t i = 0; i < str.length(); i++) {
    if (i == 0 && (str[i] == '-' || str[i] == '+') && str.length() > 1)
      continue;
    if (!std::isdigit(str[i]) && str[i] != 'f' && str[i] != '.')
      return false;
    if (str[i] == '.')
      dotCount++;
    if (str.end()[-1] == 'f' && str[i] == 'f')
      return true;
    if (dotCount > 1)
      return false;
  }
  return false;
}

static bool isDouble(const std::string &str) {
  int dotCount = 0;
  for (size_t i = 0; i < str.length(); i++) {
    if (i == 0 && (str[i] == '-' || str[i] == '+') && str.length() > 1)
      continue;
    if (!std::isdigit(str[i]) && str[i] != '.')
      return false;
    if (str[i] == '.')
      dotCount++;
    if (dotCount > 1)
      return false;
  }
  return true;
}

// print types
static void printValidChar(char c) {
  if (c >= 32 && c <= 126)
    std::cout << "char: '" << c << "'" << std::endl;
  else if (c == 127 || (c >= 0 && c <= 31))
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: impossible" << std::endl;
}

static void printValidInt(int value) {
  if (value <= std::numeric_limits<int>::min() ||
      value >= std::numeric_limits<int>::max())
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << value << std::endl;
}

static void printValidFloat(float value) {
  if (value < -std::numeric_limits<float>::max() ||
      value > std::numeric_limits<float>::max())

    std::cout << "float: impossible" << std::endl;
  else
    std::cout << "float: " << value << "f" << std::endl;
}

static void printValidDouble(double value) {
  if (value < -std::numeric_limits<double>::max() ||
      value > std::numeric_limits<double>::max())
    std::cout << "double: impossible" << std::endl;
  else
    std::cout << "double: " << value << std::endl;
}

// convert types

static void charToIntFloatDouble(char input) {
  printValidChar(input);
  printValidInt(static_cast<int>(input));
  printValidFloat(static_cast<float>(input));
  printValidDouble(static_cast<double>(input));
}

static void intToCharFloatDouble(int input) {
  printValidChar(static_cast<char>(input));
  printValidInt(input);
  printValidFloat(static_cast<float>(input));
  printValidDouble(static_cast<double>(input));
}

static void floatToCharIntDouble(float input) {
  printValidChar(static_cast<char>(input));
  printValidInt(static_cast<int>(input));
  printValidFloat(input);
  printValidDouble(static_cast<double>(input));
}

static void doubleToCharIntFloat(double input) {
  printValidChar(static_cast<char>(input));
  printValidInt(static_cast<int>(input));
  printValidFloat(static_cast<float>(input));
  printValidDouble(input);
}

static void convertByType(std::string input) {
  std::istringstream iss(input);
  if (isChar(input)) {
    char inputChar;
    iss >> std::noskipws >> inputChar;
    charToIntFloatDouble(inputChar);
  } else if (isInteger(input)) {
    int inputInt;
    iss >> std::noskipws >> inputInt;
    intToCharFloatDouble(inputInt);
  } else if (isFloat(input)) {
    float inputFloat;
    iss >> std::noskipws >> inputFloat;
    floatToCharIntDouble(inputFloat);
  } else if (isDouble(input)) {
    double inputDouble;
    iss >> std::noskipws >> inputDouble;
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
