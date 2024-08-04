#include "WrongCat.hpp"

WrongCat::WrongCat() {
  std::cout << "WrongCat default constructor called" << std::endl;
  type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) { *this = copy; }

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
  if (this != &copy) {
    type = copy.type;
  }
  return *this;
}

void WrongCat::makeSound() const { std::cout << "oink" << std::endl; }
