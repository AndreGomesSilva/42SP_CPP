#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
  type = "WrongAnimal";
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) { this->type = type; }

WrongAnimal::WrongAnimal(const WrongAnimal &copy) { *this = copy; }

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
  if (this != &copy) {
    type = copy.type;
  }
  return *this;
}

std::string WrongAnimal::getType() const { return type; }

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal sound" << std::endl;
}
