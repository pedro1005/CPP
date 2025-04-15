#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);

        void        makeSound() const;
        std::string get_idea(const int &i);
        void        set_idea(const int &i, const std::string &idea);

    private:
       Brain *brain;
};

#endif