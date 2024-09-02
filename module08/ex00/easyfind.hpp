#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
  typename T::iterator it = std::find(container.begin(), container.end(), value);
  if (it == container.end())
    throw std::out_of_range("value not found");
  return it;
}
#endif /* !EASYFIND_HPP */
