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
			T		**_ptr;
			size_t	_pos;
		public:
			iterator() : _ptr(nullptr), _pos(0) {
			};
			iterator(T** ptr, size_t pos) : _ptr(ptr) , _pos(pos) {
			};
			iterator(const iterator &src) : _ptr(src._ptr), _pos(src._pos) {
			};
			~iterator() {
			};

			/* Operators */
			bool 		operator==(const iterator &rhs) const {
				if (this->_ptr == rhs._ptr)
					return (true);
				else
					return (false);
			};
			bool 		operator!=(const iterator &rhs) const {
				if (this->_ptr != rhs._ptr)
					return (true);
				else
					return (false);
			};
			T&			operator*() {
				return (**(this->_ptr));
			};
			T*			operator->() {
				return &(operator*());
			}
			iterator&	operator++() {
				this->_ptr++;
				this->_pos++;
				return (*this);
			};
			iterator	operator++(int) {
				iterator	result(*this);

				this->_ptr++;
				this->_pos++;
				return (result);
			};
			iterator&	operator--(){
				this->_ptr--;
				this->_pos--;
				return (*this);
			};
			iterator	operator--(int) {
				iterator	result(*this);

				this->_ptr--;
				this->_pos--;
				return (result);
			};
			iterator	operator+(const	int &rhs) {
				int 		offset = 0;
				iterator	newIt = *this;

				while (offset++ < rhs)
					newIt++;
				return (newIt);
			};
			iterator	operator-(const	int &rhs) {
				int 		offset = rhs;
				iterator	newIt = *this;

				while (offset-- > 0)
					newIt--;
				return (newIt);
			};
			size_t		operator-(const iterator &rhs) const {
				size_t	diff = 0;

				while (this-- != &rhs)
					diff++;
				return (diff);
			};
			iterator	operator<(const iterator &rhs) const {
				return (this->_pos < rhs._pos);
			}
			iterator	operator>(const iterator &rhs) const {
				return (this->_pos > rhs._pos);
			}
			iterator	operator<=(const iterator &rhs) const {
				return (this->_pos <= rhs._pos);
			}
			iterator	operator>=(const iterator &rhs) const {
				return (this->_pos >= rhs._pos);
			}
			iterator	operator+=(const int &rhs) {
				int 		offset = 0;
				iterator	newIt = *this;

				while (offset++ < rhs)
					newIt++;
				return (newIt);
			};
			iterator	operator-=(const int &rhs) {
				int 		offset = rhs;
				iterator	newIt = *this;

				while (offset-- > 0)
					newIt--;
				return (newIt);
			};
			iterator&	operator=(const iterator &rhs) {
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
			T&			operator[](const int &rhs) {
				return (*(this + rhs));
			};
		};

		/* Const Forward-random-access iterator class */
		class const_iterator {
		private:
			T		**_ptr;
			size_t	_pos;
		public:
			const_iterator() : _ptr(nullptr), _pos(0) {
			};
			const_iterator(T** ptr, size_t pos) : _ptr(ptr) , _pos(pos) {
			};
			const_iterator(const const_iterator &src) : _ptr(src._ptr), _pos(src._pos) {
			};
			~const_iterator() {
			};

			/* Operators */
			bool 			operator==(const const_iterator &rhs) const {
				if (this->_ptr == rhs._ptr)
					return (true);
				else
					return (false);
			};
			bool 			operator!=(const const_iterator &rhs) const {
				if (this->_ptr != rhs._ptr)
					return (true);
				else
					return (false);
			};
			const	T&		operator*() const {
				return (**(this->_ptr));
			};
			const	T*		operator->() const {
				return &(operator*());
			}
			const_iterator&	operator++() {
				this->_ptr++;
				this->_pos++;
				return (*this);
			};
			const_iterator	operator++(int) {
				const_iterator	result(*this);

				this->_ptr++;
				this->_pos++;
				return (result);
			};
			const_iterator&	operator--() {
				this->_ptr--;
				this->_pos--;
				return (*this);
			};
			const_iterator	operator--(int) {
				const_iterator	result(*this);

				this->_ptr--;
				this->_pos--;
				return (result);
			};
			const_iterator	operator+(const	int &rhs) {
				int 			offset = 0;
				const_iterator	newIt = *this;

				while (offset++ < rhs)
					newIt++;
				return (newIt);
			};
			const_iterator	operator-(const	int &rhs) {
				int 			offset = rhs;
				const_iterator	newIt = *this;

				while (offset-- > 0)
					newIt--;
				return (newIt);
			};
			size_t			operator-(const const_iterator &rhs) {
				size_t	diff = 0;

				while (this-- != &rhs)
					diff++;
				return (diff);
			};
			const_iterator	operator<(const const_iterator &rhs) const {
				return (this->_pos < rhs._pos);
			}
			const_iterator	operator>(const const_iterator &rhs) const {
				return (this->_pos > rhs._pos);
			}
			const_iterator	operator<=(const const_iterator &rhs) const {
				return (this->_pos <= rhs._pos);
			}
			const_iterator	operator>=(const const_iterator &rhs) const {
				return (this->_pos >= rhs._pos);
			}
			const_iterator	operator+=(const int &rhs) {
				int 		offset = 0;
				const_iterator	newIt = *this;

				while (offset++ < rhs)
					newIt++;
				return (newIt);
			};
			const_iterator	operator-=(const int &rhs) {
				int 		offset = rhs;
				const_iterator	newIt = *this;

				while (offset-- > 0)
					newIt--;
				return (newIt);
			};
			const_iterator&	operator=(const const_iterator &rhs) {
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
			const	T&		operator[](const int &rhs) const {
				return (*(this + rhs));
			};
		};

		/* Reverse random-access-iterator class */
		class reverse_iterator {
		private:
			T		**_ptr;
			int		_pos;
		public:
			reverse_iterator() : _ptr(nullptr), _pos(0) {
			};
			reverse_iterator(T** ptr, size_t pos) : _ptr(ptr), _pos(pos) {
			};
			reverse_iterator(const reverse_iterator &src) : _ptr(src._ptr), _pos(src._pos) {
			};
			~reverse_iterator() {
			};

			/* Operators */
			bool 		operator==(const reverse_iterator &rhs) const {
				if (this->_pos == rhs._pos)
					return (true);
				else
					return (false);
			};
			bool 		operator!=(const reverse_iterator &rhs) const {
				if (this->_pos != rhs._pos)
					return (true);
				else
					return (false);
			};
			T&			operator*() {
				return (**(this->_ptr));
			};
			T*			operator->() {
				return &(operator*());
			}
			reverse_iterator&	operator++() {
				this->_ptr--;
				this->_pos--;
				return (*this);
			};
			reverse_iterator	operator++(int) {
				reverse_iterator	result(*this);

				this->_ptr--;
				this->_pos--;
				return (result);
			};
			reverse_iterator&	operator--() {
				this->_ptr++;
				this->_pos++;
				return (*this);
			};
			reverse_iterator	operator--(int) {
				reverse_iterator	result(*this);

				this->_ptr++;
				this->_pos++;
				return (result);
			};
			reverse_iterator	operator+(const	int &rhs) {
				int 				offset = 0;
				reverse_iterator	newIt = *this;

				while (offset++ < rhs)
					newIt++;
				return (newIt);
			};
			reverse_iterator	operator-(const	int &rhs) {
				int 		offset = rhs;
				reverse_iterator	newIt = *this;

				while (offset-- > 0)
					newIt--;
				return (newIt);
			};
			size_t				operator-(const reverse_iterator &rhs) const {
				size_t	diff = 0;

				while (this-- != &rhs)
					diff++;
				return (diff);
			};
			reverse_iterator	operator<(const reverse_iterator &rhs) const {
				return (this->_pos > rhs._pos);
			}
			reverse_iterator	operator>(const reverse_iterator &rhs) const {
				return (this->_pos < rhs._pos);
			}
			reverse_iterator	operator<=(const reverse_iterator &rhs) const {
				return (this->_pos >= rhs._pos);
			}
			reverse_iterator	operator>=(const reverse_iterator &rhs) const {
				return (this->_pos <= rhs._pos);
			}
			reverse_iterator	operator+=(const int &rhs) {
				int 				offset = 0;
				reverse_iterator	newIt = *this;

				while (offset++ < rhs)
					newIt++;
				return (newIt);
			};
			reverse_iterator	operator-=(const int &rhs) {
				int 				offset = rhs;
				reverse_iterator	newIt = *this;

				while (offset-- > 0)
					newIt--;
				return (newIt);
			};
			reverse_iterator&	operator=(const reverse_iterator &rhs) {
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
			T&					operator[](const int &rhs) {
				return (*(this + rhs));
			};
		};

		class const_reverse_iterator {
		private:
			T		**_ptr;
			int		_pos;
		public:
			const_reverse_iterator() : _ptr(nullptr), _pos(0) {
			};
			const_reverse_iterator(T** ptr, size_t pos) : _ptr(ptr), _pos(pos) {
			};
			const_reverse_iterator(const const_reverse_iterator &src) : _ptr(src._ptr), _pos(src._pos) {
			};
			~const_reverse_iterator() {
			};

			/* Operators */
			bool 		operator==(const const_reverse_iterator &rhs) const {
				if (this->_pos == rhs._pos)
					return (true);
				else
					return (false);
			};
			bool 		operator!=(const const_reverse_iterator &rhs) const {
				if (this->_pos != rhs._pos)
					return (true);
				else
					return (false);
			};
			const	T&	operator*() const {
				return (**(this->_ptr));
			};
			const	T*	operator->() const {
				return &(operator*());
			}
			const_reverse_iterator&	operator++() {
				this->_ptr--;
				this->_pos--;
				return (*this);
			};
			const_reverse_iterator	operator++(int) {
				const_reverse_iterator	result(*this);

				this->_ptr--;
				this->_pos--;
				return (result);
			};
			const_reverse_iterator&	operator--() {
				this->_ptr++;
				this->_pos++;
				return (*this);
			};
			const_reverse_iterator	operator--(int) {
				const_reverse_iterator	result(*this);

				this->_ptr++;
				this->_pos++;
				return (result);
			};
			const_reverse_iterator	operator+(const	int &rhs) {
				int 					offset = 0;
				const_reverse_iterator	newIt = *this;

				while (offset++ < rhs)
					newIt++;
				return (newIt);
			};
			const_reverse_iterator	operator-(const	int &rhs) {
				int 					offset = rhs;
				const_reverse_iterator	newIt = *this;

				while (offset-- > 0)
					newIt--;
				return (newIt);
			};
			size_t					operator-(const const_reverse_iterator &rhs) const {
				size_t	diff = 0;

				while (this-- != &rhs)
					diff++;
				return (diff);
			};
			const_reverse_iterator	operator<(const const_reverse_iterator &rhs) const {
				return (this->_pos > rhs._pos);
			}
			const_reverse_iterator	operator>(const const_reverse_iterator &rhs) const{
				return (this->_pos < rhs._pos);
			}
			const_reverse_iterator	operator<=(const const_reverse_iterator &rhs) const {
				return (this->_pos >= rhs._pos);
			}
			const_reverse_iterator	operator>=(const const_reverse_iterator &rhs) const {
				return (this->_pos <= rhs._pos);
			}
			const_reverse_iterator	operator+=(const int &rhs) {
				int 				offset = 0;
				const_reverse_iterator	newIt = *this;

				while (offset++ < rhs)
					newIt++;
				return (newIt);
			};
			const_reverse_iterator	operator-=(const int &rhs) {
				int 					offset = rhs;
				const_reverse_iterator	newIt = *this;

				while (offset-- > 0)
					newIt--;
				return (newIt);
			};
			const_reverse_iterator&	operator=(const const_reverse_iterator &rhs) {
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
			const	T&			operator[](const int &rhs) const {
				return (*(this + rhs));
			};
		};

		/* Iterators */
		iterator begin(void) {
			return(iterator(this->_vector, 0));
		};
		const_iterator	begin(void) const {
			return(const_iterator(this->_vector, 0));
		};
		iterator			end() {
			return(iterator(&(this->_vector[0 + this->_len]), this->_len));
		};
		const_iterator		end() const {
			return(const_iterator(&(this->_vector[0 + this->_len]), this->_len));
		};
		reverse_iterator	rbegin() {
			return(reverse_iterator(&(this->_vector[0 + this->_len - 1]), this->_len - 1));
		};
		const_reverse_iterator	rbegin() const {
			return(const_reverse_iterator(&(this->_vector[0 + this->_len - 1]), this->_len - 1));
		};
		reverse_iterator	rend() {
			return(reverse_iterator(this->_vector, -1));
		};
		const_reverse_iterator	rend() const {
			return(const_reverse_iterator(this->_vector, -1));
		};

		/* Capacity */
		size_t		size() const {
			return (this->_len);
		};
		size_t		max_size() const{
			return (std::numeric_limits<size_t>::max() / (sizeof(T)));
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
		T&			operator[](size_t n) {
			return (*(this->_vector[n]));
		};
		const T&	operator[](size_t n) const {
			return (*(this->_vector[n]));
		};
		T&			at(size_t n) {
			if (n > this->_len)
				throw std::out_of_range("Out of bounds");
			return (*(this->_vector[n]));
		};
		const T&	at(size_t n) const {
			if (n > this->_len)
				throw std::out_of_range("Out of bounds");
			return (*(this->_vector[n]));
		};
		T&			front() {
			return (*(this->_vector[0]));
		};
		const T&	front() const {
			return (*(this->_vector[0]));
		};
		T&			back(){
			return (*(this->_vector[this->_len - 1]));;
		};
		const T&	back() const{
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
