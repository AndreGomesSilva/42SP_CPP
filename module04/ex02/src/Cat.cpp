#include "Cat.hpp"

Cat::Cat() {
  type = "Cat";
  brain = new Brain();
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) { type = copy.type;
brain = new Brain(*copy.brain);}

Cat::~Cat() {
  delete brain;
  std::cout << "Cat destructor called" << std::endl; }

Cat &Cat::operator=(const Cat &copy) {
  if (this != &copy) {
    type = copy.type;
    delete brain;
    brain = new Brain(*copy.brain);
  }
  return *this;
}

void Cat::makeSound() const { std::cout << "Cat sound -> Meow " << std::endl; }

void Cat::setIdea(int index, std::string idea) { brain->setIdea(index, idea); }

std::string Cat::getIdea(int index) const { return brain->getIdea(index); }
