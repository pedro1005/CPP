#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "Creating Dog with new:" << std::endl;
    Dog* basic = new Dog(); // dynamically allocated Dog

    std::cout << "basic's idea[0]: " << basic->get_idea(0) << std::endl;
    basic->set_idea(0, "Play");

    {
        std::cout << "\nCreating tmp (copy of basic):" << std::endl;
        Dog tmp = *basic; // invokes copy constructor

        std::cout << "tmp's idea[0]: " << tmp.get_idea(0) << std::endl;

        tmp.set_idea(0, "Guard");

        std::cout << "\nAfter modifying tmp:" << std::endl;
        std::cout << "tmp's idea[0]: " << tmp.get_idea(0) << std::endl;
        std::cout << "basic's idea[0]: " << basic->get_idea(0) << std::endl;
    } // tmp is destroyed here

    std::cout << "\nAfter tmp is gone, basic is still valid." << std::endl;
    std::cout << "basic's idea[0]: " << basic->get_idea(0) << std::endl;

    delete basic; // cleanup

    return 0;
}
/*
//test ~virtual -> remove error flags & virtual destructor
int main() {
    Animal* animal = new Dog();  // Upcasting to base class pointer
    animal->makeSound();          // Calls Dog's makeSound

    delete animal;  // Should ideally call Dog's destructor followed by Animal's
    return 0;
}
*/