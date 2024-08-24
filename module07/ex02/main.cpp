#include "Array.hpp"
#include "iostream"

template <typename T> void printArray(Array<T> array) {
  std::cout << "Array elements: ";
  for (unsigned int i = 0; i < array.size(); ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T> void fillArray(Array<T> &arr, unsigned N) {
  for (unsigned int i = 0; i < N; ++i) {
    arr[i] = i;
  }
}

int main(void) {
  Array<int> empty;
  std::cout << "empty array" << std::endl;
  printArray(empty);
  std::cout << std::endl;

  Array<int> intArray(5);
  fillArray(intArray, 5);
  std::cout << "int array" << std::endl;
  printArray(intArray);
  std::cout << std::endl;
}
