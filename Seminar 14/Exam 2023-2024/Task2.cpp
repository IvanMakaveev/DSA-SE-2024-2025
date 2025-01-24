#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int size;
    cin >> size;
    
    vector<int> arr(size);
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    
    int queries;
    cin >> queries;
    
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < queries; i++)
    {
        int query;
        cin >> query;
        
        if(size == 0 || size == 1)
        {
            cout << -1 << endl;
        }
        
        auto currUpperToTheLeft = lower_bound(arr.begin(), arr.end(), query);
        
        if(currUpperToTheLeft == arr.end())
        {
                cout << -1 << endl;
                continue;
        }

        
        if(currUpperToTheLeft != arr.begin())
        {
            auto currCloserToTheRight = (--currUpperToTheLeft);
            ++currUpperToTheLeft;
            
            if(abs(*currUpperToTheLeft - query) <= abs(*currCloserToTheRight - query))
            {
                auto result = (++currUpperToTheLeft);
                if(result == arr.end())
                {
                    cout << -1 << endl;
                    continue;
                }
                cout << *result << endl;
            }
            else
            {
                auto result = (++currCloserToTheRight);
                cout << *result << endl;
            }
        }
        else
        {
                auto result = (++currUpperToTheLeft);
                if(result == arr.end())
                {
                    cout << -1 << endl;
                    continue;
                }
                cout << *result << endl;
        }

    }
}