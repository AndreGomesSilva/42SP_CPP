#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public Animal
{
private:
  Brain *brain;
public:
  Cat();
  Cat(const Cat &copy);
  ~Cat();
  Cat &operator=(const Cat &copy);
  void makeSound() const;
  void setIdea(int index, std::string idea);
  std::string getIdea(int index) const;
};

#endif
