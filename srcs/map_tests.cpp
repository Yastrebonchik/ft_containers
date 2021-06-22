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

	for (std::map<int, std::string, ft::more<int> >::iterator it = m1.begin(); it != m1.end(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "myM1 forward output:" << std::endl;

	for (ft::map<int, std::string, ft::more<int> >::iterator it = mym1.begin(); it != mym1.end(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "M1 reverse output:" << std::endl;

	for (std::map<int, std::string, ft::more<int> >::reverse_iterator it = m1.rbegin(); it != m1.rend(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "myM1 reverse output:" << std::endl;

	for (ft::map<int, std::string, ft::more<int> >::reverse_iterator it = mym1.rbegin(); it != mym1.rend(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "M2 const forward output:" << std::endl;

	for (std::map<int, std::string, ft::more<int> >::const_iterator it = cpm1.begin(); it != cpm1.end(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "myM2 const forward output:" << std::endl;

	for (ft::map<int, std::string, ft::more<int> >::const_iterator it = mycpm1.begin(); it != mycpm1.end(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "M2 const reverse output:" << std::endl;

	for (std::map<int, std::string, ft::more<int> >::const_reverse_iterator it = cpm1.rbegin(); it != cpm1.rend(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "myM2 const reverse output:" << std::endl;

	for (ft::map<int, std::string, ft::more<int> >::const_reverse_iterator it = mycpm1.rbegin(); it != mycpm1.rend(); ++it) {
		std::cout << "Key = " << it->first << ", and value = " << it->second << std::endl;
	}
	std::cout << std::endl;
}

static void 	capacity_tests() {
	std::map<char,int>	first;
	ft::map<char, int>	myfirst;
	std::string 		name;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	myfirst['a']=10;
	myfirst['b']=30;
	myfirst['c']=50;
	myfirst['d']=70;

	std::cout << GREEN << "-------------Capacity tests--------------" << RESET << std::endl;

	name = "Size test";
	check(name, myfirst.size() == first.size());

	name = "Max size test";
	check(name, myfirst.max_size() == first.max_size());

}

static void 	element_access_tests() {
	std::map<char,int>	first;
	ft::map<char, int>	myfirst;
	std::string 		name;

	std::cout << GREEN << "----------Element access tests-----------" << RESET << std::endl;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	myfirst['a']=10;
	myfirst['b']=30;
	myfirst['c']=50;
	myfirst['d']=70;

	const std::map<char,int>		second(first);
	const ft::map<char, int>		mysecond(myfirst);

	name = "Operator [] adding element test";
	check(name, myfirst == first);


	first['a']=20;
	first['b']=40;
	first['c']=60;
	first['d']=80;
	myfirst['a']=20;
	myfirst['b']=40;
	myfirst['c']=60;
	myfirst['d']=80;

	name = "Operator [] access element test";
	check(name, myfirst == first);
}

static void 	modifiers_test() {
	std::map<char,int>	m1;
	ft::map<char, int>	mym1;
	std::string			name;

	std::cout << GREEN << "------------Modifiers tests--------------" << RESET << std::endl;

	std::pair<std::map<char,int>::iterator,bool>	ret;
	std::pair<ft::map<char,int>::iterator,bool>		myret;

	ret = m1.insert ( std::pair<char,int>('a',100) );
	ret = m1.insert ( std::pair<char,int>('z',200) );
	myret = mym1.insert(std::pair<char,int>('a',100));
	myret = mym1.insert(std::pair<char,int>('z',200));

	name = "Insert with pair returned == true test";
	check(name, mym1 == m1 && ret.second == true && myret.second == true);


	ret = m1.insert ( std::pair<char,int>('z',500) );
	myret = mym1.insert(std::pair<char,int>('z',500));

	name = "Insert with pair ret == false test";
	check(name, mym1 == m1 && ret.second == false && myret.second == false);

	std::map<char,int>::iterator	it = m1.begin();
	ft::map<char,int>::iterator		myit = mym1.begin();

	m1.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	m1.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
	mym1.insert(myit, std::pair<char,int>('b',300));
	mym1.insert(myit, std::pair<char,int>('c',400));

	name = "Insert with iterator position test";
	check(name, mym1 == m1);

	std::map<char,int>	anothermap;
	ft::map<char, int>	myanothermap;
	anothermap.insert(m1.begin(),m1.find('c'));
	myanothermap.insert(m1.begin(), m1.find('c'));

	name = "Insert range test";
	check(name, myanothermap == anothermap);

	it = m1.find('b');
	m1.erase(it);
	myit = mym1.find('b');
	mym1.erase(myit);

	name = "Erase iterator test";
	check(name, mym1 == m1);

	name = "Erase with key test";
	check(name, mym1.erase('a') == m1.erase('a') && mym1 == m1);

	m1['w'] = 50;
	m1['x'] = 100;
	m1['y'] = 150;
	m1['z'] = 200;
	mym1['w'] = 50;
	mym1['x'] = 100;
	mym1['y'] = 150;
	mym1['z'] = 200;

	name = "Erase range test";
	m1.erase(m1.find('w'), m1.find('y'));
	mym1.erase(mym1.find('w'), mym1.find('y'));
	check(name, mym1 == m1);

	name = "Swap test";
	m1.swap(anothermap);
	mym1.swap(myanothermap);
	check(name, mym1 == m1 && myanothermap == anothermap);

	name = "Clear test";
	m1.clear();
	mym1.clear();
	check(name, mym1 == m1);
}

static void	observers_tests() {
	std::map<char,int>				m1;
	std::map<char,int>::key_compare comp = m1.key_comp();
	std::map<char, int>::iterator 	it;
	ft::map<char, int>				mym1;
	ft::map<char, int>::key_compare mycomp = mym1.key_comp();
	ft::map<char, int>::iterator	myit;
	std::string 					name;

	std::cout << GREEN << "------------Observers tests--------------" << RESET << std::endl;
	m1['a']=100;
	m1['b']=200;
	m1['c']=300;
	m1['d']=400;
	m1['e']=500;
	m1['f']=600;
	mym1['a']=100;
	mym1['b']=200;
	mym1['c']=300;
	mym1['d']=400;
	mym1['e']=500;
	mym1['f']=600;

	it = m1.begin();
	myit = mym1.begin();

	while (comp(it->first, 'd'))
		it++;
	while (mycomp(myit->first, 'd'))
		myit++;

	name = "Key comparison object test";
	check(name, myit->first == it->first && myit->second == it->second);

	name = "Value comparison object test";

	std::pair<char,int>	highest = *m1.rbegin();
	std::pair<char,int>	myhighest = *mym1.rbegin();

	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( m1.value_comp()(*it++, highest) );
	std::cout << "---------------------------------" << std::endl;
	do {
		std::cout << myit->first << " => " << myit->second << '\n';
	} while ( mym1.value_comp()(*myit++, myhighest) );

	name = "Value comparison object test";
	check(name, (--myit)->first == (--it)->first && (--myit)->second == (--it)->second);
}

static void	operation_tests() {
	std::map<char,int>				m1;
	std::map<char,int>::iterator	it;
	ft::map<char,int>				mym1;
	ft::map<char,int>::iterator		myit;
	std::string 					name;

	std::cout << GREEN << "------------Operations tests--------------" << RESET << std::endl;

	m1['a']=50;
	m1['b']=100;
	m1['c']=150;
	m1['d']=200;
	m1['e']=250;
	m1['f']=300;
	m1['h']=350;
	m1['i']=400;
	mym1['a']=50;
	mym1['b']=100;
	mym1['c']=150;
	mym1['d']=200;
	mym1['e']=250;
	mym1['f']=300;
	mym1['h']=350;
	mym1['i']=400;

	it = m1.find('b');
	myit = mym1.find('b');

	const std::map<char,int>			cm1(m1);
	std::map<char,int>::const_iterator	cit;
	const ft::map<char,int>				mycm1(mym1);
	ft::map<char,int>::const_iterator	mycit;

	name = "Find test";
	check(name, myit->first == it->first && myit->second == it->second);

	cit = cm1.find('c');
	mycit = mycm1.find('c');

	name = "Const find test";
	check(name, mycit->first == cit->first && mycit->second == cit->second);

	name = "Count test";
	check(name, mym1.count('d') == m1.count('d'));

	std::map<char,int>::iterator	itlow,itup;
	ft::map<char, int>::iterator	myitlow, myitup;

	itlow = m1.lower_bound ('g');
	itup = m1.upper_bound('g');
	myitlow = mym1.lower_bound('g');
	myitup = mym1.upper_bound('g');

	name = "Lower bound test";
	check(name, myitlow->first == itlow->first && myitlow->second == itlow->second);

	name = "Upper bound test";
	check(name, myitup->first == itup->first && myitup->second == itup->second);

	std::map<char,int>::const_iterator	citlow,citup;
	ft::map<char, int>::const_iterator	mycitlow, mycitup;

	citlow = cm1.lower_bound ('g');
	citup = cm1.upper_bound('g');
	mycitlow = mycm1.lower_bound('g');
	mycitup = mycm1.upper_bound('g');

	name = "Const Lower bound test";
	check(name, mycitlow->first == citlow->first && mycitlow->second == citlow->second);

	name = "Const Upper bound test";
	check(name, mycitup->first == citup->first && mycitup->second == citup->second);

	std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator>	pair(m1.equal_range('b'));
	std::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator>	mypair(mym1.equal_range('b'));

	std::map<char, int>			eqrangem(pair.first, pair.second);
	ft::map<char, int>			myeqrangem(mypair.first, mypair.second);

	name = "Equal range test";
	check(name, myeqrangem == eqrangem);

	std::pair<std::map<char, int>::const_iterator, std::map<char, int>::const_iterator>	cpair(cm1.equal_range('b'));
	std::pair<ft::map<char, int>::const_iterator, ft::map<char, int>::const_iterator>	mycpair(mycm1.equal_range('b'));

	const std::map<char, int>	ceqrangem(cpair.first, cpair.second);
	const ft::map<char, int>	myceqrangem(mycpair.first, mycpair.second);

	name = "Const Equal range test";
	check(name, myceqrangem.begin()->first == ceqrangem.begin()->first && myceqrangem.begin()->second == ceqrangem.begin()->second);
};

void	map_tests() {
	std::cout << BLUE << std::endl;
	std::cout << "**************************************************************" << std::endl;
	std::cout << "------------------------- Map tests --------------------------" << std::endl;
	std::cout << "**************************************************************" << std::endl;
	std::cout << RESET;

	constructor_tests();
	copy_operator_tests();
	iterators_tests();
	capacity_tests();
	element_access_tests();
	modifiers_test();
	observers_tests();
	operation_tests();
}