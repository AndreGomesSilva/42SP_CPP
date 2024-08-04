#include "Dog.hpp"

Dog::Dog() {
  type = "Dog";
  brain = new Brain();
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) {
  std::cout << "Dog copy constructor called" << std::endl;
  type = copy.type;
  brain = new Brain(*copy.brain);
}

Dog::~Dog() {
  delete brain;
  std::cout << "Dog destructor called" << std::endl; }

Dog &Dog::operator=(const Dog &copy) {
  if (this != &copy) {
    type = copy.type;
    delete brain;
    brain = new Brain(*copy.brain);
  }
  return *this;
}

void Dog::makeSound() const { std::cout << "Dog sound -> Woof" << std::endl; }

void Dog::setIdea(int index, const std::string idea) { brain->setIdea(index, idea); }

std::string Dog::getIdea(int index) const { return brain->getIdea(index); }
