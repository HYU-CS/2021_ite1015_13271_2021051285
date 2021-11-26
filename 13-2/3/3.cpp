#include <iostream>
#include <string>
#include <regex>
#include <exception>

int main(void)
{
    int count = 0;
    int groupCount = 0;

    try
    {
        std::cout << "S = ";
        std::cin >> count;

        if(std::cin.fail())
        {
            throw std::exception("input/output operation failed (formatting or extraction error, maybe non-numeric character inputed)");
        }
        if(count < 1 || count > 100)
        {
            throw std::exception("out of range error");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::regex re("[a-z]+");

    for(int i = 0; i < count; i++)
    {
        std::string str;
        bool alphabetSet['z' - 'a' + 1] = {false};

        while(true)
        {
            try
            {
                std::cin >> str;
                if(!std::regex_match(str, re))
                {
                    throw std::exception("warning");
                }
                break;
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << std::endl;
            }
        }

        bool cond = true;

        for(std::string::iterator it = str.begin(); it != str.end() && cond; it++)
        {
            if(alphabetSet[*it - 'a'])
            {
                cond = false;
            }
            else
            {
                alphabetSet[*it - 'a'] = true;
            }
        }

        if(cond)
        {
            groupCount++;
        }
    }

    std::cout << groupCount;
    
    return 0;
}