#include <iostream>
#include "Array.hpp"
#include <cstdlib>  // for srand(), rand()
#include <ctime>    // for time()

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE TEST -> check for memory leaks
    {
        Array<int> a(5);
        for (size_t i = 0; i < a.size(); ++i)
            a[i] = i * 10;
        Array<int> b(a);  // copy constructor
        // Modify original
        a[0] = 999;
        // Check that copy did not change
        if (b[0] == 999)
            std::cerr << "Error: copy constructor did shallow copy!" << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Catch exception 1: ";
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Catch exception 2: ";
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}