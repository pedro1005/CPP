#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

class RPN {
public:
    // Canonical form
    RPN();                                 // Default constructor
    RPN(const RPN& other);                 // Copy constructor
    RPN& operator=(const RPN& other);      // Copy assignment operator
    ~RPN();                                // Destructor

    // Functional interface
    static int calcRPN(const std::string& expression);

private:
    static std::stack<int> _stack;
};

#endif
