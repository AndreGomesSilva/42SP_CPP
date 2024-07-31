#include "Point.hpp"

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  return ((a.getX() - point.getX()) * (b.getY() - a.getY()) -
                  (b.getX() - a.getX()) * (a.getY() - point.getY()) >
              0 &&
          (b.getX() - point.getX()) * (c.getY() - b.getY()) -
                  (c.getX() - b.getX()) * (b.getY() - point.getY()) >
              0 &&
          (c.getX() - point.getX()) * (a.getY() - c.getY()) -
                  (a.getX() - c.getX()) * (c.getY() - point.getY()) >
              0);
}

bool isPointOnLeftSide(const Plane &plane, const Point &point) {
  Fixed dx = point.getX() - plane.point.getX();
  Fixed dy = point.getY() - plane.point.getY();
  return (plane.normal.getX() * dx + plane.normal.getY() * dy) >= Fixed(0);
}

void splitTrianglesByPlane(Triangle **triangles, int count, const Plane &plane,
                           Triangle **&leftTriangles, int &leftCount,
                           Triangle **&rightTriangles, int &rightCount) {
  leftCount = 0;
  rightCount = 0;

  leftTriangles = new Triangle *[count];
  rightTriangles = new Triangle *[count];

  for (int i = 0; i < count; ++i) {
    Triangle *triangle = triangles[i];
    bool inLeft = isPointOnLeftSide(plane, triangle->A) ||
                  isPointOnLeftSide(plane, triangle->B) ||
                  isPointOnLeftSide(plane, triangle->C);
    bool inRight = !isPointOnLeftSide(plane, triangle->A) ||
                   !isPointOnLeftSide(plane, triangle->B) ||
                   !isPointOnLeftSide(plane, triangle->C);
    std::cout << "Triangle " << i << " classification: " << "inLeft=" << inLeft
              << ", " << "inRight=" << inRight << std::endl;

    if (inLeft) {
      leftTriangles[leftCount++] = triangle;
    }
    if (inRight) {
      rightTriangles[rightCount++] = triangle;
    }
  }
}

BSPNode *constructBSP(Triangle **triangles, int triangleCount) {
  if (triangleCount == 0) {
    return NULL;
  }

  BSPNode *node = new BSPNode();
  if (triangleCount == 1) {
    node->triangles = new Triangle *[1];
    node->triangles[0] = triangles[0];
    node->triangleCount = 1;
    return node;
  }

  node->partition.point = triangles[0]->A;
  node->partition.normal = Point(
      triangles[0]->B.getX().toFloat() - triangles[0]->A.getX().toFloat(),
      triangles[0]->B.getY().toFloat() - triangles[0]->A.getY().toFloat());

  Triangle **leftTriangles = NULL;
  int leftCount = 0;
  Triangle **rightTriangles = NULL;
  int rightCount = 0;

  splitTrianglesByPlane(triangles, triangleCount, node->partition,
                        leftTriangles, leftCount, rightTriangles, rightCount);

  node->left = constructBSP(leftTriangles, leftCount);
  node->right = constructBSP(rightTriangles, rightCount);

  delete[] leftTriangles;
  delete[] rightTriangles;

  return node;
}
bool isPointInTriangles(Triangle **triangles, int count, const Point &P) {
  for (int i = 0; i < count; ++i) {
    if (bsp(triangles[i]->A, triangles[i]->B, triangles[i]->C, P))
      return true;
  }
  return false;
}

bool isPointInBSP(BSPNode *node, const Point &P) {
  if (node == NULL) {
    return false;
  }
  if (node->triangleCount == 0) {
    if (isPointOnLeftSide(node->partition, P)) {
      return isPointInBSP(node->left, P);
    } else {
      return isPointInBSP(node->right, P);
    }
  } else {
    return isPointInTriangles(node->triangles, node->triangleCount, P);
  }
}

