#include <iostream>

const double PI = 3.14;

void circle(double *radius);

int main(void)
{
    double rad;

    std::cin >> rad;

    if(rad <= 0.0)
    {
        return 0;
    }

    circle(&rad);

    std::cout << rad << std::endl;

    return 0;
}

void circle(double *radius)
{
    if(*radius <= 0.0)
    {
        return;
    }

    *radius = PI * *radius * *radius;

    return;
}