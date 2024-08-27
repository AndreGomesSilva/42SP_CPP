#include "whatever.hpp"
#include <iostream>

int main(void) {
  std::cout << "-----------" << std::endl;
  std::cout << "SWAP" << std::endl;
  std::cout << std::endl;
  int a = 2;
  int b = 3;
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "Swapping..." << std::endl;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  char one = 'a';
  char two = 'b';
  std::cout << "one = " << one << ", two = " << two << std::endl;
  std::cout << "Swapping..." << std::endl;
  ::swap(one, two);
  std::cout << "one = " << one << ", two = " << two << std::endl;
  std::cout << std::endl;
  std::cout << "-----------" << std::endl;
  std::cout << "MAX and MIN" << std::endl;
  std::cout << std::endl;
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::cout << std::endl;
  std::string c = "chaine3";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
  return 0;
}