/*
bool bsp(Point const a, Point const b, Point const c, Point const point) {
  return ((a.getX() - point.getX()) * (b.getY() - a.getY()) -
                  (b.getX() - a.getX()) * (a.getY() - point.getY()) >
              0 &&
          (b.getX() - point.getX()) * (c.getY() - b.getY()) -
                  (c.getX() - b.getX()) * (b.getY() - point.getY()) >
              0 &&
          (c.getX() - point.getX()) * (a.getY() - c.getY()) -
                  (a.getX() - c.getX()) * (c.getY() - point.getY()) >
              0);
}

bool isPointOnLeftSide(const Plane &plane, const Point &point) {
  Fixed dx = point.getX() - plane.point.getX();
  Fixed dy = point.getY() - plane.point.getY();
  return (plane.normal.getX() * dx + plane.normal.getY() * dy) >= 0;
}

void splitTriangleByPlane(Triangle **triangles, int count, const Plane
&plane, Triangle **left, int &leftCount, Triangle **right, int &rightCount) {

  leftCount = 0;
  rightCount = 0;

  left = new Triangle *[count];
  right = new Triangle *[count];

  for (int i = 0; i < count; i++) {
    if (isPointOnLeftSide(plane, triangles[i]->A)) {
      left[leftCount] = triangles[i];
      leftCount++;
    } else {
      right[rightCount] = triangles[i];
      rightCount++;
    }
  }
}


void splitTrianglesByPlane(Triangle **triangles, int count, const Plane &plane,
                           Triangle **&leftTriangles, int &leftCount,
                           Triangle **&rightTriangles, int &rightCount) {
  leftCount = 0;
  rightCount = 0;

  leftTriangles = new Triangle *[count];
  rightTriangles = new Triangle *[count];

  for (int i = 0; i < count; ++i) {
    Triangle *triangle = triangles[i];
    bool inLeft = isPointOnLeftSide(plane, triangle->A) ||
                  isPointOnLeftSide(plane, triangle->B) ||
                  isPointOnLeftSide(plane, triangle->C);
    bool inRight = !isPointOnLeftSide(plane, triangle->A) ||
                   !isPointOnLeftSide(plane, triangle->B) ||
                   !isPointOnLeftSide(plane, triangle->C);

    if (inLeft) {
      leftTriangles[leftCount++] = triangle;
    }
    if (inRight) {
      rightTriangles[rightCount++] = triangle;
    }
  }
}

BSPNode *constructBSP(Triangle **triangles, int triangleCount) {

  if (triangleCount == 0) {
    return NULL;
  }

  BSPNode *node = new BSPNode();
  if (triangleCount == 1) {
    node->triangles = triangles;
    node->triangleCount = 1;
    return node;
  }

  node->partition.point = triangles[0]->A;
  node->partition.normal = Point(
      triangles[0]->B.getX().toFloat() - triangles[0]->A.getX().toFloat(),
      triangles[0]->B.getY().toFloat() - triangles[0]->A.getY().toFloat());

  Triangle **left = NULL;
  int leftCount;
  Triangle **right = NULL;
  int rightCount;

  splitTrianglesByPlane(triangles, triangleCount, node->partition, left,
                        leftCount, right, rightCount);

  node->left = constructBSP(left, leftCount);
  node->right = constructBSP(right, rightCount);

  delete[] left;
  delete[] right;
  return node;
}

bool isPointInTriangles(Triangle **triangles, int count, const Point &P) {
  for (int i = 0; i < count; ++i) {
    if (bsp(triangles[i]->A, triangles[i]->B, triangles[i]->C, P))
      return true;
  }
  return false;
}

bool isPointInBSP(BSPNode *node, const Point &P) {
  if (node == NULL) {
    return false;
  }
  if (node->triangleCount == 0) {
    if (isPointOnLeftSide(node->partition, P)) {
      return isPointInBSP(node->left, P);
    } else {
      return isPointInBSP(node->right, P);
    }
  } else {
    return isPointInTriangles(node->triangles, node->triangleCount, P);
  }
}
*/
