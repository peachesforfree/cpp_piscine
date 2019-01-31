#include <iostream>
#include <math.h>
#include <iomanip>
#include "Conversion.hpp"
#include <string>
#include <limits.h>

int     passCheck(char *str)
{
    int i;
    int decimal;
    int sign;

    sign = 0;
    decimal = 0;
    i = 0;
    while (str[i] != '\0')
    {
        if (decimal > 1 || sign > 1)
            return (0);
        if (str[i] == '-' || str[i] == '+')
            sign++;
        if (str[i] == '.')
            decimal++;
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '+' && str[i] != '-')
            return (0);
        i++;
    }
    return (1);
}

std::string printChar(char *str)
{
    Convert f(str);
    char c;
    double chk;
    std::string schk(str);

    if (passCheck(str) == 1)
    {
        c = f;
        chk = f;
        if (chk < 0 || chk > 128)
            return "Overflow";
        if (chk <= 31 || chk >= 127)
            return "Non Displayable";
        return (std::string(1, c));
    }
    if (schk == "-inf" || schk ==  "-inff" || schk == "+inf" || schk == "+inff" || schk ==  "nan" || schk == "nanf")
        return "impossible";
    return "impossible";
}

std::string printInt(char *str)
{
    Convert f(str);
    double chk;
    int val;
    std::string schk(str);

    
    if (passCheck(str) == 1)
    {
        val = f;
        chk = f;
        if (chk < INT_MIN || chk > INT_MAX)
            return ("Overflow");
            //std::setprecision(a.getPrecision(argv[i])
        return (std::to_string(val));
    }
    if (schk == "-inf" || schk ==  "-inff" || schk == "+inf" || schk == "+inff" || schk ==  "nan" || schk == "nanf")
        return "impossible";
    return "impossible";
}

std::string printFloat(char *str)
{
    Convert f(str);
    float val;
    std::string chk(str);

    if (passCheck(str) == 1)
    {
        val = f;
        std::cout << std::setprecision(f.getPrecision(str)) << std::fixed;
        std::cout << val << "f";
        return ("");
    }
    if (chk == "-inf" || chk == "-inff")
        return "-inff";
    else if (chk == "+inf" || chk == "+inff")
        return "inff";
    else if (chk == "nan" || chk == "nanf")
        return "nanf";
    return "impossible";
}

std::string printDouble(char *str)
{
    Convert f(str);
    double val;
    std::string chk(str);

    if (passCheck(str) == 1)
    {
        val = f;
        std::cout << std::setprecision(f.getPrecision(str)) << std::fixed;
        std::cout << val;
        return ("");
    }
    if (chk == "-inf" || chk == "-inff")
        return "-inf";
    else if (chk == "+inf" || chk == "+inff")
        return "inf";
    else if (chk == "nan" || chk == "nanf")
        return "nan";
    return "impossible";
}

void    convert_values(char **argv)
{
    for (int i = 1; argv[i] != NULL; i++)
    {
        std::cout << "Char: '" << printChar(argv[i]) << "'\n";
        std::cout << "Int: " << printInt(argv[i]) << "\n";
        std::cout << "Float: " << printFloat(argv[i]) << "\n";
        std::cout << "Double: " << printDouble(argv[i]) << "\n";
    }
}

int main(int argc, char **argv)
{
    if (argc > 1)
        convert_values(argv);
    return (0);
}