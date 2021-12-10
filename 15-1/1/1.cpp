#include <vector>
#include <numeric>
#include <cmath>

int sum_odd(const std::vector<int>& v)
{
    return std::accumulate(v.cbegin(), v.cend(), 0, [](const int &sum, const int &n)->int{return (n % 2 == 1) ? (sum + n) : sum;});
}

int sum_even(const std::vector<int>& v)
{
    return std::accumulate(v.cbegin(), v.cend(), 0, [](const int &sum, const int &n)->int{return (n % 2 == 0) ? (sum + n) : sum;});
}

int sum_prime(const std::vector<int>& v)
{
    return std::accumulate(v.cbegin(), v.cend(), 0, [](const int &sum, const int &n)->int{int rt = std::sqrt(n);if(n <= 1) return sum; for(int i = 2; i <= rt; i++) if(n % i == 0) return sum; return sum + n;});
}