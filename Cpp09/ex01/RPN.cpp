#include "RPN.hpp"

#include <sstream>
#include <stdexcept>
#include <cctype>
#include <stack>

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

RPN::~RPN()
{
}

int RPN::evaluate(const std::string &expression)
{
	std::istringstream inputStream(expression);
	std::string token;
	std::stack<int> numberStack;

	while (inputStream >> token)
	{
		if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
		{
			numberStack.push(token[0] - '0');
			continue;
		}

		if (token.size() == 1 &&
			(token == "+" || token == "-" || token == "*" || token == "/"))
		{
			if (numberStack.size() < 2)
				throw std::runtime_error("Error");

			int right = numberStack.top(); numberStack.pop();
			int left = numberStack.top(); numberStack.pop();

			int result;

			if (token == "+")
				result = left + right;
			else if (token == "-")
				result = left - right;
			else if (token == "*")
				result = left * right;
			else
			{
				if (right == 0)
					throw std::runtime_error("Error");
				result = left / right;
			}
			numberStack.push(result);
			continue;
		}
		throw std::runtime_error("Error");
	}
	if (numberStack.size() != 1)
		throw std::runtime_error("Error");
	return numberStack.top();
}