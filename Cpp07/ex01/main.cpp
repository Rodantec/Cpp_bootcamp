#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printValue(T const &value)
{
	std::cout << value << std::endl;
}

void addOne(int &value)
{
	++value;
}

void addBang(std::string &value)
{
	value += "!";
}

int main()
{
	int numbers[] = {1, 2, 3, 4};
	std::string words[] = {"one", "two", "three"};
	double const constNumbers[] = {10, 20, 30};

	std::cout << "numbers before addOne:" << std::endl;
	iter(numbers, 4, printValue<int>);
	iter(numbers, 4, addOne);
	iter(numbers, 4, printValue<int>);

	iter(words, 3, printValue<std::string>);
	iter(words, 3, addBang);
	iter(words, 3, printValue<std::string>);

	iter(constNumbers, 3, printValue<double>);

	return 0;
}
