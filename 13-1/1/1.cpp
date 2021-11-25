#include <iostream>

int Exp(int base, int exponent)
{
    if(base <= 0 || exponent <= 0)
    {
        throw "Cannot use negative numbers.";
    }

    int result = 1;

    while(exponent > 0)
    {
        if(exponent % 2 == 1)
        {
            result *= base;
        }

        base *= base;
        exponent >>= 1;
    }

    return result;
}

int main(void)
{
    int v = 0;

    try
    {
        v = Exp(2, 10);
        std::cout << "The value of 2 to the power 10 is " << v << std::endl;

        v = Exp(2, -10);
        std::cout << "The value of 2 to the power -10 is " << v << std::endl;

    }
    catch(const char *s)
    {
        std::cerr << "Exception! " << s << std::endl;
    }
    
    
}