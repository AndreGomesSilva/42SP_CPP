#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}
Point::Point(float const x, float const y) : _x(x), _y(y) {}
Point::Point(Point const &src) : _x(src._x), _y(src._y) {}
Point::~Point(void) {}

Point &Point::operator=(Point const &other) {
  if (this != &other) {
    this->_x = other._x;
    this->_y = other._y;
  }
  return *this;
}
float Point::getX(void) const { return this->_x; }
float Point::getY(void) const { return this->_y; }
void Point::setX(float const x) { this->_x = x; }
void Point::setY(float const y) { this->_y = y; }
