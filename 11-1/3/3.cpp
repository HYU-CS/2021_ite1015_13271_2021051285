#include <iostream>
#include <algorithm>

class SortedArray
{
private:
    int size;
    int *p;
    void sort();

public:
    SortedArray();
    SortedArray(const SortedArray& src);
    SortedArray(int p[], int size);
    ~SortedArray();
    SortedArray operator+(const SortedArray& op2);
    SortedArray& operator=(const SortedArray& op2);
    void show();
};

void SortedArray::sort()
{
    std::sort(p, p + size);
}

SortedArray::SortedArray()
: size(0), p(new int[0]) { }

SortedArray::SortedArray(const SortedArray& src)
: size(src.size), p(new int[src.size])
{
    for(int i = 0; i < this->size; i++)
    {
        this->p[i] = src.p[i];
    }

    this->sort();
}

SortedArray::SortedArray(int p[], int size)
: size(size), p(new int[size])
{
    for(int i = 0; i < this->size; i++)
    {
        this->p[i] = p[i];
    }

    this->sort();
}

SortedArray::~SortedArray()
{
    delete[] p;
}

SortedArray SortedArray::operator+(const SortedArray& op2)
{
    int size = this->size + op2.size;
    int *p = new int[size];
    
    for(int i = 0; i < this->size; i++)
    {
        p[i] = this->p[i];
    }

    for(int i = 0; i < op2.size; i++)
    {
        p[this->size + i] = op2.p[i];
    }

    SortedArray sa(p, size);
    sa.sort();

    return sa;
}

SortedArray& SortedArray::operator=(const SortedArray& op2)
{
    int *p = new int[op2.size];

    for(int i = 0; i < op2.size; i++)
    {
        p[i] = op2.p[i];
    }

    delete[] this->p;
    
    this->size = op2.size;
    this->p = p;

    return *this;
}

void SortedArray::show()
{
    std::cout << "Array :";

    for(int i = 0; i < this->size; i++)
    {
        std::cout << ' ' << this->p[i];
    }

    std::cout << std::endl;
}

int main(void)
{
    int n[] = {2, 300, 68};
    int m[] = {100, 5, 6, 65};
    SortedArray a(n, 3), b(m, 4), c;

    c = a + b;

    a.show();
    b.show();
    c.show();

    return 0;
}