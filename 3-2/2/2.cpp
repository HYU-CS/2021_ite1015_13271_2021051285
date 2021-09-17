#include <iostream>
#include <string>

int main(void)
{
    std::string str;

    int count = 2;

    while(count)
    {
        bool cond = false;
        int ioi = 0;
        int oi = 0;

        std::cout << "S = ";
        std::getline(std::cin, str);

        for(size_t i = 0; i < str.length(); i++)
        {
            if(str[i] < 'A' || str[i] > 'Z')
            {
                cond = true;
                break;
            }
        }

        if(cond)
        {
            std::cout << "\"Warning\"" << std::endl;
            continue;
        }

        for(size_t i = 0; i < str.length(); i++)
        {
            if(i + 1 < str.length())
            {
                if(str[i] == 'O' && str[i + 1] == 'I')
                {
                    oi++;
                }
            }
            if(i + 2 < str.length())
            {
                if(str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I')
                {
                    ioi++;
                }
            }
        }

        std::cout << ioi << std::endl << oi << std::endl;

        count--;
    }

    return 0;
}