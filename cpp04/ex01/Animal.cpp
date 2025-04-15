#include "Animal.hpp"

Animal::Animal() :  type("Unknown")
{
    std::cout << "Animal with type " << type << " was constructed." << std::endl;
}

Animal::Animal(const std::string &animal) :  type(animal)
{
    std::cout << "Animal with type " << type << " was constructed." << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructed." << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Animal Copy constructor with type " << copy.getType() << std::endl;
    type = copy.getType();
}

Animal &Animal::operator = (const Animal &copy)
{
    std::cout << "Animal Copy assignment with type " << copy.getType() << std::endl;
    if (this != &copy)
        type = copy.type;
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "sound not defined!" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

//Wrong animal

WrongAnimal::WrongAnimal()
{
    type = "Unknown";
    std::cout << "WrongAnimal with type " << type << " was constructed." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "Wrong Animal Copy constructor with type " << copy.getType() << std::endl;
    type = copy.type;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &copy)
{
    std::cout << "Wrong Animal Copy assignment with type " << copy.getType() << std::endl;
    if (this != &copy)
        type = copy.type;
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "(Wrong Animal)sound not defined!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}