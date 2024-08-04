#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;
  this->_value = value << _fractional_bits;
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  this->_value = roundf(value * (1 << _fractional_bits));
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(Fixed const &Fixed) {
  std::cout << "Assignation operator called" << std::endl;
  if (this != &Fixed)
    this->_value = Fixed.getRawBits();
  return *this;
}

std::ostream &operator<<(std::ostream &os, Fixed const &Fixed) {
  os << Fixed.toFloat();
  return os;
}

int Fixed::toInt(void) const { return this->_value >> _fractional_bits; }

float Fixed::toFloat(void) const {
  return static_cast<float>(this->_value) / (1 << _fractional_bits);
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->_value;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->_value = raw;
}
