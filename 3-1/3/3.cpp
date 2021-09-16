#include <iostream>
#include <string>

int main(void)
{
    std::string str[2];

    std::getline(std::cin, str[0]);
    std::getline(std::cin, str[1]);

    std::cout << str[0] << " " << str[1] << std::endl;
    // OR
    // std::cout << str[0] + std::string(" ") + str[1] << std::endl;

    return 0;
}