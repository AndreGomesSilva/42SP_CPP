#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class ScalarConverter {

public:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &src);
  ~ScalarConverter();

  ScalarConverter &operator=(ScalarConverter const &rhs);
  static void convert(std::string input);
};
#endif // SCALAR_CONVERTER_HPP
