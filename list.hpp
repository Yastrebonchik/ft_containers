/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:29:27 by                   #+#    #+#             */
/*   Updated: 2021/06/03 01:35:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_LIST_H
# define FT_CONTAINERS_LIST_H

# include <limits>

namespace ft {
	template<class T>
	class list {
	private:
		class node {
		public:
			T		value;
			node	*next;
			node	*prev;

			node() : value(0), next(nullptr), prev(nullptr) {};
			node(const T& val) : value(val), next(nullptr), prev(nullptr) {};
			node(node &src) : value(src.value), next(nullptr), prev(nullptr) {};
		};
		node	*_Mnode;
		size_t	_len;

	public:
		list() : _len(0){
			this->_Mnode = new node();
		};
		~list(){
			this->clear();
			delete this->_Mnode;
		};

		/* Forward iterator class */
		class iterator{
		private:
			T		*_value;
			node	*_next;
			node	*_prev;
		public:
			iterator() : _value (nullptr), _next(nullptr), _prev(nullptr){
			};
			iterator(const iterator &src) : _value(src._value), _next(src._next), _prev(src._prev){
			};
			~iterator(){
			};

			/* Operators */
			iterator&	operator++(){
				this->_value = &(this->_next->value);
				this->_prev = this->_next->prev;
				this->_next = this->_next->next;;
				return (*this);
			};
			iterator&	operator++(int){
				iterator	result(*this);

				this->_value = this->_next->value;
				this->_prev = this->_next->prev;
				this->_next = this->_next->next;
				return (result);
			};
			iterator&	operator--(){
				this->_value = &(this->_prev->value);
				this->_next = this->_prev->next;
				this->_prev = this->_prev->prev;
				return (*this);
			};
			iterator&	operator--(int){
				iterator	result(*this);

				this->_value = &(this->_prev->value);
				this->_next = this->_prev->next;
				this->_prev = this->_prev->prev;
				return (result);
			};
			T&			operator*(){
				return (*(this->_value));
			};
			T*			operator->() const {
				return &(operator*());
			}
			bool 		operator!=(const iterator &rhs){
				if (this->_next != rhs._next || this->_prev != this->_prev)
					return (1);
				else
					return (0);
			};
			bool 		operator==(const iterator &rhs){
				if (this->_next == rhs._next && this->_prev == this->_prev)
					return (1);
				else
					return (0);
			};
			iterator&	operator=(const iterator &rhs){
				this->_value = rhs._value;
				this->_next = rhs._next;
				this->_prev = rhs._prev;
				return (*this);
			};

			friend iterator list<T>::begin();
			friend iterator list<T>::end();
		};

		/* Reverse iterator class */
		class reverse_iterator{
		private:
			T		*_value;
			node	*_next;
			node	*_prev;
		public:
			reverse_iterator() : _value (nullptr), _next(nullptr), _prev(nullptr){
			};
			reverse_iterator(const reverse_iterator &src) : _value(src._value), _next(src._next), _prev(src._prev){
			};
			~reverse_iterator(){
			};

			/* Operators */
			reverse_iterator&	operator++(){
				this->_value = &(this->_prev->value);
				this->_next = this->_prev->next;
				this->_prev = this->_prev->prev;
				return (*this);
			};
			reverse_iterator&	operator++(int){
				reverse_iterator	result(*this);

				this->_value = &(this->_prev->value);
				this->_next = this->_prev->next;
				this->_prev = this->_prev->prev;
				return (result);
			};
			reverse_iterator&	operator--(){
				this->_value = &(this->_next->value);
				this->_prev = this->_next->prev;
				this->_next = this->_next->next;;
				return (*this);
			};
			reverse_iterator&	operator--(int){
				iterator	result(*this);

				this->_value = this->_next->value;
				this->_prev = this->_next->prev;
				this->_next = this->_next->next;
				return (result);
			};
			T&					operator*(){
				return (*(this->_value));
			};
			T*					operator->() const {
				return &(operator*());
			}
			bool				operator!=(const reverse_iterator &rhs){
				if (this->_next != rhs._next || this->_prev != this->_prev)
					return (1);
				else
					return (0);
			};
			bool 				operator==(const reverse_iterator &rhs){
				if (this->_next == rhs._next && this->_prev == this->_prev)
					return (1);
				else
					return (0);
			};
			reverse_iterator&	operator=(const reverse_iterator &rhs){
				this->_value = rhs._value;
				this->_next = rhs._next;
				this->_prev = rhs._prev;
				return (*this);
			};

			friend reverse_iterator list<T>::rbegin();
			friend reverse_iterator list<T>::rend();
		};


		/* Iterators */
		iterator			begin(){
			iterator	ret;

			if (_len != 0) {
				ret._value = &(this->_Mnode->next->value);
				ret._next = this->_Mnode->next->next;
				ret._prev = this->_Mnode;
			}
			return (ret);
		};
		iterator			end(){
			iterator	ret;

			if (_len != 0) {
				ret._next = this->_Mnode->next;
				ret._prev = this->_Mnode->prev;
			}
			return (ret);
		};
		reverse_iterator	rbegin(){
			reverse_iterator	ret;

			if (_len != 0) {
				ret._value = &(this->_Mnode->prev->value);
				ret._prev = this->_Mnode->prev->prev;
				ret._next = this->_Mnode;
			}
			return (ret);
		};
		reverse_iterator	rend(){
			reverse_iterator	ret;

			if (_len != 0) {
				ret._next = this->_Mnode->next;
				ret._prev = this->_Mnode->prev;
			}
			return (ret);
		};

		/* Capacity */
		bool	empty() const{
			if (this->_len == 0)
				return 1;
			else
				return 0;
		};
		size_t	size() const{
			return (this->_len);
		};
		size_t	max_size() const{
			return (std::numeric_limits<T>::max());
		};

		/* Element access */
		T&		front(){
			return (this->_Mnode->next->value);
		};
		T&		back(){
			return (this->_Mnode->prev->value);
		};

		/* Modifiers */
		void 	pop_front(){
			node*	address = this->_Mnode->next;

			this->_Mnode->next = address->next;
			address->next->prev = this->_Mnode;
			delete address;
			this->_len--;
			if (this->_len == 0){
				this->_Mnode->next = nullptr;
				this->_Mnode->prev = nullptr;
			}
		};
		void 	push_front(const T& val){
			node*	newNode = new node(val);

			newNode->prev = this->_Mnode;
			if (this->_len == 0)
				newNode->next = this->_Mnode;
			else{
				newNode->next = this->_Mnode->next;
				newNode->next->prev = newNode;
			}
			this->_Mnode->next = newNode;
			if (this->_Mnode->prev == nullptr)
				this->_Mnode->prev = newNode;
			this->_len++;
		};
		void 	pop_back(){
			node*	address = this->_Mnode->prev;

			this->_Mnode->prev = address->prev;
			address->prev->next = this->_Mnode;
			delete address;
			this->_len--;
			if (this->_len == 0){
				this->_Mnode->next = nullptr;
				this->_Mnode->prev = nullptr;
			}
		};
		void 	push_back(const T& val){
			node*	newNode = new node(val);

			newNode->next = this->_Mnode;
			if (this->_len == 0)
				newNode->prev = this->_Mnode;
			else{
				newNode->prev = this->_Mnode->prev;
				newNode->prev->next = newNode;
			}
			this->_Mnode->prev = newNode;
			if (this->_Mnode->next == nullptr)
				this->_Mnode->next = newNode;
			this->_len++;
		};
		void 	clear(){
			while (!this->empty())
				this->pop_front();
		}
	};
}
#endif //FT_CONTAINERS_LIST_H
