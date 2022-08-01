#pragma once

#include <algorithm>

namespace sorts
{
	template<typename RandomAccessIterator, typename Compare>
	void _selection_sort(RandomAccessIterator begin, RandomAccessIterator end,
		Compare comp)
	{
		for (auto it = begin; it != end - 1; it++)
		{
			auto min = it;

			for (auto j = it + 1; j != end; ++j)
				if (comp(*min, *j))
					min = j;

			std::iter_swap(min, it);
		}
	}

	template<typename RandomAccessIterator>
	void SelectionSort(RandomAccessIterator begin, RandomAccessIterator end)
	{
		using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;

		_selection_sort(begin, end, std::greater<Type>());
	}

	template<typename RandomAccessIterator, typename Compare>
	void SelectionSort(RandomAccessIterator begin, RandomAccessIterator end,
		Compare comp)
	{
		_selection_sort(begin, end, comp);
	}

} // namespace sorts