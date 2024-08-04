#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
    AAnimal* cat = new Cat();
    AAnimal* dog = new Dog();

// AAnimal is a Abstract Class, so it can't be instantiated
//    AAnimal* animal = new AAnimal();
//    animal->makeSound();

    cat->makeSound();
    dog->makeSound();

    delete cat;
    delete dog;

    return 0;
  }
