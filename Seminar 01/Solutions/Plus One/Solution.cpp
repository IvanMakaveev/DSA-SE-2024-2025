#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


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
    
    int i = n - 1;
    for(; i >= 0; i--)
    {
        arr[i]++;
        if(arr[i] == 10)
        {
            arr[i] = 0;
        }
        else
        {
            break;
        }
    }
    
    if(i == -1)
    {
        arr.insert(arr.begin(), 1);
    }
    
    for(size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }
}