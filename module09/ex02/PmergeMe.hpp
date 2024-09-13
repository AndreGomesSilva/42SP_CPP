#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <deque>

class PmergeMe  {
    private:
        bool _hasStraggler;
        std::vector<int> _unsortVec;
        std::deque<int> _unsortDeque;

    public:
        PmergeMe();
        PmergeMe(PmergeMe &toCopy);
        ~PmergeMe();

        PmergeMe &operator=(PmergeMe &toCopy);
        void sort(int argc, char **argv);
        int jacobsthal(int n);
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

        template <typename Container>
        void SortInsidePair(Container &pairs)
        {
            for (typename Container::iterator it = pairs.begin(); it != pairs.end(); ++it)
            {
                if (it->first > it->second)
                    std::swap(it->first, it->second);
            }
        }
        
        template <typename InputContainer, typename OutputContainer>
        OutputContainer createPairs(const InputContainer &input)
        {
            OutputContainer splitContainer;
            typename InputContainer::const_iterator it = input.begin();

            while (it != input.end())
            {
                typename InputContainer::value_type first = *it;
                typename InputContainer::value_type second = typename InputContainer::value_type();
                ++it;
                if (it != input.end()) {
                    second = *it;
                    ++it;
                }
                splitContainer.push_back(std::make_pair(first, second));
            }
            return splitContainer;
        }

        template <typename Container>
        std::vector<int> buildJacobThalSequence(Container &pend)
        {
            std::vector<int> sequence;
            int jacobIndex = 3;
            while (jacobsthal(jacobIndex) < static_cast<int>(pend.size() -1))
            {
                sequence.push_back(jacobsthal(jacobIndex));
                ++jacobIndex;
            }
            return sequence;
        }

        template <typename Container>
        void insertionSortRecursive(Container& container, typename Container::iterator last)
        {
            if (last == container.begin())
                return;
            typename Container::iterator prev = last;
            --prev;

            insertionSortRecursive(container, prev);

            typename Container::value_type value = *last;
            typename Container::iterator j = prev;

            while (j != container.begin() && j->second > value.second)
            {
                typename Container::iterator next = j;
                ++next;
                *next = *j;
                --j;
            }
            if (j == container.begin() && j->second > value.second)
            {
                typename Container::iterator next = j;
                ++next;
                *next = *j;
                *j = value;
            }
            else
            {
                typename Container::iterator next = j;
                ++next;
                *next = value;
            }
        }

        template <typename Container, typename PairContainer>
        Container createS(PairContainer &sortedPairs, int straggler)
        {
            Container s;
            Container pend;
            std::vector<int> JacobSequece;

            for (typename PairContainer::iterator it = sortedPairs.begin(); it != sortedPairs.end(); ++it)
            {
                s.push_back(it->second);
                pend.push_back(it->first);
            }
            s.insert(s.begin(), pend.front());
            pend.erase(pend.begin());
            JacobSequece = buildJacobThalSequence(pend);

            for (typename Container::iterator it = pend.begin(); it != pend.end(); ++it) {
                typename Container::value_type item = *it;
                typename Container::iterator insertion_point = std::upper_bound(s.begin(), s.end(), item);
                s.insert(insertion_point, item);
            }
            for (std::vector<int>::iterator it = JacobSequece.begin(); it != JacobSequece.end(); ++it) {
              if (*it < static_cast<int>(pend.size())) {
                  typename Container::value_type item = pend[*it];
                  typename Container::iterator insertion_point = std::upper_bound(s.begin(), s.end(), item);
                  s.insert(insertion_point, item);
              }
            }
            if (_hasStraggler) {
                typename Container::iterator insertion_point = std::upper_bound(s.begin(), s.end(), straggler);
                s.insert(insertion_point, straggler);
            }
            return (s);
        }

        template <typename Container, typename PairContainer>
        Container mergeInsertionSort(Container &input){
            Container result;
            _hasStraggler = input.size() % 2 != 0;
            typename Container::value_type straggler = typename Container::value_type();
            if (_hasStraggler)
            {
                straggler = input.back();
                input.pop_back();
            }
            PairContainer pairContainer = createPairs<Container, PairContainer>(input);
            SortInsidePair(pairContainer);
            insertionSortRecursive(pairContainer, --pairContainer.end());
            result = createS<Container, PairContainer>(pairContainer, straggler);
            return result;
        }

        template <typename Container, typename PairContainer>
        void sortShowTime(Container &container, const std::string type)
        {
            Container result;
            clock_t start = clock();
            result = mergeInsertionSort<Container, PairContainer>(container);
            clock_t end = clock();
            std::cout << "After: ";
            printContainer(result);
            double timeSec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
            std::cout << "Time to process a range of " << container.size() << " elements with " << "std::" << type << ": " << (timeSec * 1000.0) << " us" << std::endl;
        }
};

#endif //PMERGEME_HPP
