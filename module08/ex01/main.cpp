#include "Span.hpp"
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

void testAddNumber(){
  std::cout << "Test add number" << std::endl;
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  std::cout << "shortest span" << std::endl;
  std::cout << sp.shortestSpan() << std::endl;

  std::cout << "longest span" << std::endl;
  std::cout << sp.longestSpan() << std::endl;
}

void testFillSp(){
  std::cout << "Test fill sp" << std::endl;
  Span sp = Span(20000);
  std::vector<int> vec;
  srand(time(NULL));
  try {
   for (int i = 0; i < 20000; i++)
    vec.push_back(rand() % 20000);
   std::cout << "filling span" << std::endl;
   sp.fill(vec.begin(), vec.end());
   std::cout << sp.getCapacity() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try{
    std::cout << "shortest span" << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try{
    std::cout << "longest span" << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

void testOutOfRange(){
  std::cout << "Test out of range" << std::endl;
  Span sp = Span(5);
  try {
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  Span sp2 = sp;
  try {
    sp2.addNumber(42);
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    sp.addNumber(2147483647);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;;
  }
  try {
    sp.addNumber(-2147483648);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

int main(void) {
  std::cout << "-------------------------------" << std::endl;
  testAddNumber();
  std::cout << std::endl;
  std::cout << "-------------------------------" << std::endl;
  testFillSp();
  std::cout << std::endl;
  std::cout << "-------------------------------" << std::endl;
  testOutOfRange();
  std::cout << std::endl;
  std::cout << "-------------------------------" << std::endl;
return 0;
}
