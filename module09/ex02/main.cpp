#include "PmergeMe.hpp"
#include <exception>
#include <iostream>
#include <deque>
#include <sstream>

int main(int argc, char **argv) {
    std::cout << "Start PmergeME" << std::endl;
    (void)argv;
    (void)argc;
    if (argc > 2)
    {
        PmergeMe pm;
        try{
           std::deque<int> dq;
           std::deque<int> sortDq;
           dq.push_back(9);
           dq.push_back(1);
           dq.push_back(8);
           dq.push_back(3);
           dq.push_back(5);
           dq.push_back(6);
           dq.push_back(7);
           dq.push_back(2);
           dq.push_back(4);
           sortDq = pm.mergeInsertionSort(dq);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    else {
        std::cerr << "Error" << std::endl;
    }
    return 0;
}
