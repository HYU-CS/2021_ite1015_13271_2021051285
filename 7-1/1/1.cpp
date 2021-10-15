#include <iostream>

class Shape
{
protected:
    int width;
    int height;

public:
    Shape(int width, int height);
};

class Triangle : public Shape
{
public:
    Triangle(int width, int height);
    double getArea(void) const;
};

class Square : public Shape
{
public:
    Square(int width, int height);
    double getArea(void) const;
};

Shape::Shape(int width, int height)
: width(width), height(height) { }

Triangle::Triangle(int width, int height)
: Shape(width, height) { }

double Triangle::getArea(void) const
{
    return this->width * this->height / (double)2;
}

Square::Square(int width, int height)
: Shape(width, height) { }

double Square::getArea(void) const
{
    return this->width * this->height;
}

int main(void)
{
    int width, height;

    std::cout << "Width : ";
    std::cin >> width;
    std::cout << "Height : ";
    std::cin >> height;

    Triangle tri(width, height);
    Square sq(width, height);

    std::cout << "Area of Triangle is " << tri.getArea() << std::endl;
    std::cout << "Area of Square is " << sq.getArea() << std::endl;
    
    return 0;
}