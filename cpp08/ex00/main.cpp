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
        std::cout << "Found in vector: " << *easyfind(vec, 20) << std::endl;

        std::list<int> lst;
        lst.push_back(30);
        lst.push_back(40);
        std::cout << "Found in list: " << *easyfind(lst, 30) << std::endl;

        std::deque<int> deq;
        deq.push_back(50);
        deq.push_back(60);
        std::cout << "Found in deque: " << *easyfind(deq, 60) << std::endl;

        std::set<int> st;
        st.insert(70);
        st.insert(80);
        std::cout << "Found in set: " << *easyfind(st, 80) << std::endl;
        easyfind(st, 90); // will fail

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
