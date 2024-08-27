#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <class T> class Array {
private:
  T *_array;
  unsigned int _size;

public:
  Array() : _array(NULL), _size(0) {}
  Array(unsigned int n) : _array(new T[n]()), _size(n) {}
  Array(const Array &other) : _array(new T[other._size]), _size(other._size) {
    for (unsigned int i = 0; i < _size; ++i) {
      _array[i] = other._array[i];
    }
  }

  Array &operator=(const Array &other) {
    if (this != &other) {
      delete[] _array;

      _size = other._size;
      _array = new T[_size];
      for (unsigned int i = 0; i < _size; ++i) {
        _array = other._array[i];
      }
    }
    return *this;
  }

  ~Array() { delete[] _array; }

  T &operator[](unsigned int index) {
    if (index >= _size) {
      throw std::out_of_range("index out of bounds");
    }
    return _array[index];
  }

  const T &operator[](unsigned int index) const {
    if (index >= _size) {
      throw std::out_of_range("index out of bounds");
    }
    return _array[index];
  }

  unsigned int size() const { return _size; }
};

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

#endif
