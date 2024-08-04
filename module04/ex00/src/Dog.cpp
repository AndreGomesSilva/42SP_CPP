#include "Dog.hpp"

Dog::Dog() {
  type = "Dog";
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) {
  std::cout << "Dog copy constructor called" << std::endl;
  *this = copy;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog &Dog::operator=(const Dog &copy) {
  if (this != &copy) {
    this->type = copy.type;
  }
  return *this;
}

void Dog::makeSound() const { std::cout << "Dog sound -> Woof" << std::endl; }
