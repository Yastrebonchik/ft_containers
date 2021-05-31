/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:29:27 by                   #+#    #+#             */
/*   Updated: 2021/05/31 23:00:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_LIST_H
# define FT_CONTAINERS_LIST_H

# include <memory>
# include <cmath>

namespace ft {
	template<class T, class Alloc = std::allocator<T> >
	class list {
	private:
		class node {
		public:
			T		*value;
			node	*next;
			node	*prev;
			Alloc	*falloc;
			node(Alloc *alloc) : value(nullptr), next(nullptr), prev(nullptr), falloc(alloc){
			};
			node(Alloc *alloc, const T& val) : next(nullptr), prev(nullptr), falloc(alloc){
				this->value = falloc->allocate(1);
				falloc->construct(this->value, val);
			};
			node(Alloc *alloc, node &src) : next(nullptr), prev(nullptr), falloc(alloc){
				this->value = falloc->allocate(1);
				falloc->construct(this->value, *(src->value));
			};
		};
		Alloc	_alloc;
		node	*_Mnode;
		size_t	_len;
	public:
		list() : _len(0){
			this->_Mnode = new node(&(this->_alloc));
		};
		~list(){
		};
		void 	pushback(const T& val){
			node*	newNode = new node(&(this->_alloc), val);

			newNode->next = _Mnode;
			newNode->prev = _Mnode->prev;
			_Mnode->prev = newNode;
			if (_Mnode->next == nullptr)
				_Mnode->next = newNode;
			this->_len++;
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
			return ((size_t)pow(2, 64)/sizeof(T) - 1);
		};
		/* Element access */

		T&		front(){
			return (*(_Mnode->next->value));
		};
		T&		back(){
			return (*(_Mnode->prev->value));
		};
		/* Observers */

		std::allocator<T>	get_allocator(){
			return (this->_alloc);
		};
	};
}
#endif //FT_CONTAINERS_LIST_H
