#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <database.csv> <input.txt>\n";
        return 1;
    }

    try {
        BitcoinExchange btcExchange("data.csv");      // Load BTC rates from DB
        btcExchange.processInputFile(argv[1]);     // Process each line from input file
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
