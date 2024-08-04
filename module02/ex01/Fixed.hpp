#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
public:
  Fixed(void);
  Fixed(Fixed const &src);
  Fixed(int const value);
  Fixed(float const value);
  ~Fixed(void);

  Fixed &operator=(Fixed const &Fixed);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  int toInt(void) const;
  float toFloat(void) const;

private:
  int _value;
  static const int _fractional_bits = 8;
};
std::ostream &operator<<(std::ostream &os, Fixed const &Fixed);

#endif // __FIXED_HPP__
