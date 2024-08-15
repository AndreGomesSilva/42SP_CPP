#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &src);
  ~ScalarConverter();

  ScalarConverter &operator=(ScalarConverter const &rhs);

public:
  static void convert(std::string input);
};

#endif // SCALAR_CONVERTER_HPP
