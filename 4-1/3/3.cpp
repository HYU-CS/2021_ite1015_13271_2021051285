#include <iostream>

void mySwap(int &lhs, int &rhs)
{
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

int main(void)
{
    int x, y;

    std::cin >> x >> y;

    std::cout << "Before call by reference - x: " << x << ", y: " << y << std::endl;

    mySwap(x, y);

    std::cout << "After call by reference  - x: " << x << ", y: " << y << std::endl;

    return 0;
}