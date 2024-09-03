#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
  MutantStack() : std::stack<T, Container>() {
    std::cout << "MutantStack constructor called" << std::endl;
  }
  MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {
    std::cout << "MutantStack copy constructor called" << std::endl;
  }
  MutantStack &operator=(const MutantStack &other) {
    std::cout << "MutantStack copy operator called" << std::endl;
    if (this != &other)
      std::stack<T, Container>::operator=(other);
    return *this;
  }
  ~MutantStack() { std::cout << "MutantStack destructor called" << std::endl; }

  typedef typename std::stack<T, Container>::container_type::iterator iterator;
  typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
  typedef
      typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
  typedef typename std::stack<T, Container>::container_type::const_reverse_iterator
      const_reverse_iterator;

  iterator begin() { return this->c.begin(); };
  iterator end() { return this->c.end(); }
  const_iterator begin() const { return this->c.begin(); }
  const_iterator end() const { return this->c.end(); }
  reverse_iterator rbegin() { return this->c.rbegin(); }
  reverse_iterator rend() { return this->c.rend(); }
  const_reverse_iterator rbegin() const { return this->c.rbegin(); }
  const_reverse_iterator rend() const { return this->c.rend(); }
};
#endif // MUTANTSTACK_HPP
