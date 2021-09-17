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
        std::cin >> str;

        alphabet[str[0] - 'a'] = true;

        for(int i = 1; i < str.length(); i++)
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
}