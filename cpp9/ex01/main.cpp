#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./rpn \"expression\"" << std::endl;
        return 1;
    }

    try {
        RPN rpn;
        int result = rpn.calcRPN(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
