/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:29:27 by                   #+#    #+#             */
/*   Updated: 2021/06/03 12:43:09 by                  ###   ########.fr       */
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

			node() : next(nullptr), prev(nullptr) {};
			node(const T& val) : value(val), next(nullptr), prev(nullptr) {};
			node(node &src) : value(src.value), next(nullptr), prev(nullptr) {};
		};
		node	*_Mnode;
		size_t	_len;

	public:
		list() : _Mnode(new node()), _len(0){
		};
		list(size_t n, const T& val = T()) : _Mnode(new node()), _len(0) {
			this->assign(n, val);
		};
		template <class InputIterator>
		list (InputIterator first, InputIterator last) : _Mnode(new node()), _len(0) {
			this->insert(first, last);
		};
		list (const list& x) : _Mnode(new node()), _len(0) {
			const_iterator	it = x.begin();
			const_iterator	ite = x.end();

			this->template assign(it, ite);
		};
		~list(){
			this->clear();
			delete this->_Mnode;
		};

		/* Forward iterator class */
		class iterator{
		private:
			node	*_current;
		public:
			iterator() : _current(nullptr) {
			};
			iterator(node *Node) : _current(Node) {
			};
			iterator(const iterator &src) : _current(src._current) {
			};
			~iterator(){
			};

			/* Operators */
			iterator&	operator++(){
				this->_current = this->_current->next;
				return (*this);
			};
			iterator	operator++(int){
				iterator	result(*this);

				this->_current = this->_current->next;
				return (result);
			};
			iterator&	operator--(){
				this->_current = this->_current->prev;
				return (*this);
			};
			iterator	operator--(int){
				iterator	result(*this);

				this->_current = this->_current->prev;
				return (result);
			};
			T&			operator*(){
				return (this->_current->value);
			};
			T*			operator->() const {
				return &(operator*());
			}
			bool 		operator!=(const iterator &rhs){
				if (this->_current != rhs._current)
					return (true);
				else
					return (false);
			};
			bool 		operator==(const iterator &rhs){
				if (this->_current == rhs._current)
					return (true);
				else
					return (false);
			};
			iterator&	operator=(const iterator &rhs){
				if (this != &rhs)
					this->_current = rhs._current;
				return (*this);
			};

			//friend iterator list<T>::begin();
			//friend iterator list<T>::end();
			friend iterator	list<T>::erase(iterator position);
			friend iterator list<T>::insert(iterator position, const T& val);
		};

		/* Const Forward iterator class */
		class const_iterator{
		private:
			node	*_current;
		public:
			const_iterator() : _current(nullptr) {
			};
			const_iterator(node *Node) : _current(Node){
			};
			const_iterator(const const_iterator &src) : _current(src._current) {
			};
			~const_iterator() {
			};

			/* Operators */
			const_iterator&	operator++() {
				this->_current = this->_current->next;
				return (*this);
			};
			const_iterator	operator++(int) {
				const_iterator	result(*this);

				this->_current = this->_current->next;
				return (result);
			};
			const_iterator&	operator--() {
				this->_current = this->_current->prev;
				return (*this);
			};
			const_iterator	operator--(int) {
				const_iterator	result(*this);

				this->_current = this->_current->prev;
				return (result);
			};
			const T&		operator*() {
				return (this->_current->value);
			};
			const T*		operator->() const {
				return &(operator*());
			}
			bool 		operator!=(const const_iterator &rhs) {
				if (this->_current != rhs._current)
					return (true);
				else
					return (false);
			};
			bool 		operator==(const const_iterator &rhs) {
				if (this->_current == rhs._current)
					return (true);
				else
					return (false);
			};
			const_iterator&	operator=(const const_iterator &rhs) {
				if (this != &rhs)
					this->_current = rhs._current;
				return (*this);
			};

			//friend const_iterator	list<T>::begin() const;
			//friend const_iterator	list<T>::end() const;
		};

		/* Reverse iterator class */
		class reverse_iterator{
		private:
			node	*_current;
		public:
			reverse_iterator() : _current(nullptr) {
			};
			reverse_iterator(const reverse_iterator &src) : _current(src._current){
			};
			~reverse_iterator(){
			};

			/* Operators */
			reverse_iterator&	operator++(){
				this->_current = this->_current->prev;
				return (*this);
			};
			reverse_iterator	operator++(int){
				reverse_iterator	result(*this);

				this->_current = this->_current->prev;
				return (result);
			};
			reverse_iterator&	operator--(){
				this->_current = this->_current->next;
				return (*this);
			};
			reverse_iterator	operator--(int){
				iterator	result(*this);

				this->_current = this->_current->next;
				return (result);
			};
			T&					operator*(){
				return (this->_current->value);
			};
			T*					operator->() const {
				return &(operator*());
			}
			bool 				operator!=(const reverse_iterator &rhs){
				if (this->_current != rhs._current)
					return (true);
				else
					return (false);
			};
			bool 				operator==(const reverse_iterator &rhs){
				if (this->_current == rhs._current)
					return (true);
				else
					return (false);
			};
			reverse_iterator&	operator=(const reverse_iterator &rhs){
				if (this != &rhs)
					this->_current = rhs._current;
				return (*this);
			};

			friend reverse_iterator list<T>::rbegin();
			friend reverse_iterator list<T>::rend();
		};

		/* Iterators */
		iterator begin(void) {
			if (_len != 0)
				return(iterator(this->_Mnode->next));
			else
				return(iterator(this->_Mnode));
		};
		const_iterator	begin(void) const{
			if (_len != 0)
				return(const_iterator(this->_Mnode->next));
			else
				return(const_iterator(this->_Mnode));
		};
		iterator			end() {
			return(iterator(this->_Mnode));
		};
		const_iterator		end() const {
			return(const_iterator(this->_Mnode));
		};
		reverse_iterator	rbegin() {
			reverse_iterator	ret;

			if (_len != 0)
				ret._current = this->_Mnode->prev;
			else
				ret._current = this->_Mnode;
			return (ret);
		};
		reverse_iterator	rend(){
			reverse_iterator	ret;

			ret._current = this->_Mnode;
			return (ret);
		};

		/* Capacity */
		bool		empty() const{
			if (this->_len == 0)
				return true;
			else
				return false;
		};
		size_t		size() const{
			return (this->_len);
		};
		size_t		max_size() const{
			return (std::numeric_limits<T>::max());
		};

		/* Element access */
		T&			front(){
			return (this->_Mnode->next->value);
		};
		T&			back(){
			return (this->_Mnode->prev->value);
		};

		/* Modifiers */
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last){
			this->clear();
			this->insert(this->begin(), first, last);
		};
		void assign (size_t n, const T& val){
			this->clear();
			this->insert(this->begin(), n ,val);
		};
		void 		push_front(const T& val){
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
		void 		pop_front(){
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
		void 		push_back(const T& val){
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
		void 		pop_back(){
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
		iterator	insert(iterator position, const T& val) {
			iterator	ret;

			if (position._current != this->_Mnode) {
				node	*newNode = new node(val);

				ret._current = newNode;
				newNode->next = position._current;
				newNode->prev = position._current->prev;
				position._current->prev->next = newNode;
				position._current->prev = newNode;
				this->_len++;
			}
			else {
				this->push_back(val);
				ret._current = this->_Mnode->next;
			}
			return (ret);
		};
		void		insert(iterator position, size_t n, const T& val) {
			size_t	i = 0;
			while (i++ < n)
				position = this->insert(position, val);
		};
		template <class InputIterator>
		void 	insert (iterator position, InputIterator first, InputIterator last) {
			T	val;
			while (first != last) {
				val = *first;
				position = this->insert(position, val);
				first++;
			}
		};
		iterator	erase(iterator position) {
			iterator	ret;

			/* При попытке удаления конечного элемента (служебного) - Undefined Behaviour без exception'а */

			if (position._current != this->_Mnode) {
				ret._current = position._current->next;
				position._current->next->prev = position._current->prev;
				position._current->prev->next = position._current->next;
				delete position._current;
			}
			this->_len--;
			return (ret);
		};
		iterator	erase(iterator first, iterator last){
			while (first != last)
				first = this->erase(first);
			return (first);
		};
		void 		clear(){
			while (!this->empty())
				this->pop_front();
		}
	};
}
#endif //FT_CONTAINERS_LIST_H
