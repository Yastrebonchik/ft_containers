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
	template <class T> struct more : std::binary_function <T,T,bool> {
		bool operator() (const T& x, const T& y) const {return x>y;}
	};

	template< class Key, class T, class Compare = less<Key> >
	class map {
	public:
		typedef Key 									key_type;
		typedef T 										mapped_type;
		typedef Compare 								key_compare;
		typedef std::pair<const key_type, mapped_type>	value_type;

		class	value_compare
		{
			friend  map;
		protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {
			};
		public:
			typedef bool 		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const {
				return comp(x.first, y.first);
			}
		};

	private:
		class node {
		public:
			value_type	val;
			node		*next;
			node		*prev;

			node() : val(std::pair<key_type, mapped_type>()), next(nullptr), prev(nullptr) {};
			node(const key_type& key, const T& val) : val(std::pair<key_type, mapped_type>(key, val)), next(nullptr), prev(nullptr) {};
			node(node &src) : val(src.val), next(nullptr), prev(nullptr) {};
		};
		node			*_Mnode;
		size_t			_len;
		key_compare		_comp;
		value_compare	_valComp;

	public:
		map(const key_compare& comp = key_compare()) : _Mnode(new node()), _len(0), _comp(comp), _valComp(comp) {
			this->_Mnode->next = this->_Mnode;
			this->_Mnode->prev = this->_Mnode;
		};
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare()) : _Mnode(new node()), _len(0), _comp(comp), _valComp(comp) {
			this->_Mnode->next = this->_Mnode;
			this->_Mnode->prev = this->_Mnode;
			this->insert(first, last);
		};
		map (const map& x) : _Mnode(new node()), _len(0), _comp(x._comp), _valComp(x._comp) {
			this->_Mnode->next = this->_Mnode;
			this->_Mnode->prev = this->_Mnode;
			this->insert(x.begin(), x.end());
		};
		~map() {
			this->clear();
			delete this->_Mnode;
		};

		map& operator= (const map& x) {
			this->clear();
			this->insert(x.begin(), x.end());
		};

		class iterator {
		public:
			node		*_current;

			iterator() : _current(nullptr) {
			};
			iterator(node *Node) : _current(Node) {
			};
			iterator(const iterator &src) : _current(src._current) {
			};
			~iterator() {
			};

			/* Operators */
			iterator&		operator++() {
				this->_current = this->_current->next;
				return (*this);
			};
			iterator		operator++(int) {
				iterator	result(*this);

				this->_current = this->_current->next;
				return (result);
			};
			iterator&		operator--() {
				this->_current = this->_current->prev;
				return (*this);
			};
			iterator		operator--(int) {
				iterator	result(*this);

				this->_current = this->_current->prev;
				return (result);
			};
			value_type*		operator->() {
				return (&(this->_current->val));
			};
			value_type&		operator*() {
				return ((this->_current->val));
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
			const_iterator&		operator++() {
				this->_current = this->_current->next;
				return (*this);
			};
			const_iterator		operator++(int) {
				const_iterator	result(*this);

				this->_current = this->_current->next;
				return (result);
			};
			const_iterator&		operator--() {
				this->_current = this->_current->prev;
				return (*this);
			};
			const_iterator		operator--(int) {
				const_iterator	result(*this);

				this->_current = this->_current->prev;
				return (result);
			};
			const value_type*	operator->() {
				return (&(this->_current->val));
			};
			bool 				operator!=(const const_iterator &rhs) {
				if (this->_current != rhs._current)
					return (true);
				else
					return (false);
			};
			bool 				operator==(const const_iterator &rhs) {
				if (this->_current == rhs._current)
					return (true);
				else
					return (false);
			};
			const_iterator&		operator=(const const_iterator &rhs) {
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
			value_type*			operator->() {
				return (&(this->_current->val));
			};
			value_type&		operator*() {
				return ((this->_current->val));
			};
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
			const value_type*		operator->() {
				return (&(this->_current->val));
			};
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
			return (std::numeric_limits<size_t>::max() / (sizeof(node) * 5/3));
		};

		/* Element access */
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

		/* Modifiers */
		std::pair<iterator,bool>		insert(const value_type& val) {
			iterator					it = this->begin();
			std::pair<iterator, bool>	ret;
			node						*nNode;

			while (it != this->end()) {
				if (this->_comp(it._current->val.first, val.first))
					it++;
				else {
					ret.first = it;
					if (it._current->val.first == val.first)
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

		iterator						insert (iterator position, const value_type& val) {
			iterator	ret;
			node		*nNode = new node(val.first, val.second);

			if (!this->_comp(position->first, position->second))
				position = this->begin();
			while (position != this->end()) {
				if (this->_comp(position->first, val.first))
					position++;
				else {
					if (position->first == val.first) {
						ret = position;
						delete	nNode;
					}
					else {
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
			nNode->next = position._current;
			nNode->prev = position._current->prev;
			position._current->prev->next = nNode;
			position._current->prev = nNode;
			this->_len += 1;
			ret = position._current->prev;
			return (ret);
		};
		template <class InputIterator>
		void 							insert (InputIterator first, InputIterator last) {
			std::pair<key_type, mapped_type>	pair;
			while (first != last) {
				pair = std::make_pair(first->first, first->second);
				this->insert(pair);
				first++;
			}
		};

		void 							erase (iterator position) {
			if (position != this->_Mnode) {
				position._current->next->prev = position._current->prev;
				position._current->prev->next = position._current->next;
				delete position._current;
				this->_len--;
			}
		};
		size_t							erase (const key_type& k) {
			iterator	it = this->begin();

			while (it != this->end()) {
				if (it._current->val.first == k) {
					this->erase(it);
					return (1);
				}
				it++;
			}
			return (0);
		};
		void							erase (iterator first, iterator last) {
			iterator	it;

			while (first != last) {
				it._current = first._current->next;
				this->erase(first);
				first = it;
			}
		};
		void 							swap (map& x) {
			size_t	nlen;
			node	*nNode;

			nlen = this->_len;
			this->_len = x._len;
			x._len = nlen;
			nNode = this->_Mnode;
			this->_Mnode = x._Mnode;
			x._Mnode = nNode;
		};
		void 							clear() {
			this->erase(this->begin(), this->end());
		}

		/* Observers */
		key_compare						key_comp() const {
			return (this->_comp);
		};
		value_compare					value_comp() const {
			return (this->_valComp);
		};

		/* Operations */
		iterator 						find (const key_type& k) {
			iterator	it = this->begin();

			while (it != this->end()) {
				if (it._current->val.first == k)
					break;
				it++;
			}
			return (it);
		};
		const_iterator					find (const key_type& k) const {
			const_iterator	it = this->begin();

			while (it != this->end()) {
				if (it._current->val.first == k)
					break;
				it++;
			}
			return (it);
		};
		size_t 							count (const key_type& k) const {
			const_iterator	it = this->begin();

			while (it != this->end()) {
				if (it._current->val.first == k)
					return (1);
				it++;
			}
			return (0);
		};
		iterator						lower_bound (const key_type& k) {
			iterator	it = this->begin();

			while (it != this->end()) {
				if (!this->_comp(it._current->val.first, k))
					break;
				it++;
			}
			return (it);
		};
		const_iterator					lower_bound (const key_type& k) const {
			const_iterator	it = this->begin();

			while (it != this->end()) {
				if (!this->_comp(it._current->val.first, k))
					break;
				it++;
			}
			return (it);
		};
		iterator						upper_bound (const key_type& k) {
			iterator	it = this->begin();

			while (it != this->end()) {
				if (this->_comp(k, it._current->val.first))
					break;
				it++;
			}
			return (it);
		};
		const_iterator					upper_bound (const key_type& k) const {
			const_iterator	it = this->begin();

			while (it != this->end()) {
				if (this->_comp(k, it._current->val.first))
					break;
				it++;
			}
			return (it);
		};
		std::pair<iterator,iterator>	equal_range (const key_type& k) {
			iterator	it = this->begin();
			iterator	ret;

			while (it != this->end()) {
				if (!this->_comp(it._current->val.first, k)) {
					if (it._current->val.first == k) {
						ret = it++;
						return (std::make_pair(ret, it));
					}
				}
				it++;
				ret = it;
			}
			return (std::make_pair(ret, it));
		};
		std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			const_iterator	it = this->begin();
			const_iterator	ret;

			while (it != this->end()) {
				if (!this->_comp(it._current->val.first, k)) {
					if (it._current->val.first == k) {
						ret = it++;
						return (std::make_pair(ret, it));
					}
				}
				it++;
				ret = it;
			}
			return (std::make_pair(ret, it));
		};
	};
}

#endif //FT_CONTAINERS_MAP_HPP
