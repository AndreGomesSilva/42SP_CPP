#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <stdexcept>
# include <limits>
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
      throw std::out_of_range("iterator out of range");
  }
};


#endif // SPAN_HPP
