#include "PmergeMe.hpp"

bool NumberElement::operator==(const NumberElement &rhs) const
{
	return value == rhs.value;
}

bool NumberElement::operator<(const NumberElement &rhs) const
{
	return value < rhs.value;
}

PmergeMe::PmergeMe() 
{

}

PmergeMe::~PmergeMe() 
{

}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		_vec = rhs._vec;
		_lst = rhs._lst;
	}
	return *this;
}

std::vector<NumberElement> const &PmergeMe::getVector() const 
{ 
    return _vec; 
}
std::list<NumberElement> const &PmergeMe::getList() const 
{
     return _lst; 
}

void PmergeMe::add_to_vector(NumberElement v)
{
	if (std::find(_vec.begin(), _vec.end(), v) != _vec.end())
		throw std::invalid_argument("duplicate");
	_vec.push_back(v);
}

void PmergeMe::add_to_list(NumberElement v)
{
	if (std::find(_lst.begin(), _lst.end(), v) != _lst.end())
		throw std::invalid_argument("duplicate");
	_lst.push_back(v);
}

std::vector<NumberElement> PmergeMe::ford_johnson_vector(std::vector<NumberElement> v)
{
	std::vector<NumberElement> mainChain;
	std::vector<NumberElement> pendingChain;
	std::vector<std::pair<NumberElement, NumberElement> > pairs;
	create_pairs(v, mainChain, pendingChain, pairs);
	if (mainChain.size() > 1)
		mainChain = ford_johnson_vector(mainChain);
	update_index(mainChain, pendingChain, pairs);
	insert_pending(mainChain, pendingChain);
	return mainChain;
}

std::list<NumberElement> PmergeMe::ford_johnson_list(std::list<NumberElement> l)
{
	std::list<NumberElement> mainChain;
	std::list<NumberElement> pendingChain;
	std::list<std::pair<NumberElement, NumberElement> > pairs;
	create_pairs(l, mainChain, pendingChain, pairs);
	if (mainChain.size() > 1)
		mainChain = ford_johnson_list(mainChain);
	update_index(mainChain, pendingChain, pairs);
	insert_pending(mainChain, pendingChain);

	return mainChain;
}

void PmergeMe::run()
{
	std::cout << "Input: ";
	print_container(_vec);

	if (_vec.size() == 1)
	{
		std::cout << "Output: ";
		print_container(_vec);
		return;
	}
	std::clock_t t1 = std::clock();
	_vec = ford_johnson_vector(_vec);
	t1 = std::clock() - t1;
	std::clock_t t2 = std::clock();
	_lst = ford_johnson_list(_lst);
	t2 = std::clock() - t2;
	std::cout << "Output vector: ";
	print_container(_vec);
	std::cout << "Output list: ";
	print_container(_lst);
	std::cout << "vector time: " << 1000.0 * t1 / CLOCKS_PER_SEC << "ms\n";
	std::cout << "list time: " << 1000.0 * t2 / CLOCKS_PER_SEC << "ms\n";
}