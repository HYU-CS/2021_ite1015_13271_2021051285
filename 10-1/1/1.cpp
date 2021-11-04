#include <iostream>

class RangeCalc
{
    virtual void read(void) = 0;
    virtual void write(void) const = 0;
    virtual int calculate(void) = 0;

protected:
    int result;

public:
    void run(void)
    {
        read();
        result = calculate();
        write();
    }
    virtual ~RangeCalc() { }  // as class with virtual function have virtual destructor
};

class RangeAdder: public RangeCalc
{
    int range[2];

    void read(void);
    void write(void) const;
    int calculate(void);
};

void RangeAdder::read(void)
{
    std::cout << "Add Ints In Range: Sum all integer values between first and second input." << std::endl;
    std::cout << "Insert two integers >> ";

    std::cin >> range[0] >> range[1];
}

void RangeAdder::write(void) const
{
    std::cout << "The result is " << this->result << std::endl;
}

int RangeAdder::calculate(void)
{
    if(this->range[0] > this->range[1])
    {
        int temp = this->range[0];
        this->range[0] = this->range[1];
        this->range[1] = temp;
    }

    return (this->range[1] - this->range[0] + 1) * (this->range[0] + this->range[1]) / 2;
}

class RangeMultiplier: public RangeCalc
{
    int range[2];

    void read(void);
    void write(void) const;
    int calculate(void);
};

void RangeMultiplier::read(void)
{
    std::cout << "Add Ints In Range: Multiply all integer values between first and second input." << std::endl;
    std::cout << "Insert two integers >> ";

    std::cin >> range[0] >> range[1];
}

void RangeMultiplier::write(void) const
{
    std::cout << "The result is " << this->result << std::endl;
}

int RangeMultiplier::calculate(void)
{
    int result = 1;

    if(this->range[0] > this->range[1])
    {
        int temp = this->range[0];
        this->range[0] = this->range[1];
        this->range[1] = temp;
    }

    for(int i = this->range[0]; i <= this->range[1]; i++)
    {
        result *= i;
    }

    return result;
}

int main(void)
{
    RangeCalc *adder = new RangeAdder;
    adder->run();

    RangeCalc *multiplier = new RangeMultiplier;
    multiplier->run();

    delete adder;
    delete multiplier;

    return 0;
}