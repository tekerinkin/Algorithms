#pragma once

#include <algorithm>

namespace sorts
{
	template<typename RandomAccessIterator, typename Compare>
	void _shaker_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare comp)
	{
		auto control = end - 1;
		auto left	 = begin;
		auto right	 = end - 1;

		do
		{
			for (auto it = left; it != right; ++it)
			{
				if (comp(*it, *(it + 1)))
				{
					std::iter_swap(it, it + 1);
					control = it;
				}
			}

			right = control;

			for (auto it = right; it != left; --it)
			{
				if (comp(*(it - 1), *it))
				{
					std::iter_swap(it - 1, it);
					control = it;
				}
			}

			left = control;
		} while (left < right);
	}

	template<typename RandomAccessIterator>
	void ShakerSort(RandomAccessIterator begin, RandomAccessIterator end)
	{
		_shaker_sort(begin, end,
			std::greater<typename std::iterator_traits<RandomAccessIterator>::value_type>());
	}

	template<typename RandomAccessIterator, typename Compare>
	void ShakerSort(RandomAccessIterator begin, RandomAccessIterator end, Compare comp)
	{
		_shaker_sort(begin, end, comp);
	}

} // namespace sorts