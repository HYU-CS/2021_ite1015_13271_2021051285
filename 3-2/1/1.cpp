#include <iostream>
#include <string>

int main(void)
{
    std::string str;

    while(true)
    {
        std::cout << "Write lowercase string: ";

        std::getline(std::cin, str);

        if(str.compare("EXIT") == 0)
        {
            break;
        }

        bool cond = false;

        for(size_t i = 0; i < str.length(); i++)
        {
            if(str[i] < 'a' || str[i] > 'z')
            {
                std::cout << "\"warning\"" << std::endl;
                cond = true;
                break;
            }
            else
            {
                str[i] += 'A' - 'a';
            }
        }

        if(cond)
        {
            continue;
        }

        std::cout << str << std::endl;
    }

    return 0;
}