//
// Created by Karyn Cedra on 6/19/21.
//

#ifndef FT_CONTAINERS_VECTOR_TESTS_HPP
#define FT_CONTAINERS_VECTOR_TESTS_HPP

#include "test_headers.hpp"

void	vector_tests();

template <typename T>
bool operator==(ft::vector<T> &a, std::vector<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return (false);
	}
	return (true);
};

#endif //FT_CONTAINERS_VECTOR_TESTS_HPP
