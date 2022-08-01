#pragma once

#include <type_traits>
#include <iterator>
#include <Algorithms/sorts/insertionSort.h>

// TODO Поправить mergeSort, подумать над тем какие параметры передавать

namespace sorts
{

	template<typename RandomAccessIterator, typename Comp>
	void Merge(RandomAccessIterator res_begin, RandomAccessIterator left_begin,
				RandomAccessIterator left_end, RandomAccessIterator right_begin,
				RandomAccessIterator right_end, Comp comp) {

		auto length = (left_end - left_begin) + (right_end - right_begin);

		for(auto i = left_begin, j = right_begin, k = res_begin; k < length; ++k) {

			if(i == left_end) {
				*k = *j;
				j++;
				continue;
			}

			if(j == right_end) {
				*k = *i;
				i++;
				continue;
			}

			if(comp(*i, *j)) {
				*k = *j;
				j++;
			} else {
				*k = *i;
				i++;
			}
		}
	}


	template<typename RandomAccessIterator, typename Comp>
	void _merge_sort_rec(RandomAccessIterator res, RandomAccessIterator copy,
						RandomAccessIterator left, RandomAccessIterator right, Comp comp) {
		if(std::distance(left, right) <= 10) {sorts::InsertionSort(left, right, comp); return;}

		auto m = std::distance(left, right)/2 + left;
		_merge_sort_rec(copy, res, left, m, comp);
		_merge_sort_rec(copy, res, m+left, right);
		Merge(res, copy, m - left + 1, copy + m + 1, right - m);
	}

	template<typename Container, typename Comp>
	void MergeSort(Container& res, Comp comp) {
		Container copy(res.size());
		for(auto i = 0; i < res.size(); ++i)
			copy[i] = res[i];

		_merge_sort_rec(begin(res), begin(copy), begin(res), end(res), comp);

	}

	template<typename Container>
	void MergeSort(Container& res) {
		Container copy(res.size());
		for(auto i = 0; i < res.size(); ++i)
			copy[i] = res[i];

		_merge_sort_rec(begin(res), begin(copy), begin(res), end(res), std::greater<typename Container::value_type>());
	}
}