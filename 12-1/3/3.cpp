#include <iostream>
#include <string>

template <class T>
class Calculator
{
private:
    T num1, num2;

public:
    Calculator(T n1, T n2)
    {
        num1 = n1;
        num2 = n2;
    }
    void Result(void)
    {
        std::cout << "Numbers: " << this->num1 << " and " << this->num2 << std::endl;
        std::cout << this->num1 << " + " << this->num2 << " = " << this->num1 + this->num2 << std::endl;
        std::cout << this->num1 << " - " << this->num2 << " = " << this->num1 - this->num2 << std::endl;
        std::cout << this->num1 << " * " << this->num2 << " = " << this->num1 * this->num2 << std::endl;
        std::cout << this->num1 << " / " << this->num2 << " = " << this->num1 / this->num2 << std::endl;
    }
};

int main(void)
{
    int n1;
    float n2;

    std::cout << "Input 2 numbers. 1st an Integer, 2nd a Rational number" << std::endl;

    std::cin >> n1;
    std::cin >> n2;

    Calculator<double> doubleCalc(n1, n2);

    std::cout << std::endl << "Results:" << std::endl;
    doubleCalc.Result();

    return 0;
}