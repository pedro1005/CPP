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
    while (i < (int)(sizeof(this->level) / sizeof(this->level[0])))
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

    if (index == 4)
    {
        this->unknown();
        return ;
    }
    while (index < 4)
    {
        switch (index)
        {
        case (0):
            this->debug();
            break ;
        case (1):
            this->info();
            break ;
        case (2):
            this->warning();
            break ;
        case (3):
            this->error();
            break ;
        }
        index++;
    }
    return ;
}