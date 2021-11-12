#include <iostream>

class HardwareA;
class HardwareB;

class HardwareA
{
private:
    int specification;

public:
    HardwareA(int specification);
    void setSpecification(int specification);

    friend void show(const HardwareA &hwA, const HardwareB &hwB);
    friend void exchange(HardwareA &hwA, HardwareB &hwB);
    friend void exchange(HardwareA *hwA, HardwareB *hwB);
};

class HardwareB
{
private:
    int specification;

public:
    HardwareB(int specification);
    void setSpecification(int specification);

    friend void show(const HardwareA &hwA, const HardwareB &hwB);
    friend void exchange(HardwareA &hwA, HardwareB &hwB);
    friend void exchange(HardwareA *hwA, HardwareB *hwB);
};

HardwareA::HardwareA(int specification)
: specification(specification) { };

void HardwareA::setSpecification(int specification)
{
    this->specification = specification;
}

HardwareB::HardwareB(int specification)
: specification(specification) { };

void HardwareB::setSpecification(int specification)
{
    this->specification = specification;
}

void show(const HardwareA &hwA, const HardwareB &hwB)
{
    std::cout << "HardwareA, HardwareB : " << hwA.specification << " , " << hwB.specification << std::endl;
}

void exchange(HardwareA &hwA, HardwareB &hwB)
{
    int temp = hwA.specification;
    hwA.setSpecification(hwB.specification);
    hwB.setSpecification(temp);
}

void exchange(HardwareA *hwA, HardwareB *hwB)
{
    int temp = hwA->specification;
    hwA->setSpecification(hwB->specification);
    hwB->setSpecification(temp);
}

int main(void)
{
    HardwareA hardwareA(10);
    HardwareB hardwareB(20);

    show(hardwareA, hardwareB);
    exchange(hardwareA, hardwareB);
    show(hardwareA, hardwareB);
    exchange(&hardwareA, &hardwareB);
    show(hardwareA, hardwareB);

    return 0;
}