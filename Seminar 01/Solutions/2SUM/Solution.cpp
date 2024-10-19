#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, targetSum;
    cin >> n >> targetSum;
    
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; i++)
    {
        int input = 0;
        cin >> input;
        arr.push_back({input, i});
    }
    
    sort(arr.begin(), arr.end());
    
    int begin = 0;
    int end = n - 1;
    
    while(begin != end)
    {
        int sum = arr[begin].first + arr[end].first;
        
        if(sum == targetSum)
        {
            cout << arr[begin].second << ' ' << arr[end].second;
            return 0;
        }
        else if(sum > targetSum)
        {
            end--;
        }
        else
        {
            begin++;
        }
    }
}