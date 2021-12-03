#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <algorithm>
#include <cmath>

template <class _Sqt, class _Vt = _Sqt::value_type>
void print_stats(const _Sqt& sq)
{
    _Vt min, max;
    double median = 0.0, average = 0.0;
    double variance = 0.0, standardDeviation = 0.0;

    std::vector<_Vt> newSq(sq.begin(), sq.end());

    size_t size = 0;

    min = max = sq.front();

    for(auto &&it : sq)
    {
        if(min > it)
        {
            min = it;
        }
        if(max < it)
        {
            max = it;
        }
        average += it;
        size++;
    }

    average /= size;

    for(auto &&it : sq)
    {
        variance += (it - average) * (it - average);
    }
    variance /= size;

    standardDeviation = ::sqrt(variance);
    
    std::sort(newSq.begin(), newSq.end());

    size_t i = 0;
    for(auto &&it : newSq)
    {
        if(i == (size - 1) / 2)
        {
            median += it / 2.0;
        }
        if(i == size / 2)
        {
            median += it / 2.0;
        }
        i++;
    }

    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Median: " << median << std::endl;
    std::cout << "Average: " << average << std::endl;
    std::cout << "Variance: " << variance << std::endl;
    std::cout << "Standard Deviation: " << standardDeviation << std::endl;
}

int main(void)
{
    std::list<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    print_stats(a);
}
