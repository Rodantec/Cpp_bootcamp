#include "PmergeMe.hpp"

int conv_to_int(const std::string &s)
{
	std::stringstream ss(s);
	int v;
	ss >> v;
	if (ss.fail() || !ss.eof() || v < 0)
		throw std::invalid_argument("bad input");
	return v;
}

bool comp(const NumberElement &a, const NumberElement &b)
{
	return a < b;
}

int jacob(int n)
{
	return (std::pow(2, n + 1) + std::pow(-1, n)) / 3;
}

int main(int ac, char **av)
{
	try
	{
		if (ac < 2)
		{
			std::cerr << "Usage: ./PmergeMe <positive_int> [positive_int ...]" << std::endl;
			return 1;
		}
		PmergeMe p;
		NumberElement x;
		for (int i = 1; i < ac; ++i)
		{
			x.value = conv_to_int(av[i]);
			p.add_to_vector(x);
			p.add_to_list(x);
		}
		p.run();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}