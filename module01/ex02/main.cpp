#include <iostream>

int main() {
  std::string str = "HI THIS IS BRAIN";
  std::string str1 = "HEy";
  std::string *stringPTR = &str;
  std::string &stringREF = str;
  stringPTR = &str1;

  std::cout << &str << std::endl;
  std::cout << stringPTR << std::endl;
  std::cout << &stringREF << std::endl;

  std::cout << str << std::endl;
  std::cout << *stringPTR << std::endl;
  std::cout << stringREF << std::endl;

  return (0);
}
