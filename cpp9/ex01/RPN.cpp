#include "RPN.hpp"
#include <sstream>
#include <stdexcept>


RPN::RPN() {}

RPN::RPN(const RPN& other) {(void)other;}

RPN& RPN::operator=(const RPN& other) {
    (void)other;
    return *this;
}

RPN::~RPN() {}

std::stack<int> RPN::_stack;

int RPN::calcRPN(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.size() == 1 && isdigit(token[0])) {
            _stack.push(token[0] - '0');
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (_stack.size() < 2)
                throw std::runtime_error("Not enough operands");

            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();

            int result = 0;
            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") {
                if (b == 0)
                    throw std::runtime_error("Division by zero");
                result = a / b;
            }

            _stack.push(result);
        } else {
            throw std::runtime_error("Invalid token: " + token);
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Invalid expression");

    return _stack.top();
}
