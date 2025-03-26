#include "replace.hpp"

int main(int argc, char* argv[])
{
    // Check if the correct number of arguments is passed
    if (argc != 4)
    {
        std::cerr << "Wrong args: <filename> <str to replace> <replacement str>" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    // Ensure s1 is not empty to avoid infinite loops or errors
    if (s1.empty())
    {
        std::cerr << "Error: The string to replace cannot be empty." << std::endl;
        return 1;
    }
    // Perform the replacement
    replaceStr(filename, s1, s2);
    return (0);
}
