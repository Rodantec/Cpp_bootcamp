#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{

}
ScalarConverter::ScalarConverter(const ScalarConverter&) 
{

}

ScalarConverter::~ScalarConverter() 
{

}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
    return *this;
}

static void impossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

static void printChar(double n)
{
    std::cout << "char: ";

    if (std::isnan(n) || std::isinf(n) || n < std::numeric_limits<char>::min() || n > std::numeric_limits<char>::max())
    {
        std::cout << "impossible" << std::endl;
        return;
    }

    char c = static_cast<char>(n);
    if (std::isprint(static_cast<unsigned char>(c)))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

static void printInt(double n)
{
    std::cout << "int: ";

    if (std::isnan(n) || std::isinf(n)
        || n < std::numeric_limits<int>::min()
        || n > std::numeric_limits<int>::max())
    {
        std::cout << "impossible" << std::endl;
        return;
    }

    std::cout << static_cast<int>(n) << std::endl;
}

static void printFloat(double n)
{
    std::cout << "float: ";

    if (std::isnan(n))
        std::cout << "nanf";
    else if (std::isinf(n))
        std::cout << (n < 0 ? "-inff" : "+inff");
    else if (n < -std::numeric_limits<float>::max() || n >  std::numeric_limits<float>::max())
        std::cout << "impossible";
    else
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f";

    std::cout << std::endl;
}

static void printDouble(double n)
{
    std::cout << "double: ";

    if (std::isnan(n))
        std::cout << "nan";
    else if (std::isinf(n))
        std::cout << (n < 0 ? "-inf" : "+inf");
    else
        std::cout << std::fixed << std::setprecision(1) << n;

    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
    double n;
   
    if (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
    {
        n = static_cast<double>(str[0]);
    }
    else if (str == "nan" || str == "nanf")
    {
        n = std::numeric_limits<double>::quiet_NaN();
    }
    else if (str == "+inf" || str == "+inff")
    {
        n = std::numeric_limits<double>::infinity();
    }
    else if (str == "-inf" || str == "-inff")
    {
        n = -std::numeric_limits<double>::infinity();
    }
    else
    {
        char *end;
        n = std::strtod(str.c_str(), &end);

        if (errno == ERANGE)
        {
            impossible();
            return;
        }
        std::string suffix(end);
        bool noSuffix = suffix.empty();
        bool floatSuffix = (suffix == "f");

        if (!noSuffix && !floatSuffix)
        {
            impossible();
            return;
        }

        if (floatSuffix && str.find('.') == std::string::npos)
        {
            impossible();
            return;
        }
    }
    printChar(n);
    printInt(n);
    printFloat(n);
    printDouble(n);
}