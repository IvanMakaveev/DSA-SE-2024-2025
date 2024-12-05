#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    size_t N;
    cin >> N;
    vector<pair<size_t, size_t>> parents(N, { 0,0 });
    size_t parent, child;
    for (size_t i = 0; i < N - 1; i++) {
        cin >> parent >> child;
        parents[child].first = parent;
    }

    for (long long i = N - 1; i >= 0; i--) {
        size_t next = i;
        while (next) {
            next = parents[next].first;
            parents[next].second++;
        }
    }

    for (auto& node : parents) {
        cout << node.second << ' ';
    }
}
