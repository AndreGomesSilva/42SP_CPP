#include "RPN.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2)
    {
        std::cerr << "Usage:  " << argv[0] << " <operations>" << std::endl;
        return 1;
    }
    std::string input = argv[1];
    RPN rpn(input);
    if (rpn.validateInput())
    {
        try{
            int result = rpn.calculator();
            std::cout << result << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            return 1;
        }
    }
    else
    {
        std::cerr << "Error" << std::endl;
    };
    return 0;
}
