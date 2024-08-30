#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _capacity(N) {
  std::cout << "Span constructor called" << std::endl;
}

Span::~Span() {
  std::cout << "Span destructor called" << std::endl;
}

Span::Span(const Span &obj) { 
  std::cout << "Span copy constructor called" << std::endl;
  if (this != &obj) {
    _capacity = obj._capacity;
    _vec = obj._vec;
  }
}

Span &Span::operator=(const Span &obj) {
  std::cout << "Span copy assignment operator called" << std::endl;
  if (this != &obj) {
    _capacity = obj._capacity;
    _vec = obj._vec;
  }
  return *this;
}

void Span::addNumber(int num) {
  if (_vec.size() < _capacity && num > -2147483648 && num < 2147483647)
    _vec.push_back(num);
  else
    throw std::out_of_range("number out of range");
}

int Span::getCapacity() const {
  return _capacity;
}

int Span::longestSpan() {
  if (_vec.size() < 2)
    throw std::exception();
  std::vector<int> tmp = _vec;
  std::sort(tmp.begin(), tmp.end());
  return (tmp[tmp.size() - 1] - tmp[0]);
}

int Span::shortestSpan() {
  if (_vec.size() < 2)
    throw std::exception();
  int shorter = 2147483647;
  std::vector<int>tmp = _vec;
  std::sort(tmp.begin(), tmp.end());  
  for (unsigned int i = 1; i < tmp.size(); ++i) {
    if (tmp[i] - tmp[i - 1] < shorter)
      shorter = tmp[i] - tmp[i - 1];
  }
  return (shorter);
}
