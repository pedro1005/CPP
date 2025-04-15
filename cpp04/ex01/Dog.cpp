#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog with type " << type << " was constructed." << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) // Copy constructor
{
    type = copy.type;
    brain = new Brain(*copy.brain);
    std::cout << "Dog copied with type " << type << "." << std::endl;
}

Dog &Dog::operator=(const Dog &copy) // Copy assignment operator
{
    if (this != &copy) {
        Animal::operator=(copy); // Call base class assignment operator
        if (brain)
            delete brain;
        brain = new Brain(*copy.brain);
    }
    std::cout << "Dog assigned with type " << type << "." << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructed." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

std::string Dog::get_idea(const int &i)
{
    return this->brain->getIdea(i);
}

void Dog::set_idea(const int &i, const std::string &idea)
{
    if (i >= 0 && i < 100 && brain)
        brain->setIdea(i, idea);
}