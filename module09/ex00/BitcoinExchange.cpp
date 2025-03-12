#include "BitcoinExchange.hpp"

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string& date)
{
    std::regex dateRegex(R"(^(\d{4})-(\d{2})-(\d{2})$)");
    std::smatch match;

    if (!std::regex_match(date, match, dateRegex))
        return false;  // incorrect format

    int year = std::stoi(match[1].str());
    int month = std::stoi(match[2].str());
    int day = std::stoi(match[3].str());

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

std::string trim(const std::string &str)
{
    size_t first = str.find_first_not_of(" \n\r\t");
    size_t last = str.find_last_not_of(" \n\r\t");
    return (first == std::string::npos || last == std::string::npos) ? "" : str.substr(first, last - first + 1);
}


bool isValidValue(const std::string &valueStr, double &value)
{
    try
    {
        value = std::stod(valueStr);
        return value >= 0 && value <= 1000;
    }
    catch (const std::exception &)
    {
        return false;
    }
}
// Constructor: Initializes the BTC price database
BitcoinExchange::BitcoinExchange(const std::string &database)
{
    loadDatabase(database);
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

// Copy assignment operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _data = other._data;
    }
    return *this;
}

void BitcoinExchange::loadDatabase(const std::string &database)
{
    std::ifstream file(database);
    if (!file)
    {
        std::cout << "Error: Could not open BTC database file: " << database << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, priceStr;
        if (std::getline(ss, date, ',') && std::getline(ss, priceStr))
        {
            try
            {
                _data[date] = std::stod(priceStr);
            }
            catch (const std::exception &)
            {
                std::cout << "Skipping invalid entry in BTC database: " << line << std::endl;
            }
        }
    }
}

// Function to process user input file and compute BTC values
void BitcoinExchange::processInputFile(const std::string &inputFile) const
{
    std::ifstream file(inputFile);
    if (!file)
    {
        std::cout << "Error: Could not open input file: " << inputFile << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, valueStr;

        // read "date | value" format
        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
        {
            //std::cout << "Invalid format: " << line << std::endl;
            continue; // skip invalid format to avoid long output
        }

        // trim spaces from both date and value
        date = trim(date);
        valueStr = trim(valueStr);

        if (date.empty() || valueStr.empty())
            continue; // skip empty / malformed lines

        if (!isValidDate(date))
            continue; // skip irrelevant lines

        double value;
        if (!isValidValue(valueStr, value))
        {
            std::cout << "Invalid value: " << valueStr << " (must be between 0 and 1000)" << std::endl;
            continue;
        }

        // find closest lower date in BTC database
        auto it = _data.lower_bound(date);

        if (it == _data.end() || it->first > date)
        {
            if (it == _data.begin())
            {
                std::cout << "No valid BTC price available before date: " << date << std::endl;
                continue;
            }
            --it;  // move to closest lower date
        }

        std::string closestDate = it->first;
        double btcPrice = it->second;
        double btcEquivalent = value * btcPrice;

        std::cout << date << " => " << value << " BTC = " << btcEquivalent
                  << std::endl;
    }
}
