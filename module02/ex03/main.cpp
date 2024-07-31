#include "Fixed.hpp"
#include "Point.hpp"

int main() {
  Triangle *triangles[] = {
      new Triangle(Point(0, 10), Point(10, 10), Point(10, 0)),
      new Triangle(Point(20, 0), Point(20, 20), Point(20, 0))};
  int triangleCount = sizeof(triangles) / sizeof(triangles[0]);

  BSPNode *bspRoot = constructBSP(triangles, triangleCount);

  Point P = Point(2.5, 2);

  if (isPointInBSP(bspRoot, P)) {
    std::cout << "Point P is inside one of the triangles." << std::endl;
  } else {
    std::cout << "Point P is outside all the triangles." << std::endl;
  }

  delete bspRoot;
  for (int i = 0; i < triangleCount; ++i) {
    delete triangles[i];
  }

  return 0;
}
