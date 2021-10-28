#include <iostream>

using namespace std;

class Calculator
{
    void input(void)
    {
        cout << "Input 2 integers >> ";
        cin >> a >> b;
    }

protected:
    int a, b;
    virtual int calc(int a, int b) { return 0; }

public:
    void run(void)
    {
        input();
        cout << "Answer : " << calc(a, b) << endl;
    }
};

class Adder : public Calculator
{
protected:
    virtual int calc(int a, int b)
    {
        return a + b;
    }
};

class Subtractor : public Calculator
{
protected:
    virtual int calc(int a, int b)
    {
        return a + b;
    }
};

int main(void)
{
    Calculator *adder = new Adder;
    Calculator *subtractor = new Subtractor;
    
    adder->run();
    subtractor->run();

    return 0;
}