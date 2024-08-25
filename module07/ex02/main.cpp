#include "Array.hpp"
#include "iostream"
#include <exception>

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

  std::cout << "char array" << std::endl;
  Array<char> charArray(6);
  charArray[0] = 'm';
  charArray[1] = 'a';
  charArray[2] = 'r';
  charArray[3] = 'v';
  charArray[4] = 'i';
  charArray[5] = 'n';
  printArray(charArray);
  std::cout << std::endl;

  std::cout << "try add element out of range" << std::endl;
  try {
    charArray[6] = '!';
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
