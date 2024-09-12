#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(PmergeMe &toCopy){
    (void) toCopy;
}

PmergeMe::~PmergeMe(){}

PmergeMe &PmergeMe::operator=(PmergeMe &toCopy){
    (void) toCopy;
    return *this;
}

int PmergeMe::jacobsThal(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsThal(n - 1) + 2 * jacobsThal(n - 2);
}

void PmergeMe::sort(int argc, char **argv){

    std::vector<int> unsortVec;
    std::vector<int> sortedVec;
    std::list<int> unsortLst;
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
        unsortVec.push_back(value);
        unsortLst.push_back(value);
    }

    //Vector
    std::cout << "Before: ";
    printContainer(unsortVec);
    sortedVec = mergeInsertionSort<std::vector<int>, std::vector<std::pair<int, int > > >(unsortVec);
    std::cout << "After: ";
    printContainer(sortedVec);
    displayTime<std::vector<int>, std::vector<std::pair<int, int > > >(unsortVec, "vector");
    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;

    //List
    std::cout << "Before: ";
    printContainer(unsortLst);
    sorteLst = mergeInsertionSort<std::list<int>, std::list<std::pair<int, int> > > (unsortLst);
    std::cout << "After: ";
    printContainer(sorteLst);
    displayTime<std::list<int>, std::list<std::pair<int, int > > >(unsortLst, "list");
}
