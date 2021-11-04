#include <iostream>
#include <string>

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
        std::cout << "Convert" << getSrcMetric() << " to"<< getDestMetric() << std::endl;
        std::cout << "Input" << getSrcMetric() << " : ";
        std::cin >> src;
        std::cout << "Result : " << convert(src) << getDestMetric() << std::endl;
    }
    virtual ~Converter() { }
};

class DollarToWon: public Converter
{
protected:
    virtual double convert(double src);
    virtual std::string getSrcMetric(void);
    virtual std::string getDestMetric(void);

public:
    DollarToWon(double ratio): Converter(ratio) { }
};

double DollarToWon::convert(double src)
{
    return src * this->_ratio;
}

std::string DollarToWon::getSrcMetric(void)
{
    return " dollar";
}

std::string DollarToWon::getDestMetric(void)
{
    return " won";
}

int main(void)
{ 
    DollarToWon dtw(1176.5); 
    dtw.run(); 
}