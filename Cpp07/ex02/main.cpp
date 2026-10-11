#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); i++)
	{
			a[i] = i + 1;
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
	}
	Array<int> b(a);
	b[0] = 42;
	std::cout << "a[0] = " << a[0] << std::endl;
	std::cout << "b[0] = " << b[0] << std::endl;
	Array<int> c;
	std::cout << "empty size = " << c.size() << std::endl;
	c = a;
	c[1] = 99;
	std::cout << "a[1] = " << a[1] << std::endl;
	std::cout << "c[1] = " << c[1] << std::endl;
	try
	{
		std::cout << a[42] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Array<std::string> str(3);
	str[0] = "Salut";
	str[1] = "les";
	str[2] = "gens";
	for (unsigned int i = 0; i < str.size(); i++)
		std::cout << str[i] << " ";
	std::cout << std::endl;
	return (0);
}