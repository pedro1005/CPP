#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


/*int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();

std::cout << "type of meta: " << meta->getType() << std::endl;
std::cout << "type of j: " << j->getType() << std::endl;
j->makeSound();
meta->makeSound();

delete meta;
delete j;
return (0);
}*/

int main() {
    std::cout << "Creating an Animal object..." << std::endl;
    Animal genericAnimal;
    std::cout << "Type: " << genericAnimal.getType() << std::endl;
    genericAnimal.makeSound();
    std::cout << std::endl;

    std::cout << "Creating a Dog object..." << std::endl;
    Dog dog;
    std::cout << "Type: " << dog.getType() << std::endl;
    dog.makeSound();
    std::cout << std::endl;

    std::cout << "Testing copy constructor..." << std::endl;
    Dog dogCopy(dog);
    std::cout << "Type of dogCopy: " << dogCopy.getType() << std::endl;
    dogCopy.makeSound();
    std::cout << std::endl;

    std::cout << "Testing assignment operator..." << std::endl;
    Dog anotherDog;
    anotherDog = dog;
    std::cout << "Type of anotherDog: " << anotherDog.getType() << std::endl;
    anotherDog.makeSound();
    std::cout << std::endl;

    std::cout << "Creating an array of Animal pointers with polymorphism..." << std::endl;
    Animal* animals[3];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Cat();

    for (int i = 0; i < 3; ++i) {
        std::cout << "Type: " << animals[i]->getType() << " - ";
        animals[i]->makeSound();
    }
    for (int i = 0; i < 3; ++i) {
        delete animals[i];
    }

    WrongAnimal *badCat = new WrongCat();
    std::cout << "WrongCat says: ";
    badCat->makeSound();
    delete badCat;

    WrongCat newBadCat;
    std::cout << "New WrongCat says: ";
    newBadCat.makeSound();

    return 0;
}