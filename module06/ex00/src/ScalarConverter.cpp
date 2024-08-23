#include "ScalarConverter.hpp"

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

static int countFractionalPart(std::string str) {
  size_t posDot = str.find(".");
  int fractional = 0;
  std::string newStr = str.substr(posDot + 1);
  fractional = newStr.length();
  return fractional;
}

// print types
static void printChar(char c) {
  std::cout << "char: '" << c << "'" << std::endl;
}

static void printInt(int value) { std::cout << "int: " << value << std::endl; }

static void printFloat(float value, int fractional) {
  if (!fractional)
    fractional = 1;
  std::cout << "float: " << std::fixed << std::setprecision(fractional) << value
            << "f" << std::endl;
}

static void printDouble(double value, int fractional) {
  if (!fractional)
    fractional = 1;
  std::cout << "double: " << std::fixed << std::setprecision(fractional)
            << value << std::endl;
}

// valid types
static int validChar(char c) {
  if (c >= 32 && c <= 126)
    return true;
  else if (c == 127 || (c >= 0 && c <= 31))
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: impossible" << std::endl;
  return false;
}

static int validInt(int value) {
  if ((value < std::numeric_limits<int>::min()) ||
      value > std::numeric_limits<int>::max())
    std::cout << "int: impossible" << std::endl;
  else {
    return true;
  }
  return false;
}

static int validFloat(float value) {
  if (value < -std::numeric_limits<float>::max() ||
      value > std::numeric_limits<float>::max())

    std::cout << "float: impossible" << std::endl;
  else {
    return true;
  }
  return false;
}

static int validDouble(double value) {
  if (value < -std::numeric_limits<double>::max() ||
      value > std::numeric_limits<double>::max())
    std::cout << "double: impossible" << std::endl;
  else
    return true;

  return false;
}

// convert types
static void charToIntFloatDouble(char input, int fractional) {
  int intValue = static_cast<int>(input);
  float floatValue = static_cast<float>(input);
  double doubleValue = static_cast<double>(input);
  printChar(input);
  if (validInt(intValue)) {
    printInt(intValue);
  }
  if (validFloat(floatValue)) {
    printFloat(floatValue, fractional);
  }
  if (validDouble(doubleValue)) {
    printDouble(doubleValue, fractional);
  }
}

static void intToCharFloatDouble(int input, int fractional) {
  char charValue = static_cast<char>(input);
  float floatValue = static_cast<float>(input);
  double doubleValue = static_cast<double>(input);
  if (input < 0 || input > 127)
    std::cout << "char: impossible" << std::endl;
  else if (validChar(charValue)) {
    printChar(charValue);
  }
  printInt(input);
  if (validFloat(floatValue)) {
    printFloat(floatValue, fractional);
  }
  if (validDouble(doubleValue)) {
    printDouble(doubleValue, fractional);
  }
}

static void floatToCharIntDouble(float input, int fractional) {
  char charValue = static_cast<char>(input);
  int intValue = static_cast<int>(input);
  double doubleValue = static_cast<double>(input);
  if (intValue < 0 || intValue > 127)
    std::cout << "char: impossible" << std::endl;
  else if (validChar(charValue)) {
    printChar(charValue);
  }
  if (validInt(intValue)) {
    printInt(intValue);
  }
  printFloat(input, fractional);
  if (validDouble(doubleValue)) {
    printDouble(doubleValue, fractional);
  }
}

static void doubleToCharIntFloat(double input, int fractional) {
  char charValue = static_cast<char>(input);
  int intValue = static_cast<int>(input);
  float floatValue = static_cast<float>(input);
  if (intValue < 0 || intValue > 127)
    std::cout << "char: impossible" << std::endl;
  else if (validChar(charValue)) {
    printChar(charValue);
  }

  if (validInt(intValue)) {
    printInt(intValue);
  }
  if (validFloat(floatValue)) {
    printFloat(floatValue, fractional);
  }
  printDouble(input, fractional);
}

static void convertByType(std::string input) {
  std::istringstream iss(input);
  int fractionalPart = 0;
  if (isChar(input)) {
    char inputChar;
    iss >> std::noskipws >> inputChar;
    charToIntFloatDouble(inputChar, fractionalPart);
  } else if (isInteger(input)) {
    int inputInt;
    iss >> std::noskipws >> inputInt;
    if (iss.fail()) {
      std::cout << "Int: impossible" << std::endl;
      return;
    }
    intToCharFloatDouble(inputInt, fractionalPart);
  } else if (isFloat(input)) {
    float inputFloat;
    fractionalPart = countFractionalPart(input);
    fractionalPart -= 1;
    iss >> std::noskipws >> inputFloat;
    if (iss.fail()) {
      std::cout << "float: impossible" << std::endl;
      return;
    }
    floatToCharIntDouble(inputFloat, fractionalPart);
  } else if (isDouble(input)) {
    double inputDouble;
    fractionalPart = countFractionalPart(input);
    iss >> std::noskipws >> inputDouble;
    if (iss.fail()) {
      std::cout << "double: impossible" << std::endl;
      return;
    }
    doubleToCharIntFloat(inputDouble, fractionalPart);
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
