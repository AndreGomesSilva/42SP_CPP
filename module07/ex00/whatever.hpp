#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T> void swap(T &a, T &b) {
  T temp;
  temp = a;
  a = b;
  b = temp;
}

template <typename T> T min(T first, T second) {
  if (first > second)
    return second;
  else if (first < second)
    return first;
  else
    return second;
}

template <typename T> T max(T first, T second) {
  if (first > second)
    return first;
  else if (first < second)
    return second;
  else
    return second;
}
#endif // WHATEVER_HPP
