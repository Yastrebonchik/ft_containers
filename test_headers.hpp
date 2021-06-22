//
// Created by Karyn Cedra on 6/19/21.
//

#ifndef FT_CONTAINERS_TEST_HEADERS_HPP
# define FT_CONTAINERS_TEST_HEADERS_HPP

# include <iostream>
# include <list>
# include <vector>
# include <map>
# include <queue>
# include <stack>
# include <cmath>
# include <string>
# include "list.hpp"
# include "vector.hpp"
# include "queue.hpp"
# include "stack.hpp"
# include "map.hpp"
# include "list_tests.hpp"
# include "vector_tests.hpp"
# include "queue_tests.hpp"
# include "stack_tests.hpp"
# include "map_tests.hpp"
# include "vector.hpp"
# include <exception>

# ifdef __linux__
#  define RESET "\e[0m"
#  define GREEN "\e[92m"
#  define BLUE "\e[94m"
#  define BOLD "\e[1m"
#  define CYAN "\033[36m"
# endif

# ifdef __APPLE__
#  define RESET "\e[0m"
#  define GREEN "\e[92m"
#  define BLUE "\e[94m"
#  define BOLD "\e[1m"
#  define CYAN "\033[36m"
# endif

# define GOOD "✓"
# define FAIL "❌"

#endif //FT_CONTAINERS_TEST_HEADERS_HPP
