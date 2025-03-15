#pragma once

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <functional>
#include <numeric>
#include <utility>
#include <vector>

namespace sort {


template <typename F>
void sort(std::vector < int > & vector, std::size_t left, std::size_t right, F && compare_func)
{
	for (auto i = left + 1; i < right; ++i)
	{
		for (auto j = i; j > left; --j)
		{
			if (compare_func(vector[j - 1], vector[j])) 
			{
				std::swap(vector[j], vector[j - 1]);
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void merge(std::vector < int > & vector, std::size_t left, std::size_t middle, std::size_t right)
{
	std::vector < int > buffer(right - left, 0);

	for (auto i = left, j = middle, k = 0uz; k < std::size(buffer); ++k) 
	{
		if (i < middle && ((j < right && vector[i] <= vector[j]) || j == right))
		{
			buffer[k] = vector[i++];
		}
		else
		{
			buffer[k] = vector[j++];
		}
	}

	for (auto i = 0uz, j = 0uz; j < std::size(buffer); ++j) 
	{
		vector[left + i++] = buffer[j];
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////

template <typename F>
void split(std::vector < int > & vector, std::size_t left, std::size_t right, F && compare_func)
{
	if (right - left <= 64)
	{
		sort(vector, left, right, compare_func);
	}
	else
	{
		auto middle = std::midpoint(left, right);
		
		split(vector, left, middle, compare_func       );
		
		split(vector,       middle, right, compare_func);

		merge(vector, left, middle, right);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////
template <typename F>
void timsort(std::vector < int > & vector, F && compare_func)
{
	split(vector, 0, std::size(vector), compare_func);
}

}