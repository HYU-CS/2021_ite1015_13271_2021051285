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

    std::cout << "x :";
    std::cin >> x;

    std::cout << "y :";
    std::cin >> y;

    std::cout << "Before call by reference - x: " << x << ", y: " << y << std::endl;

    mySwap(x, y);

    std::cout << "After call by reference  - x: " << x << ", y: " << y << std::endl;

    return 0;
}