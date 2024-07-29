#include "Point.hpp"

int main() {
  Point a(0, 0);
  Point b(10, 30);
  Point c(20, 0);
  Point point(1, 1);
  std::cout << bsp(a, b, c, point) << std::endl;

  point.setX(0);
  point.setY(0);
  std::cout << bsp(a, b, c, point) << std::endl;

  point.setX(2);
  point.setY(2);
  std::cout << bsp(a, b, c, point) << std::endl;
  return 0;
}
