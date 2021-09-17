#include <iostream>
#include <string>
#include <cstdarg>

std::string func(void)
{
    return "Hello world";
}

std::string func(std::string str_1, std::string str_2)
{
    return str_1 + " " + str_2;
}

std::string func(std::string str_1, std::string str_2, std::string str_3)
{
    return str_1 + " " + str_2 + " " + str_3;
}

int main(void)
{ 
    std::string str_1 = func(); 
    std::string str_2 = func("Hello", "Hanyang"); 
    std::string str_3 = func("Hello", "C++", "world"); 
 
    std::cout << str_1 << std::endl; 
    std::cout << str_2 << std::endl; 
    std::cout << str_3 << std::endl;

    return 0;
}