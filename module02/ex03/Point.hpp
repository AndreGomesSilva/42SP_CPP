#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <climits>

class Point {

public:
  Point(void);
  Point(float const x, float const y);
  Point(Point const &src);
  ~Point(void);
  Point &operator=(Point const &other);
  Fixed getX(void) const;
  Fixed getY(void) const;
  void setX(float const x);
  void setY(float const y);

private:
  Fixed _x;
  Fixed _y;
};

struct Triangle {
  Point A, B, C;

  Triangle(Point A, Point B, Point C) : A(A), B(B), C(C) {}
};

struct Plane {
  Point point;
  Point normal;

  Plane(Point point, Point normal) : point(point), normal(normal) {}
};

struct BSPNode {
  Plane partition;
  BSPNode *left;
  BSPNode *right;
  Triangle **triangles;
  int triangleCount;

  BSPNode()
      : partition(Point(0,0), Point(0,0)), left(NULL), right(NULL), triangles(NULL),
        triangleCount(0) {}
  ~BSPNode() { delete[] triangles; }
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
BSPNode *constructBSP(Triangle **triangles, int triangleCount);
bool isPointInBSP(BSPNode *node, const Point &P);

#endif
