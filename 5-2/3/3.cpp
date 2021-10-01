#include <iostream>

class Distance
{
private:
    double _meter;

public:
    Distance(void);
    void setDis(double meter);
    double getDis(void);
};

Distance::Distance(void)
: _meter(0.0) { }

void Distance::setDis(double meter)
{
    this->_meter = meter;
}

double Distance::getDis(void)
{
    return this->_meter;
}

double addDis(double dis_1, double dis_2)
{
    return dis_1 + dis_2;
}

double subDis(double dis_1, double dis_2)
{
    if(dis_1 > dis_2)
    {
        return dis_1 - dis_2;
    }
    else
    {
        return dis_2 - dis_1;
    }
}

int main(void)
{
    Distance d1, d2;

    {
        double dist;

        std::cout << "Enter distance1 value of meters : ";
        std::cin >> dist;
        d1.setDis(dist);

        std::cout << "Enter distance2 value of meters : ";
        std::cin >> dist;
        d2.setDis(dist);
    }

    std::cout << "The sum between the two distance : " << addDis(d1.getDis(), d2.getDis()) << " m";
    std::cout << "The difference between the two distance : " << subDis(d1.getDis(), d2.getDis()) << " m";

    return 0;
}