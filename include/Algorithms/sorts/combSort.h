#pragma once

#include <algorithm>

namespace sorts
{
	template<typename RandomAccessIterator, typename Compare>
	void _comb_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare comp)
	{
		double factor = 1.25;
		auto jump	  = std::distance(begin, end);

		while (jump >= 1)
		{
			for (auto it = begin; it != end - jump; ++it)
			{
				if (comp(*it, *(it + jump)))
					std::iter_swap(it, it + jump);
			}

			jump /= factor;
		}
	}

	template<typename RandomAccessIterator>
	void CombSort(RandomAccessIterator begin, RandomAccessIterator end)
	{
		_comb_sort(begin, end,
			std::greater<typename std::iterator_traits<RandomAccessIterator>::value_type>());
	}

	template<typename RandomAccessIterator, typename Compare>
	void CombSort(RandomAccessIterator begin, RandomAccessIterator end, Compare comp)
	{
		_comb_sort(begin, end, comp);
	}
} // namespace sorts