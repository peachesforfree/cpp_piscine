#include "Conversion.hpp"

Convert::Convert(void): value(0){}

Convert::Convert(char *in): value(strtod(in, NULL)) , precision(getPrecision(in))
{
    //std::cout << "Convert class: constructed\n";
}

Convert::~Convert()
{
    //std::cout << "Convert class: destructed\n";
}

Convert&Convert::operator=(const Convert &source)
{
    if (this != &source)
    {
        this->value = source.value;
    }
    return (*this);
}
Convert::Convert(const Convert &source)
{
    this->value = source.value;
}

double Convert::getValue(void) {return value;};
void Convert::setValue(char *in)
{
    this->value = strtod(in, NULL);
    this->precision = getPrecision(in);
}

int     Convert::getPrecision(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0' && str[i] != '.')
        i++;
    if (str[i] == '.')
    {
        i++;
        while (str[i] != '\0')
        {
            i++;
            count++;
        }
    }
    if (count == 0)
        count = 1;
    return (count);
}