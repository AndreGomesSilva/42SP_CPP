#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
  const Animal *animalBase = new Animal();
  const Animal *dog = new Dog();
  const Animal *cat = new Cat();
  const WrongAnimal *wrongAnimalBase = new WrongAnimal();
  const WrongAnimal *wrongCat = new WrongCat();
  std::cout << dog->getType() << " " << std::endl;
  std::cout << cat->getType() << " " << std::endl;
  std::cout << animalBase->getType() << " " << std::endl;
  std::cout << wrongAnimalBase->getType() << " " << std::endl;
  cat->makeSound(); // will output the cat sound!
  dog->makeSound();
  wrongAnimalBase->makeSound();
  wrongCat->makeSound();
  animalBase->makeSound();
}
