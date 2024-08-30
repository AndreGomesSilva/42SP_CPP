#ifndef SPAN_HPP
# define SPAN_HPP

#include <filesystem>
# include <iostream>
# include <vector>
# include <algorithm>

class Span {
private:
  unsigned int _capacity;
  std::vector<int> _vec;

public:
  Span();
  Span(unsigned int N);
  Span(const Span &obj);
  ~Span();
  Span &operator=(const Span &obj);
  void addNumber(int num);
  int shortestSpan();
  int longestSpan();
  int getCapacity() const;
  template <class Iterator>
  void fill(Iterator begin, Iterator end)
  {
    if (_vec.size() < _capacity)
    {
      for (Iterator it = begin; it != end; it++)
        addNumber(*it);
    }
    else
      throw std::exception();
  }
};


#endif // SPAN_HPP
