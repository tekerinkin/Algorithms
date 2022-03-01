//
// Created by Дима Шестаков on 22.02.2022.
//

#pragma once

#include <algorithm>

namespace Sorts
{
    template<typename RandomAccessIterator, typename Compare>
    void _selection_sort(RandomAccessIterator begin, RandomAccessIterator end,
                         Compare comp)
    {
        for(auto it = begin; it != end - 1; it++)
        {
            auto min = it;

            for(auto j = it + 1; j != end; ++j)
                if(comp(*min, *j))
                    min = j;

            std::iter_swap(min, it);
        }
    }

    template<typename RandomAccessIterator>
    void selectionSort(RandomAccessIterator begin, RandomAccessIterator end)
    {
        using type = typename std::iterator_traits<RandomAccessIterator>::value_type;

        _selection_sort(begin, end, std::greater<type>());
    }

    template<typename RandomAccessIterator, typename Compare>
    void selectionSort(RandomAccessIterator begin, RandomAccessIterator end,
                       Compare comp)
    {
        _selection_sort(begin, end, comp);
    }

}