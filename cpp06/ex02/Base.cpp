#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

// Base destructor implementation
Base::~Base() {}

// Randomly generate an instance of A, B, or C
Base* generate() {
    
    switch (std::rand() % 3) {
        case 0: std::cout << "Generated: A\n"; return new A;
        case 1: std::cout << "Generated: B\n"; return new B;
        default: std::cout << "Generated: C\n"; return new C;
    }
}

// Identify type by pointer
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Type: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type: C" << std::endl;
    else
        std::cout << "Type: Unknown" << std::endl;
}

// Identify type by reference
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type: A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type: B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type: C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Type: Unknown" << std::endl;
}
