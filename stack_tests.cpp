//
// Created by Karyn Cedra on 6/20/21.
//

#include "stack_tests.hpp"

static void	check(std::string title, bool value) {

	std::string	margin(38 - title.length(), ' ');
	if (value)
		std::cout << title << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << title << ": " << margin << FAIL << std::endl;
}


static void	constructor_tests() {
	std::stack<std::string>	v1;
	ft::stack<std::string>	myv1;
	std::string				name = "Default constructor test";

	std::cout << GREEN << "-----------Constructor tests------------" << RESET << std::endl;

	check(name, myv1.empty() == v1.empty());
}

static void	member_functions_tests() {
	std::stack<std::string>	q1;
	ft::stack<std::string>	myq1;
	std::string 	name;

	std::cout << GREEN << "-------Member functions tests--------" << RESET << std::endl;

	name = "Empty test";
	check(name, q1.empty() == myq1.empty());

	name = "Push test";
	q1.push("Bondrewd");
	myq1.push("Bondrewd");
	check(name, myq1.top() == q1.top());

	name = "Size test";
	check(name, myq1.size() == q1.size());

	q1.push("Rico");
	myq1.push("Rico");

	name = "Top test";
	check(name, myq1.top() == q1.top());

	name = "Pop test";
	q1.pop();
	myq1.pop();
	check(name, myq1.top() == q1.top());
}

static void relational_operators_test() {
	std::stack<int>	foo;   // three ints with a value of 100
	std::stack<int>	bar;   // two ints with a value of 200
	std::stack<int>	foo2;
	std::stack<int>	bar2;
	ft::stack<int>	myfoo;
	ft::stack<int>	myfoo2;
	ft::stack<int>	mybar;
	ft::stack<int>	mybar2;
	std::string		name;

	std::cout << GREEN << "-------Relational operators tests--------" << RESET << std::endl;

	foo.push(100);
	foo.push(100);
	foo.push(100);

	bar.push(200);
	bar.push(200);

	foo2.push(100);
	foo2.push(100);
	foo2.push(100);

	bar2.push(200);
	bar2.push(200);

	myfoo.push(100);
	myfoo.push(100);
	myfoo.push(100);

	mybar.push(200);
	mybar.push(200);

	myfoo2.push(100);
	myfoo2.push(100);
	myfoo2.push(100);

	mybar2.push(200);
	mybar2.push(200);

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

void 	stack_tests() {
	std::cout << BLUE << std::endl;
	std::cout << "**************************************************************" << std::endl;
	std::cout << "------------------------ Stack tests -------------------------" << std::endl;
	std::cout << "**************************************************************" << std::endl;
	std::cout << RESET;

	constructor_tests();
	member_functions_tests();
	relational_operators_test();
}