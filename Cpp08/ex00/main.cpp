#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	try
	{
		std::cout << "Vector: " << *easyfind(vec, 20) << std::endl;
		std::cout << "List: " << *easyfind(lst, 2) << std::endl;
		std::cout << "Deque: " << *easyfind(deq, 300) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		easyfind(vec, 42);
	}
	catch (const std::exception &e)
	{
		std::cout << "Vector: " << e.what() << std::endl;
	}

	return 0;
}