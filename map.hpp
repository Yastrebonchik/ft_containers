//
// Created by Alexander on 04.06.2021.
//

#ifndef FT_CONTAINERS_MAP_HPP
# define FT_CONTAINERS_MAP_HPP

# include <functional>
# include <utility>

namespace ft {
	template <class T> struct less : std::binary_function <T,T,bool> {
		bool operator() (const T& x, const T& y) const {return x<y;}
	};

	template< class Key, class T, class Compare = less<Key> >
	class map {
	public:
		typedef Key 									key_type;
		typedef T 										mapped_type;
		typedef Compare 								key_compare;
		typedef std::pair<const key_type, mapped_type>	value_type;

	private:
		class node {
		public:
			key_type	_first;
			mapped_type	_second;
			node		*next;
			node		*prev;

			node() : _first(key_type()), _second(mapped_type()), next(nullptr), prev(nullptr) {};
			node(const key_type& key, const T& val) : _first(key), _second(val), next(nullptr), prev(nullptr) {};
			node(node &src) : _first(src._key), _second(src._value), next(nullptr), prev(nullptr) {};
		};
		node		*_Mnode;
		size_t		_len;
		key_compare	_comp;

	public:
		map(const key_compare& comp = key_compare()) : _Mnode(new node()), _len(0), _comp(comp) {
			this->_Mnode->next = this->_Mnode;
			this->_Mnode->prev = this->_Mnode;
		};

		class iterator {
		private:
			std::pair<key_type, mapped_type>*	_val;
		public:
			node		*_current;

			iterator() : _current(nullptr) {
			};
			iterator(node *Node) : _val(new std::pair<key_type, mapped_type>(Node->_first, Node->_second)), _current(Node) {
			};
			iterator(const iterator &src) : _val(src._val), _current(src._current) {
			};
			~iterator() {
				if (this->_val != nullptr)
					delete this->_val;
			};

			/* Operators */
			iterator&		operator++() {
				this->_current = this->_current->next;
				this->_val->first = this->_current->_first;
				this->_val->second = this->_current->_second;
				return (*this);
			};
			iterator		operator++(int) {
				iterator	result(*this);

				this->_current = this->_current->next;
				this->_val->first = this->_current->_first;
				this->_val->second = this->_current->_second;
				return (result);
			};
			iterator&		operator--() {
				this->_current = this->_current->prev;
				this->_val->first = this->_current->_first;
				this->_val->second = this->_current->_second;
				return (*this);
			};
			iterator		operator--(int) {
				iterator	result(*this);

				this->_current = this->_current->prev;
				this->_val->first = this->_current->_first;
				this->_val->second = this->_current->_second;
				return (result);
			};
			std::pair<key_type, mapped_type>*	operator->() {
				return (this->_val);
			};
			bool 			operator!=(const iterator &rhs) {
				if (this->_current != rhs._current)
					return (true);
				else
					return (false);
			};
			bool 			operator==(const iterator &rhs) {
				if (this->_current == rhs._current)
					return (true);
				else
					return (false);
			};
			iterator&		operator=(const iterator &rhs) {
				if (this != &rhs)
					this->_current = rhs._current;
				return (*this);
			};

		};

		/* Const Forward iterator class */
		class const_iterator {
		public:
			node	*_current;

			const_iterator() : _current(nullptr) {
			};
			const_iterator(node *Node) : _current(Node) {
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

		};

		/* Reverse iterator class */
		class reverse_iterator {
		public:
			node	*_current;

			reverse_iterator() : _current(nullptr) {
			};
			reverse_iterator(node *Node) : _current(Node){
			};
			reverse_iterator(const reverse_iterator &src) : _current(src._current) {
			};
			~reverse_iterator() {
			};

			/* Operators */
			reverse_iterator&	operator++() {
				this->_current = this->_current->prev;
				return (*this);
			};
			reverse_iterator	operator++(int) {
				reverse_iterator	result(*this);

				this->_current = this->_current->prev;
				return (result);
			};
			reverse_iterator&	operator--() {
				this->_current = this->_current->next;
				return (*this);
			};
			reverse_iterator	operator--(int) {
				reverse_iterator	result(*this);

				this->_current = this->_current->next;
				return (result);
			};
			T&					operator*() {
				return (this->_current->value);
			};
			T*					operator->() const {
				return &(operator*());
			}
			bool 				operator!=(const reverse_iterator &rhs) {
				if (this->_current != rhs._current)
					return (true);
				else
					return (false);
			};
			bool 				operator==(const reverse_iterator &rhs) {
				if (this->_current == rhs._current)
					return (true);
				else
					return (false);
			};
			reverse_iterator&	operator=(const reverse_iterator &rhs) {
				if (this != &rhs)
					this->_current = rhs._current;
				return (*this);
			};
		};

