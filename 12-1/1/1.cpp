#include <iostream>

template <typename T>
T sum(T* arr, size_t size)
{
    T s = 0;

    for(size_t i = 0; i < size; i++)
    {
        s += arr[i];
    }

    return s;
}

int main(void)
{
    float fdata[5];
    int i = 0;

    //input 5 numbers
    std::cout << "\nInput 5 numbers >>" << std::endl;
    for(i = 0; i < 5; i++)
    {
        std::cin >> fdata[i];
    }

    std::cout << "\nSum of above inputs is : " << sum(fdata, 5) << std::endl;

    std::cin.get();
    return 0;
}