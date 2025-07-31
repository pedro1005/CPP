#include "Span.hpp"
#include <limits>
#include <cmath>

// Constructor
Span::Span() : _maxSize(0), _numbers() {}
Span::Span(unsigned int N) : _maxSize(N), _numbers() {}

// Copy constructor
Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

// Assignment operator
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

// Destructor
Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Cannot add number: Span is full.");
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Cannot find span: Not enough numbers.");

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Cannot find span: Not enough numbers.");

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return maxVal - minVal;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (static_cast<unsigned int>(std::distance(begin, end)) + _numbers.size() > _maxSize)
        throw std::runtime_error("Cannot add range: Exceeds maximum size.");
    _numbers.insert(_numbers.end(), begin, end);
}
