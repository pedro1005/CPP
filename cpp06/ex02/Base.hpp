#ifndef BASE_HPP
#define BASE_HPP

// Base class
class Base {
public:
    virtual ~Base();
};

// Derived classes
class A : public Base {};
class B : public Base {};
class C : public Base {};

// Function declarations
Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif // BASE_HPP
