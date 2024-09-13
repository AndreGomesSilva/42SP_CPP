#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _hasStraggler(false) {
    _unsortVec = std::vector<int>();
    _unsortDeque = std::deque<int>();
}

PmergeMe::PmergeMe(PmergeMe &toCopy) : _hasStraggler(toCopy._hasStraggler), _unsortVec(toCopy._unsortVec), _unsortDeque(toCopy._unsortDeque) {
}

PmergeMe::~PmergeMe(){}

PmergeMe &PmergeMe::operator=(PmergeMe &toCopy){
  if (this != &toCopy)
  {
    _hasStraggler = toCopy._hasStraggler;
    _unsortVec = toCopy._unsortVec;
    _unsortDeque = toCopy._unsortDeque;
  }
  return *this;
}

int PmergeMe::jacobsthal(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::sort(int argc, char **argv){
    std::stringstream ss;
    int value;
    for (int i = 1; i < argc; ++i)
    {
        ss.clear();
        ss.str("");
        ss << argv[i];
        ss >> value;
        if (ss.fail() || !ss.eof())
        {
            throw std::invalid_argument("Error");
        }
        _unsortVec.push_back(value);
        _unsortDeque.push_back(value);
    }

    if (hasDuplicates(_unsortVec))
        throw std::invalid_argument("Error");

    std::cout << "Before: ";
    printContainer(_unsortVec);

    //Vector
    sortShowTime<std::vector<int>, std::vector<std::pair<int, int > > >(_unsortVec, "vector");
    //Deque
    sortShowTime<std::deque<int>, std::deque<std::pair<int, int > > >(_unsortDeque, "deque");
}
