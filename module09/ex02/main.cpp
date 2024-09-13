#include "PmergeMe.hpp"
#include <exception>
#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
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
