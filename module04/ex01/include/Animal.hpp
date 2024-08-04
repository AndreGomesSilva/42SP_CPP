#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
  std::string type;

public:
  Animal();
  Animal(const Animal &copy);
  virtual ~Animal();
  Animal &operator=(const Animal &copy);
  std::string getType() const;
  virtual void makeSound() const;
};

#endif
