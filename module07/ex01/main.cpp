#include "iter.hpp"
#include <iostream>

void increment(int &i) { i++; }

void fillArray(int *arr, int N) {
  for (int i = 0; i < N; ++i) {
    arr[i] = i;
  }
}

void changeOForA(std::string &str) {
  for (unsigned int i = 0; i < str.length(); ++i) {
    if (str[i] == 'o') {
      str[i] = 'a';
    }
  }
 }

int main(void) {
  int size = 10;
  int arr[size];

  fillArray(arr, size);
  iter(arr, size, printElement);
  std::cout << std::endl;
  std::cout << "---------------" << std::endl;
  iter(arr, size, increment);
  iter(arr, size, printElement);

  std::cout << std::endl;
  std::cout << "---------------" << std::endl;
  std::string str[] = {"hello", "world"};
  iter(str, 2, printElement);
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "change \'o\' to \'a\'" << std::endl;
  std::cout << std::endl;
  iter(str, 2, changeOForA);
  iter(str, 2, printElement);
  std::cout << std::endl;
  return 0;
}
