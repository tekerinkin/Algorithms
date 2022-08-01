#pragma once

#include <algorithm>

namespace sorts
{

	template<typename RandomAccessIterator, typename Compare>
	void _insertion_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare comp)
	{
		for (auto it = begin + 1; it != end; ++it)
		{
			for (auto j = it - 1; comp(*j, *(j + 1)); --j)
			{
				std::iter_swap(j, j + 1);

				if (j == begin)
					break;
			}
		}
	}

	template<typename RandomAccessIterator, typename Compare>
	void _shell_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare comp)
	{
		using DiffT = typename std::iterator_traits<RandomAccessIterator>::difference_type;

		DiffT offset = std::distance(begin, end);

		for (auto d = offset / 2; d != 0; d /= 2)
		{
			for (auto i = begin + d; i != end; ++i)
			{
				for (auto j = i; std::distance(begin, j) >= d && comp(*(j - d), *j); j -= d)
					std::iter_swap(j, j - d);
			}
		}
	}

	template<typename RandomAccessIterator>
	void InsertionSort(RandomAccessIterator begin, RandomAccessIterator end)
	{
		using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;

		_insertion_sort(begin, end,
			std::greater<Type>());
	}

	template<typename RandomAccessIterator, typename Compare>
	void InsertionSort(RandomAccessIterator begin, RandomAccessIterator end, Compare comp)
	{
		_insertion_sort(begin, end, comp);
	}

	template<typename RandomAccessIterator>
	void ShellSort(RandomAccessIterator begin, RandomAccessIterator end)
	{
		using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;

		_shell_sort(begin, end,
			std::greater<Type>());
	}

	template<typename RandomAccessIterator, typename Compare>
	void ShellSort(RandomAccessIterator begin, RandomAccessIterator end, Compare comp)
	{
		_shell_sort(begin, end, comp);
	}
} // namespace sorts