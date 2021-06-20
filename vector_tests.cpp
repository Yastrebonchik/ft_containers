//
// Created by Karyn Cedra on 6/19/21.
//

#include "vector_tests.hpp"


static void 	check(std::string title, bool value) {

	std::string	margin(38 - title.length(), ' ');
	if (value)
		std::cout << title << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << title << ": " << margin << FAIL << std::endl;
}

static void 	constructor_tests() {
	std::vector<std::string>	v1;
	ft::vector<std::string>		myv1;
	std::string					name = "Default constructor test";

	std::cout << GREEN << "-----------Constructors tests------------" << RESET << std::endl;

	check(name, myv1 == v1);

	std::vector<std::string>	fillv1(15, "41324123412");
	ft::vector<std::string>		myfillv1(15, "41324123412");

	name = "Fill constructor test";
	check(name, myfillv1 == fillv1);

	std::list<int>				range_list(7, -41234231);
	std::vector<int>			rangev1(range_list.begin(), range_list.end());
	ft::vector<int>				myrangev1(range_list.begin(), range_list.end());

	name = "Range constructor test";
	//myrangev1.push_back(42);
	check(name, myrangev1 == rangev1);

	std::vector<int>		cpv1(rangev1);
	ft::vector<int>			mycpv1(myrangev1);

	name = "Copy constructor test";
	check(name, mycpv1 == cpv1);
}

static void 	copy_operator_tests() {
	std::vector<std::string>	fillv1(15, "41324123412");
	ft::vector<std::string>		myfillv1(15, "41324123412");
	std::vector<std::string>	cpyv1 = fillv1;
	ft::vector<std::string>		mycpyv1 = myfillv1;
	std::string					name = "Copy operator test";

	std::cout << GREEN << "-----------Copy operator test------------" << RESET << std::endl;
	check(name, mycpyv1 == cpyv1);
}

