#include <iostream>

struct Data
{
    int            number;
    std::string    first;
    std::string    second;
};

void *serialize(void)
{
    Data *ptr = new Data;
    char key[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for (int i = 0; i < 8; i++)
    {
        ptr->first += key[rand() % 62];
    }
    ptr->number = rand();
    for(int i = 0; i < 8; i++)
    {
        ptr->second += key[rand() % 62];
    }

    std::cout << "'" << ptr->first << "'" << "\n";
    std::cout << "Number: " << ptr->number << "\n";
    std::cout << "'" << ptr->second << "'\n";


    return static_cast<void*>(ptr);
}

Data*   deserialize(void *ptr)
{
    Data *ret;

    ret = static_cast<Data*>(ptr);
    return (ret);
}

int main(void)
{
    srand(time(0));
    void *ptr;
    Data *value;

    ptr = serialize();
    value = deserialize(ptr);

    std::cout << "'" << value->first << "'" << "\n";
    std::cout << "Number: " << value->number << "\n";
    std::cout << "'" << value->second << "'\n";

    return 0;
}