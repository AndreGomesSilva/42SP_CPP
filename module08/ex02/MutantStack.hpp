#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
  public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;  

    MutantStack();
    MutantStack(const MutantStack &obj);
    MutantStack &operator=(const MutantStack &obj);
    ~MutantStack();
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};
#endif // MUTANTSTACK_HPP
