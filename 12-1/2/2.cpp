#include <iostream>

template <typename T>
void reverseArray(T *arr, size_t size)
{
    T temp;
    for(size_t i = 0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main(void)
{
    int x[] = {1, 10, 100, 3, 5};
    reverseArray(x, 5);
    for(int i = 0; i < 5; i++)
    {
        std::cout << x[i] << ' ';
    }

    return 0;
}