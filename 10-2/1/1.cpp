#include <iostream>
#include <cstdlib>

class Container
{
public:
    virtual void push_back(int value) = 0;
    virtual void pop_back(void) = 0;
    virtual int front(void) const = 0;
    virtual int back(void) const = 0;
    virtual int getVectorArr(int index) const = 0;
    virtual void setVectorArr(int index, int value) = 0;

    virtual ~Container();
};


Container::~Container() { }



class MyVector: public Container
{
protected:
    int *arr;
    size_t size;
    size_t capacity;

public:
    MyVector(void);
    MyVector(size_t initial_size);

    ~MyVector();

    void push_back(int value);
    void pop_back(void);

    int front(void) const;
    int back(void) const;

    int getVectorArr(int index) const;
    void setVectorArr(int index, int value);
};


MyVector::MyVector(void)
: size(0), capacity(1)
{
    this->arr = new int[capacity];
}

MyVector::MyVector(size_t initial_size)
: size(0), capacity(initial_size)
{
    this->arr = new int[capacity];
}


MyVector::~MyVector()
{
    delete[] this->arr;
}


void MyVector::push_back(int value)
{
    if(this->size == this->capacity)
    {
        int *temp = new int[this->capacity * 2];

        int *arr_it = this->arr;
        int *temp_it = temp;

        while(arr_it != this->arr + this->capacity)
        {
            *temp_it++ = *arr_it++;
        }

        delete[] this->arr;
        this->arr = temp;

        this->capacity *= 2;
    }

    this->arr[this->size++] = value;
}

void MyVector::pop_back(void)
{
    if(this->size == 0)
    {
        std::cerr << "error" << std::endl;
    }
    else
    {
        std::cout << this->arr[--this->size] << " ";
    }
}

int MyVector::front(void) const
{
    return this->arr[0];
}

int MyVector::back(void) const
{
    return this->arr[this->size - 1];
}

int MyVector::getVectorArr(int index) const
{
    if(index < 0 || index >= this->size)
    {
        std::cerr << "error" << std::endl;
        ::exit(EXIT_FAILURE);
    }
    else
    {
        return this->arr[index];
    }
}

void MyVector::setVectorArr(int index, int value)
{
    if(index < 0 || index >= this->size)
    {
        std::cerr << "error" << std::endl;
    }
    else
    {
        this->arr[index] = value;
    }
}

int main(void)
{
    Container *v = new MyVector(5);
    for(int i = 0; i < 10; i++)
    {
        v->push_back(i * 10);
    }

    std::cout << v->front() << std::endl;
    std::cout << v->back() << std::endl;
    std::cout << v->getVectorArr(3) << std::endl;
    v->setVectorArr(3, 20);
    std::cout << v->getVectorArr(3) << std::endl;

    for(int j = 0; j < 10; j++)
    {
        v->pop_back();
    }

    std::cout << std::endl;

    return 0;
}