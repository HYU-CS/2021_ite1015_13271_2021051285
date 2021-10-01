#include <iostream>

class Time
{
private:
    int _hour;
    int _minute;
    int _second;

public:
    Time(void);
    void setTime(int hour, int minute, int second);
    void addTime(Time T1, Time T2);
    void showTime(void);
};

Time::Time(void)
: _hour(0), _minute(0), _second(0) { }

void Time::setTime(int hour, int minute, int second)
{
    if(hour < 0 || minute < 0 || second < 0)
    {
        return;
    }
    else if (minute >= 60 || second >= 60)
    {
        return;
    }
    else
    {
        this->_hour = hour;
        this->_minute = minute;
        this->_second = second;
    }
}

void Time::addTime(Time T1, Time T2)
{
    this->_second = (T1._second + T2._second) % 60;
    this->_minute = (T1._minute + T2._minute + (T1._second + T2._second) / 60) % 60;
    this->_hour = T1._hour + T2._hour + (T1._minute + T2._minute + (T1._second + T2._second) / 60) / 60;
}

void Time::showTime(void)
{
    std::cout << this->_hour << ":" << this->_minute << ":" << this->_second;
}

int main(void)
{
    Time T1, T2, T3;

    {
        int hour, minute, second;

        std::cout << "Hours: ";
        std::cin >> hour;
        std::cout << "Minutes: ";
        std::cin >> minute;
        std::cout << "Seconds: ";
        std::cin >> second;

        T1.setTime(hour, minute, second);

        std::cout << std::endl;

        std::cout << "Hours: ";
        std::cin >> hour;
        std::cout << "Minutes: ";
        std::cin >> minute;
        std::cout << "Seconds: ";
        std::cin >> second;

        T2.setTime(hour, minute, second);
    }

    std::cout << std::endl;

    T3.addTime(T1, T2);

    std::cout << "Total time: ";
    T3.showTime();
    std::cout << std::endl;

    return 0;
}