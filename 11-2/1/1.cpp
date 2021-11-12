#include <iostream>

class MyInt;
class MyDouble;

class MyInt
{
private:
    int num;

public:
    MyInt(int num);
    int getNum(void) const;
    void show(void);

    MyInt operator+(const MyInt &rhs);
    MyInt operator-(const MyInt &rhs);
    MyInt operator*(const MyInt &rhs);
    MyInt operator/(const MyInt &rhs);

    MyDouble operator+(const MyDouble &rhs);
    MyDouble operator-(const MyDouble &rhs);
    MyDouble operator*(const MyDouble &rhs);
    MyDouble operator/(const MyDouble &rhs);
};

class MyDouble
{
private:
    double num;

public:
    MyDouble(double num);
    double getNum(void) const;
    void show(void);

    MyDouble operator+(const MyInt &rhs);
    MyDouble operator-(const MyInt &rhs);
    MyDouble operator*(const MyInt &rhs);
    MyDouble operator/(const MyInt &rhs);

    MyDouble operator+(const MyDouble &rhs);
    MyDouble operator-(const MyDouble &rhs);
    MyDouble operator*(const MyDouble &rhs);
    MyDouble operator/(const MyDouble &rhs);
};

MyInt::MyInt(int num)
: num(num) { }

int MyInt::getNum(void) const
{
    return this->num;
}

void MyInt::show(void)
{
    std::cout << num << std::endl;
}


MyInt MyInt::operator+(const MyInt &rhs)
{
    MyInt temp(this->getNum() + rhs.getNum());
    return temp;
}
MyInt MyInt::operator-(const MyInt &rhs)
{
    MyInt temp(this->getNum() - rhs.getNum());
    return temp;
}
MyInt MyInt::operator*(const MyInt &rhs)
{
    MyInt temp(this->getNum() * rhs.getNum());
    return temp;
}
MyInt MyInt::operator/(const MyInt &rhs)
{
    MyInt temp(this->getNum() / rhs.getNum());
    return temp;
}

MyDouble MyInt::operator+(const MyDouble &rhs)
{
    MyDouble temp(this->getNum() + rhs.getNum());
    return temp;
}
MyDouble MyInt::operator-(const MyDouble &rhs)
{
    MyDouble temp(this->getNum() - rhs.getNum());
    return temp;
}
MyDouble MyInt::operator*(const MyDouble &rhs)
{
    MyDouble temp(this->getNum() * rhs.getNum());
    return temp;
}
MyDouble MyInt::operator/(const MyDouble &rhs)
{
    MyDouble temp(this->getNum() / rhs.getNum());
    return temp;
}

MyDouble::MyDouble(double num)
: num(num) { }

double MyDouble::getNum(void) const
{
    return this->num;
}

void MyDouble::show(void)
{
    std::cout << num << std::endl;
}


MyDouble MyDouble::operator+(const MyInt &rhs)
{
    MyDouble temp(this->getNum() + rhs.getNum());
    return temp;
}
MyDouble MyDouble::operator-(const MyInt &rhs)
{
    MyDouble temp(this->getNum() - rhs.getNum());
    return temp;
}
MyDouble MyDouble::operator*(const MyInt &rhs)
{
    MyDouble temp(this->getNum() * rhs.getNum());
    return temp;
}
MyDouble MyDouble::operator/(const MyInt &rhs)
{
    MyDouble temp(this->getNum() / rhs.getNum());
    return temp;
}

MyDouble MyDouble::operator+(const MyDouble &rhs)
{
    MyDouble temp(this->getNum() + rhs.getNum());
    return temp;
}
MyDouble MyDouble::operator-(const MyDouble &rhs)
{
    MyDouble temp(this->getNum() - rhs.getNum());
    return temp;
}
MyDouble MyDouble::operator*(const MyDouble &rhs)
{
    MyDouble temp(this->getNum() * rhs.getNum());
    return temp;
}
MyDouble MyDouble::operator/(const MyDouble &rhs)
{
    MyDouble temp(this->getNum() / rhs.getNum());
    return temp;
}


int main(void)
{
    MyInt intNum_1(10), intNum_2(20);
    MyDouble doubleNum_1(100.0), doubleNum_2(70.0);

    (intNum_1 * intNum_2).show();
    (doubleNum_2 - intNum_1).show();
    (intNum_2 + doubleNum_1).show();
    (doubleNum_1 / doubleNum_2).show();

    return 0;
}