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
#include <set>

class PmergeMe  {
    private:
        bool _hasStraggler;

    public:
        PmergeMe();
        PmergeMe(PmergeMe &toCopy);
        ~PmergeMe();

        PmergeMe &operator=(PmergeMe &toCopy);
        void sort(int argc, char **argv);
        int jacobsThal(int n);
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
        void printContainerPair(Container &container)
        {
            typename Container::iterator it;
            std::cout << "[ ";
            for (typename Container::iterator it = container.begin(); it != container.end(); ++it)
            {
                std::cout << "[ " << it->first << " " << it->second  << " ]" << " ";
            }
            std::cout << " ]" << std::endl;
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
        
        template <typename Container>
        bool hasDuplicates(Container &container)
        {
          std::set<int> box;
          typename Container::iterator it;
          
          for(it = container.begin(); it != container.end(); it++)
          {
            if (box.find(*it) != box.end())
            {
               return true;
            }
            box.insert(*it);
          }  
          return false;
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
        Container buildJacobThalSequence(Container &pend)
        {
            Container sequence;
            int jacobIndex = 3;
            while (jacobsThal(jacobIndex) < static_cast<int>(pend.size() -1))
            {
                sequence.push_back(jacobsThal(jacobIndex));
                ++jacobIndex;
            }
            return sequence;
        }

        template <typename Container>
        void insertionSortRecursive(Container& container, typename Container::iterator last)
        {
            // Base case: If container has one or fewer elements, it's already sorted
            if (last == container.begin())
                return;

            // Sort first n-1 elements
            typename Container::iterator prev = last;
            --prev;
            insertionSortRecursive(container, prev);

            // Insert the last element at its correct position in the sorted array
            typename Container::value_type value = *last;

            typename Container::iterator j = prev;

            // Move elements of container[begin()..last-1] that are greater than last.second to one position ahead
            while (j != container.begin() && j->second > value.second)
            {
                typename Container::iterator next = j;
                ++next;
                *next = *j;
                --j;
            }
            // Special case for the first element
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

        // template <typename Container>
        // void insertionSortVector(Container& container, int n)
        // {
        //     // Base case
        //     if (n <= 1)
        //         return;

        //     // Sort first n-1 elements
        //     insertionSortVector(container, n-1);

        //     // Insert the last element at its correct position in sorted array
        //     typename Container::value_type last = container[n-1];
        //     int j = n-2;

        //     // Move elements of container[0..n-2] that are greater than last.second to one position ahead
        //     while (j >= 0 && container[j].second > last.second)
        //     {
        //         container[j+1] = container[j];
        //         j--;
        //     }
        //     container[j+1] = last;
        // }


        template <typename Container, typename PairContainer>
        Container createS(PairContainer &sortedPairs, int straggler)
        {
            Container s;
            Container pend;
            Container JacobSequece;

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
        void displayTime(Container &container, const std::string type)
        {
            clock_t start = clock();
            mergeInsertionSort<Container, PairContainer>(container);
            clock_t end = clock();
            double timeSec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
            std::cout << "Time to process a range of " << container.size() << " elements with " << "std::" << type << ": " << (timeSec * 1000.0) << " us" << std::endl;
        }
};

#endif //PMERGEME_HPP
