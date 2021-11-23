#include <iostream>
#include <vector>

template<class InputIt, class OutputIt>
void MyCopy(InputIt first, InputIt last, OutputIt result)
{
    InputIt iIt = first;
    OutputIt oIt = result;

    while(iIt != last)
    {
        *oIt++ = *iIt++;
    }
}

template<class InputIt1, class InputIt2, class OutputIt>
void MyMerge(InputIt1 first_1, InputIt1 last_1, InputIt2 first_2, InputIt2 last_2, OutputIt result)
{
    InputIt1 i1It = first_1;
    InputIt2 i2It = first_2;
    OutputIt oIt = result;
    
    while(i1It != last_1 && i2It != last_2)
    {
        if(*i1It < *i2It)
        {
            *oIt++ = *i1It++;
        }
        else
        {
            *oIt++ = *i2It++;
        }
    }

    while(i1It != last_1)
    {
        *oIt++ = *i1It++;
    }
    
    while(i2It != last_2)
    {
        *oIt++ = *i2It++;
    }
}

int main(void)
{
    int first[] = {5, 10, 15, 20, 25};
    int second[] = {10, 20, 30, 40, 50};
    std::vector<int> v(10);
    std::vector<int> myVector(5);

    MyCopy(first, first + 5, myVector.begin());

    std::cout << "myVector contains:";
    for(std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++)
    {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    MyMerge(first, first + 5, second, second + 5, v.begin());

    std::cout << "the resulting vector contains:";
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
    
    return 0;
}