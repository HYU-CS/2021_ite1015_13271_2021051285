#include <iostream>

class SimpleTest
{
protected:
    int num;

public:
    SimpleTest(int num);
    void showTest(void);
    void showTest(void) const;
    void changeNum(int num);
};

SimpleTest::SimpleTest(int num)
: num(num) { }

void SimpleTest::showTest(void)
{
    std::cout << "Call number : " << this->num << std::endl;
}

void SimpleTest::showTest(void) const
{
    std::cout << "Call const number : " << this->num << std::endl;
}

void SimpleTest::changeNum(int num)
{
    this->num = num;
}

int main(void)
{ 
    int num_1,num_2;

    std::cout << "Number_1 : ";
    std::cin >> num_1;
    std::cout << "Number_2 : ";
    std::cin >> num_2;

    SimpleTest simpleTest(num_1);
    const SimpleTest constSimpleTest(num_2);

    std::cout << "Change num_1 : ";
    std::cin >> num_1;
    simpleTest.changeNum(num_1);

    simpleTest.showTest();
    constSimpleTest.showTest();

    return 0; 
}