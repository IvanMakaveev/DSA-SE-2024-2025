#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    char curr = s[0];
    size_t count = 1;
    for(size_t i = 1; i < s.size(); i++)
    {
        if(s[i] == curr)
        {
            count++;
        }
        else
        {
            cout << count;
            cout << curr;
            curr = s[i];
            count = 1;
        }
    }
    
    cout << count;
    cout << curr;
}