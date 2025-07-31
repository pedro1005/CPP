#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange();                                      // Default constructor
    BitcoinExchange(const BitcoinExchange& other);          // Copy constructor
    BitcoinExchange& operator=(const BitcoinExchange& other); // Copy assignment
    ~BitcoinExchange();                                     // Destructor

    BitcoinExchange(const std::string& dbFilename);         // Custom constructor

    float getRateForDate(const std::string& date) const;
    bool isValidDate(const std::string& date) const;
    void processInputFile(const std::string& inputFilename);

private:
    std::map<std::string, float> _rates;
    void processLine(const std::string& line);
};

#endif
