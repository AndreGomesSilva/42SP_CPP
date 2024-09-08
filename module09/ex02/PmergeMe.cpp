#include "PmergeMe.hpp"
#include <list>
#include <sstream>
#include <stdexcept>
#include <vector>

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

// static void splitVec(std::vector<int> mainVec, std::vector<int>vecA, std::vector<int> vecB)
// {

// }

std::vector<int> mergeInsertVector(std::vector<int> vec)
{
    std::vector<int> sortedVec;
    std::vector<int> vecA;
    std::vector<int> vecB;

    int holdLastValue;
    bool odd = vec.size() % 2 != 0;
    if (odd)
    {
        holdLastValue = vec.back();
        vec.pop_back();
    }
    splitVec(vec, vecA, vecB);

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
    printContainer(unsortedVec);
    printContainer(unsortedLst);
        // //Vector
        // sortedVec = mergeInsertVector(unsortedVec);

        // //List
        // sorteLst = mergeInsertList(unsortedLst);
}
