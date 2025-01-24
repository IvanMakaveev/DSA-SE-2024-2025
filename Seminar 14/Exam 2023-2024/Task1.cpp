#include <bits/stdc++.h>

using namespace std;

void solve(string s)
{
    vector<size_t> counts(26);
    for (size_t i = 0; i < s.size(); i++)
    {
        counts[s[i] - 'a']++;
    }

    unordered_map<size_t, size_t> map;    
    for (size_t i = 0; i < 26; i++)
    {
        if (counts[i] != 0)
        {
            map[counts[i]]++;
        }
    }
    
    if (map.size() > 2)
    {
        std::cout << 0 << endl;
        return;
    }

    if (map.size() == 1)
    {
        auto el = *map.begin();
        std::cout << (el.second == 1 || el.first == 1) << endl;
        return;
    }
    
    if (map.size() == 2)
    {
        auto first = *map.begin();
        auto second = *(++map.begin());
        if (first.first == second.first + 1 && first.second == 1)
        {
            std::cout << 1 << endl;
        }
        else if (first.first + 1 == second.first && second.second == 1)
        {
            std::cout << 1 << endl;
        }
        else if ((first.first == 1 && first.second == 1) || (second.first == 1 && second.second == 1))
        {
            std::cout << 1 << endl;
        }
        else
        {
            std::cout << 0 << endl;
        }
        
        return;
    }
    
    cout << 0 << endl;
}

int main()
{
    size_t c;
    cin >> c;

    for (size_t i = 0; i < c; i++)
    {
        string input;
        cin >> input;
        solve(input);
    }
    
}