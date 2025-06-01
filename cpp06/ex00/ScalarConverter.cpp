#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <cmath>

/*| Constant | Type     | Meaning                          |
  | -------- | -------- | -------------------------------- |
  | `-inff`  | `float`  | Negative infinity (for `float`)  |
  | `+inff`  | `float`  | Positive infinity (for `float`)  |
  | `nanf`   | `float`  | Not-a-Number (for `float`)       |
  | `-inf`   | `double` | Negative infinity (for `double`) |
  | `+inf`   | `double` | Positive infinity (for `double`) |
  | `nan`    | `double` | Not-a-Number (for `double`)      |
*/

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& copy) { (void)copy; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) { (void)copy; return *this; }
ScalarConverter::~ScalarConverter() {}

static bool detectPseudoLiteral(const std::string& literal)
{
    return (literal == "nan" || literal == "+inf" || literal == "-inf"
        || literal == "nanf" || literal == "+inff" || literal == "-inff");
}

void printConversions(char c, int i, float f, double d, bool isPseudoLiteral, const std::string& literal)
{
    // char
    std::cout << "char: ";
    if (isPseudoLiteral || i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else if (std::isprint(static_cast<unsigned char>(c)))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    // int
    std::cout << "int: ";
    if (isPseudoLiteral || d < static_cast<double>(std::numeric_limits<int>::min())
        || d > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;

    // float
    std::cout << "float: ";
    if (isPseudoLiteral)
    {
        if (literal == "nan" || literal == "nanf")
            std::cout << "nanf" << std::endl;
        else if (literal[0] == '+')
            std::cout << "+inff" << std::endl;
        else if (literal[0] == '-')
            std::cout << "-inff" << std::endl;
    }
    else
        std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    // double
    std::cout << "double: ";
    if (isPseudoLiteral)
    {
        if (literal == "nan" || literal == "nanf")
            std::cout << "nan" << std::endl;
        else if (literal[0] == '+')
            std::cout << "+inf" << std::endl;
        else if (literal[0] == '-')
            std::cout << "-inf" << std::endl;
    }
    else
        std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

static void convertFromChar(const std::string& literal)
{
    char c = literal[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    printConversions(c, i, f, d, false, literal);
}

static void convertFromNumeric(const std::string& literal, bool isPseudoLiteral)
{
    char* endPtr;
    double d = std::strtod(literal.c_str(), &endPtr);
    float f = static_cast<float>(d);
    int i = static_cast<int>(d);
    char c = static_cast<char>(i);

    printConversions(c, i, f, d, isPseudoLiteral, literal);
}

void ScalarConverter::convert(const std::string& literal)
{
    if (literal.length() == 1 && std::isprint(static_cast<unsigned char>(literal[0])) && !std::isdigit(static_cast<unsigned char>(literal[0])))
    {
        convertFromChar(literal);
        return;
    }

    bool isPseudoLiteral = detectPseudoLiteral(literal);
    convertFromNumeric(literal, isPseudoLiteral);
}
