#include <iostream>
#include <string>

int main()
{
    int count = 0;
    int groupCount = 0;
    std::string str;

    std::cout << "s = ";
    std::cin >> count;

    for(int i = 0; i < count; i++)
    {
        groupCount++;
        bool alphabet[26] = { false };
        bool cond = false;
        std::cin >> str;

        for(size_t i = 0; i < str.length(); i++)
        {
            if(str[i] < 'a' || str[i] > 'z')
            {
                cond = true;
                break;
            }
        }

        if(cond)
        {
            std::cout << "\"Warning\"" << std::endl;
            i--;
            continue;
        }

        alphabet[str[0] - 'a'] = true;

        for(size_t i = 1; i < str.length(); i++)
        {
            if(str[i] == str[i - 1])
            {
                continue;
            }
            else
            {
                if(alphabet[str[i] - 'a'])
                {
                    groupCount--;
                    break;
                }
                else
                {
                    alphabet[str[i] - 'a'] = true;
                }
            }
        }
    }

    std::cout << groupCount << std::endl;

    return 0;
}