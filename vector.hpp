//
// Created by Alexander on 04.06.2021.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

# include <limits>
# include "algorithm.hpp"
# include <cmath>

namespace ft {
	template<class T>
	class vector {
	private:
		T		**_vector;
		size_t	_len;
		size_t	_capacity;
		size_t	_capacityCounter(size_t	newcap) {
			size_t	i = 0;
			size_t	capacity;

			while (newcap > (capacity = std::pow(2, i)))
				i++;
			return (capacity);
		};

	public:
		vector() :  _vector(nullptr), _len(0), _capacity(0) {
		};
//		vector(size_t n, const T& val = T()) : _len(0), _capacity(0) {
//			this->assign(n, val);
//		};
//		template <class InputIterator>
//		vector (InputIterator first, InputIterator last) : _len(0), _capacity(0) {
//			this->assign(first, last);
//		};
//		vector (const list& x) : _len(0), _capacity(0) {
//			this->assign(x.begin(), x.end());
//		};
		~vector(){
			this->clear();
			delete[] this->_vector;
		};
//
//		vector&	operator=(const list& x) {
//			this->assign(x.begin(), x.end());
//			return (*this);
//		};

		/* Forward random-access-iterator class */
		class iterator {
		private:
			T	**_ptr;
		public:
			iterator() : _ptr(nullptr) {
			};
			iterator(T** ptr) : _ptr(ptr) {
			};
			iterator(const iterator &src) : _ptr(src._ptr) {
			};
			~iterator(){
			};

			/* Operators */
			iterator&	operator++(){
				this->_ptr++;
				return (*this);
			};
			iterator	operator++(int){
				iterator	result(*this);

				this->_ptr++;
				return (result);
			};
			iterator&	operator--(){
				this->_ptr--;
				return (*this);
			};
			iterator	operator--(int){
				iterator	result(*this);

				this->_ptr--;
				return (result);
			};
			iterator	operator+(const	int &rhs) const {
				return ()
			};
			T&			operator*(){
				return (**(this->_ptr));
			};
			T*			operator->() const {
				return &(operator*());
			}
			bool 		operator!=(const iterator &rhs){
				if (this->_ptr != rhs._ptr)
					return (true);
				else
					return (false);
			};
			bool 		operator==(const iterator &rhs){
				if (this->_ptr == rhs._ptr)
					return (true);
				else
					return (false);
			};
			iterator&	operator=(const iterator &rhs){
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
		};

		/* Const Forward-randow-access iterator class */
		class const_iterator {
		private:
			T	**_ptr;
		public:
			const_iterator() : _ptr(nullptr) {
			};
			const_iterator(T** ptr) : _ptr(ptr) {
			};
			const_iterator(const iterator &src) : _ptr(src._ptr) {
			};
			~const_iterator(){
			};

			/* Operators */
			const_iterator&	operator++(){
				this->_ptr++;
				return (*this);
			};
			const_iterator	operator++(int){
				const_iterator	result(*this);

				this->_ptr++;
				return (result);
			};
			const_iterator&	operator--(){
				this->_ptr--;
				return (*this);
			};
			const_iterator	operator--(int){
				const_iterator	result(*this);

				this->_ptr--;
				return (result);
			};
			const	T&		operator*(){
				return (*(this->_ptr));
			};
			const	T*		operator->() const {
				return &(operator*());
			}
			bool 			operator!=(const const_iterator &rhs){
				if (this->_ptr != rhs._ptr)
					return (true);
				else
					return (false);
			};
			bool 			operator==(const const_iterator &rhs){
				if (this->_ptr == rhs._ptr)
					return (true);
				else
					return (false);
			};
			const_iterator&	operator=(const const_iterator &rhs){
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
		};
//
//		/* Reverse iterator class */
//		class reverse_iterator{
//		public:
//			node	*_current;
//
//			reverse_iterator() : _current(nullptr) {
//			};
//			reverse_iterator(const reverse_iterator &src) : _current(src._current){
//			};
//			~reverse_iterator(){
//			};
//
//			/* Operators */
//			reverse_iterator&	operator++(){
//				this->_current = this->_current->prev;
//				return (*this);
//			};
//			reverse_iterator	operator++(int){
//				reverse_iterator	result(*this);
//
//				this->_current = this->_current->prev;
//				return (result);
//			};
//			reverse_iterator&	operator--(){
//				this->_current = this->_current->next;
//				return (*this);
//			};
//			reverse_iterator	operator--(int){
//				iterator	result(*this);
//
//				this->_current = this->_current->next;
//				return (result);
//			};
//			T&					operator*(){
//				return (this->_current->value);
//			};
//			T*					operator->() const {
//				return &(operator*());
//			}
//			bool 				operator!=(const reverse_iterator &rhs){
//				if (this->_current != rhs._current)
//					return (true);
//				else
//					return (false);
//			};
//			bool 				operator==(const reverse_iterator &rhs){
//				if (this->_current == rhs._current)
//					return (true);
//				else
//					return (false);
//			};
//			reverse_iterator&	operator=(const reverse_iterator &rhs){
//				if (this != &rhs)
//					this->_current = rhs._current;
//				return (*this);
//			};
//
//			friend reverse_iterator list<T>::rbegin();
//			friend reverse_iterator list<T>::rend();
//		};
//
		/* Iterators */
		iterator begin(void) {
			return(iterator(this->_vector));
		};
		const_iterator	begin(void) const {
			return(const_iterator(this->_vector));
		};
		iterator			end() {
			return(iterator(&(this->_vector[0 + this->_len])));
		};
		const_iterator		end() const {
			return(const_iterator(&(this->_vector[0 + this->_len])));
		};
//		reverse_iterator	rbegin() {
//			reverse_iterator	ret;
//
//			if (_len != 0)
//				ret._current = this->_Mnode->prev;
//			else
//				ret._current = this->_Mnode;
//			return (ret);
//		};
//		reverse_iterator	rend(){
//			reverse_iterator	ret;
//
//			ret._current = this->_Mnode;
//			return (ret);
//		};
//
		/* Capacity */
		size_t		size() const {
			return (this->_len);
		};
//		// Need to find fix for this shit
//		size_t		max_size() const{
//			return (std::numeric_limits<size_t>::max()/(sizeof(T)*4));
//		};
		void resize (size_t n, T val = T()) {
			if (n < this->_len) {
				while (n < this->_len)
					this->pop_back();
			}
			else if (n > this->_len) {
				while (n > this->_len)
					this->push_back(val);
			}
		};
		size_t	capacity() const {
			return (this->_capacity);
		};
		bool		empty() const{
			if (this->_len == 0)
				return true;
			else
				return false;
		};
		void reserve (size_t n) {
			T		**cpy;
			size_t	newCap;
			size_t	i = 0;

			if (n > this->capacity()) {
				newCap = this->_capacityCounter(n);
				this->_capacity = newCap;
				cpy	= new T* [newCap];
				while (i < this->_len) {
					cpy[i] = this->_vector[i];
					i++;
				}
				while (i < this->_capacity) {
					cpy[i++] = nullptr;
				}
				delete[] this->_vector;
				this->_vector = cpy;
			}
		};


