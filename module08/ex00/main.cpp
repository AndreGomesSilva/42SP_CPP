#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void) {
  std::vector<int> vec;
  std::cout << "Pushing 10 elements" << std::endl;
  for (int i = 0; i < 10; i++)
  {
    vec.push_back(i);
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
  try{
    std::cout << "Trying to find 5" << std::endl;
    std::vector<int>::iterator it = easyfind(vec, 5);
    std::cout << *it << std::endl;
  }
  catch(const std::exception& e){
    std::cerr << e.what() << std::endl;
  }
 try{
    std::cout << "Trying to find 10" << std::endl;
    std::vector<int>::iterator it = easyfind(vec, 10);
    std::cout << *it << std::endl;
  }
  catch(const std::exception& e){
    std::cerr << e.what() << std::endl;
  }
try{
    std::cout << "Trying to find -1" << std::endl;
    std::vector<int>::iterator it = easyfind(vec, -1);
    std::cout << *it << std::endl;
  }
  catch(const std::exception& e){
    std::cerr << e.what() << std::endl;
  }


  return 0;
}
