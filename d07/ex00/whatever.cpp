#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b; 
    b = temp;
    return;
}

template <typename T>
T const& min(T &a, T &b) //should be T const return
{
    if (a < b)
        return a;
    if (b < a)
        return b;
    return b;
}

template <typename T>
T const& max(T &a, T &b)
{
    if (a > b)
        return a;
    if (b > a)
        return b;
    return b;
}

int main( void )
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}

/*  Expected out

a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2

*/