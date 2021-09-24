#include <iostream>

int N;

void max(const int *numBox, int *max);
void min(const int *numBox, int *min);
void average(const int *numBox, double *ave);

int main(void)
{
    int ma, mi;
    double ave;

    std::cin >> N;

    if(N <= 0)
    {
        return 0;
    }

    int *numArr = new int[N];
    for(size_t i = 0; i < N; i++)
    {
        std::cin >> numArr[i];
    }

    max(numArr, &ma);
    min(numArr, &mi);
    average(numArr, &ave);

    std::cout << "Max: " << ma << std::endl;
    std::cout << "Min: " << mi << std::endl;
    std::cout << "Average: " << ave << std::endl;

    delete[] numArr;

    return 0;
}

void max(const int *numBox, int *max)
{
    if(N <= 0)
    {
        return;
    }

    *max = numBox[0];

    for(size_t i = 1; i < N; i++)
    {
        if(numBox[i] > *max)
        {
            *max = numBox[i];
        }
    }

    return;
}

void min(const int *numBox, int *min)
{
    if(N <= 0)
    {
        return;
    }

    *min = numBox[0];

    for(size_t i = 1; i < N; i++)
    {
        if(numBox[i] < *min)
        {
            *min = numBox[i];
        }
    }

    return;
}

void average(const int *numBox, double *ave)
{
    if(N <= 0)
    {
        return;
    }

    int sum = 0;

    for(size_t i = 0; i < N; i++)
    {
        sum += numBox[i];
    }

    *ave = (double)sum / N;

    return;
}
