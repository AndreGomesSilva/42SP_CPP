#include "test.hpp"
#include <iostream>

int main() {

  Sample instance; // called contructor
  
  std::cout << instance.getFoo() << std::endl;
  instance.setFoo(10);
  std::cout << instance.getFoo() << std::endl;
  instance.setFoo(-1);
  std::cout << instance.getFoo() << std::endl;
  
  return 0; // called destructor
}
