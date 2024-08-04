#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
  Fixed(void);
  Fixed(Fixed const &src);
  ~Fixed(void);

  Fixed &operator=(Fixed const &other);

  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int _value;
  static const int _bits = 8;
};

#endif // __FIXED_HPP__
