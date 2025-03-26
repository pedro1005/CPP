#include <string>
#include <iostream>

int main(void)
{
    std::string     str = "HI THIS IS BRAIN";
    std::string*    stringPTR = &str;
    std::string&    stringREF = str;

    std::cout << "memory adress of str: " << &str << std::endl;
    std::cout << "memory adress of stringPTR: " << stringPTR << std::endl;
    std::cout << "memory adress of stringREF: " << &stringREF << std::endl;

    std::cout << "value of str: " << str << std::endl;
    std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "value pointed to by stringREF: " << stringREF << std::endl;

    return (0);
}