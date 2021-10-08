#include <iostream>
#include <string>
#include <map>

int main(void)
{
    std::map<std::string, int> maps;
    std::string str;

    std::string::size_type lpos = 0;
    std::string::size_type rpos = 0;
    
    std::getline(std::cin, str);
    while(true)
    {
        rpos = str.find(' ', lpos);

        std::string word = str.substr(lpos, rpos - lpos);

        if(maps.find(word) == maps.end())
        {
            maps[word] = 1;
        }
        else
        {
            maps[word] += 1;
        }

        if(rpos == std::string::npos)
        {
            break;
        }
        else
        {
            lpos = rpos + 1;
        }
    }

    for(std::map<std::string, int>::const_iterator it = maps.begin(); it != maps.end(); it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}