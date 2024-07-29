#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {

public:
  Point(void);
  Point(float const x, float const y);
  Point(Point const &src);
  ~Point(void);
  Point &operator=(Point const &other);
  float getX(void) const;
  float getY(void) const;
  void setX(float const x);
  void setY(float const y);

private:
  float _x;
  float _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
