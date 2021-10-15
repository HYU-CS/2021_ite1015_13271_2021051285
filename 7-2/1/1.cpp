#include <iostream>
#include <string>

// class declaration

class Point
{
protected:
    int x;
    int y;

public:
    Point(int _x, int _y);
    void move(int _x, int _y);
};

class ColorPoint: public Point
{
private:
    std::string color;

public:
    ColorPoint(int _x, int _y, std::string _color);
    void setPoint(int _x, int _y);
    void setColor(std::string _color);
    void show(void);
};

// function definition of class Point

Point::Point(int _x, int _y)
: x(_x), y(_y) { }

void Point::move(int _x, int _y)
{
    this->x = _x;
    this->y = _y;
}

// function definition of class ColorPoint

ColorPoint::ColorPoint(int _x, int _y, std::string _color)
: Point(_x, _y), color(_color) { }

void ColorPoint::setPoint(int _x, int _y)
{
    this->move(_x, _y);
}

void ColorPoint::setColor(std::string _color)
{
    this->color = _color;
}

void ColorPoint::show(void)
{
    std::cout << "The point's color is " << this->color;
    std::cout << " which is on (" << this->x << "," << this->y << ")." << std::endl;
}

// main function

int main(void)
{
    ColorPoint cp(5, 5, "RED");
    cp.show();

    cp.setPoint(10, 20);
    cp.setColor("BLUE");
    cp.show();

    return 0;
}