#include <iostream>
#include <string>
#include <map>

int main(void)
{
    int n;
    std::map<std::string, int> scores;

    std::cout << "N =" << std::endl;
    std::cin >> n;

    std::string name;
    int score;

    for(int i = 0; i < n; i++)
    {
        std::cin >> name >> score;

        scores[name] = score;
    }

    std::cout << "Which student's score?" << std::endl;
    std::cin >> name;

    std::map<std::string, int>::iterator it = scores.find(name);
    if(it == scores.end())
    {
        std::cout << name << " is not in the database." << std::endl;
    }
    else
    {
        std::cout << it->first << "'s score: " << it->second << std::endl;
    }
    
    return 0;
}