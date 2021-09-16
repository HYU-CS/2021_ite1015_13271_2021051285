#include <iostream>
#include <string>

int main(void)
{
    std::string name, major, studentID;


    std::cout << "name: ";
    std::getline(std::cin, name);

    std::cout << "major: ";
    std::getline(std::cin, major);

    std::cout << "studentID: ";
    std::getline(std::cin, studentID);


    std::cout << "Hello. My name is " << name << ".\n";
    std::cout << "My major is " << major << ".\n";
    std::cout << "My student ID is " << studentID << ".\n";


    return 0;
}