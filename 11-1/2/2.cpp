#include <iostream>

class Circle
{
private:
    int radius;

public:
    Circle(int radius = 0)
    {
        this->radius = radius;
    }
    void show(void)
    {
        std::cout << "Circle's radius = " << radius << std::endl;
    }

    friend Circle& operator++(Circle &circle);
    friend Circle operator++(Circle &circle, int);
};

Circle& operator++(Circle& circle)
{
    circle.radius++;

    return circle;
}

Circle operator++(Circle &circle, int)
{
    Circle temp = circle;

    circle.radius++;

    return temp;
}

int main(void)
{
    Circle a(5), b;

    b = ++a;
    a.show(); b.show();
    b = a++;
    a.show(); b.show();

    return 0;
}