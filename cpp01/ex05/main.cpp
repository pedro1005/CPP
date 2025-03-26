#include "Harl.hpp"

int main(void)
{
    Harl harl;

    harl.complain("ERROR");
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("42");

    return (0);
}