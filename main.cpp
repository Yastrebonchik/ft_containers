/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kcedra>                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:15:32 by kcedra            #+#    #+#             */
/*   Updated: 2021/06/03 11:26:35 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_headers.hpp"

bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};

bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

void test_vector(void);
void test_list(void);

int main() {
	/*


	test_list();
	ft::list<int>						test;
	std::list<int>  					a1;
	std::list<int>::iterator 			test1;
	std::list<int>::iterator 			end1;
	std::list<int>::const_iterator 		con1;
	std::list<int>::reverse_iterator	test2;

	a1.insert(a1.begin(), 10, 7);
	//std::list<int>::iterator 			cpyass = a1.begin();
	//cpyass += 5;
	for (std::list<int>::const_iterator it = a1.begin(); it != a1.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "My list tests ----------------------------------------" << std::endl;
	std::cout << "Container is empty? : " << test.empty() << std::endl;
	test.push_back(3);
	test.push_back(4);
	std::cout << test.back() << std::endl;
	test.push_back(2);
	std::cout << test.back() << std::endl;
	std::cout << "Changing back to 5" << std::endl;
	test.back() = 5;
	std::cout << test.back() << std::endl;
	std::cout << test.front() << std::endl;
	test.push_front(15);
	std::cout << test.front() << std::endl;
	std::cout << "Print container len: " << test.size() << std::endl;
	std::cout << "Container is empty? : " << test.empty() << std::endl;
	std::cout << "Popping front" << std::endl;
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
	iters = test.erase(iters, test.end());
	test.insert(++iters, a1.begin(),a1.end());
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
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
	iters = test.begin();
	//iters = test.erase(iters);
	iters = test.insert(iters, 1254);
	iters = test.insert(iters, 327);
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Fill with insert tests -------------------------" << std::endl;
	test.insert(test.begin(), (size_t)10, -15);
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Fill with insert tests end ---------------------" << std::endl;


	std::cout << "Assign tests -------------------------" << std::endl;
	test.assign(a1.begin(), a1.end());
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Assign tests end ---------------------" << std::endl;


	std::cout << "Copy constructor tests ---------------" << std::endl;
	const ft::list<int>	copytest(test);
	//con1 = a1.begin();
	//ft::list<int>::iterator ittest = test.begin();
	//ft::list<int>::iterator	assiter;
	//std::list<int>::const_iterator consttestit = a1.cbegin();
	for (std::list<int>::const_iterator it = a1.begin(); it != a1.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	for (ft::list<int>::const_iterator itc = copytest.begin(); itc != copytest.end(); ++itc)
		std::cout << "Value = " << *itc << std::endl;
	std::cout << "Copy constructor tests end -----------" << std::endl;


	std::cout << "String list tests --------------------" << std::endl;
	std::cout << "Fill with val constructor" << std::endl;
	ft::list<std::string>	strlist;
	strlist.push_back("one");
	strlist.push_back("two");
	strlist.push_back("Three");
	strlist.sort();

	std::cout << "mylist contains:";
	for (ft::list<std::string>::iterator it=strlist.begin(); it!=strlist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	strlist.sort(compare_nocase);

	std::cout << "mylist contains:";
	for (ft::list<std::string>::iterator it=strlist.begin(); it!=strlist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
//	ft::list<std::string>	strlist(10, "aboba");
	int 								i = 0;
	for (ft::list<std::string>::reverse_iterator it = strlist.rbegin(); it != strlist.rend(); ++it){
		if (i++ % 2 == 0)
			*it = "KekV";
		std::cout << "Value = " << *it << std::endl;
	}
	std::cout << "After compare-nocase" << std::endl;
	strlist.sort(compare_nocase);
	for (ft::list<std::string>::reverse_iterator it = strlist.rbegin(); it != strlist.rend(); ++it){
		std::cout << "Value = " << *it << std::endl;
	}
	std::cout << "String list tests end ----------------" << std::endl;


	std::cout << "Resize tests -------------------------" << std::endl;
	std::cout << "Print container len: " << test.size() << std::endl;
	test.resize(12, -14343124);
	std::cout << "Resizing to value 12" << std::endl;
	std::cout << "Print container len: " << test.size() << std::endl;
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	test.resize(3);
	std::cout << "Resizing to value 3" << std::endl;
	std::cout << "Print container len: " << test.size() << std::endl;
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Resize tests end ---------------------" << std::endl;


	std::cout << "Remove tests -------------------------" << std::endl;
	test.push_back(12);
	test.push_back(7);
	test.push_back(41234213);
	test.push_back(7);
	test.push_back(31312);
	test.push_front(1);
	std::cout << "Print container len: " << test.size() << std::endl;
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	test.remove(7);
	std::cout << "Removing value 7" << std::endl;
	std::cout << "Print container len: " << test.size() << std::endl;
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Remove tests end ---------------------" << std::endl;


	std::cout << "Remove if tests ----------------------" << std::endl;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);
	test.push_back(6);
	std::cout << "Print container len: " << test.size() << std::endl;
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	test.remove_if(single_digit);
	test.remove_if(is_odd());
	std::cout << "Removing 1 digit numbers and odd numbers" << std::endl;
	std::cout << "Print container len: " << test.size() << std::endl;
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Remove if tests end ------------------" << std::endl;


	std::cout << "Sort tests ---------------------------" << std::endl;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_front(4);
	test.push_front(5);
	test.push_front(6);
	test.push_back(3);
	test.push_back(3);
	test.push_back(3);
	std::cout << "Print container len: " << test.size() << std::endl;
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "After sort" << std::endl;
	test.sort();
	std::cout << "Print container len: " << test.size() << std::endl;
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;

	std::cout << "Test unique function " << std::endl;
	test.unique();
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Sort tests end -----------------------" << std::endl;


	std::cout << "Unique tests -------------------------" << std::endl;
	double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
						 12.77, 73.35, 72.25, 15.3,  72.25 };
	ft::list<double> mylist (mydoubles,mydoubles+10);

	mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
	// 15.3,  72.25, 72.25, 73.0,  73.35

	mylist.unique();           //  2.72,  3.14, 12.15, 12.77
	// 15.3,  72.25, 73.0,  73.35

	mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
	// 15.3,  72.25, 73.0

	mylist.unique (is_near());           //  2.72, 12.15, 72.25

	std::cout << "mylist contains:";
	for (ft::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "Unique tests end ---------------------" << std::endl;


	std::cout << "Swap tests ---------------------------" << std::endl;
	ft::list<int>	swaptest((size_t)5, 214213442);
	std::cout << "Print swaptest len: " << swaptest.size() << std::endl;
	for (ft::list<int>::iterator it = swaptest.begin(); it != swaptest.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Print test len: " << test.size() << std::endl;
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Swap here " << std::endl;
	swaptest.swap(test);
	std::cout << "Print swaptest len: " << swaptest.size() << std::endl;
	for (ft::list<int>::iterator it = swaptest.begin(); it != swaptest.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Print test len: " << test.size() << std::endl;
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Swap tests end -----------------------" << std::endl;


	std::cout << "Splice tests -------------------------" << std::endl;
	ft::list<int>::iterator itspl = test.begin();
	std::cout << "Print swaptest len: " << swaptest.size() << std::endl;
	std::cout << "Print test len: " << test.size() << std::endl;
	itspl++;
	itspl++;
	swaptest.splice(swaptest.end(), test, itspl, test.end());
	std::cout << "Print swaptest len: " << swaptest.size() << std::endl;
	std::cout << "Print test len: " << test.size() << std::endl;
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	test.push_front(-312312);
	swaptest.splice(swaptest.begin(), test, test.begin());
	std::cout << "Print swaptest len: " << swaptest.size() << std::endl;
	std::cout << "Print test len: " << test.size() << std::endl;
	for (ft::list<int>::iterator it = swaptest.begin(); it != swaptest.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Splice tests end ---------------------" << std::endl;


	std::cout << "Reverse tests ------------------------" << std::endl;
	for (ft::list<int>::iterator it = swaptest.begin(); it != swaptest.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Reverse" << std::endl;
	swaptest.reverse();
	for (ft::list<int>::iterator it = swaptest.begin(); it != swaptest.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Reverse tests end --------------------" << std::endl;

	std::cout << "Merge tests --------------------------" << std::endl;

	ft::list<double> firstmy, secondmy;

	firstmy.push_back (3.1);
	firstmy.push_back (2.2);
	firstmy.push_back (2.9);

	secondmy.push_back (3.7);
	secondmy.push_back (7.1);
	secondmy.push_back (1.4);

	firstmy.sort();
	secondmy.sort();

	firstmy.merge(secondmy);
	std::cout << "first contains:";
	for (ft::list<double>::iterator it = firstmy.begin(); it != firstmy.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	secondmy.push_back (2.1);

	firstmy.merge(secondmy, mycomparison);

	std::cout << "first contains:";
	for (ft::list<double>::iterator it = firstmy.begin(); it != firstmy.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "Merge tests end ----------------------" << std::endl;
	std::cout << "My list tests end ------------------------------------" << std::endl;
	a1.push_back(2);
	a1.push_back(3);
	std::list<double> first, second;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);

	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);

	first.sort();
	second.sort();

	first.merge(second);

	second.push_back (2.1);

	first.merge(second, mycomparison);

	std::cout << "first contains:";
	for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	a1.clear();
	if (a1 == a1)
		test1 = a1.begin();
//	test2 = a1.rbegin() +3;
//	test1 = a1.erase(test1);
//	test1 = a1.insert(test1, 421);
//	test1 = a1.insert(test1, 3);
//	for (std::list<int>::iterator it = a1.begin(); it != a1.end(); ++it)
//		std::cout << "Value = " << *it << std::endl;
//	std::cout << a1.size() << std::endl;
//	std::cout << *test1 << std::endl;
//	end1 = --a1.begin();
//	test2 = a1.rend();
//	if (test1 == end1)
//		std::cout << "I'm here" << std::endl;
//	std::cout << "This is first end: " << *test1 << "; and this is second one: " << *test2 << std::endl;
//	std::cout << "My max_size() : " << test.max_size() << "; and list std max_size() : " << a1.max_size() << std::endl;
//	std::cout << test.max_size() - a1.max_size() << std::endl;
//	std::cout << (int)sqrt(test.max_size()) << std::endl;
//	std::cout << (int)sqrt(a1.max_size()) << std::endl;
//	std::cout << "List allocator max size = " << a1.get_allocator().max_size() << " and a1 max size = " << a1.max_size() << std::endl;
//	std::cout << a1.get_allocator().max_size() - a1.max_size() << std::endl;
//	std::cout << a1.get_allocator().max_size() / 2;




	std::vector<int>	v1;
	std::vector<int>::iterator	tv1;
	ft::vector<int>		myv1;

	myv1.push_back(15);
	myv1.push_back(20);
	std::cout << v1.capacity() << std::endl;
	v1.insert(v1.begin(), 10, 22);
	std::cout << v1.capacity() << std::endl;
	myv1.insert(myv1.begin(), size_t(10), 22);
//	myv1.push_back(30);
//	myv1.push_back(15);
//	myv1.push_back(20);
//	myv1.push_back(30);

	std::cout << "Capacity : " << myv1.capacity() << std::endl;
	std::cout << "Size : " << myv1.size() << std::endl;
	for (ft::vector<int>::iterator it = myv1.begin(); it != myv1.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << myv1.size() << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	myv1.assign((size_t)10, 143214);
	for (ft::vector<int>::iterator it = myv1.begin(); it != myv1.end(); ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << myv1.size() << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	myv1.insert(myv1.end(), myv1.begin(), myv1.end());
	for (ft::vector<int>::iterator it = myv1.begin(); it != myv1.end(); ++it)
		std::cout << "Value = " << *it << std::endl;

	std::cout << myv1.size() << std::endl;

	myv1.insert(myv1.end(), (size_t)10, 21);
	myv1.erase(myv1.end() - 1);

	for (ft::vector<int>::iterator it = myv1.begin(); it != myv1.end(); ++it)
		std::cout << "Value = " << *it << std::endl;

	std::cout << myv1.size() << std::endl;
//	std::list<int>  					a1;
//	std::list<int>::iterator 			test1;



//	std::list<int>	l1;
//	std::vector<int>::iterator 	it;
//
//	it.operator[]();

	//test_list();
	//test_vector();

	std::cout << "---------------------------------------------" << std::endl;

	ft::vector<int>		v1((size_t)10, 134);

	v1.push_back(4124123);
	v1.insert(v1.begin(), 656757);
	v1.insert(v1.begin(), (size_t)4, -14324);
	ft::vector<int>::reverse_iterator it = v1.rbegin();
	ft::vector<int>::reverse_iterator ite = v1.rend();
	for (it = v1.rbegin(); it != ite; ++it)
		std::cout << "Value = " << *it << std::endl;
	std::cout << "Capacity : " << v1.capacity() << std::endl;

	*/

	//test_vector();
	vector_tests();
	queue_tests();
	return 0;
}