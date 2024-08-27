#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}
Base *generate(void) {
  srand(time(0));
  int random = std::rand() % 3 + 1;
  switch (random) {
  case 1:
    return new A();
    break;
  case 2:
    return new B();
    break;
  case 3:
    return new C();
    break;
  }
  return NULL;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p)) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B *>(p)) {
    std::cout << "B" << std::endl;
  } else if (dynamic_cast<C *>(p)) {
    std::cout << "C" << std::endl;
  } else {
    std::cout << "Problem to cast pointer" << std::endl;
  }
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    return;
  } catch (std::exception &e) {}
  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    return;
  } catch (std::exception &e) {}
  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    return;
  } catch (std::exception &e) {
    std::cout << "problem to cast reference of Base class to a derived class"
              << std::endl;
  }
}
