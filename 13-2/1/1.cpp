#include <iostream>

class Container
{
public:
    virtual ~Container() { }
    virtual void push_back(int value) = 0;
    virtual void pop_back(void) = 0;
    virtual int getVectorArr(size_t index) = 0;
    virtual void setVectorArr(size_t index, int value) = 0;
};

class MyVector : public Container
{
private:
    int *data;
    size_t size;
    size_t capacity;

public:
    MyVector(void);
    MyVector(size_t size);
    ~MyVector();

    void push_back(int value);
    void pop_back(void);
    int getVectorArr(size_t index);
    void setVectorArr(size_t index, int value);
};

MyVector::MyVector(void)
: MyVector(0) { }
MyVector::MyVector(size_t size)
: size(0), capacity(size)
{
    if(this->capacity == 0)
    {
        this->capacity = 1;
    }

    this->data = new int[this->capacity];
}
MyVector::~MyVector()
{
    delete[] data;
}

void MyVector::push_back(int value)
{
    if(this->size == this->capacity)
    {
        int *temp = new int[this->capacity * 2];

        for(size_t i = 0; i < this->capacity; i++)
        {
            temp[i] = this->data[i];
        }

        delete[] this->data;

        this->data = temp;
        this->capacity *= 2;
    }
    
    this->data[this->size++] = value; 
}
void MyVector::pop_back(void)
{
    if(this->size == 0)
    {
        std::cerr << std::endl;
        throw "nothing to pop";
    }

    std::cout << this->data[--this->size] << " ";
}
int MyVector::getVectorArr(size_t index)
{
    if(index < 0 || index >= this->size)
    {
        throw "out of range error";
    }

    return this->data[index];
}
void MyVector::setVectorArr(size_t index, int value)
{
    if(index < 0 || index >= this->size)
    {
        throw "out of range error";
    }

    this->data[index] = value; 
}

int main(void)
{
    Container *v = new MyVector(5);
    for(int i = 0; i < 10; i++)
    {
        v->push_back(i * 10);
    }
    
    try
    {
        v->setVectorArr(11, 20);
        std::cout << v->getVectorArr(10) << std::endl;
    }
    catch(const char *msg)
    {
        std::cerr << msg << std::endl;
    }
    for(int i = 0; i < 11; i++)
    {
        try
        {
            v->pop_back();
        }
        catch(const char *msg)
        {
            std::cerr << msg << std::endl;
        }
        
    }
    
    std::cout << std::endl;
    
    return 0;
}