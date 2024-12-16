#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct PersonTime 
{
    unsigned int arrival;
    unsigned int departure;
    unsigned int index;
    unsigned int seat = 0;

    PersonTime(unsigned int arrival, unsigned int departure, unsigned int index)
    {
        this->arrival = arrival;
        this->departure = departure;
        this->index = index;
    }

    bool operator<(const PersonTime& other) const
    {
        return this->departure > other.departure;
    }
};

bool compareArrivalTimes(const PersonTime& first, const PersonTime& second)
{
    return first.arrival < second.arrival;
}

int main() 
{
    unsigned int totalPeople = 0;
    cin >> totalPeople;

    vector<PersonTime> peopleList;
    set<unsigned int> freeIndecies;
    for (size_t i = 0; i < totalPeople; i++)
    {
        unsigned int arrival = 0, departure = 0;
        cin >> arrival >> departure;

        peopleList.push_back(PersonTime(arrival, departure, i));
        freeIndecies.insert(i);
    }

    unsigned int targetIndex = 0;
    cin >> targetIndex;

    sort(peopleList.begin(), peopleList.end(), compareArrivalTimes);

    priority_queue<PersonTime> pq;
    for (size_t i = 0; i < totalPeople; i++)
    {
        while (!pq.empty() && pq.top().departure <= peopleList[i].arrival)
        {
            freeIndecies.insert(pq.top().seat);
            pq.pop();
        }

        peopleList[i].seat = *freeIndecies.begin();
        freeIndecies.erase(freeIndecies.begin());
        pq.push(peopleList[i]);

        if (peopleList[i].index == targetIndex)
        {
            cout << peopleList[i].seat;
            break;
        }
    }
}