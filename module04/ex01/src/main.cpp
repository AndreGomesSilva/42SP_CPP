#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {

  Dog firstDog;
  firstDog.setIdea(0, "First Dog first idea -> Woof!");
  firstDog.setIdea(1, "First Dog second idea -> Woof");
  firstDog.setIdea(2, "Third Dog first idea -> Woof?");


  std::cout << "--------------------------------" << std::endl;
  std::cout << "Creating deep copies of first dog" << std::endl;
  Dog secondDog(firstDog);
  Dog thirdDog;
  thirdDog = firstDog;


  std::cout << "--------------------------------" << std::endl;
  std::cout << "**  Printing ideas of all 3 dogs  **" << std::endl;
  for (int i = 0; i < 3; i++) {
    std::cout << firstDog.getIdea(i) << std::endl;
  }
  for (int i = 0; i < 3; i++) {
    std::cout << secondDog.getIdea(i) << std::endl;
  }
  for (int i = 0; i < 3; i++) {
    std::cout << thirdDog.getIdea(i) << std::endl;
  }



  std::cout << "--------------------------------" << std::endl;
  std::cout << "Changing idea of second dog to something else" << std::endl;
  secondDog.setIdea(0, "Second Dog first idea -> Bark!");
  secondDog.setIdea(1, "Second Dog second idea -> Bark");
  secondDog.setIdea(2, "Third Dog first idea -> Bark?");

  std::cout << "--------------------------------" << std::endl;
  std::cout << "Changing idea of third dog to something else" << std::endl;
  thirdDog.setIdea(0, "Third Dog first idea -> blaf-blaf");
  thirdDog.setIdea(1, "Third Dog second idea -> blaf-blaf");
  thirdDog.setIdea(2, "Third Dog third idea -> blaf-blaf");


  std::cout << "--------------------------------" << std::endl;
  std::cout << "** Printing ideas of all 3 dogs  **" << std::endl;
  for (int i = 0; i < 3; i++) {
    std::cout << firstDog.getIdea(i) << std::endl;
  }
  for (int i = 0; i < 3; i++) {
    std::cout << secondDog.getIdea(i) << std::endl;
  }
  for (int i = 0; i < 3; i++) {
    std::cout << thirdDog.getIdea(i) << std::endl;
  }


  std::cout << "--------------------------------" << std::endl;
  std::cout << "Creating 10 animals and making sound" << std::endl;
  Animal *animal[10];
  for (int i = 0; i < 5; i++) {
    animal[i] = new Dog();
  }
  for (int i = 5; i < 10; i++) {
    animal[i] = new Cat();
  }
  for (int i = 0; i < 10; i++) {
    animal[i]->makeSound();
  }
  for (int i = 0; i < 10; i++) {
    delete animal[i];
  }
}
