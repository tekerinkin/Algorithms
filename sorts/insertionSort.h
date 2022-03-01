//
// Created by Дима Шестаков on 22.02.2022.
//

#pragma once

#include <algorithm>

namespace Sorts
{

    template<typename RandomAccessIterator, typename Compare>
    void _insertion_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare comp)
    {
        for(auto it = begin + 1; it != end; ++it)
        {
            for(auto j = it - 1; comp(*j, *(j+1)); --j)
            {
                std::iter_swap(j, j+1);

                if(j == begin)
                    break;
            }
        }
    }

    template<typename RandomAccessIterator, typename Compare>
    void _shell_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare comp)
    {
        using diff_t = typename std::iterator_traits<RandomAccessIterator>::difference_type;

        diff_t offset = std::distance(begin, end);

        for(auto d = offset/2; d != 0; d /= 2)
        {
            for(auto i = begin + d; i != end; ++i)
            {
                for(auto j = i; std::distance(begin, j) >= d &&
                        comp(*(j-d), *j);  j -= d)
                    std::iter_swap(j, j-d);
            }
        }
    }

    template<typename RandomAccessIterator>
    void insertionSort(RandomAccessIterator begin, RandomAccessIterator end)
    {
        using type = typename std::iterator_traits<RandomAccessIterator>::value_type;

        _insertion_sort(begin, end,
                     std::greater<type>());
    }

    template<typename RandomAccessIterator, typename Compare>
    void insertionSort(RandomAccessIterator begin, RandomAccessIterator end, Compare comp)
    {
        _insertion_sort(begin, end, comp);
    }

    template<typename RandomAccessIterator>
    void shellSort(RandomAccessIterator begin, RandomAccessIterator end)
    {
        using type = typename std::iterator_traits<RandomAccessIterator>::value_type;

        _shell_sort(begin, end,
                        std::greater<type>());
    }

    template<typename RandomAccessIterator, typename Compare>
    void shellSort(RandomAccessIterator begin, RandomAccessIterator end, Compare comp)
    {
        _shell_sort(begin, end, comp);
    }
}