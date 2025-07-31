#include "iter.hpp"




int main()
{
    std::string names[3] = {"Pedro", "Ana", "Tomás"};

    int         numbers[3] = {1, 2, 3};

    ::iter(names, 3, printIt);
    ::iter(numbers, 3, printIt);

    return 0;
}