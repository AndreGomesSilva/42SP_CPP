#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <cmath>
#include <iostream>

class Fixed {
public:
  Fixed(void);
  Fixed(Fixed const &src);
  Fixed(int const value);
  Fixed(float const value);
  ~Fixed(void);

  Fixed &operator=(Fixed const &other);
  int operator<(Fixed const &other) const;
  int operator>(Fixed const &other) const;
  int operator>=(Fixed const &other) const;
  int operator<=(Fixed const &other) const;
  int operator==(Fixed const &other) const;
  int operator!=(Fixed const &other) const;
  Fixed operator+(Fixed const &Fixed) const;
  Fixed operator-(Fixed const &Fixed) const;
  Fixed operator*(Fixed const &Fixed) const;
  Fixed operator/(Fixed const &Fixed) const;
  Fixed &operator++(void);
  Fixed operator++(int);
  Fixed &operator--(void);
  Fixed operator--(int);

  static Fixed &min(Fixed &first, Fixed &second);
  static Fixed const &min(Fixed const &first, Fixed const &second);
  static Fixed &max(Fixed &first, Fixed &second);
  static Fixed const &max(Fixed const &first, Fixed const &second);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  int toInt(void) const;
  float toFloat(void) const;

private:
  int _value;
  static const int _fractional_bits = 8;
};
std::ostream &operator<<(std::ostream &os, Fixed const &fixedNumber);

#endif // __FIXED_HPP__
