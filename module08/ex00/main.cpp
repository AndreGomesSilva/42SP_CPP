#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void) {
  std::cout << "-------------------------------" << std::endl;
  std:: cout<< "Vector test" << std::endl;
  std::vector<int> vec;
  std::cout << "Pushing 10 elements" << std::endl;
  for (int i = 0; i < 10; i++)
    vec.push_back(i);
  for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    std::cout << *it << " ";
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
  

  std::cout << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "List test" << std::endl;
  std::list<int> lst;
  std::cout << "Pushing 10 elements" << std::endl;
  for (int i = 0; i < 10; i++)
    lst.push_back(i);
  for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
  try{
    std::cout << "Trying to find 2" << std::endl;
    std::list<int>::iterator it = easyfind(lst, 2);
    std::cout << *it << std::endl;
  }
  catch(const std::exception& e){
    std::cerr << e.what() << std::endl;
  }
  try{
    std::cout << "Trying to find 10" << std::endl;
    std::list<int>::iterator it = easyfind(lst, 10);
    std::cout << *it << std::endl;
  }
  catch(const std::exception& e){
    std::cerr << e.what() << std::endl;
  }
  try{
    std::cout << "Trying to find -1" << std::endl;
    std::list<int>::iterator it = easyfind(lst, -1);
    std::cout << *it << std::endl;
  }
  catch(const std::exception& e){
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "Deque test" << std::endl;
  std::deque<int> deq;
  std::cout << "Pushing 10 elements" << std::endl;
  for (int i = 0; i < 10; i++)
    deq.push_back(i);
  for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
  try{
    std::cout << "Trying to find 4" << std::endl;
    std::deque<int>::iterator it = easyfind(deq, 4);
    std::cout << *it << std::endl;
  }
  catch(const std::exception& e){
    std::cerr << e.what() << std::endl;
  }
  try{
    std::cout << "Trying to find 10" << std::endl;
    std::deque<int>::iterator it = easyfind(deq, 10);
    std::cout << *it << std::endl;
  }
  catch(const std::exception& e){
    std::cerr << e.what() << std::endl;
  }
  try{
    std::cout << "Trying to find -1" << std::endl;
    std::deque<int>::iterator it = easyfind(deq, -1);
    std::cout << *it << std::endl;
  }
  catch(const std::exception& e){
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
