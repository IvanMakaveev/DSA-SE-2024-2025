// 08. Special Triples
// All triples (i, j, k):
// a[j] = a[i]*M
// a[k] = a[j]*M
// Вариант 1 - взимаме всички такива двойки и после връщаме тези, за които first.end == second.start
// Вариант 2 - два map-а:
// За arr[curr] търсим дали в левия има arr[curr]/M и в десния дали има arr[curr]*M

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    long long M, N;
    cin >> N >> M;
    unordered_map<long long, long long> l;
    unordered_map<long long, long long> r;
    vector<int> v(N);

    for (long long i = 0; i < N; ++i) {
        long long n;
        cin >> n;
        r[n]++;
        v[i] = n;
    }

    long long count = 0;
    for (long long i = 0; i < N; ++i) {
        r[v[i]]--;
        
        if (v[i] % M == 0) {
            count += l[v[i] / M] * r[v[i] * M];
        }
        
        l[v[i]]++;
    }


    printf("%lld", count);
    return 0;
}