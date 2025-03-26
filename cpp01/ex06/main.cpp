#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;

    if (argc != 2)
    {
        std::cout << "Nothing to complain: try <exec> <error code>" << std::endl;
        return (0); 
    }
    std::string level = argv[1];
    harl.complain(level);

    return (0);
}