#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>

template <typename T>
void mergeContainers(T &container1, const T &container2)
{
    for(typename T::const_iterator it = container2.begin(); it != container2.end(); it++)
    {
        container1.push_back(*it);
    }
}

template <typename T>
void mergeContainers(std::set<T> &container1, const std::set<T> &container2)
{
    for(typename std::set<T>::const_iterator it = container2.begin(); it != container2.end(); it++)
    {
        container1.insert(*it);
    }
}

template <typename KT, typename VT>
void mergeContainers(std::map<KT, VT> &container1, const std::map<KT, VT> &container2)
{
    for(typename std::map<KT, VT>::const_iterator it = container2.begin(); it != container2.end(); it++)
    {
        container1.insert(*it);
    }
}