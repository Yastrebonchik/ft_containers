//
// Created by Karyn Cedra on 6/20/21.
//

#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

#include "vector.hpp"

namespace ft {
	template<class T, class Container = ft::vector<T> >
	class stack {
	private:
		Container	_stack;
	public:
		stack(const Container& cntr = Container()) {
		};
		~stack() {};

		/* Member functions */

		bool		empty() const {
			return (this->_stack.empty());
		};
		size_t		size() const {
			return (this->_stack.size());
		}
		T&			top() {
			return (this->_stack.back());
		}
		const T&	top() const {
			return (this->_stack.back());
		}
		void		push(const T& val) {
			this->_stack.push_back(val);
		}
		void 		pop() {
			this->_stack.pop_back();
		}

		friend bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return (lhs._stack == rhs._stack);
		};
		friend bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return (lhs._stack != rhs._stack);
		};
		friend bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return(lhs._stack < rhs._stack);
		};
		friend bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return (lhs._stack > rhs._stack);
		};
		friend bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return (lhs._stack <= rhs._stack);
		};
		friend bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return (lhs._stack >= rhs._stack);
		};
	};
}

#endif //FT_CONTAINERS_STACK_HPP
