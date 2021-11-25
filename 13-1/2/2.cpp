#include <iostream>
#include <exception>

class InvalidInputException : public std::exception
{
    virtual const char* what() const noexcept
    {
        return "Negative value input exception";
    }
};
class DivideByZeroException : public std::exception
{
    virtual const char* what() const noexcept
    {
        return "Divide by zero exception";
    }
};

double divide(int dividend, int divisor)
{
    if(dividend < 0 || divisor < 0)
    {
        throw InvalidInputException();
    }
    else if(divisor == 0)
    {
        throw DivideByZeroException();
    }

    return dividend / divisor;
}

int main(void)
{
    int x, y;
    double result;
    try
    {
        std::cout << "Division. Input two numbers >> ";
        std::cin >> x >> y;

        result = divide(x, y);
        std::cout << result << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}