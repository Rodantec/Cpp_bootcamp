#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>
#include <cmath>
#include <ctime>
#include <iomanip>

struct NumberElement
{
	int value;
	int index;
	bool operator==(const NumberElement &rhs) const;
	bool operator<(const NumberElement &rhs) const;
};

int conv_to_int(const std::string &input);
bool comp(const NumberElement &a, const NumberElement &b);
int jacob(int n);

template <typename T, typename P>
void create_pairs(T &input, T &mainChain, T &pendingChain, P &pairs)
{
	typename T::iterator it;
	typename T::iterator next;
	for (it = input.begin(); it != input.end(); std::advance(it, 2))
	{
		next = it;
		++next;

		if (next == input.end())
		{
			it->index = -1;
			pendingChain.push_back(*it);
			break;
		}
		if (comp(*it, *next) == false)
		{
			mainChain.push_back(*it);
			pendingChain.push_back(*next);
			pairs.push_back(std::make_pair(*it, *next));
		}
		else
		{
			pendingChain.push_back(*it);
			mainChain.push_back(*next);
			pairs.push_back(std::make_pair(*next, *it));
		}
	}
}

template <typename T, typename P>
void update_index(T &mainChain, T &pendingChain, P &pairs)
{
	int idx = 0;

	typename T::iterator it;
	typename T::iterator itP;
	typename P::iterator itPair;
	for (it = mainChain.begin(); it != mainChain.end(); ++it, ++idx)
	{
		it->index = idx;
		for (itPair = pairs.begin();itPair != pairs.end() && itPair->first.value != it->value;++itPair)
			;
		for (itP = pendingChain.begin(); itP != pendingChain.end(); ++itP)
		{
			if (itPair->second.value == itP->value)
				itP->index = idx;
		}
	}
}

template <typename T>
typename T::iterator find_by_index(T &container, int index)
{
	typename T::iterator it = container.begin();
	for (; it != container.end() && it->index != index; ++it)
		;
	return it;
}

template <typename T>
T get_jacob_group(T &pending, int jacob_n, int start)
{
	T group;
	int size = jacob(jacob_n + 1) - jacob(jacob_n);
	while (pending.size() && size--)
	{
		typename T::iterator it = find_by_index(pending, start);
		if (it == pending.end())
			it = find_by_index(pending, -1);
		group.push_back(*it);
		pending.erase(it);
		++start;
	}
	return group;
}

template <typename T>
void insert_pending(T &mainChain, T &pendingChain)
{
	typename T::iterator it = find_by_index(pendingChain, 0);
	mainChain.insert(mainChain.begin(), *it);
	pendingChain.erase(it);
	int start = 1;
	int jacob_n = 0;
	while (pendingChain.size())
	{
		T group = get_jacob_group(pendingChain, ++jacob_n, start);
		for (typename T::reverse_iterator rit = group.rbegin();rit != group.rend();++rit)
		{
			typename T::iterator pos;
			if (rit->index == -1)
				pos = std::upper_bound(mainChain.begin(), mainChain.end(), *rit, comp);
			else
				pos = std::upper_bound(mainChain.begin(),find_by_index(mainChain, rit->index), *rit, comp);
			mainChain.insert(pos, *rit);
			++start;
		}
	}
}

template <typename T>
void print_container(T &c)
{
	for (typename T::iterator it = c.begin(); it != c.end(); ++it)
	{
		std::cout << it->value << " ";
		typename T::iterator next = it;
		++next;
	}
	std::cout << std::endl;
}

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &rhs);
	PmergeMe &operator=(const PmergeMe &rhs);
	std::vector<NumberElement> const &getVector() const;
	std::list<NumberElement> const &getList() const;
	void add_to_vector(NumberElement v);
	void add_to_list(NumberElement v);
	std::vector<NumberElement> ford_johnson_vector(std::vector<NumberElement> v);
	std::list<NumberElement> ford_johnson_list(std::list<NumberElement> l);
	void run();
private:
	std::vector<NumberElement> _vec;
	std::list<NumberElement> _lst;
};

#endif