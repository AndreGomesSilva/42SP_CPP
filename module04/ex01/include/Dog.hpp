#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {
private:
  Brain *brain;
public:
  Dog();
  Dog(const Dog &copy);
  ~Dog();
  Dog &operator=(const Dog &copy);
  void makeSound() const;
  void setIdea(int index, std::string idea);
  std::string getIdea(int index) const;
};

#endif
