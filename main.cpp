/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kcedra>                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:15:32 by kcedra            #+#    #+#             */
/*   Updated: 2021/05/31 23:16:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <string>
#include "list.hpp"

int main() {
	ft::list<int>	test;
	std::list<int>  a1;
	std::list<int>::iterator 			test1;
	std::list<int>::iterator 			end1;
	std::list<int>::reverse_iterator	test2;

	//std::cout << "My list Allocator max size = : " << test.get_allocator().max_size() << std::endl;
	//std::cout << "Normal list Allocator max size = : " << a1.get_allocator().max_size() << std::endl;
	std::cout << "My list tests ----------------------------------------" << std::endl;
	std::cout << "Container is empty? : " << test.empty() << std::endl;
	test.pushback(3);
	test.pushback(4);
	std::cout << test.back() << std::endl;
	test.pushback(2);
	std::cout << test.back() << std::endl;
	std::cout << "Changing back to 5" << std::endl;
	test.back() = 5;
	std::cout << test.back() << std::endl;
	std::cout << test.front() << std::endl;
	std::cout << "Print container len: " << test.size() << std::endl;
	std::cout << "Container is empty? : " << test.empty() << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
	a1.push_back(2);
	a1.push_back(3);
	test1 = a1.end();
	end1 = --a1.begin();
	test2 = a1.rend();
	if (test1 == end1)
		std::cout << "I'm here" << std::endl;
	std::cout << "This is first end: " << *test1 << "; and this is second one: " << *test2 << std::endl;
	std::cout << "My max_size() : " << test.max_size() << "; and list std max_size() : " << a1.max_size() << std::endl;
	std::cout << test.max_size() - a1.max_size() << std::endl;
	std::cout << (int)sqrt(test.max_size()) << std::endl;
	std::cout << (int)sqrt(a1.max_size()) << std::endl;
	//std::cout << "List allocator max size = " << a1.get_allocator().max_size() << " and a1 max size = " << a1.max_size() << std::endl;
	//std::cout << a1.get_allocator().max_size() - a1.max_size() << std::endl;
	//std::cout << a1.get_allocator().max_size() / 2;
	return 0;
}