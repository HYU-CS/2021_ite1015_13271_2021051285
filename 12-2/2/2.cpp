#include <iostream>
#include <vector>

template <class InputIt, class T>
InputIt MyFind(InputIt first, InputIt last, const T &val)
{
    InputIt it = first;
    
    while(it != last)
    {
        if(*it == val)
        {
            return it;
        }

        it++;
    }

    return last;
}

int main(void)
{
    int myInts[] = {10, 20, 30, 40};
    int *p;
    std::vector<int> myVector(myInts, myInts + 4);
    std::vector<int>::iterator it;

    p = MyFind(myInts, myInts + 4, 50);
    if(p != myInts + 4)
    {
        std::cout << "Element found in myInts: " << *p << std::endl;
    }
    else
    {
        std::cout << "Element not found in myInts" << std::endl;
    }

    it = MyFind(myVector.begin(), myVector.end(), 30);
    if(it != myVector.end())
    {
        std::cout << "Element found in myVector: " << *it << std::endl;
    }
    else
    {
        std::cout << "Element not found in myVector" << std::endl;
    }

    return 0;
}