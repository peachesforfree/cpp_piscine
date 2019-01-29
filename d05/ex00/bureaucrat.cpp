#include "bureaucrat.hpp"

#include <iostream>

Bereaucrat&Bereaucrat::operator=(const Bereaucrat &source)
{
    if (this != &source)
    {
        *this = source;
        //this->_name = source._name;
        //this->_grade = source._grade;
    }
    return (*this);
}

Bereaucrat::~Bereaucrat() {}

Bereaucrat::Bereaucrat(const Bereaucrat &source)
{
    this->_name = source._name;
    this->_grade = source._grade;
}

std::ostream &operator<<(std::ostream &stream, const Bereaucrat &source)
{
    stream << _name << ", bureaucrat" << _grade << ".\n";
    return (stream);
}
