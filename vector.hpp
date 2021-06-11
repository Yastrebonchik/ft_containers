//
// Created by Alexander on 04.06.2021.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

# include <limits>
# include "algorithm.hpp"
# include <cmath>
# include <exception>

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
		vector (size_t n, const T& val = T()) : _vector(nullptr), _len(0), _capacity(0) {
			this->assign(n, val);
		};
		template <class InputIterator>
		vector (InputIterator first, InputIterator last) : _vector(nullptr), _len(0), _capacity(0) {
			this->assign(first, last);
		};
		vector (const vector& x) : _vector(nullptr), _len(0), _capacity(0) {
			this->assign(x.begin(), x.end());
		};
		~vector(){
			this->clear();
			delete[] this->_vector;
		};

		vector&	operator=(const vector& x) {
			this->assign(x.begin(), x.end());
			return (*this);
		};

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
				int 		offset = 0;
				iterator	newIt = *this;

				while (offset++ < rhs)
					newIt++;
				return (newIt);
			};
			iterator	operator-(const	int &rhs) const {
				int 		offset = rhs;
				iterator	newIt = *this;

				while (offset-- > 0)
					newIt--;
				return (newIt);
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

		/* Const Forward-random-access iterator class */
		class const_iterator {
		private:
			T **_ptr;
		public:
			const_iterator() : _ptr(nullptr) {
			};

			const_iterator(T **ptr) : _ptr(ptr) {
			};

			const_iterator(const const_iterator &src) : _ptr(src._ptr) {
			};

			~const_iterator() {
			};

			/* Operators */
			const_iterator &operator++() {
				this->_ptr++;
				return (*this);
			};

			const_iterator operator++(int) {
				const_iterator result(*this);

				this->_ptr++;
				return (result);
			};

			const_iterator &operator--() {
				this->_ptr--;
				return (*this);
			};

			const_iterator operator--(int) {
				const_iterator result(*this);

				this->_ptr--;
				return (result);
			};

			const T &operator*() {
				return (**(this->_ptr));
			};

			const T *operator->() const {
				return &(operator*());
			}

			bool operator!=(const const_iterator &rhs) {
				if (this->_ptr != rhs._ptr)
					return (true);
				else
					return (false);
			};

			bool operator==(const const_iterator &rhs) {
				if (this->_ptr == rhs._ptr)
					return (true);
				else
					return (false);
			};

			const_iterator &operator=(const const_iterator &rhs) {
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
		};

		/* Reverse random-access-iterator class */
		class reverse_iterator {
		private:
			T	**_ptr;
		public:
			reverse_iterator() : _ptr(nullptr) {
			};
			reverse_iterator(T** ptr) : _ptr(ptr) {
			};
			reverse_iterator(const reverse_iterator &src) : _ptr(src._ptr) {
			};
			~reverse_iterator(){
			};

			/* Operators */
			reverse_iterator&	operator++(){
				this->_ptr--;
				return (*this);
			};
			reverse_iterator	operator++(int){
				iterator	result(*this);

				this->_ptr--;
				return (result);
			};
			reverse_iterator&	operator--(){
				this->_ptr++;
				return (*this);
			};
			reverse_iterator	operator--(int){
				reverse_iterator	result(*this);

				this->_ptr++;
				return (result);
			};
			reverse_iterator	operator+(const	int &rhs) const {
				int 		offset = 0;
				reverse_iterator	newIt = *this;

				while (offset++ < rhs)
					newIt++;
				return (newIt);
			};
			reverse_iterator	operator-(const	int &rhs) const {
				int 		offset = rhs;
				reverse_iterator	newIt = *this;

				while (offset-- > 0)
					newIt--;
				return (newIt);
			};
			T&			operator*(){
				return (**(this->_ptr));
			};
			T*			operator->() const {
				return &(operator*());
			}
			bool 		operator!=(const reverse_iterator &rhs){
				if (this->_ptr != rhs._ptr)
					return (true);
				else
					return (false);
			};
			bool 		operator==(const reverse_iterator &rhs){
				if (this->_ptr == rhs._ptr)
					return (true);
				else
					return (false);
			};
			reverse_iterator&	operator=(const reverse_iterator &rhs){
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
		};

		class const_reverse_iterator {
		private:
			T	**_ptr;
		public:
			const_reverse_iterator() : _ptr(nullptr) {
			};
			const_reverse_iterator(T** ptr) : _ptr(ptr) {
			};
			const_reverse_iterator(const const_reverse_iterator &src) : _ptr(src._ptr) {
			};
			~const_reverse_iterator(){
			};

			/* Operators */
			const_reverse_iterator&	operator++(){
				this->_ptr--;
				return (*this);
			};
			const_reverse_iterator	operator++(int){
				iterator	result(*this);

				this->_ptr--;
				return (result);
			};
			const_reverse_iterator&	operator--(){
				this->_ptr++;
				return (*this);
			};
			const_reverse_iterator	operator--(int){
				reverse_iterator	result(*this);

				this->_ptr++;
				return (result);
			};
			const_reverse_iterator	operator+(const	int &rhs) const {
				int 		offset = 0;
				reverse_iterator	newIt = *this;

				while (offset++ < rhs)
					newIt++;
				return (newIt);
			};
			const_reverse_iterator	operator-(const	int &rhs) const {
				int 		offset = rhs;
				reverse_iterator	newIt = *this;

				while (offset-- > 0)
					newIt--;
				return (newIt);
			};
			const T&				operator*(){
				return (**(this->_ptr));
			};
			const T*				operator->() const {
				return &(operator*());
			}
			bool 		operator!=(const const_reverse_iterator &rhs){
				if (this->_ptr != rhs._ptr)
					return (true);
				else
					return (false);
			};
			bool 		operator==(const const_reverse_iterator &rhs){
				if (this->_ptr == rhs._ptr)
					return (true);
				else
					return (false);
			};
			const_reverse_iterator&	operator=(const const_reverse_iterator &rhs){
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
		};

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
		reverse_iterator	rbegin() {
			return(--reverse_iterator(this->_vector));
		};
		const_reverse_iterator	rbegin() const {
			return(--const_reverse_iterator(this->_vector));
		};
		reverse_iterator	rend(){
			return(--reverse_iterator(&(this->_vector[0 + this->_len])));
		};
		const_reverse_iterator	rend() const {
			return(--const_reverse_iterator(this->_vector));
		};

		/* Capacity */
		size_t		size() const {
			return (this->_len);
		};
		// Need to find fix for this shit
		size_t		max_size() const{
			return (std::numeric_limits<size_t>::max()/(sizeof(T)*4));
		};
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
			if (n > this->_len)
				throw std::out_of_range("Out of bounds");
			return (*(this->_vector[n]));
		};
		T&	at(size_t n) const {
			if (n > this->_len)
				throw std::out_of_range("Out of bounds");
			return (*(this->_vector[n]));
		};
		T&	front() {
			return (*(this->_vector[0]));
		};
		T&	back(){
			return (*(this->_vector[this->_len - 1]));;
		};

		/* Modifiers */
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {
			this->clear();
			this->insert(this->begin(), first, last);
		};
		void assign (size_t n, const T& val) {
			this->clear();
			this->insert(this->begin(), n, val);
		};
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
			int			offset = 0;
			iterator	ret = this->begin();

			while (ret++ != position)
				offset++;
			if (this->_len + 1 > this->capacity())
				this->reserve(this->_capacityCounter(this->_len + 1));
			position = this->begin() + offset;
			ret = position;
			this->push_back(T());
			position = this->begin() + (static_cast<int>(this->_len) - 1);
			while (position != ret) {
				*position = *(position - 1);
				position--;
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

			last--;
			while (first != last) {
				val = *last;
				position = this->insert(position, val);
				last--;
			}
			val = *last;
			position = this->insert(position, val);
		};
		iterator erase (iterator position) {
			int			offset = 0;
			iterator	ret = this->end();

			while (ret-- != position)
				offset++;
			while (position != this->end() - 1) {
				*position = *(position + 1);
				position++;
			}
			this->pop_back();

			return (position);
		};
		iterator 	erase (iterator first, iterator last) {
			while (first != last)
				first = this->erase(first);
		};
		void 		swap (vector& x) {
			T		**vector;
			size_t	len;
			size_t	capacity;

			vector = this->_vector;
			len = this->_len;
			capacity = this->_capacity;
			this->_vector = x._vector;
			this->_len = x._len;
			this->_capacity = x._capacity;
			x._vector = vector;
			x._len = len;
			x._capacity = capacity;
		};
		void 		clear() {
			while (!this->empty())
				this->pop_back();
		}
	};

	/* Non member function overloads */
	template <class T>
	void swap (vector<T>& x, vector<T>& y) {
		x.swap(y);
	};

	template <class T>
	bool operator==(const vector<T>& lhs, const vector<T>& rhs) {
		typename vector<T>::const_iterator	itl = lhs.begin();
		typename vector<T>::const_iterator	itle = lhs.end();
		typename vector<T>::const_iterator	itr = rhs.begin();
		typename vector<T>::const_iterator	itre = rhs.end();

		if (lhs.size() != rhs.size())
			return (false);
		while (itl != itle && itr != itre) {
			if (*itl != *itr)
				return (false);
			itl++;
			itr++;
		}
		return (true);
	};

	template <class T>
	bool operator!=(const vector<T>& lhs, const vector<T>& rhs) {
		return (!(lhs == rhs));
	};

	template <class T>
	bool operator<(const vector<T>& lhs, const vector<T>& rhs) {
		return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template <class T>
	bool operator>(const vector<T>& lhs, const vector<T>& rhs) {
		return (operator<(rhs, lhs));
	};

	template <class T>
	bool operator<=(const vector<T>& lhs, const vector<T>& rhs) {
		return (!(operator<(rhs, lhs)));
	};

	template <class T>
	bool operator>=(const vector<T>& lhs, const vector<T>& rhs) {
		return (!(operator<(lhs, rhs)));
	};

}

#endif //FT_CONTAINERS_VECTOR_HPP
