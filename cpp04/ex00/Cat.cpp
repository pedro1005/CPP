#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat was constructed." << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) // Copy constructor
{
    std::cout << "Cat Copy Constructor with type " << type << std::endl;
}

Cat &Cat::operator=(const Cat &copy) // Copy assignment operator
{
    if (this != &copy)
    {
        Animal::operator=(copy); // Call base class assignment operator
    }
    std::cout << "Cat assigned with type " << type << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miau!" << std::endl;
}


// WrongCat

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat with type " << type << " was constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) // Copy constructor
{
    std::cout << "WrongCat copied with type " << type << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) // Copy assignment operator
{
    if (this != &copy)
    {
        WrongAnimal::operator=(copy); // Call base class assignment operator
        type = copy.type;
    }
    std::cout << "WrongCat assigned with type " << type << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructed." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong Miau!" << std::endl;
}