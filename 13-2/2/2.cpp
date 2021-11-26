#include <iostream>

class MyArray
{
private:
    int *my_array;
    int maxSize;

public:
    MyArray(int size);
    ~MyArray();

    int &operator[](const int& index);
};

class MyException
{
public:
    void report(void);
};

MyArray::MyArray(int size)
: maxSize(size)
{
    this->my_array = new int[this->maxSize];
}
MyArray::~MyArray()
{
    delete[] this->my_array;
}

int &MyArray::operator[](const int& index)
{
    if(index < 0 || index >= this->maxSize)
    {
        throw MyException();
    }

    return this->my_array[index];
}

void MyException::report(void)
{
    std::cerr << "Exception report" << std::endl;
}

int main(void)
{
    MyArray myArray(5);

    try
    {
        myArray[20];
    }
    catch(MyException &e)
    {
        e.report();
    }
    
    return 0;
}