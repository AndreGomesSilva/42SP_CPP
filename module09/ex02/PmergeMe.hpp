#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <set>

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

        template <typename Container>
        void SortInsidePair(Container &pairs)
        {
            for (std::size_t i = 0; i < pairs.size(); ++i)
            {
                if (pairs[i].first > pairs[i].second)
                    std::swap(pairs[i].first, pairs[i].second);
            }
        }

        template <typename InputContainer, typename OutputContainer>
        OutputContainer createPairs(const InputContainer &input)
        {
            OutputContainer splitContainer;
            for (std::size_t i = 0; i < input.size(); i += 2)
            {
                typename InputContainer::value_type first = input[i];
                typename InputContainer::value_type second = (i + 1 < input.size()) ? input[i + 1] : typename InputContainer::value_type();
                splitContainer.push_back(std::make_pair(first, second));
            }
            return splitContainer;
        }

        template <typename Container>
        Container buildJacobThalSequence(Container &pend)
        {
            Container sequence;
            int jacobIndex = 3;
            while (jacobsthal(jacobIndex) < static_cast<int>(pend.size() -1))
            {
                sequence.push_back(jacobsthal(jacobIndex));
                ++jacobIndex;
            }
            return sequence;
        }

        template <typename Container>
        void insertionSortRecursive(Container& container, std::size_t last)
        {
            if (last == 0)
                return;
            insertionSortRecursive(container, last - 1);

            typename Container::value_type value = container[last];
            std::size_t j = last - 1;

            while (j > 0 && container[j].second > value.second)
            {
                container[j + 1] = container[j];
                --j;
            }
            if (j == 0 && container[j].second > value.second)
            {
                container[j + 1] = container[j];
                container[j] = value;
            }
            else
            {
                container[j + 1] = value;
            }
        }

        template <typename Container, typename PairContainer>
        Container createS(PairContainer &sortedPairs, int straggler)
        {
            Container s;
            Container pend;
            Container JacobSequence;

            for (std::size_t i = 0; i < sortedPairs.size(); ++i)
            {
                s.push_back(sortedPairs[i].second);
                pend.push_back(sortedPairs[i].first);
            }

            s.insert(s.begin(), pend[0]);
            pend.erase(pend.begin());
            JacobSequence = buildJacobThalSequence(pend);

            for (std::size_t i = 0; i < pend.size(); ++i) {
                typename Container::value_type item = pend[i];
                typename Container::iterator insertion_point = std::upper_bound(s.begin(), s.end(), item);
                s.insert(insertion_point, item);
            }

            for (std::size_t i = 0; i < JacobSequence.size(); ++i) {
                if (JacobSequence[i] < static_cast<int>(pend.size())) {
                    typename Container::value_type item = pend[JacobSequence[i]];
                    typename Container::iterator insertion_point = std::upper_bound(s.begin(), s.end(), item);
                    s.insert(insertion_point, item);
                }
            }

            if (_hasStraggler) {
                typename Container::iterator insertion_point = std::upper_bound(s.begin(), s.end(), straggler);
                s.insert(insertion_point, straggler);
            }
            return s;
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
            insertionSortRecursive(pairContainer, pairContainer.size() - 1);
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
            if (type == "vector")
            {
                std::cout << "After: ";
                printContainer(result);
            }
            double timeSec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
            std::cout << "Time to process a range of " << container.size() << " elements with " << "std::" << type << ": " << (timeSec * 1000.0) << " us" << std::endl;
        }
};

#endif //PMERGEME_HPP
