//
// Created by Alexander on 22.06.2021.
//

#ifndef FT_CONTAINERS_MAP_TESTS_HPP
#define FT_CONTAINERS_MAP_TESTS_HPP

#include "test_headers.hpp"

void map_tests();

template <typename T, typename S>
bool operator==(ft::map<T, S> &a, std::map<T, S> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::map<T, S>::iterator it = a.begin();
	typename std::map<T, S>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (it->first != it2->first || it->second != it2->second)
			return (false);
		++it;
		++it2;
	}
	return (true);
};

#endif //FT_CONTAINERS_MAP_TESTS_HPP
