#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
  std::string type;

public:
  WrongAnimal();
  WrongAnimal(std::string type);
  WrongAnimal(const WrongAnimal &copy);
  virtual ~WrongAnimal();
  WrongAnimal &operator=(const WrongAnimal &copy);
  std::string getType() const;
  void makeSound() const;
};

#endif
