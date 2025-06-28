#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main() {

    std::cout << "***SUBJECT'S MAIN***" << std::endl;
    Span sp1 = Span(5);
sp1.addNumber(6);
sp1.addNumber(3);
sp1.addNumber(17);
sp1.addNumber(9);
sp1.addNumber(11);
std::cout << sp1.shortestSpan() << std::endl;
std::cout << sp1.longestSpan() << std::endl;

std::cout << "***PEDMONTE'S TEST***" << std::endl;


try {
    Span sp(10000);

    // Fill a vector of 10,000 random numbers
    std::vector<int> values;
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < 10000; ++i) {
        values.push_back(std::rand());
    }

    // Add them to Span using a range of iterators
    sp.addNumbers(values.begin(), values.end());

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    // Edge test: try to add one more
    try {
        sp.addNumber(42);
    } catch (const std::exception &e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    } catch (const std::exception &e) {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}
