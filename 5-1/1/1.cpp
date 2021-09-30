#include <iostream>

class Cat
{
private:
    int _age;
    int _weight;

public:
    Cat(int age, int weight);
    void showCatInfo(void);
};

Cat::Cat(int age, int weight)
: _age(age), _weight(weight) {}

void Cat::showCatInfo(void)
{
    if(this->_age > 1)
    {
        std::cout << "Age: " << this->_age << " months" << std::endl;
    }
    else
    {
        std::cout << "Age: " << this->_age << " month" << std::endl;
    }
    std::cout << "Weight: " << this->_weight << "kg" << std::endl;
}

int main(void)
{
    int age, weight;

    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Weight: ";
    std::cin >> weight;

    if(age < 0 || weight < 0)
    {
        return 0;
    }
    
    Cat cat(age, weight);

    cat.showCatInfo();

    return 0;
}