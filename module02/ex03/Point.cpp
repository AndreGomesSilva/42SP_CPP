#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) {}
Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {}
Point::Point(Point const &src) : _x(src._x), _y(src._y) {}
Point::~Point(void) {}

Point &Point::operator=(Point const &other) {
  if (this != &other) {
    this->_x = other._x;
    this->_y = other._y;
  }
  return *this;
}
Fixed Point::getX(void) const { return this->_x; }
Fixed Point::getY(void) const { return this->_y; }
void Point::setX(float const x) { this->_x = x; }
void Point::setY(float const y) { this->_y = y; }
