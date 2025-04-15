#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>

class   Animal
{
    protected:
        std::string type;
    
    public:
        Animal();
        Animal(const std::string &animal);
        virtual ~Animal();
        Animal(const Animal &copy);
        Animal &operator = (const Animal &copy);

        virtual void makeSound() const = 0;
        std::string getType() const;
};

class   WrongAnimal
{
    protected:
        std::string type;
    
    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal &operator = (const WrongAnimal &copy);

        void makeSound() const;
        std::string getType() const;
};

#endif