		/* Const reverse iterator class */
		class const_reverse_iterator{
		public:
			node	*_current;

			const_reverse_iterator() : _current(nullptr) {
			};
			const_reverse_iterator(node *Node) : _current(Node){
			};
			const_reverse_iterator(const const_reverse_iterator &src) : _current(src._current) {
			};
			~const_reverse_iterator() {
			};

			/* Operators */
			const_reverse_iterator&	operator++() {
				this->_current = this->_current->prev;
				return (*this);
			};
			const_reverse_iterator	operator++(int) {
				const_reverse_iterator	result(*this);

				this->_current = this->_current->prev;
				return (result);
			};
			const_reverse_iterator&	operator--() {
				this->_current = this->_current->next;
				return (*this);
			};
			const_reverse_iterator	operator--(int) {
				const_reverse_iterator	result(*this);

				this->_current = this->_current->next;
				return (result);
			};
			const T&				operator*() {
				return (this->_current->value);
			};
			const T*				operator->() const {
				return &(operator*());
			}
			bool 					operator!=(const const_reverse_iterator &rhs) {
				if (this->_current != rhs._current)
					return (true);
				else
					return (false);
			};
			bool 					operator==(const const_reverse_iterator &rhs) {
				if (this->_current == rhs._current)
					return (true);
				else
					return (false);
			};
			const_reverse_iterator&	operator=(const reverse_iterator &rhs) {
				if (this != &rhs)
					this->_current = rhs._current;
				return (*this);
			};
		};

		/* Iterators */
		iterator 				begin(void) {
			return(iterator(this->_Mnode->next));
		};
		const_iterator			begin(void) const {
			return(const_iterator(this->_Mnode->next));
		};
		iterator				end() {
			return(iterator(this->_Mnode));
		};
		const_iterator			end() const {
			return(const_iterator(this->_Mnode));
		};
		reverse_iterator		rbegin() {
			return(reverse_iterator(this->_Mnode->prev));
		};
		const_reverse_iterator	rbegin() const {
			return(const_reverse_iterator(this->_Mnode->prev));
		};
		reverse_iterator		rend(){
			return(reverse_iterator(this->_Mnode));
		};
		const_reverse_iterator	rend() const {
			return(const_reverse_iterator(this->_Mnode));
		};

		/* Capacity */
		bool		empty() const {
			if (this->_len == 0)
				return true;
			else
				return false;
		};
		size_t		size() const {
			return (this->_len);
		};

		size_t		max_size() const {
			return (std::numeric_limits<size_t>::max() / (sizeof(node)));
		};

		mapped_type& operator[] (const key_type& k) {
			iterator	it = this->begin();

			while (it != this->end()) {
				if (it->first == k)
					return (it->second);
				it++;
			}
			it = insert(it, std::pair<key_type, mapped_type>(k, mapped_type()));
			return (it->second);
		};

		std::pair<iterator,bool>	insert(const value_type& val) {
			iterator					it = this->begin();
			std::pair<iterator, bool>	ret;
			node						*nNode;

			while (it != this->end()) {
				if (this->_comp(it._current->_first, val.first))
					it++;
				else {
					ret.first = it;
					if (it._current->_first == val.first)
						ret.second = false;
					else {
						nNode = new node(val.first, val.second);
						nNode->next = it._current;
						nNode->prev = it._current->prev;
						it._current->prev->next = nNode;
						it._current->prev = nNode;
						ret.second = true;
						this->_len += 1;
					}
					return (ret);
				}
			}
			nNode = new node(val.first, val.second);
			nNode->next = it._current;
			nNode->prev = it._current->prev;
			it._current->prev->next = nNode;
			it._current->prev = nNode;
			ret.first = --it;
			ret.second = true;
			this->_len += 1;
			return (ret);
		};

		iterator insert (iterator position, const value_type& val) {
			iterator	ret;
			node		*nNode = new node(val.first, val.second);

			if (!this->_comp(position->first, position->second))
				position = this->begin();
			while (position != this->end()) {
				if (this->_comp(position->first, val.first))
					position++;
				else {
					if (position->first == val.first)
						ret = position;
					else {
						nNode->_first = val.first;
						nNode->_second = val.second;
						nNode->next = position._current;
						nNode->prev = position._current->prev;
						position._current->prev->next = nNode;
						position._current->prev = nNode;
						this->_len += 1;
						ret = position._current->prev;
					}
					return (ret);
				}
			}
			nNode->_first = val.first;
			nNode->_second = val.second;
			nNode->next = position._current;
			nNode->prev = position._current->prev;
			position._current->prev->next = nNode;
			position._current->prev = nNode;
			this->_len += 1;
			ret = position._current->prev;
			return (ret);
		};

	};
}

#endif //FT_CONTAINERS_MAP_HPP
