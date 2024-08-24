#include "iter.hpp"
#include <iostream>

void increment(int &i) { i++; }

void fillArray(int *arr, int N) {
  for (int i = 0; i < N; ++i) {
    arr[i] = i;
  }
}

template <typename T> void printElement(T &element) {
  std::cout << element << std::endl;
}

int main(void) {
  int size = 10;
  int arr[size];

  fillArray(arr, size);
  iter(arr, size, printElement);

  std::cout << std::endl;
  std::cout << "---------------" << std::endl;
  iter(arr, size, increment);
  std::cout << std::endl;
  iter(arr, size, printElement);
  return 0;
}
