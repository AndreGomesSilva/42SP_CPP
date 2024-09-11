#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <vector>

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
        OutputContainer createPairs(const InputContainer &A)
        {
            OutputContainer splitContainer;
            typename InputContainer::const_iterator it = A.begin();

            while (it != A.end())
            {
                typename InputContainer::value_type first = *it;
                typename InputContainer::value_type second = typename InputContainer::value_type();
                ++it;
                if (it != A.end()) {
                    second = *it;
                    ++it;
                }
                splitContainer.push_back(std::make_pair(first, second));
            }
            return splitContainer;
        }

        int jacbsthal(int n){
            if (n == 0) return 0;
            if (n == 1) return 1;
            return jacbsthal(n - 1) + 2 * jacbsthal(n - 2);
        }

        template <typename Container>
        Container buildJacobThalSequence(Container &pend)
        {
            Container sequence;
            int jacobIndex = 3;
            while (jacbsthal(jacobIndex) < static_cast<int>(pend.size() -1))
            {
                sequence.push_back(jacbsthal(jacobIndex));
                ++jacobIndex;
            }
            return sequence;
        }

        template <typename Container>
        void insertionSortRecursive(Container& container, int n)
        {
            // Base case
            if (n <= 1)
                return;

            // Sort first n-1 elements
            insertionSortRecursive(container, n-1);

            // Insert the last element at its correct position in sorted array
            typename Container::value_type last = container[n-1];
            int j = n-2;

            // Move elements of container[0..n-2] that are greater than last.second to one position ahead
            while (j >= 0 && container[j].second > last.second)
            {
                container[j+1] = container[j];
                j--;
            }
            container[j+1] = last;
        }

        template <typename Container, typename PairContainer>
        Container createS(PairContainer &sortedPairs, int straggler)
        {
            Container s;
            Container pend;
            Container JacobSequece;
            (void)straggler;

            for (typename PairContainer::iterator it = sortedPairs.begin(); it != sortedPairs.end(); ++it)
            {
                s.push_back(it->second);
                pend.push_back(it->first);
            }
            printContainer(s);
            printContainer(pend);

            s.insert(s.begin(), pend.front());
            pend.erase(pend.begin());

            printContainer(s);
            printContainer(pend);

            JacobSequece = buildJacobThalSequence(pend);
            printContainer(JacobSequece);


            int iterator = 0;
                while (iterator < static_cast<int>(pend.size())) {
                    typename Container::value_type item = pend[iterator++];
                    typename Container::iterator insertion_point = std::upper_bound(s.begin(), s.end(), item);
                    s.insert(insertion_point, item);
                }

                if (straggler != typename Container::value_type()) {
                    typename Container::iterator insertion_point = std::upper_bound(s.begin(), s.end(), straggler);
                    s.insert(insertion_point, straggler);
                }
            printContainer(s);
            return (s);
        }

        template <typename Container>
        Container mergeInsertionSort(Container &A){
            printContainer(A);
            typedef std::deque<std::pair<int, int> > splitDeque;
            bool hasStragler = A.size() % 2 != 0;
            typename Container::value_type straggler = typename Container::value_type();

            if (hasStragler)
            {
                straggler = A.back();
                A.pop_back();
            }
            (void)straggler;
            printContainer(A);
            splitDeque dequePair = createPairs<Container, splitDeque>(A);
            std::cout << "[ ";
            for (std::deque<std::pair<int, int> >::iterator it = dequePair.begin(); it != dequePair.end(); ++it)
            {
                std::cout << "[ " << it->first << " " << it->second  << " ]" << " ";
            }
            std::cout << " ]" << std::endl;
            SortInsidePair(dequePair);
            std::cout << "[ ";
            for (std::deque<std::pair<int, int> >::iterator it = dequePair.begin(); it != dequePair.end(); ++it)
            {
                std::cout << "[ " << it->first << " " << it->second  << " ]" << " ";
            }
            std::cout << " ]" << std::endl;
            insertionSortRecursive(dequePair, dequePair.size());
            std::cout << "[ ";
            for (std::deque<std::pair<int, int> >::iterator it = dequePair.begin(); it != dequePair.end(); ++it)
            {
                std::cout << "[ " << it->first << " " << it->second  << " ]" << " ";
            }
            std::cout << " ]" << std::endl;
            createS<Container, splitDeque>(dequePair, straggler);
            return A;
        }
};

#endif //PMERGEME_HPP
