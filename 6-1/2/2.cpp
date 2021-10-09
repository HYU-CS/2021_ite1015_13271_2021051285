#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>

void mergeContainers(std::vector<int> &container1, const std::vector<int> &container2)
{
    for(std::vector<int>::const_iterator it = container2.begin(); it != container2.end(); it++)
    {
        container1.push_back(*it);
    }
}

void mergeContainers(std::list<int> &container1, const std::list<int> &container2)
{
    for(std::list<int>::const_iterator it = container2.begin(); it != container2.end(); it++)
    {
        container1.push_back(*it);
    }
}

void mergeContainers(std::deque<int> &container1, const std::deque<int> &container2)
{
    for(std::deque<int>::const_iterator it = container2.begin(); it != container2.end(); it++)
    {
        container1.push_back(*it);
    }
}

void mergeContainers(std::set<int> &container1, const std::set<int> &container2)
{
    for(std::set<int>::const_iterator it = container2.begin(); it != container2.end(); it++)
    {
        container1.insert(*it);
    }
}

void mergeContainers(std::map<int, int> &container1, const std::map<int, int> &container2)
{
    for(std::map<int, int>::const_iterator it = container2.begin(); it != container2.end(); it++)
    {
        container1.insert(*it);
    }
}