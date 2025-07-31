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

    ++init;
    --init;
    std::cout << "***Iterate MutantStack***" << std::endl;
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

    std::cout << "MutantStack with chars" << std::endl;
	MutantStack<char> letters;
	letters.push('4');
	letters.push('2');
	std::cout << "Last element: " << letters.top() << std::endl; // 2
	letters.pop();
    letters.pop();
	letters.push('p');
	letters.push('e');
	letters.push('d');
	letters.push('m');
    letters.push('o');
    letters.push('n');
    letters.push('t');
    letters.push('e');
	MutantStack<char>::iterator it2 = letters.begin();
	MutantStack<char>::iterator ite2 = letters.end();
	while (it2 != ite2)
	{
		std::cout << *it2;
		++it2;
	}
    std::cout << std::endl;
	std::stack<char> s2(letters);
    while (!s2.empty())
    {
        std::cout << s2.top();
        s2.pop();
    }
    std::cout << std::endl;

    std::stack<char>::container_type::iterator it5 = letters.begin();
    std::cout << *it5 << std::endl;

    return 0;
}
