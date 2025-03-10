#include "BitcoinExchange.hpp"

DatesAndPrices::DatesAndPrices(std::string database) : _content(database)
{
    std::cout << _content << std::endl;
}

