#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
    Span();

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif
