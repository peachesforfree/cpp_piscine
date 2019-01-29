#ifndef BEREAUCRAT_HPP
# define BEREAUCRAT_HPP

# include <iostream>

class Bereaucrat
{
    public:
    //standard coplean functions
        Bereaucrat();
        Bereaucrat(std::string name, std::string grade);
        ~Bereaucrat();
        Bereaucrat &operator=(const Bereaucrat &source);


    //excercise specific
        std::string getName(void);
        std::string getGrade(void);
        void        setGrade(std::string grade);
        void        setName(std::string name);
        void        incrementGrade(void);
        void        decrementGrade(void);
    
    private:
        std::string const _name;
        std::string const _grade;
};

std::ostream &operator<<(std::ostream &stream, const Bereaucrat &source);


#endif