static void 	iterators_tests() {
	std::vector<int>			v1;
	ft::vector<int>				myv1;
	std::string					name = "Begin iterator test";

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(9);
	v1.push_back(10);
	myv1.push_back(1);
	myv1.push_back(2);
	myv1.push_back(3);
	myv1.push_back(4);
	myv1.push_back(5);
	myv1.push_back(6);
	myv1.push_back(7);
	myv1.push_back(8);
	myv1.push_back(9);
	myv1.push_back(10);

	std::cout << GREEN << "-------------Iterators tests-------------" << RESET << std::endl;
	check(name, *myv1.begin() == *v1.begin());

	name = "End iterator test";
	check(name, *--myv1.end() == *--v1.end());

	name = "Rbegin iterator test";
	check(name, *myv1.rbegin() == *v1.rbegin());

	name = "Rend iterator test";
	check(name, *(--myv1.rend()) == *(--v1.rend()));

	const	std::vector<int>	cpv1(v1);
	const	ft::vector<int>		mycpv1(myv1);

	name = "Const Begin iterator test";
	check(name, *mycpv1.begin() == *cpv1.begin());

	name = "Const End iterator test";
	check(name, *--mycpv1.end() == *--cpv1.end());

	name = "Const Rbegin iterator test";
	check(name, *mycpv1.rbegin() == *cpv1.rbegin());

	name = "Const Rend iterator test";
	check(name, *(--mycpv1.rend()) == *(--cpv1.rend()));

	std::cout << CYAN << "Iterators operators tests" << RESET << std::endl;

	std::vector<int>::iterator	it1 = v1.begin();
	ft::vector<int>::iterator	myit1 = myv1.begin();

	it1 += 6;
	myit1 += 6;
	name = "+= operator test";
	check(name, *myit1 == *it1);

	it1 -= 2;
	myit1 -= 2;
	name = "-= operator test";
	check(name, *myit1 == *it1);

	it1 = 2 + it1;
	myit1 = 2 + myit1;
	name = "+  operator test with positive n";
	check(name, *myit1 == *it1);


	it1 = it1 + (-2);
	myit1 = myit1 + (-2);
	name = "+  operator test with negative n";
	check(name, *myit1 == *it1);

	it1 = it1 - 3;
	myit1 = myit1 - 3;
	name = "-  operator test";
	check(name, *myit1 == *it1);

	size_t	v1diff = it1 - v1.begin();
	size_t	myv1diff = myit1 - myv1.begin();

	name = "-  operator of 2 iterators test";
	check(name, v1diff == myv1diff);

	name = "[] operator test";
	//std::cout << "My [] : " << myit1[1] << " and std: " << it1[1] << std::endl;
	check(name, myit1[2] == it1[2]);

	std::vector<int>::iterator	cmp = it1 - 1;
	ft::vector<int>::iterator	mycmp = myit1 - 1;

	name = ">  operator test";
	check(name, (myit1 > mycmp) == (it1 > cmp));

	name = ">=  operator test";
	check(name, (myit1 >= mycmp) == (it1 >= cmp));

	cmp++;
	mycmp++;
	name = ">=  operator test with equality";
	check(name, (myit1 >= mycmp) == (it1 >= cmp));

	name = "<=  operator test with equality";
	check(name, (myit1 <= mycmp) == (it1 <= cmp));

	cmp++;
	mycmp++;
	name = "<=  operator test";
	check(name, (myit1 <= mycmp) == (it1 <= cmp));

	name = "<  operator test";
	check(name, (myit1 < mycmp) == (it1 < cmp));

	std::cout << CYAN << "Const Iterators operators tests" << RESET << std::endl;

	const std::vector<int>				v2(v1);
	const ft::vector<int>				myv2(myv1);
	std::vector<int>::const_iterator 	it2 = v2.begin();
	ft::vector<int>::const_iterator		myit2 = myv2.begin();

	it2 += 6;
	myit2 += 6;
	name = "+= operator test";
	check(name, *myit2 == *it2);

	it2 -= 2;
	myit2 -= 2;
	name = "-= operator test";
	check(name, *myit2 == *it2);

	it2 = 2 + it2;
	myit2 = 2 + myit2;
	name = "+  operator test with positive n";
	check(name, *myit2 == *it2);


	it2 = it2 + (-2);
	myit2 = myit2 + (-2);
	name = "+  operator test with negative n";
	check(name, *myit2 == *it2);

	it2 = it2 - 3;
	myit2 = myit2 - 3;
	name = "-  operator test";
	check(name, *myit2 == *it2);

	size_t	v2diff = it2 - v2.begin();
	size_t	myv2diff = myit2 - myv2.begin();

	name = "-  operator of 2 iterators test";
	check(name, v2diff == myv2diff);

	name = "[] operator test";
	//std::cout << "My [] : " << myit2[1] << " and std: " << it2[1] << std::endl;
	check(name, myit2[2] == it2[2]);

	std::vector<int>::const_iterator 	cmp2 = it2 - 1;
	ft::vector<int>::const_iterator		mycmp2 = myit2 - 1;

	name = ">  operator test";
	check(name, (myit2 > mycmp2) == (it2 > cmp2));

	name = ">=  operator test";
	check(name, (myit2 >= mycmp2) == (it2 >= cmp2));

	cmp2++;
	mycmp2++;
	name = ">=  operator test with equality";
	check(name, (myit2 >= mycmp2) == (it2 >= cmp2));

	name = "<=  operator test with equality";
	check(name, (myit2 <= mycmp2) == (it2 <= cmp2));

	cmp2++;
	mycmp2++;
	name = "<=  operator test";
	check(name, (myit2 <= mycmp2) == (it2 <= cmp2));

	name = "<  operator test";
	check(name, (myit2 < mycmp2) == (it2 < cmp2));

	std::cout << CYAN << "Reverse Iterators operators tests" << RESET << std::endl;

	std::vector<int>::reverse_iterator	rit1 = v1.rbegin();
	ft::vector<int>::reverse_iterator	myrit1 = myv1.rbegin();

	rit1 += 6;
	myrit1 += 6;
	name = "+= operator test";
	check(name, *myrit1 == *rit1);

	rit1 -= 2;
	myrit1 -= 2;
	name = "-= operator test";
	check(name, *myrit1 == *rit1);

	rit1 = 2 + rit1;
	myrit1 = 2 + myrit1;
	name = "+  operator test with positive n";
	check(name, *myrit1 == *rit1);


	rit1 = rit1 + (-2);
	myrit1 = myrit1 + (-2);
	name = "+  operator test with negative n";
	check(name, *myrit1 == *rit1);

	rit1 = rit1 - 3;
	myrit1 = myrit1 - 3;
	name = "-  operator test";
	check(name, *myrit1 == *rit1);

	size_t	v3diff = rit1 - v1.rbegin();
	size_t	myv3diff = myrit1 - myv1.rbegin();

	name = "-  operator of 2 iterators test";
	check(name, v3diff == myv3diff);

	name = "[] operator test";
	//std::cout << "My [] : " << myrit1[1] << " and std: " << rit1[1] << std::endl;
	check(name, myrit1[2] == rit1[2]);

	std::vector<int>::reverse_iterator 	cmp3 = rit1 - 1;
	ft::vector<int>::reverse_iterator	mycmp3 = myrit1 - 1;

	name = ">  operator test";
	check(name, (myrit1 > mycmp3) == (rit1 > cmp3));

	name = ">=  operator test";
	check(name, (myrit1 >= mycmp3) == (rit1 >= cmp3));

	cmp3++;
	mycmp3++;
	name = ">=  operator test with equality";
	check(name, (myrit1 >= mycmp3) == (rit1 >= cmp3));

	name = "<=  operator test with equality";
	check(name, (myrit1 <= mycmp3) == (rit1 <= cmp3));

	cmp3++;
	mycmp3++;
	name = "<=  operator test";
	check(name, (myrit1 <= mycmp3) == (rit1 <= cmp3));

	name = "<  operator test";
	check(name, (myrit1 < mycmp3) == (rit1 < cmp3));

	std::cout << CYAN << "Const Reverse Iterators operators tests" << RESET << std::endl;

	std::vector<int>::const_reverse_iterator 	rit2 = v2.rbegin();
	ft::vector<int>::const_reverse_iterator		myrit2 = myv2.rbegin();

	rit2 += 6;
	myrit2 += 6;
	name = "+= operator test";
	check(name, *myrit2 == *rit2);

	rit2 -= 2;
	myrit2 -= 2;
	name = "-= operator test";
	check(name, *myrit2 == *rit2);

	rit2 = 2 + rit2;
	myrit2 = 2 + myrit2;
	name = "+  operator test with positive n";
	check(name, *myrit2 == *rit2);


	rit2 = rit2 + (-2);
	myrit2 = myrit2 + (-2);
	name = "+  operator test with negative n";
	check(name, *myrit2 == *rit2);

	rit2 = rit2 - 3;
	myrit2 = myrit2 - 3;
	name = "-  operator test";
	check(name, *myrit2 == *rit2);

	size_t	v4diff = rit2 - v2.rbegin();
	size_t	myv4diff = myrit2 - myv2.rbegin();

	name = "-  operator of 2 iterators test";
	check(name, v4diff == myv4diff);

	name = "[] operator test";
	//std::cout << "My [] : " << myrit2[1] << " and std: " << rit2[1] << std::endl;
	check(name, myrit2[2] == rit2[2]);

	std::vector<int>::const_reverse_iterator 	cmp4 = rit2 - 1;
	ft::vector<int>::const_reverse_iterator		mycmp4 = myrit2 - 1;

	name = ">  operator test";
	check(name, (myrit2 > mycmp4) == (rit2 > cmp4));

	name = ">=  operator test";
	check(name, (myrit2 >= mycmp4) == (rit2 >= cmp4));

	cmp4++;
	mycmp4++;
	name = ">=  operator test with equality";
	check(name, (myrit2 >= mycmp4) == (rit2 >= cmp4));

	name = "<=  operator test with equality";
	check(name, (myrit2 <= mycmp4) == (rit2 <= cmp4));

	cmp4++;
	mycmp4++;
	name = "<=  operator test";
	check(name, (myrit2 <= mycmp4) == (rit2 <= cmp4));

	name = "<  operator test";
	check(name, (myrit2 < mycmp4) == (rit2 < cmp4));

	std::cout << CYAN << "Testing for iterators output" <<  RESET << std::endl;

	std::cout << "V1 forward output:" << std::endl;

	for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::cout << "myV1 forward output:" << std::endl;

	for (ft::vector<int>::iterator it = myv1.begin(); it != myv1.end(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::cout << "V1 reverse output:" << std::endl;

	for (std::vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::cout << "myV1 reverse output:" << std::endl;

	for (ft::vector<int>::reverse_iterator it = myv1.rbegin(); it != myv1.rend(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::cout << "V2 const forward output:" << std::endl;

	for (std::vector<int>::const_iterator it = v2.begin(); it != v2.end(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::cout << "myV2 const forward output:" << std::endl;

	for (ft::vector<int>::const_iterator it = myv2.begin(); it != myv2.end(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::cout << "V2 const reverse output:" << std::endl;

	for (std::vector<int>::const_reverse_iterator it = v2.rbegin(); it != v2.rend(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::cout << "myV2 const reverse output:" << std::endl;

	for (ft::vector<int>::const_reverse_iterator it = myv2.rbegin(); it != myv2.rend(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}

static void 	capacity_tests() {
	std::vector<int>			v1;
	ft::vector<int>				myv1;
	std::string					name = "Size test";

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(9);
	v1.push_back(10);
	myv1.push_back(1);
	myv1.push_back(2);
	myv1.push_back(3);
	myv1.push_back(4);
	myv1.push_back(5);
	myv1.push_back(6);
	myv1.push_back(7);
	myv1.push_back(8);
	myv1.push_back(9);
	myv1.push_back(10);

	std::cout << GREEN << "-------------Capacity tests--------------" << RESET << std::endl;

	check(name, myv1.size() == v1.size());

	name = "Max size test";
	check(name, myv1.max_size() == v1.max_size());

	name = "Capacity test";
	check(name, myv1.capacity() == v1.capacity());

	name = "Resize test with n < capacity";
	v1.resize(8);
	myv1.resize(8);
	check(name, myv1 == v1);

	name = "Resize test with n == capacity";
	v1.resize(8);
	myv1.resize(8);
	check(name, myv1 == v1);

	name = "Resize test with n > capacity";
	v1.resize(19);
	myv1.resize(19);
	check(name, myv1 == v1);

	name = "Reserve test with n < capacity";
	v1.reserve(15);
	myv1.reserve(15);
	//std::cout << "My = " << myv1.capacity() << " and std: " << v1.capacity() << std::endl;
	check(name, myv1.capacity() == v1.capacity());

	name = "Reserve test with n == capacity";
	v1.reserve(32);
	myv1.reserve(32);
	//std::cout << "My = " << myv1.capacity() << " and std: " << v1.capacity() << std::endl;
	check(name, myv1.capacity() == v1.capacity());

	name = "Reserve test with n > capacity";
	v1.reserve(64);
	myv1.reserve(49);
	//std::cout << "My = " << myv1.capacity() << " and std: " << v1.capacity() << std::endl;
	check(name, myv1.capacity() >= v1.capacity());
}

static void 	element_access_tests() {
	std::vector<std::string>	v1;
	ft::vector<std::string>		myv1;
	std::string					name = "Vector [] operator test";

	v1.push_back("1");
	v1.push_back("2");
	v1.push_back("3");
	v1.push_back("4");
	v1.push_back("5");
	v1.push_back("6");
	v1.push_back("7");
	v1.push_back("8");
	v1.push_back("9");
	v1.push_back("10");
	myv1.push_back("1");
	myv1.push_back("2");
	myv1.push_back("3");
	myv1.push_back("4");
	myv1.push_back("5");
	myv1.push_back("6");
	myv1.push_back("7");
	myv1.push_back("8");
	myv1.push_back("9");
	myv1.push_back("10");

	const std::vector<std::string>	v2(v1);
	const ft::vector<std::string>	myv2(myv1);

	std::cout << GREEN << "----------Element access tests-----------" << RESET << std::endl;

	check(name, myv1[2] == v1[2]);

	name = "Const vector [] operator test";
	check(name, myv2[2] == v2[2]);

	name = "Vector at operator test";
	check(name, myv1.at(2) == v1.at(2));

	name = "Const vector at operator test";
	check(name, myv2.at(2) == v2.at(2));

	std::cout << CYAN << "Exceptions throwing" << RESET << std::endl;
	name = "Vector at operator test exception";
	try {
		check(name, myv1.at(142314) == v1.at(142314));
	}
	catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}

	name = "Const vector at operator test exception";
	try {
		check(name, myv2.at(142314) == v2.at(142314));
	}
	catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}

	std::cout << CYAN << "-------------------------" << RESET << std::endl;

	name = "Front test";
	check(name, myv1.front() == v1.front());

	name = "Const front test";
	check(name, myv2.front() == v2.front());

	name = "Back test";
	check(name, myv1.back() == v1.back());

	name = "Const back test";
	check(name, myv2.back() == v2.back());
}

static void 	modifiers_test() {
	std::vector<std::string>	v1;
	ft::vector<std::string>		myv1;
	std::list<std::string>		l1(15, "Bondrewd");
	std::string					name = "Pushback test";

	std::cout << GREEN << "------------Modifiers tests--------------" << RESET << std::endl;

	v1.push_back("1");
	myv1.push_back("1");

	check(name, myv1 == v1);

	v1.push_back("2");
	myv1.push_back("2");
	v1.push_back("3");
	myv1.push_back("3");

	v1.pop_back();
	myv1.pop_back();
	name = "Pop back test";
	check(name, myv1 == v1);


	name = "Assign range test";
	v1.assign(l1.begin(), l1.end());
	myv1.assign(l1.begin(), l1.end());
	check(name, myv1 == v1);

	name = "Assign fill test";
	v1.assign(10, "Reg");
	myv1.assign(10, "Reg");
	check(name, myv1 == v1);

	name = "Insert 1 element test";
	v1.insert(v1.begin() + 4, "Rico");
	myv1.insert(myv1.begin() + 4, "Rico");
	check(name, myv1 == v1);

	name = "Insert fill test";
	v1.insert(v1.begin() + 4, 5, "Rico");
	myv1.insert(myv1.begin() + 4, 5, "Rico");
	check(name, myv1 == v1);

	name = "Insert range test";
	v1.insert(v1.begin() + 4, l1.begin(), l1.end());
	myv1.insert(myv1.begin() + 4, l1.begin(), l1.end());
	check(name, myv1 == v1);

	name = "Erase 1 element test";
	v1.erase(v1.begin() + 4);
	myv1.erase(myv1.begin() + 4);
	check(name, myv1 == v1);


	name = "Erase range of elements test";
	std::vector<std::string>::iterator	erit1 = v1.erase(v1.begin() + 4, v1.begin() + 6);
	ft::vector<std::string>::iterator	myerit1 = myv1.erase(myv1.begin() + 4, myv1.begin() + 6);

	//myerit1--;
	check(name, myv1 == v1 && *erit1 == *myerit1);

	std::vector<std::string>	v2;
	ft::vector<std::string>		myv2;

	v2.swap(v1);
	myv2.swap(myv1);
	name = "Swap test";
	check(name, myv1 == v1 && myv2 == v2);

	name = "Clear test";
	v1.clear();
	myv1.clear();
	check(name, myv1 == v1);
}

static void 	relational_operators_test() {
	std::vector<int>	foo(3,100);   // three ints with a value of 100
	std::vector<int>	bar(2,200);   // two ints with a value of 200
	std::vector<int>	foo2(3,100);
	std::vector<int>	bar2(2,200);
	ft::vector<int>		myfoo((size_t)3,100);
	ft::vector<int>		myfoo2((size_t)3,100);
	ft::vector<int>		mybar((size_t)2,200);
	ft::vector<int>		mybar2((size_t)2,200);
	std::string					name;

	std::cout << GREEN << "-------Relational operators tests--------" << RESET << std::endl;

	name = "== test test";
	check(name, (foo == foo2) && (myfoo == myfoo2));

	name = "!= test test";
	check(name, (foo != bar) && (myfoo != mybar));

	name = "< test test";
	check(name, (foo < bar) && (myfoo < mybar));

	name = "<= test test";
	check(name, (foo <= bar) && (myfoo <= mybar));

	name = "> test test";
	check(name, !((foo > bar) && (myfoo > mybar)));

	name = ">= test test";
	check(name, !((foo >= bar) && (myfoo >= mybar)));
}

void 	vector_tests() {
	std::cout << BLUE << std::endl;
	std::cout << "**************************************************************" << std::endl;
	std::cout << "------------------------ Vector tests ------------------------" << std::endl;
	std::cout << "**************************************************************" << std::endl;
	std::cout << RESET;

	constructor_tests();
	copy_operator_tests();
	iterators_tests();
	capacity_tests();
	element_access_tests();
	modifiers_test();
	relational_operators_test();
}