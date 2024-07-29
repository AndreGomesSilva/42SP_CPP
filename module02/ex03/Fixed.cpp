#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {}

Fixed::Fixed(Fixed const &src) { *this = src; }

Fixed::Fixed(const int value) { this->_value = value << _fractional_bits; }

Fixed::Fixed(const float value) {
  this->_value = roundf(value * (1 << _fractional_bits));
}

Fixed::~Fixed(void) {}

Fixed &Fixed::operator=(Fixed const &other) {
  if (this != &other)
    this->_value = other.getRawBits();
  return *this;
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixedNumber) {
  os << fixedNumber.toFloat();
  return os;
}

int Fixed::operator>(Fixed const &other) const {
  return this->_value > other._value;
}

int Fixed::operator<(Fixed const &other) const {
  return this->_value < other._value;
}

int Fixed::operator>=(Fixed const &other) const {
  return this->_value >= other._value;
}

int Fixed::operator<=(Fixed const &other) const {
  return this->_value <= other._value;
}

int Fixed::operator==(Fixed const &other) const {
  return this->_value == other._value;
}

int Fixed::operator!=(Fixed const &other) const {
  return this->_value != other._value;
}

Fixed Fixed::operator-(Fixed const &other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator+(Fixed const &other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator*(Fixed const &other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const &other) const {
  return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(void) {
  ++this->_value;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  ++this->_value;
  return tmp;
}

Fixed &Fixed::operator--(void) {
  --this->_value;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  --this->_value;
  return tmp;
}

Fixed &Fixed::min(Fixed &first, Fixed &second) {
  if (first < second)
    return first;
  return second;
}

Fixed const &Fixed::min(Fixed const &first, Fixed const &second) {
  if (first < second)
    return first;
  return second;
}

Fixed &Fixed::max(Fixed &first, Fixed &second) {
  if (first > second)
    return first;
  return second;
}

Fixed const &Fixed::max(Fixed const &first, Fixed const &second) {
  if (first > second)
    return first;
  return second;
}

int Fixed::toInt(void) const { return this->_value >> _fractional_bits; }

float Fixed::toFloat(void) const {
  return (float)this->_value / (1 << _fractional_bits);
}

int Fixed::getRawBits(void) const { return this->_value; }

void Fixed::setRawBits(int const raw) { this->_value = raw; }
