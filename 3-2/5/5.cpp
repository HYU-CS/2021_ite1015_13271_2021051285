#include <iostream>

namespace multi
{
    int multi(int lhs, int rhs = 2)
    {
        return lhs * rhs;
    }
}

int main(void)
{
    std::cout << multi::multi(3) << std::endl;

    return 0;
}