//
// Created by Alexander on 22.06.2021.
//

#include "map_tests.hpp"

static void 	check(std::string title, bool value) {

	std::string	margin(38 - title.length(), ' ');
	if (value)
		std::cout << title << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << title << ": " << margin << FAIL << std::endl;
}

static void 	constructor_tests() {
	std::map<char,int>	first;
	ft::map<char, int>	myfirst;
	std::string 		name;

	std::cout << GREEN << "-----------Constructors tests------------" << RESET << std::endl;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	myfirst['a']=10;
	myfirst['b']=30;
	myfirst['c']=50;
	myfirst['d']=70;

	name = "Default constructor test";
	check(name, myfirst == first);

	std::map<char,int>	second (first.begin(),first.end());
	ft::map<char, int>	mysecond(first.begin(), first.end());

	name = "Range constructor test";
	check(name, mysecond == second);

	std::map<char,int>	third (second);
	ft::map<char, int>	mythird(mysecond);

	//mythird.insert(std::pair<char, int>('y', 13434));
	name = "Range constructor test";
	check(name, mythird == third);
}

static void 	copy_operator_tests() {
	std::map<char,int>	first;
	ft::map<char, int>	myfirst;
	std::string 		name;

	std::cout << GREEN << "-----------Copy operator test------------" << RESET << std::endl;
	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	myfirst['a']=10;
	myfirst['b']=30;
	myfirst['c']=50;
	myfirst['d']=70;

	std::map<char, int>			cpy = first;
	ft::map<char, int>			mycpy = myfirst;

	name = "Copy operator test";
	check(name, mycpy == cpy);
}

