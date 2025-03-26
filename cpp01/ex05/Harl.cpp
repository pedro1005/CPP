#include "Harl.hpp"

Harl::Harl(void)
{
    level[0] = "DEBUG";
    level[1] = "INFO";
    level[2] = "WARNING";
    level[3] = "ERROR";
};

Harl::~Harl(void) {};

void Harl::debug(void)
{
    std::cout << "[DEBUG]: debug message..." << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]: info message..." << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]: warning message" << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]: error message..." << std::endl;
}

void Harl::unknown(void)
{
    std::cout << "Unknown error!" << std::endl;
}

int Harl::getIndex(const std::string& str)
{
    int i = 0;
    while (i < 4)
    {
        if (str == this->level[i])
            return (i);
        i++;
    }
    return (4);
}

void    Harl::complain(std::string level)
{
    int index = this->getIndex(level);
    
    void    (Harl::*ft_ptr[5])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
        &Harl::unknown
    };

    (this->*ft_ptr[index])();
    
    return ;
}