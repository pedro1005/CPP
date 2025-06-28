#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl; // Should print 17

    mstack.pop(); //remove 17

    std::cout << mstack.size() << std::endl; // Should print 1
    std::cout << std::endl;
    // 5 3 5 737 0
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    // [...]
    mstack.push(0);

    MutantStack<int>::iterator init = mstack.begin();
    MutantStack<int>::iterator end = mstack.end();

    while (init != end)
    {
        std::cout << *init << std::endl;
        ++init;
    }
    std::cout << "***Compare with list iterator***" << std::endl;

    std::list<int> lstack;

    lstack.push_back(5);
    lstack.push_back(17);

    lstack.pop_back();

    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    // [...]
    lstack.push_back(0);

    std::list<int>::iterator it = lstack.begin();
    std::list<int>::iterator ite = lstack.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    return 0;
}
