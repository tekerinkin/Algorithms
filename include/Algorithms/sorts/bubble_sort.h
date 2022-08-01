#pragma once

#include <algorithm>

namespace sorts
{

	template<typename RandomAccessIterator, typename Compare>
	inline void _bubbleSort(RandomAccessIterator begin, RandomAccessIterator end,
		Compare comp)
	{
		std::size_t step{};

		bool any_swaps = true;

		while (any_swaps)
		{
			any_swaps = false;

			for (auto it = begin; it != end - step - 1; ++it)
			{
				if (comp(*it, *(it + 1)))
				{
					std::iter_swap(it, it + 1);
					any_swaps = true;
				}
			}

			step++;
		}
	}

	template<typename RandomAccessIterator>
	void BubbleSort(RandomAccessIterator begin, RandomAccessIterator end)
	{
		_bubble_sort(begin, end,
			std::greater<typename std::iterator_traits<RandomAccessIterator>::value_type>());
	}

	template<typename RandomAccessIterator, typename Compare>
	void BubbleSort(RandomAccessIterator begin, RandomAccessIterator end, Compare comp)
	{
		_bubble_sort(begin, end, comp);
	}
} // namespace sorts