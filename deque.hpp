//
// Created by Alexander on 04.06.2021.
//

#ifndef FT_CONTAINERS_DEQUE_HPP
#define FT_CONTAINERS_DEQUE_HPP

namespace ft {
	template<class T>
	class deque {
	private:
		class deque_node {
			T		value[4];
			node*	next,
			node*	prev;
		};
	};
}
#endif //FT_CONTAINERS_DEQUE_HPP
