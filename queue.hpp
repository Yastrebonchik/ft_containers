//
// Created by Karyn Cedra on 6/19/21.
//

#ifndef FT_CONTAINERS_QUEUE_HPP
#define FT_CONTAINERS_QUEUE_HPP

#include "vector.hpp"

namespace ft {
	template<class T, class Container = ft::vector<T> >
	class queue {
	private:
		Container	_queue;
	public:
		queue(const Container& cntr = Container()) {
		};
		~queue() {};

		/* Member functions */

		bool		empty() const {
			return (this->_queue.empty());
		};
		size_t		size() const {
			return (this->_queue.size());
		}
		T&			front() {
			return (this->_queue.front());
		}
		const T&	front() const {
			return (this->_queue.front());
		}
		T&			back() {
			return (this->_queue.back());
		}
		const T&	back() const {
			return (this->_queue.back());
		}
		void		push(const T& val) {
			this->_queue.push_back(val);
		}
		void 		pop() {
			this->_queue.erase(this->_queue.begin());
		}

		friend bool operator==(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
			return (lhs._queue == rhs._queue);
		};
		friend bool operator!=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
			return (lhs._queue != rhs._queue);
		};
		friend bool operator<(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
			return(lhs._queue < rhs._queue);
		};
		friend bool operator>(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
			return (lhs._queue > rhs._queue);
		};
		friend bool operator<=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
			return (lhs._queue <= rhs._queue);
		};
		friend bool operator>=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
			return (lhs._queue >= rhs._queue);
		};
	};

//	template <class T, class Container>
//	bool operator==(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
//		return (lhs._queue == rhs.queue);
//	};
//
//	template <class T, class Container>
//	bool operator!=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
//		return (lhs._queue != rhs.queue);
//	};
//
//	template <class T, class Container>
//	bool operator<(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
//		return(lhs._queue < rhs.queue);
//	};
//
//	template <class T, class Container>
//	bool operator>(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
//		return (lhs._queue > rhs.queue);
//	};
//
//	template <class T, class Container>
//	bool operator<=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
//		return (lhs._queue <= rhs.queue);
//	};
//
//	template <class T, class Container>
//	bool operator>=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
//		return (lhs._queue >= rhs.queue);
//	};
}

#endif //FT_CONTAINERS_QUEUE_HPP
