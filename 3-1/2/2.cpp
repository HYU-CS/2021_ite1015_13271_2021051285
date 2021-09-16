#include <iostream>
#include <string>

namespace selfIntro
{
    std::string name(void)
    {
        std::string str;
        std::cout << "name: ";
        std::getline(std::cin, str);
        return str;
    }

    void name(std::string str)
    {
        std::cout << "Hello. My name is " << str << ".\n";
    }

    std::string major(void)
    {
        std::string str;
        std::cout << "major: ";
        std::getline(std::cin, str);
        return str;
    }

    void major(std::string str)
    {
        std::cout << "My major is " << str << ".\n";
    }

    std::string studentID(void)
    {
        std::string str;
        std::cout << "studentID: ";
        std::getline(std::cin, str);
        return str;
    }

    void studentID(std::string str)
    {
        std::cout << "My student ID is " << str << ".\n";
    }
}

int main(void)
{
    std::string strName, strMajor, strStudentID;


    strName = selfIntro::name();
    strMajor = selfIntro::major();
    strStudentID = selfIntro::studentID();


    selfIntro::name(strName);
    selfIntro::major(strMajor);
    selfIntro::studentID(strStudentID);


    return 0;
}