#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &copy);
  ~Dog();
  Dog &operator=(const Dog &copy);
  void makeSound() const;
};

#endif
