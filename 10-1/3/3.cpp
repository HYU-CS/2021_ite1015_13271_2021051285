#include <iostream>
#include <string>
#include <vector>

class Shape
{
    std::string name;

protected:
    int radius, height;

public:
    Shape(std::string n, int r, int h): name(n), radius(r), height(h) { }
    virtual ~Shape() { }
    virtual double getVolume(void) = 0;
    std::string getName(void) const { return name; }
};

class Cone: public Shape
{
public:
    Cone(std::string n, int r, int h);
    virtual double getVolume(void);
};

Cone::Cone(std::string n, int r, int h)
: Shape(n, r, h) { }

double Cone::getVolume(void)
{
    return this->radius * this->radius * this->height * 3.14 / 3.0;
}

class Cylinder: public Shape
{
public:
    Cylinder(std::string n, int r, int h);
    virtual double getVolume(void);
};

Cylinder::Cylinder(std::string n, int r, int h)
: Shape(n, r, h) { }

double Cylinder::getVolume(void)
{
    return this->radius * this->radius * this->height * 3.14;
}

int main(void)
{
    std::vector<Shape *> p(2);
    p[0] = new Cone("Cone", 10, 20);
    p[1] = new Cylinder("Cylinder", 10, 20);

    for(int i = 0; i < 2; i++)
    {
        std::cout << p[i]->getName() << "'s volume is " << p[i]->getVolume() << std::endl;
    }

    for(int i = 0; i < 2; i++)
    {
        delete p[i];
    }

    return 0;
}