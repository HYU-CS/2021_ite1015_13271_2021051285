#include <iostream>

namespace multiNS
{
    int multi(int lhs, int rhs = 2)
    {
        return lhs * rhs;
    }
}

using multiNS::multi;

int main(void)
{
    std::cout << multi(3) << std::endl;

    return 0;
}