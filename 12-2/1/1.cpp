#include <iostream>
#include <cstdlib>

template <typename T>
class Container
{
public:
    Container(void) {}
    virtual void push(T value) = 0;
    virtual T pop(void) = 0;
    virtual bool isEmpty(void) = 0;
    virtual ~Container() {}
};

template <typename T>
class MyStack : public Container<T>
{
private:
    T *arr;
    size_t size;
    size_t capacity;

public:
    MyStack(void);
    MyStack(size_t size);

    ~MyStack();

    void push(T value);
    T pop(void);
    bool isEmpty(void);
};

template <typename T>
MyStack<T>::MyStack(void)
: size(0), capacity(1)
{
    this->arr = new T[this->capacity];
}
template <typename T>
MyStack<T>::MyStack(size_t size)
: size(size), capacity(size)
{
    this->arr = new T[this->capacity];
}

template <typename T>
MyStack<T>::~MyStack()
{
    delete this->arr;
}

template <typename T>
void MyStack<T>::push(T value)
{
    if(this->size == this->capacity)
    {
        T *temp = new T[this->capacity * 2];

        for(size_t i = 0; i < this->size; i++)
        {
            temp[i] = this->arr[i];
        }

        delete this->arr;
        this->arr = temp;
        this->capacity *= 2;
    }

    this->arr[this->size++] = value;
}
template <typename T>
T MyStack<T>::pop(void)
{
    if(this->isEmpty())
    {
        ::exit(EXIT_FAILURE);
    }
    else
    {
        return this->arr[--this->size];
    }
}
template <typename T>
bool MyStack<T>::isEmpty(void)
{
    return this->size == 0;
}

int main(void)
{
    Container<int> *myStack = new MyStack<int>(5);
    Container<double> *myStack_2 = new MyStack<double>(5);

    for(int i = 0; i < 10; i++)
    {
        myStack->push(i * 10);
        myStack_2->push(i * 10 + 0.5);
    }

    for(int i = 0; i < 10; i++)
    {
        std::cout << myStack->pop() << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < 10; i++)
    {
        std::cout << myStack_2->pop() << " ";
    }
    std::cout << std::endl;

    delete myStack;
    delete myStack_2;

    return 0;
}