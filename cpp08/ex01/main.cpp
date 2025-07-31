#include "Span.hpp"
#include <iostream>
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

    std::cout << "***AddNumber() with Range TEST***" << std::endl;


    try {
        Span sp2 = Span(5);

        // Fill a vector of 10,000 random numbers
        std::vector<int> values;
        values.push_back(6);
        values.push_back(3);
        values.push_back(17);
        values.push_back(9);
        values.push_back(11);

        // Add them to Span using a range of iterators
        sp2.addNumbers(values.begin(), values.end());

        std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;

        // Edge test: try to add one more
        try {
            sp2.addNumber(42);
        } catch (const std::exception &e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
        }

        } catch (const std::exception &e) {
            std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}
