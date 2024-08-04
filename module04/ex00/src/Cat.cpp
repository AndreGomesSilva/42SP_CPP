#include "Cat.hpp"

Cat::Cat() {
  type = "Cat";
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) { *this = copy; }

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat &Cat::operator=(const Cat &copy) {
  if (this != &copy) {
    type = copy.type;
  }
  return *this;
}

void Cat::makeSound() const { std::cout << "Cat sound -> Meow " << std::endl; }
