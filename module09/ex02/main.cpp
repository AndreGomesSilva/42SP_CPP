#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv) {
    std::cout << "Start PmergeME" << std::endl;
    if (argc > 2)
    {
        PmergeMe pm;
        try{
           pm.sort(argc, argv);
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
