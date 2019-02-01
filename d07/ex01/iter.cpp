#include <iostream>

template <typename T>
void iter(T *a, T b, void (*f)(T &))
{
    for (int i = 0; i < b; i++)
    {
        f(a[i]);
    }
}

template <typename T>
void addFive(T & number)
{
    number += 5;
}

int main()
{
    int foo[5] = {10, 15, 25, 78, 125};
    
    iter(foo, 5, addFive);

    for (int i = 0; i < 5; i++)
    {
        //addFive(foo[i]);
        std::cout <<" " << foo[i];
    }
    std::cout <<"\n";
    return (0);
}