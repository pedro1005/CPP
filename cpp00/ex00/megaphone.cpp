#include <iostream>
#include <string>
#include <cctype>

// Helper function to convert a character to uppercase
char to_upper(char c)
{
    return std::toupper(static_cast<unsigned char>(c));
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            // Convert argv[i] to std::string
            std::string arg_str = std::string(argv[i]);
            // Manually convert each character to uppercase
            for (size_t j = 0; j < arg_str.length(); j++) {
                arg_str[j] = to_upper(arg_str[j]);
            }
            if (i > 1 && i < argc)
                std::cout << " ";
            // Print the uppercase string
            std::cout << arg_str;
        }
        std::cout << std::endl;
    }
    return (0);
}
