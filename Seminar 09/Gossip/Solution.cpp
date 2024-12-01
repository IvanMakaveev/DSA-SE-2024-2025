#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() 
{
    unsigned int count = 0;
    cin >> count;


    unordered_map<unsigned int, unsigned int> map;
    unsigned int result = 0;
    for (size_t i = 0; i < count; i++)
    {
        unsigned int current = 0;
        cin >> current;
        
        if (map.count(current) == 0)
        {
            map.insert({ current, i });
            continue;
        }
        else
        {
            unsigned int currentDistance = i - map[current];

            if (result == 0 || currentDistance < result)
            {
                result = currentDistance;
            }

            map[current] = i;
        }
    }

    cout << result;
}