#include <iostream>
#include <string>

class Flight
{
private:
    std::string flightNum;
    std::string flightDep;
    std::string flightDes;
    float dis;
    float fuel;
    float calFuel(void);

public:
    void flightInfo(void);
    void showFlightInfo(void);
};

float Flight::calFuel(void)
{
    if(dis <= 1000)
    {
        return 500.0f;
    }
    else if(dis <= 2000)
    {
        return 1500.0f;
    }
    else
    {
        return 3000.0f;
    }
}

void Flight::flightInfo(void)
{
    std::cout << "Flight number : ";
    std::cin >> this->flightNum;

    std::cout << "Departure : ";
    std::cin >> this->flightDep;

    std::cout << "Destination : ";
    std::cin >> this->flightDes;

    while(true)
    {
        std::cout << "Distance : ";
        std::cin >> this->dis;

        if(this->dis <= 100)
        {
            std::cout << "\'Warning\'" << std::endl;
        }
        else
        {
            break;
        }
    }

    this->fuel = this->calFuel();
}

void Flight::showFlightInfo(void)
{
    std::cout << "Flight Information" << std::endl;
    std::cout << "Flight number : " << this->flightNum << std::endl;
    std::cout << "Departure / Destination : " << this->flightDep << " / " << this->flightDes << std::endl;
    std::cout << "Distance : " << this->dis << " km" << std::endl;
    std::cout << "Fuel : " << this->fuel << std::endl;
}

int main(void)
{
    Flight flight;

    flight.flightInfo();
    flight.showFlightInfo();

    return 0;
}