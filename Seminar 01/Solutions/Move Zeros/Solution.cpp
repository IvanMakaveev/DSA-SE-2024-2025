#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Notes: A solution can be made without ever storing the data in a Vector
int main() {
    int n = 0;
    cin >> n;
    vector<int> arr;
    
    for(int i = 0; i < n; i++)
    {
        int input = 0;
        cin >> input;
        arr.push_back(input);
    }
    
    int count = 0;
    for(int i = n-1; i >= 0; i--)
    {
        if(arr[i] == 0)
        {
            count++;
            arr.erase(arr.begin() + i);
        }
    }
    
    for(int i = 0; i < count; i++)
    {
        arr.push_back(0);
    }
    
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}