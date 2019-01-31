#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <math.h>
# include <iomanip>
# include <iostream>

class Convert
{
    public:
        Convert(void);
        Convert(char *in);
        ~Convert();
        Convert &operator=(const Convert &source);
        Convert(const Convert &source);

        double getValue(void);
        void setValue(char *in);
        int     getPrecision(char *str);
        
        operator float() {return static_cast<float>(this->value); };
        operator int() {return static_cast<int>(this->value); };
        operator char() {return static_cast<char>(this->value); };

    private:
        long double value;
        int precision;
};

#endif