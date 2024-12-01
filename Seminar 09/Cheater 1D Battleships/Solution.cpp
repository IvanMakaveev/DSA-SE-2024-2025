#include <cstdio>
#include <iostream>
#include <set>

using namespace std;


int main() {
    int mapSize, shipCount, shipSize;
    cin >> mapSize >> shipCount >> shipSize;
    set<int> shots; // ORDER MATTERS!!!! WE NEED SET, NOT UNRORDERED_SET

    int shotsCount;
    cin >> shotsCount;
    int currentCount = (mapSize  + 1) / (shipSize + 1); // Max possible ships, cannot touch

    for (int i = 1; i <= shotsCount; i++) {
        int shot;
        cin >> shot;
        auto iterPair = shots.insert(shot);
        if (!iterPair.second) {
            continue;
        }
        auto iter = iterPair.first;
        int left = 0;
        int right = mapSize+1;
        if (iter != shots.begin()) {
            left = *(--iter);
            ++iter;
        }
        if (++iter != shots.end()) {
            right = *iter;
        }
        int prevCount = (right - left) / (shipSize + 1);
        int leftCount = (shot - left) / (shipSize + 1);
        int rightCount = (right - shot) / (shipSize + 1);
        int diff = prevCount - (leftCount + rightCount);
        currentCount -= diff;

        if (currentCount < shipCount) {
            printf("%d", i);
            return 0;
        }
    }
    printf("%d", -1);
    return 0;
}