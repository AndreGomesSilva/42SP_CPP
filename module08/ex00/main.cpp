#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void) {
  std::vector<int> vec;
  for (int i = 0; i < 10; i++)
    vec.push_back(i);

  try
  {
    std::vector<int>::iterator it = easyfind(vec, 5);
    std::cout << *it << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
