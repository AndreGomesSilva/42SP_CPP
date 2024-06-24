#include "test.hpp"
#include <iostream>

Sample::Sample() {
  std::cout << "Constructor called" << std::endl;
  return;
}

Sample::~Sample(void) {
  std::cout << "Destruct called" << std::endl;
  return;
}

int Sample::getFoo( void ) const {
    return this->_foo;
}

void Sample::setFoo(int v){
    if (v >= 0)
        this->_foo = v;
        
    return;
}

int Sample::compare(Sample *other) const{
    if (this->_foo < other->_foo)
        return -1;
    else if (this->_foo > other->_foo)
        return 1;
    return (0);
}

// void Sample::bar(void) const {
//     std::cout << "this->pi: " << this->pi << std::endl;
//     std::cout << "this->qd: " << this->qd << std::endl;
//   return;
// }
