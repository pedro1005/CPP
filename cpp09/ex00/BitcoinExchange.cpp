#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

// Default constructor
BitcoinExchange::BitcoinExchange() {}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _rates(other._rates) {}

// Copy assignment operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _rates = other._rates;
    return *this;
}

// Custom constructor: loads BTC price database
BitcoinExchange::BitcoinExchange(const std::string& dbFilename) {
    std::ifstream dbFile(dbFilename.c_str());
    if (!dbFile)
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    std::getline(dbFile, line); // Skip header

    while (std::getline(dbFile, line)) {
        std::istringstream ss(line);
        std::string date, rateStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
            continue;

        // Trim whitespace
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        rateStr.erase(0, rateStr.find_first_not_of(" \t"));
        rateStr.erase(rateStr.find_last_not_of(" \t") + 1);

        if (!isValidDate(date))
            continue;

        std::stringstream rateSS(rateStr);
        float rate;
        rateSS >> rate;
        if (rateSS.fail())
            continue;

        _rates[date] = rate;
    }
}

// Get BTC rate for a given date or closest earlier
float BitcoinExchange::getRateForDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);

    if (it != _rates.end() && it->first == date)
        return it->second;

    if (it == _rates.begin())
        throw std::runtime_error("Error: date is before earliest rate.");

    --it;
    return it->second; //first:key, second:value
}

// Validate date format: YYYY-MM-DD with basic checks
bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int y, m, d;
    char dash1, dash2;
    std::istringstream ss(date);
    ss >> y >> dash1 >> m >> dash2 >> d;

    if (ss.fail() || dash1 != '-' || dash2 != '-')
        return false;
    if (y < 2000 || y > 2100 || m < 1 || m > 12 || d < 1 || d > 31)
        return false;

    // Days in months check
    static const int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (m == 2) {
        bool isLeap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
        if (d > (isLeap ? 29 : 28))
            return false;
    } else if (d > daysInMonth[m - 1]) {
        return false;
    }

    return true;
}

// New: Process input file line by line
void BitcoinExchange::processInputFile(const std::string& inputFilename) {
    std::ifstream inputFile(inputFilename.c_str());
    if (!inputFile)
        throw std::runtime_error("Error: could not open input file.");

    std::string line;
    std::getline(inputFile, line); //skip header
    while (std::getline(inputFile, line)) {
        processLine(line);
    }
}

// Private helper function to process one input line
void BitcoinExchange::processLine(const std::string& line) {
    if (line.empty()) {
        return;
    }

    // Split line into date and value by '|'
    size_t pipePos = line.find('|');
    if (pipePos == std::string::npos) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string date = line.substr(0, pipePos);
    std::string valueStr = line.substr(pipePos + 1);

    // Trim whitespace from date and value
    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t") + 1);
    valueStr.erase(0, valueStr.find_first_not_of(" \t"));
    valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

    if (!isValidDate(date)) {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }

    // Parse valueStr to float using stringstream (C++98 safe)
    float value = 0.0f;
    std::stringstream ss(valueStr);
    ss >> value;
    if (ss.fail() || !ss.eof()) {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return;
    }

    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }

    if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return;
    }

    try {
        float rate = getRateForDate(date);
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: bad input => " << date << std::endl;
    }
}
