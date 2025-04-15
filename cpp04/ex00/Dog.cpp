#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog with type " << type << " was constructed." << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) // Copy constructor
{
    type = copy.type;
    std::cout << "Dog copied with type " << type << std::endl;
}

Dog &Dog::operator=(const Dog &copy) // Copy assignment operator
{
    if (this != &copy) {
        Animal::operator=(copy); // Call base class assignment operator
        type = copy.type;
    }
    std::cout << "Dog assigned with type " << type << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructed." << std::endl;;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}