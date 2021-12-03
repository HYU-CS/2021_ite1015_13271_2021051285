#include <iostream>
#include <string>
#include <memory>

class CleaningUp
{
private:
    std::string word;

public:
    CleaningUp(const std::string &str)
    {
        this->word = str;
        std::cout << "Created word: " << word << std::endl;
    }
    ~CleaningUp()
    {
        std::cout << "Destroyed word: " << word << std::endl;
    }
};

void ThrowsException(void)
{
    CleaningUp hi("HI");
    std::unique_ptr<int> pi(new int);
    throw "Exception";
    pi.reset();
    CleaningUp bye("BYE");
}

int main(void)
{
    try
    {
        ThrowsException();
    }
    catch(const char *e)
    {
        std::cerr << "Caught an exception" << std::endl;
    }
    
    return 0;
}