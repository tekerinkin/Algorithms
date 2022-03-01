//
// Created by Дима Шестаков on 01.03.2022.
//

#pragma once

#include <type_traits>

//TODO: Complete merge_sort!! Doesn't sort!
// TODO: Think about requires & concepts

namespace Sorts
{

    template<typename Arr, typename Comp>
    void merge(Arr& arr,
                typename Arr::size_type left,
                typename Arr::size_type mid,
                typename Arr::size_type right,
                Comp comp)
    {
        using Value = typename Arr::value_type;
        using Index = typename Arr::size_type;

        Index it1 = 0;
        Index it2 = 0;

        Arr result(right - left);

        while(left + it1 < mid && mid + it2 < right)
        {
            if(!comp(arr[left + it1], arr[mid + it2]))
            {
                result[it1 + it2] = arr[left + it1];
                it1++;
            }
            else {
                result[it1+it2] = arr[mid+it2];
                it2++;
            }
        }

        while(left + it1 < mid)
        {
            result[it1+it2] = arr[left + it1];
            it1++;
        }

        while(mid + it2 < right){
            result[it1+it2] = arr[mid + it2];
            it2++;
        }

        for(auto i = 0; i < it1+it2; ++i)
        {
            arr[left + i] = result[i];
        }

    }

    template<typename Arr, typename Comp>
    void _merge_sort(Arr& arr, Comp comp)
    {
        for(size_t i = 0; i < arr.size(); i *= 2)
        {
            for(size_t j = 0; j < arr.size() - 1; j += 2*i)
                merge(arr, j, j+i, std::min(j+2*i, arr.size()), comp);
        }
    }

    template<typename Arr, typename Comp>
    void mergeSort(Arr& arr, Comp comp)
    {
        _merge_sort(arr, comp);
    }

    template<typename Arr>
    void mergeSort(Arr& arr)
    {
        using Type = typename Arr::value_type;
        _merge_sort(arr, std::greater<Type>());
    }

}