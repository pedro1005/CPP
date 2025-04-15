#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);

        void    makeSound() const;
        std::string get_idea(const int &i);
        void        set_idea(const int &i, const std::string &idea);
    
    private:
        Brain *brain;
       
};

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat &copy);
        WrongCat &operator=(const WrongCat &copy);

        void    makeSound() const;
       
};

#endif