static void 	iterators_tests() {
	std::map<int, std::string, ft::more<int> >	m1;
	ft::map<int, std::string, ft::more<int> >	mym1;
	std::string					name = "Begin iterator test";
	std::pair<int, std::string>	nums[] = {std::pair<int, std::string>(1, "One"),
	        std::pair<int, std::string>(2, "Two"), std::pair<int, std::string>(3, "Three"),
	        std::pair<int, std::string>(4, "Four"), std::pair<int, std::string>(5, "Five")};

	m1.insert(nums, nums + 5);
	mym1.insert(nums, nums + 5);
	std::cout << GREEN << "-------------Iterators tests-------------" << RESET << std::endl;
	check(name, mym1.begin()->first == m1.begin()->first && mym1.begin()->second == m1.begin()->second);

	name = "End iterator test";
	check(name, (--mym1.end())->first == (--m1.end())->first && (--mym1.end())->second == (--m1.end())->second);

	name = "Rbegin iterator test";
	check(name, mym1.rbegin()->first == m1.rbegin()->first && mym1.rbegin()->second == m1.rbegin()->second);

	name = "Rend iterator test";
	check(name, (--mym1.rend())->first == (--m1.rend())->first && (--mym1.rend())->second == (--m1.rend())->second);

	const	std::map<int, std::string, ft::more<int> >	cpm1(m1);
	const	ft::map<int, std::string, ft::more<int> >	mycpm1(mym1);

	name = "Const Begin iterator test";
	check(name, mycpm1.begin()->first == cpm1.begin()->first && mycpm1.begin()->second == cpm1.begin()->second);

	name = "Const End iterator test";
	check(name, (--mycpm1.end())->first == (--cpm1.end())->first && (--mycpm1.end())->second == (--cpm1.end())->second);

	name = "Const Rbegin iterator test";
	check(name, mycpm1.rbegin()->first == cpm1.rbegin()->first && mycpm1.rbegin()->second == cpm1.rbegin()->second);

	name = "Const Rend iterator test";
	check(name, (--mycpm1.rend())->first == (--cpm1.rend())->first && (--mycpm1.rend())->second == (--cpm1.rend())->second);

	std::cout << CYAN << "Testing for iterators output with comparator object = ft::more" <<  RESET << std::endl;


	std::cout << "M1 forward output:" << std::endl;

	for (std::map<int, std::string, ft::more<int>>::iterator it = m1.begin(); it != m1.end(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "myM1 forward output:" << std::endl;

	for (ft::map<int, std::string, ft::more<int>>::iterator it = mym1.begin(); it != mym1.end(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "M1 reverse output:" << std::endl;

	for (std::map<int, std::string, ft::more<int>>::reverse_iterator it = m1.rbegin(); it != m1.rend(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "myM1 reverse output:" << std::endl;

	for (ft::map<int, std::string, ft::more<int>>::reverse_iterator it = mym1.rbegin(); it != mym1.rend(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "M2 const forward output:" << std::endl;

	for (std::map<int, std::string, ft::more<int>>::const_iterator it = cpm1.begin(); it != cpm1.end(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "myM2 const forward output:" << std::endl;

	for (ft::map<int, std::string, ft::more<int>>::const_iterator it = mycpm1.begin(); it != mycpm1.end(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "M2 const reverse output:" << std::endl;

	for (std::map<int, std::string, ft::more<int>>::const_reverse_iterator it = cpm1.rbegin(); it != cpm1.rend(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "myM2 const reverse output:" << std::endl;

	for (ft::map<int, std::string, ft::more<int>>::const_reverse_iterator it = mycpm1.rbegin(); it != mycpm1.rend(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;
}

//static void 	capacity_tests() {
//	std::vector<int>			l1;
//	ft::vector<int>				myl1;
//	std::string					name = "Size test";
//
//	l1.push_back(1);
//	l1.push_back(2);
//	l1.push_back(3);
//	l1.push_back(4);
//	l1.push_back(5);
//	l1.push_back(6);
//	l1.push_back(7);
//	l1.push_back(8);
//	l1.push_back(9);
//	l1.push_back(10);
//	myl1.push_back(1);
//	myl1.push_back(2);
//	myl1.push_back(3);
//	myl1.push_back(4);
//	myl1.push_back(5);
//	myl1.push_back(6);
//	myl1.push_back(7);
//	myl1.push_back(8);
//	myl1.push_back(9);
//	myl1.push_back(10);
//
//	std::cout << GREEN << "-------------Capacity tests--------------" << RESET << std::endl;
//
//	check(name, myl1.size() == l1.size());
//
//	name = "Max size test";
//	check(name, myl1.max_size() == l1.max_size());
//
//	name = "Capacity test";
//	check(name, myl1.capacity() == l1.capacity());
//}
//
//static void 	element_access_tests() {
//	std::list<std::string>	l1;
//	ft::list<std::string>	myl1;
//	std::string				name;
//
//	l1.push_back("1");
//	l1.push_back("2");
//	l1.push_back("3");
//	l1.push_back("4");
//	l1.push_back("5");
//	l1.push_back("6");
//	l1.push_back("7");
//	l1.push_back("8");
//	l1.push_back("9");
//	l1.push_back("10");
//	myl1.push_back("1");
//	myl1.push_back("2");
//	myl1.push_back("3");
//	myl1.push_back("4");
//	myl1.push_back("5");
//	myl1.push_back("6");
//	myl1.push_back("7");
//	myl1.push_back("8");
//	myl1.push_back("9");
//	myl1.push_back("10");
//
//	const std::list<std::string>	l2(l1);
//	const ft::list<std::string>		myl2(myl1);
//
//	std::cout << GREEN << "----------Element access tests-----------" << RESET << std::endl;
//
//	name = "Front test";
//	check(name, myl1.front() == l1.front());
//
//	name = "Const front test";
//	check(name, myl2.front() == l2.front());
//
//	name = "Back test";
//	check(name, myl1.back() == l1.back());
//
//	name = "Const back test";
//	check(name, myl2.back() == l2.back());
//}
//
//static void 	modifiers_test() {
//	std::list<std::string>		l1;
//	ft::list<std::string>		myl1;
//	std::vector<std::string>	v(15, "Bondrewd");
//	std::string					name = "Pushback test";
//
//	std::cout << GREEN << "------------Modifiers tests--------------" << RESET << std::endl;
//
//	l1.push_back("1");
//	myl1.push_back("1");
//
//	check(name, myl1 == l1);
//
//	l1.push_back("2");
//	myl1.push_back("2");
//	l1.push_back("3");
//	myl1.push_back("3");
//
//	l1.pop_back();
//	myl1.pop_back();
//	name = "Pop back test";
//	check(name, myl1 == l1);
//
//	l1.push_front("1");
//	myl1.push_front("1");
//	name = "Pushfront test";
//	check(name, myl1 == l1);
//
//	l1.pop_front();
//	myl1.pop_front();
//	name = "Pop front test";
//	check(name, myl1 == l1);
//
//	name = "Assign range test";
//	l1.assign(l1.begin(), l1.end());
//	myl1.assign(l1.begin(), l1.end());
//	check(name, myl1 == l1);
//
//	name = "Assign fill test";
//	l1.assign(10, "Reg");
//	myl1.assign(10, "Reg");
//	check(name, myl1 == l1);
//
//	std::list<std::string>::iterator	it1 = l1.begin();
//	ft::list<std::string>::iterator		myit1 = myl1.begin();
//
//	it1++;
//	it1++;
//	it1++;
//	myit1++;
//	myit1++;
//	myit1++;
//
//	name = "Insert 1 element test";
//	l1.insert(it1, "Rico");
//	myl1.insert(myit1, "Rico");
//	check(name, myl1 == l1);
//
//	name = "Insert fill test";
//	l1.insert(it1, 5, "Rico");
//	myl1.insert(myit1, 5, "Rico");
//	check(name, myl1 == l1);
//
//	name = "Insert range test";
//	l1.insert(it1, v.begin(), v.end());
//	myl1.insert(myit1, v.begin(), v.end());
//	check(name, myl1 == l1);
//
//	it1 = l1.begin();
//	myit1 = myl1.begin();
//	it1++;
//	it1++;
//	it1++;
//	myit1++;
//	myit1++;
//	myit1++;
//
//	name = "Erase 1 element test";
//	it1 = l1.erase(it1);
//	myit1 = myl1.erase(myit1);
//	check(name, myl1 == l1 && *it1 == *myit1);
//
//
//	name = "Erase range of elements test";
//	std::list<std::string>::iterator	erit1 = l1.erase(it1, l1.end());
//	ft::list<std::string>::iterator		myerit1 = myl1.erase(myit1, myl1.end());
//
//	check(name, myl1 == l1 && *--erit1 == *--myerit1);
//
//	name = "Resize test with n < capacity";
//	l1.resize(8);
//	myl1.resize(8);
//	check(name, myl1 == l1);
//
//	name = "Resize test with n == capacity";
//	l1.resize(8);
//	myl1.resize(8);
//	check(name, myl1 == l1);
//
//	name = "Resize test with n > capacity";
//	l1.resize(19);
//	myl1.resize(19);
//	check(name, myl1 == l1);
//
//	std::list<std::string>	v2;
//	ft::list<std::string>	myv2;
//
//	v2.swap(l1);
//	myv2.swap(myl1);
//	name = "Swap test";
//	check(name, myl1 == l1 && myv2 == v2);
//
//	name = "Clear test";
//	l1.clear();
//	myl1.clear();
//	check(name, myl1 == l1);
//}
//
//static void 	relational_operators_test() {
//	std::list<int>	foo(3,100);   // three ints with a value of 100
//	std::list<int>	bar(2,200);   // two ints with a value of 200
//	std::list<int>	foo2(3,100);
//	std::list<int>	bar2(2,200);
//	ft::list<int>	myfoo((size_t)3,100);
//	ft::list<int>	myfoo2((size_t)3,100);
//	ft::list<int>	mybar((size_t)2,200);
//	ft::list<int>	mybar2((size_t)2,200);
//	std::string					name;
//
//	std::cout << GREEN << "-------Relational operators tests--------" << RESET << std::endl;
//
//	name = "== test test";
//	check(name, (foo == foo2) && (myfoo == myfoo2));
//
//	name = "!= test test";
//	check(name, (foo != bar) && (myfoo != mybar));
//
//	name = "< test test";
//	check(name, (foo < bar) && (myfoo < mybar));
//
//	name = "<= test test";
//	check(name, (foo <= bar) && (myfoo <= mybar));
//
//	name = "> test test";
//	check(name, !((foo > bar) && (myfoo > mybar)));
//
//	name = ">= test test";
//	check(name, !((foo >= bar) && (myfoo >= mybar)));
//}
//
//void 	operation_tests() {
//	std::list<int> 				l1(12, -423), l2(4, 4124);
//	std::list<int>::iterator 	it1;
//	ft::list<int> 				myl1((size_t)12, -423), myl2((size_t)4, 4124);
//	ft::list<int>::iterator 	myit1;
//	std::string 				name;
//
//	std::cout << GREEN << "-------Operations operators tests--------" << RESET << std::endl;
//
//	name = "Splice entire list test";
//	it1 = l1.begin();
//	l1.splice (it1, l2);
//	myit1 = myl1.begin();
//	myl1.splice (myit1, myl2);
//	check(name, myl1 == l1);
//
//	name = "Splice single element test";
//	it1 = l2.begin();
//	l2.splice (it1, l1, l1.begin());
//	myit1 = myl2.begin();
//	myl2.splice (myit1, myl1, myl1.begin());
//	check(name, myl2 == l2);
//
//	name = "Splice element range test";
//	it1 = l2.begin();
//	l2.splice (it1, l1, l1.begin(), l1.end());
//	myit1 = myl2.begin();
//	myl2.splice (myit1, myl1, myl1.begin(), myl1.end());
//	check(name, myl2 == l2);
//
//	name = "Remove element test";
//	l2.remove(4124);
//	myl2.remove(4124);
//	check(name, myl2 == l2);
//
//	name = "Sort test";
//	l1.push_back(10);
//	l1.push_back(9);
//	l1.push_back(8);
//	l1.push_back(7);
//	l1.push_back(6);
//	l1.push_back(5);
//	l1.push_back(4);
//	l1.push_back(3);
//	l1.push_back(2);
//	l1.push_back(1);
//	myl1.push_back(10);
//	myl1.push_back(9);
//	myl1.push_back(8);
//	myl1.push_back(7);
//	myl1.push_back(6);
//	myl1.push_back(5);
//	myl1.push_back(4);
//	myl1.push_back(3);
//	myl1.push_back(2);
//	myl1.push_back(1);
//	l1.sort();
//	myl1.sort();
//	check(name, myl1 == l1);
//
//	name = "Sort with comp test";
//	std::list<std::string>				list;
//	std::list<std::string>::iterator	it;
//	ft::list<std::string>				mylist;
//	ft::list<std::string>::iterator		myit;
//
//	list.push_back ("one");
//	list.push_back ("two");
//	list.push_back ("Three");
//	mylist.push_back ("one");
//	mylist.push_back ("two");
//	mylist.push_back ("Three");
//
//	list.sort(compare_nocase);
//	mylist.sort(compare_nocase);
//	check(name, mylist == list);
//
//	name = "Removeif test";
//	l1.remove_if(single_digit);
//	myl1.remove_if(single_digit);
//	check(name, myl1 == l1);
//
//
//	double				mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14, 12.77, 73.35, 72.25, 15.3,  72.25 };
//	std::list<double>	dlist(mydoubles,mydoubles+10);
//	ft::list<double>	mydlist(mydoubles, mydoubles+10);
//
//	name = "Unique with test";
//	dlist.sort();
//	dlist.unique();
//	mydlist.sort();
//	mydlist.unique();
//	check(name, mydlist == dlist);
//
//	name = "Unique with pred test";
//	dlist.unique(same_integral_part);
//	dlist.unique(is_near());
//	mydlist.unique(same_integral_part);
//	mydlist.unique(is_near());
//	check(name, mydlist == dlist);
//
//	name = "Reverse test";
//	dlist.reverse();
//	mydlist.reverse();
//	check(name, mydlist == dlist);
//
//	std::list<double> 	first, second;
//	ft::list<double>	myfirst, mysecond;
//
//	first.push_back (3.1);
//	first.push_back (2.2);
//	first.push_back (2.9);
//	myfirst.push_back (3.1);
//	myfirst.push_back (2.2);
//	myfirst.push_back (2.9);
//
//	second.push_back (3.7);
//	second.push_back (7.1);
//	second.push_back (1.4);
//	mysecond.push_back (3.7);
//	mysecond.push_back (7.1);
//	mysecond.push_back (1.4);
//
//	first.sort();
//	second.sort();
//	myfirst.sort();
//	mysecond.sort();
//
//	first.merge(second);
//	myfirst.merge(mysecond);
//	name = "Merge test";
//
//	//first.push_back(2.1);
//	check(name, myfirst == first);
//
//	second.push_back (2.1);
//	mysecond.push_back(2.1);
//
//	name = "Merge with comp test";
//	first.merge(second, mycomparison);
//	myfirst.merge(mysecond, mycomparison);
//	check(name, myfirst == first);
//}

void	map_tests() {
	std::cout << BLUE << std::endl;
	std::cout << "**************************************************************" << std::endl;
	std::cout << "------------------------- Map tests --------------------------" << std::endl;
	std::cout << "**************************************************************" << std::endl;
	std::cout << RESET;

	constructor_tests();
	copy_operator_tests();
	iterators_tests();
//	capacity_tests();
//	element_access_tests();
//	modifiers_test();
//	operation_tests();
//	relational_operators_test();
}