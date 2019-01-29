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
    this->name = source.name;
    this->grade = source.grade;
}

std::ostream &operator<<(std::ostream &stream, Bereaucrat &source)
{
    stream << source.getName()  + ", bureaucrat" << source.getGrade() << ".\n";
    return (stream);
}
