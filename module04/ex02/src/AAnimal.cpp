#include "AAnimal.hpp"

AAnimal::AAnimal() {
  type = "AAnimal";
  std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) {
  std::cout << "AAnimal copy constructor called" << std::endl;
  *this = copy;
}

AAnimal::~AAnimal() { std::cout << "Animal destructor called" << std::endl; }

AAnimal &AAnimal::operator=(const AAnimal &copy) {
  if (this != &copy) {
    this->type = copy.type;
  }
  return *this;
}

std::string AAnimal::getType() const { return type; }

void AAnimal::makeSound() const { std::cout << "AAnimal sound" << std::endl; }
