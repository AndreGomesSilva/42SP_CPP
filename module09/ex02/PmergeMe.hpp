#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>

class PmergeMe  {
    private:
        std::vector<int> containerOne;
        std::list<int> containerTwo;

    public:
        PmergeMe();
        PmergeMe(PmergeMe &toCopy);
        ~PmergeMe();

        PmergeMe &operator=(PmergeMe &toCopy);
        void sort(int argc, char **argv);
        std::vector<int> mergeInsertVector(std::vector<int> vec);
        std::list<int> mergeInsertList(std::list<int> lst);

        template <typename Container>
        void printContainer(const Container &container)
        {
            typename Container::const_iterator it;
            for (it = container.begin(); it != container.end(); ++it)
            {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
};

#endif //PMERGEME_HPP
