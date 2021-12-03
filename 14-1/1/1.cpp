#include <iostream>

int add_int(int lhs, int rhs)
{
    return lhs + rhs;
}

double add_double(int lhs, int rhs)
{
    return lhs + rhs;
}

template <class _Lt, class _Rt>
auto add_any(_Lt lhs, _Rt rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}