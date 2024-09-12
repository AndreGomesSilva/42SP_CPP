#include "PmergeMe.hpp"
#include <exception>
#include <list>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <set>

PmergeMe::PmergeMe(){
    std::cout << "Constructor PmergeMe called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe &toCopy){
    std::cout << "Copy constructor PmergeMe called" << std::endl;
    (void) toCopy;
}

PmergeMe::~PmergeMe(){
    std::cout << "Destructor PmergeMe called" << std::endl;
}

PmergeMe &PmergeMe::operator=(PmergeMe &toCopy){
    std::cout << "Assignment copy operator called" << std::endl;
    (void) toCopy;
    return *this;
}

void PmergeMe::insertPairInVec(std::pair<int, int> &pair, std::vector<std::pair<int, int> > &vec, int n)
{

    if (n < 0)
    {
        vec.insert(vec.begin(), pair);
      return;
    }
    else if (pair.second >= vec[n].second)
    {
        if (n == static_cast<int>(vec.size() - 1))
            vec.push_back(pair);
        else
            vec.insert(vec.begin() + n + 1, pair);
    }
    else
    {
        insertPairInVec(pair, vec, n - 1);
    }
 }

void PmergeMe::sortByPairs(std::vector<std::pair<int, int> > &vec, int n)
{
  if (n < 1)
      return;
  else
  {
    sortByPairs(vec, n - 1);
    insertPairInVec(vec[n], vec, n - 1);
  }
}

void PmergeMe::sortInsidePairs(std::vector<std::pair<int, int> > &vec)
{
  std::vector<std::pair<int, int> >::iterator it;
  for (it = vec.begin(); it != vec.end(); ++it)
  {
    if (it->first > it->second)
    {
      std::swap(it->first, it->second);
    }
  }
}

std::vector<std::pair<int, int> > PmergeMe::splitVec(std::vector<int> mainVec)
{
  std::vector<std::pair<int ,int> > splitVec;
  std::vector<int>::iterator it;
  std::vector<std::pair<int, int> >::iterator it2;

  if (mainVec.size() < 1)
    throw std::invalid_argument("Error");
  
  for (it = mainVec.begin(); it != mainVec.end(); it += 2)
  {
    splitVec.push_back(std::make_pair(*it, *(it + 1)));
  }

  return splitVec;
}

std::vector<int> PmergeMe::mergeInsertVector(std::vector<int> vec)
{
    std::vector<int> sortedVec;
    std::vector<std::pair<int, int> > pairVec;

    int holdLastValue;
    bool odd = vec.size() % 2 != 0;
    if (odd)
    {
        holdLastValue = vec.back();
        vec.pop_back();
        std::cout << "odd" << std::endl;
        std::cout << holdLastValue << std::endl;
    }

    pairVec = splitVec(vec);
  std::cout << "------ Pair of Vec ------" << std::endl;
  for (std::vector<std::pair<int,int> >::iterator it2 = pairVec.begin(); it2 != pairVec.end(); it2++)
  {
    std::cout << it2->first << " " << it2->second << std::endl;
  }
    sortInsidePairs(pairVec);
  std::cout << "------ Sort Pair of Vec ------" << std::endl;
  for (std::vector<std::pair<int,int> >::iterator it2 = pairVec.begin(); it2 != pairVec.end(); it2++)
  {
    std::cout << it2->first << " " << it2->second << std::endl;
  }
  sortByPairs(pairVec, pairVec.size() - 1);
  std::cout << "------ Sort ByPair of Vec ------" << std::endl;
  for (std::vector<std::pair<int,int> >::iterator it2 = pairVec.begin(); it2 != pairVec.end(); it2++)
  {
    std::cout << it2->first << " " << it2->second << std::endl;
  }
  return sortedVec;
}

bool hasDuplicates(std::vector<int> &vec)
{
  std::set<int> box;
  std::vector<int>::iterator it;

  for (it = vec.begin(); it != vec.end(); it++)
  {
    if (box.find(*it) != box.end())
    {
      return true;
    }
    box.insert(*it);
  }
  return false;
}

void PmergeMe::sort(int argc, char **argv){

    std::vector<int> unsortedVec;
    std::vector<int> sortedVec;
    std::list<int> unsortedLst;
    std::list<int> sorteLst;
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
        unsortedVec.push_back(value);
        unsortedLst.push_back(value);
    }
    if (hasDuplicates(unsortedVec))
      throw std::invalid_argument("Erro: Duplicate element");
    std::cout << "Vector Before: ";
    printContainer(unsortedVec);
    std::cout << "Vector Before: ";
    printContainer(unsortedLst);
    //Vector
    sortedVec = mergeInsertVector(unsortedVec);

        // //List
        // sorteLst = mergeInsertList(unsortedLst);
}
