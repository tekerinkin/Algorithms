//
// Created by Дима Шестаков on 22.02.2022.
//

#pragma once

#include <algorithm>

namespace Sorts
{


    template<typename RandomAccessIterator, typename Compare>
    inline void _bubble_sort(RandomAccessIterator begin, RandomAccessIterator end,
                    Compare comp)
    {
        std::size_t step {};

        bool any_swaps = true;

        while(any_swaps)
        {
            any_swaps = false;

            for(auto it = begin; it != end - step - 1; ++it)
            {
                if(comp(*it, *(it+1)))
                {
                    std::iter_swap(it, it+1);
                    any_swaps = true;
                }
            }

            step++;
        }
    }

    template<typename RandomAccessIterator>
    void bubbleSort(RandomAccessIterator begin, RandomAccessIterator end)
    {
        _bubble_sort(begin, end,
                     std::greater<typename std::iterator_traits<RandomAccessIterator>::value_type>());
    }

    template<typename RandomAccessIterator, typename Compare>
    void bubbleSort(RandomAccessIterator begin, RandomAccessIterator end, Compare comp)
    {
        _bubble_sort(begin, end, comp);
    }
}
