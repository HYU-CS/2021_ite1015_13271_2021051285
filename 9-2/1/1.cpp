#include <iostream>

const size_t MEMORY_UNIT = 5;

class Container
{ 
public: 
    virtual void push(int value) { }
    virtual int pop(void) { return 0; }
    virtual bool isEmpty(void) { return false; }
    virtual ~Container() { }
};

class MyStack : public Container
{
protected:
    int *arr;
    size_t size;
    size_t capacity;
public:
    MyStack(void);
    MyStack(size_t init_cap);
    virtual void push(int value);
    virtual int pop(void);
    virtual bool isEmpty(void);
    virtual ~MyStack();
};

class MyQueue : public Container
{
protected:
    int *arr;
    size_t size;
    size_t capacity;
public:
    MyQueue(void);
    MyQueue(size_t init_cap);
    virtual void push(int value);
    virtual int pop(void);
    virtual bool isEmpty(void);
    virtual ~MyQueue();
};

MyStack::MyStack(void)
: size(0), capacity(1)
{
    this->arr = new int[1];
}

MyStack::MyStack(size_t init_cap)
: size(0), capacity(init_cap)
{
    if(this->capacity == 0)
    {
        this->capacity++;
    }

    this->arr = new int[this->capacity];
}

void MyStack::push(int value)
{
    if(this->size == this->capacity)
    {
        int *temp = new int[this->capacity * 2];

        for(size_t i = 0; i < this->capacity; i++)
        {
            temp[i] = this->arr[i];
        }

        delete[] this->arr;
        this->arr = temp;

        this->capacity *= 2;
    }

    this->arr[this->size++] = value;
}

int MyStack::pop(void)
{
    return this->arr[--this->size];
}

bool MyStack::isEmpty(void)
{
    return (this->size == 0);
}

MyStack::~MyStack()
{
    delete[] this->arr;
}

MyQueue::MyQueue(void)
: size(0), capacity(1)
{
    this->arr = new int[1];
}

MyQueue::MyQueue(size_t init_cap)
: size(0), capacity(init_cap)
{
    if(this->capacity == 0)
    {
        this->capacity++;
    }
    this->arr = new int[this->capacity];
}

void MyQueue::push(int value)
{
    if(this->size == this->capacity)
    {
        int *temp = new int[this->capacity * 2];

        for(size_t i = 0; i < this->capacity; i++)
        {
            temp[i] = this->arr[i];
        }

        delete[] this->arr;
        this->arr = temp;

        this->capacity *= 2;
    }

    this->arr[this->size++] = value;
}

int MyQueue::pop(void)
{
    int result = this->arr[0];

    this->size--;

    for(size_t i = 0; i < this->size; i++)
    {
        this->arr[i] = this->arr[i + 1];
    }

    return result;
}

bool MyQueue::isEmpty(void)
{
    return (this->size == 0);
}

MyQueue::~MyQueue()
{
    delete[] this->arr;
}

int main(void)
{
    Container *myStack = new MyStack(5);
    Container *myQueue = new MyQueue(5);

    for(int i = 0; i < 10; i++)
    {
        myStack->push(i * 10);
        myQueue->push(i * 10);
    }

    for(int i = 0; i < 10; i++)
    {
        int n = myStack->pop();
        std::cout << n << " ";
    }
    std::cout << std::endl;

    for(int i = 0; i < 10; i++)
    { 
        int n = myQueue->pop(); 
        std::cout << n << " "; 
    } 
    std::cout << std::endl;

    delete myStack; 
    delete myQueue; 
}