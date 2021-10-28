#include <iostream>
#include <string>

using namespace std;

class Converter { 
protected: 
    double _ratio; 
    virtual double convert(double src) { return 0; } 
    virtual string getSrcMetric() { return ""; } 
    virtual string getDestMetric() { return ""; } 
 
public: 
    Converter(double ratio): _ratio(ratio) { } 
    double getRatio() const { return _ratio; } 
    void run() { 
        double src; 
        cout << "Convert " <<getSrcMetric() << " to " << getDestMetric() << endl; 
        cout << "Input " <<getSrcMetric() << " : "; 
        cin >> src; 
        cout << "Result : " <<convert(src) << getDestMetric() << endl; 
    } 
};

class KmToMile : public Converter
{
protected:
    virtual double convert(double src)
    {
        return src * getRatio();
    }

    virtual string getSrcMetric() { return "km"; }
    virtual string getDestMetric() { return "mile"; }

public:
    KmToMile(double ratio): Converter(ratio) { }
};

int main(void)
{ 
    Converter *ktm = new KmToMile(0.621371); 
    ktm->run();
}