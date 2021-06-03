/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kcedra>                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:15:32 by kcedra            #+#    #+#             */
/*   Updated: 2021/06/03 03:25:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <string>
#include "list.hpp"

int main() {
	int 								i = 0;
	ft::list<int>						test;
	std::list<int>  					a1;
	std::list<int>::iterator 			test1;
	std::list<int>::iterator 			end1;
	std::list<int>::reverse_iterator	test2;

	a1.insert(a1.begin(), 10, 7);
	//std::cout << "My list Allocator max size = : " << test.get_allocator().max_size() << std::endl;
	//std::cout << "Normal list Allocator max size = : " << a1.get_allocator().max_size() << std::endl;
	std::cout << "My list tests ----------------------------------------" << std::endl;
	std::cout << "Container is empty? : " << test.empty() << std::endl;
	test.push_back(3);
	test.push_back(4);
	//std::cout << test.back() << std::endl;
	test.push_back(2);
	//std::cout << test.back() << std::endl;
	//std::cout << "Changing back to 5" << std::endl;
	//test.back() = 5;
	//std::cout << test.back() << std::endl;
	//std::cout << test.front() << std::endl;
	test.push_front(15);
	//std::cout << test.front() << std::endl;
	std::cout << "Print container len: " << test.size() << std::endl;
	//std::cout << "Container is empty? : " << test.empty() << std::endl;
	//std::cout << "Popping front" << std::endl;
	test.pop_front();
	test.pop_front();
	std::cout << test.front() << std::endl;
	std::cout << "Print container len: " << test.size() << std::endl;
	std::cout << "Popping back" << std::endl;
	test.pop_back();
	std::cout << test.back() << std::endl;
	test.push_back(10);
	test.push_back(15);
	test.push_back(20);
	test.push_back(25);
	test.push_back(30);
	//ft::list<int>::iterator	it;
	//ft::list<int>::iterator	ite;
	std::cout << "Before testing iterators" << std::endl;
	std::cout << "Print container len: " << test.size() << std::endl;
	std::cout << "Forward iterators test --------------" << std::endl;
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Forward iterators test end ----------" << std::endl;
	std::cout << "Reverse iterators test --------------" << std::endl;
	for (ft::list<int>::reverse_iterator it = test.rbegin(); it != test.rend(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Reverse iterators test end ----------" << std::endl;
	std::cout << "Print container len: " << test.size() << std::endl;
	std::cout << "After testing iterators" << std::endl;
	std::cout << "Print container len: " << test.size() << std::endl;
	std::cout << "Erase tests --------------------------" << std::endl;
	ft::list<int>::iterator iters = test.begin();
	++iters;
	iters++;
	//test.erase(ites, test.end());
	//test.insert(++iters, a1.begin(),a1.end());
	//test.erase(++iters, test.end());
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	//test.erase(ites);
	std::cout << "Erase tests end ----------------------" << std::endl;
	std::cout << "Clear tests --------------------------" << std::endl;
	test.push_back(30);
	test.push_back(35);
	test.push_back(40);
	test.push_back(45);
	std::cout << "Print container len: " << test.size() << std::endl;
	std::cout << "Clear happens here" << std::endl;
	test.clear();
	std::cout << "Print container len: " << test.size() << std::endl;
	std::cout << "Clear tests end ----------------------" << std::endl;
	std::cout << "String list tests --------------------" << std::endl;
	std::cout << "Fill with val constructor" << std::endl;
	ft::list<std::string>	strlist(10, "Aboba");
	for (ft::list<std::string>::reverse_iterator it = strlist.rbegin(); it != strlist.rend(); ++it){
		if (i++ % 2 == 0)
			*it = "KekV";
		std::cout << "Value = " << *it << std::endl;
	}
	std::cout << "String list tests end ----------------" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
//	a1.push_back(2);
//	a1.push_back(3);
//	test1 = a1.begin();
//	std::cout << a1.size() << std::endl;
//	std::cout << *test1 << std::endl;
//	end1 = --a1.begin();
//	test2 = a1.rend();
//	if (test1 == end1)
//		std::cout << "I'm here" << std::endl;
//	std::cout << "This is first end: " << *test1 << "; and this is second one: " << *test2 << std::endl;
	std::cout << "My max_size() : " << test.max_size() << "; and list std max_size() : " << a1.max_size() << std::endl;
//	std::cout << test.max_size() - a1.max_size() << std::endl;
//	std::cout << (int)sqrt(test.max_size()) << std::endl;
//	std::cout << (int)sqrt(a1.max_size()) << std::endl;
	//std::cout << "List allocator max size = " << a1.get_allocator().max_size() << " and a1 max size = " << a1.max_size() << std::endl;
	//std::cout << a1.get_allocator().max_size() - a1.max_size() << std::endl;
	//std::cout << a1.get_allocator().max_size() / 2;
	return 0;
}