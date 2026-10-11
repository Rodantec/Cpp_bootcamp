#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>


BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}
static std::string trim(const std::string& input)
{
    size_t start = 0;
    while (start < input.size() && std::isspace(input[start]))
        ++start;
    size_t end = input.size();
    while (end > start && std::isspace(input[end - 1]))
        --end;
    return input.substr(start, end - start);
}

static bool isValidDate(const std::string& date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }
    return true;
}

bool BitcoinExchange::loadDatabase(const char* databasePath)
{
    std::ifstream inputFile(databasePath);
    if (!inputFile.is_open())
        return false;
    std::string line;
    while (std::getline(inputFile, line))
    {
        if (line.empty())
            continue;
        size_t commaPosition = line.find(',');
        if (commaPosition == std::string::npos)
            continue;
        std::string datePart = trim(line.substr(0, commaPosition));
        std::string ratePart = trim(line.substr(commaPosition + 1));
        if (!isValidDate(datePart))
            continue;
        std::stringstream rateStream(ratePart);
        double exchangeRate;
        if (!(rateStream >> exchangeRate))
            continue;
        _db[datePart] = exchangeRate;
    }
    return !_db.empty();
}

void BitcoinExchange::processInput(const char* inputFilePath) const
{
    std::ifstream inputFile(inputFilePath);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    bool isFirstLine = true;
    while (std::getline(inputFile, line))
    {
        if (line.empty())
            continue;
        if (isFirstLine)
        {
            isFirstLine = false;
            if (line.find("date") != std::string::npos)
                continue;
        }
        size_t separatorPosition = line.find('|');
        if (separatorPosition == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string datePart = trim(line.substr(0, separatorPosition));
        std::string valuePart = trim(line.substr(separatorPosition + 1));
        if (!isValidDate(datePart))
        {
            std::cerr << "Error: bad input => " << datePart << std::endl;
            continue;
        }
        std::stringstream valueStream(valuePart);
        double bitcoinAmount;
        if (!(valueStream >> bitcoinAmount) || bitcoinAmount < 0 || bitcoinAmount > 1000)
        {
            std::cerr << "Error: not a valid value." << std::endl;
            continue;
        }
        std::map<std::string, double>::const_iterator databaseIt = _db.upper_bound(datePart);
        if (databaseIt == _db.begin())
        {
            std::cerr << "Error: no data available for " << datePart << std::endl;
            continue;
        }
        --databaseIt;
        double exchangeRate = databaseIt->second;
        double result = bitcoinAmount * exchangeRate;
        std::cout << datePart << " => " << bitcoinAmount << " = " << result << std::endl;
    }
}