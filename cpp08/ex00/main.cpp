#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include "easyfind.hpp"

int main() {
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        std::cout << *easyfind(vec, 10) << " was found in vector at pos: " 
                  << std::distance(vec.begin(), easyfind(vec, 10)) << std::endl;

        std::list<int> lst;
        lst.push_back(30);
        lst.push_back(40);
        std::cout << *easyfind(lst, 30) << " was found in list at pos: " 
                  << std::distance(lst.begin(), easyfind(lst, 30)) << std::endl;

        std::deque<int> deq;
        deq.push_back(50);
        deq.push_back(60);
        std::cout << *easyfind(deq, 60) << " was found in deque at pos: " 
                  << std::distance(deq.begin(), easyfind(deq, 60)) << std::endl;

        std::set<int> st;
        st.insert(70);
        st.insert(80);
        std::cout << *easyfind(st, 80) << " was found in set at pos: " 
                  << std::distance(st.begin(), easyfind(st, 80)) << std::endl;

        easyfind(st, 90); // will throw

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
