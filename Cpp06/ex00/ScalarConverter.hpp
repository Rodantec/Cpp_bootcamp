#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cerrno>

 enum LiteralType
    {
        TYPE_INVALID,
        TYPE_CHAR,
        TYPE_INT,
        TYPE_FLOAT,
        TYPE_DOUBLE,
        TYPE_PSEUDO_FLOAT,
        TYPE_PSEUDO_DOUBLE
    };
class ScalarConverter
{
    private :
    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &copy);

    public :
        static void convert(const std::string &literal);
};

#endif