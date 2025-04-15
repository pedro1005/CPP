#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
//Animal error; //error: variable type 'const Animal' is an abstract class
Dog* dog = new Dog();

std::cout << "type of animal: " << dog->getType() << std::endl;
dog->makeSound();

delete dog;
return (0);
}
