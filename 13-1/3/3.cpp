#include <iostream>
#include <string>
#include <exception>

class InvalidRatioException : public std::exception
{
    virtual const char* what() const noexcept
    {
        return "Invalid ratio";
    }  
};

class NegativeValueException : public std::exception
{
    virtual const char* what() const noexcept
    {
        return "Cannot convert negative value";
    }  
};

class Converter
{
protected:
    double _ratio;
    virtual double convert(double src) = 0;
    virtual std::string getSrcMetric(void) = 0;
    virtual std::string getDestMetric(void) = 0;

public:
    Converter(double ratio): _ratio(ratio) { }
    void run(void)
    {
        double src;
        std::cout << "Convert" << this->getSrcMetric() << " to" << getDestMetric() << std::endl;
        std::cout << "Input" << this->getSrcMetric() << " : ";

        std::cin >> src;

        if(src < 0.0)
        {
            throw NegativeValueException();
        }

        std::cout << "Result : " << this->convert(src) << getDestMetric() << std::endl;
    }
};

class DollarToWon : public Converter
{
public:
    DollarToWon(double ratio = 0.0) : Converter(ratio)
    {
        if(ratio <= 0.0)
        {
            throw InvalidRatioException();
        }
    }

protected:
    double convert(double src) {return src * _ratio;}
    std::string getSrcMetric(void) {return " dollar";}
    std::string getDestMetric(void) {return " won";}
};

int main(void)
{
    try
    {
        DollarToWon dtw(1176.5); 
        dtw.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception! " << e.what() << std::endl;
    }
    
}