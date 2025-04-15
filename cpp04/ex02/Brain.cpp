#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain constructed." << std::endl;
    const std::string sampleIdeas[] = {
        "Eat", "Sleep", "Code", "Play", "Run", "Fear", "Think", "Jump", "Explore", "Nap"
    };
    const int sampleSize = sizeof(sampleIdeas) / sizeof(sampleIdeas[0]);
    for (int i = 0; i < 100; ++i)
    {
        ideas[i] = sampleIdeas[i % sampleSize];
    }
}

Brain::~Brain()
{
    std::cout << "Brain destructed." << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain copy constructor." << std::endl;
    for (int i = 0; i < 100; ++i)
    {
        ideas[i] = copy.ideas[i];
    }
}

Brain &Brain::operator = (const Brain &copy)
{
    std::cout << "Brain copy assign." << std::endl;
    if (this != &copy)
    {
        for (int i = 0; i < 100; ++i)
        {
            ideas[i] = copy.ideas[i];
        }
    }
    return (*this);
}

void	Brain::setIdea( int i, std::string newIdea )
{
	this->ideas[i] = newIdea;
}

std::string Brain::getIdea( int i ) const
{
	return (this->ideas[i]);
}