		/* Element access */
		T&	operator[](size_t n) {
			return (*(this->_vector[n]));
		};
		T&	operator[](size_t n) const {
			return (*(this->_vector[n]));
		};
		T&	at(size_t n) {
			return (*(this->_vector[n]));
		};
		T&	at(size_t n) const {
			return (*(this->_vector[n]));
		};
		T&	front() {
			return (*(this->_vector[0]));
		};
		T&	back(){
			return (*(this->_vector[this->_len - 1]));;
		};

		/* Modifiers */
//		template <class InputIterator>
//		void assign (InputIterator first, InputIterator last) {
//
//		};
//		void assign (size_t n, const T& val) {
//
//		};
		void 		push_back(const T& val) {
			if (this->capacity() < this->_len + 1)
				this->reserve(this->_capacityCounter(this->_len + 1));
			this->_len++;
			this->_vector[this->_len - 1] = new T;
			this->at(this->_len - 1) = val;
		};
		void 		pop_back() {
			delete this->_vector[this->_len - 1];
			this->_vector[this->_len - 1] = nullptr;
			this->_len--;
		};
		iterator insert (iterator position, const T& val) {
			iterator	ret;

			if (this->_len + 1 > this->capacity())
				this->reserve(this->_capacityCounter(this->_len + 1));
			ret = position + 1;
			this->push_back(0);
			while (ret != this->end()) {
				*ret = *(ret - 1);
				ret++;
			}
			*position = val;

			return (position);
		};
		void insert (iterator position, size_t n, const T& val) {
			size_t	i = 0;

			while (i++ < n)
				position = this->insert(position, val);
		};
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last) {
			T	val;
			while (first != last) {
				val = *first;
				position = this->insert(position, val);
				first++;
			}
		};
//		iterator	erase(iterator position) {
//			iterator	ret;
//
//			/* При попытке удаления конечного элемента (служебного) - Undefined Behaviour без exception'а */
//
//			if (position._current != this->_Mnode) {
//				ret._current = position._current->next;
//				position._current->next->prev = position._current->prev;
//				position._current->prev->next = position._current->next;
//				delete position._current;
//			}
//			this->_len--;
//			return (ret);
//		};
//		void swap (list& x){
//			size_t	nlen;
//			node	*nNode;
//
//			nlen = this->_len;
//			this->_len = x._len;
//			x._len = nlen;
//			nNode = this->_Mnode;
//			this->_Mnode = x._Mnode;
//			x._Mnode = nNode;
//		};
//		iterator	erase(iterator first, iterator last) {
//			while (first != last)
//				first = this->erase(first);
//			return (first);
//		};
//		void resize (size_t n, T val = T()) {
//			if (n > this->size()){
//				while (n > this->size())
//					this->push_back(val);
//			}
//			else{
//				while (n < this->size())
//					this->pop_back();
//			}
//		};
		void 		clear() {
			while (!this->empty())
				this->pop_back();
		}
	};

	/* Non member function overloads */
//	template <class T>
//	void swap (list<T>& x, list<T>& y) {
//		x.swap(y);
//	};

}

#endif //FT_CONTAINERS_VECTOR_HPP
