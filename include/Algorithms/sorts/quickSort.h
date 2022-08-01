#pragma once

#include <Algorithms/sorts/insertionSort.h>
#include <algorithm>
#include <iterator>

namespace sorts
{
	const int MIN_SIZE_FOR_SORT = 10;

	template<typename RandomAccessIterator, typename Comp>
	RandomAccessIterator _mediana(RandomAccessIterator a,
		RandomAccessIterator b,
		RandomAccessIterator c,
		Comp comp)
	{
		if (comp(*a, *b))
		{
			if (comp(*a, *c))
				return a;
			return comp(*b, *c) ? b : c;
		}

		if (comp(*c, *b))
			return b;
		return comp(*a, *c) ? a : c;
	}

	template<typename RandomAccessIterator, typename Comp>
	RandomAccessIterator _partition(RandomAccessIterator begin,
		RandomAccessIterator end,
		Comp comp)
	{
		auto pivot = begin + (std::distance(begin, end) >> 1);

		auto i = begin;
		auto j = end;

		while (i <= j)
		{
			while (comp(*i, *pivot))
				i++;
			while (comp(*j, *pivot))
				j--;
			if (j <= i)
				break;
			std::iter_swap(j--, i++);
		}

		return j;
	}

	template<typename RandomAccessIterator, typename Comp>
	void _quick_sort(RandomAccessIterator begin,
		RandomAccessIterator end, Comp comp)
	{
		if (std::distance(begin, end) <= MIN_SIZE_FOR_SORT)
		{
			_insertion_sort(begin, end, comp);
			return;
		}

		auto pivot = begin + (std::distance(begin, end) >> 1);

		auto med = _mediana(begin, pivot, end, comp);

		std::iter_swap(pivot, med);

		auto idx = _partition(begin, end, comp);

		_quick_sort(begin, idx, comp);
		_quick_sort(idx + 1, end, comp);
	}

	template<typename RandomAccessIterator>
	void QuickSort(RandomAccessIterator begin,
		RandomAccessIterator end)
	{
		using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;
		_quick_sort(begin, end, std::greater<Type>());
	}

	template<typename RandomAccessIterator, typename Comp>
	void QuickSort(RandomAccessIterator begin,
		RandomAccessIterator end,
		Comp comp)
	{
		_quick_sort(begin, end, comp);
	}
} // namespace sorts