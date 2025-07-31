#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc <= 1)
        return (0);
    try {
        PmergeMe::sortAndMeasure(argv, argc);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
