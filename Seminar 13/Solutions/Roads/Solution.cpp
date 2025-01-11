#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const unsigned int MAXIMUM_NODES = 2*1e5;
unsigned int parent[MAXIMUM_NODES + 1], depth[MAXIMUM_NODES + 1];

int findRoot(unsigned int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findRoot(parent[node]);
}

bool nodeUnion(unsigned int firstNode, unsigned int secondNode)
{
    int firstRoot = findRoot(firstNode);
    int secondRoot = findRoot(secondNode);
    if (firstRoot == secondRoot)
    {
        return false;
    }

    if (depth[firstRoot] > depth[secondRoot])
    {
        swap(firstRoot, secondRoot);
    }

    if (depth[firstRoot] == depth[secondRoot])
    {
        depth[secondRoot]++;
    }

    parent[firstRoot] = secondRoot;
    return true;
}

struct Road 
{
    unsigned int startNode;
    unsigned int endNode;
    unsigned int index;
    long long cost;
    long long profit;

    Road(unsigned int startNode, 
        unsigned int endNode, 
        unsigned int index,
        long long cost, 
        long long profit)
    {
        this->startNode = startNode;
        this->endNode = endNode;
        this->index = index;
        this->cost = cost;
        this->profit = profit;
    }

    bool operator<(const Road& other) const 
    {
        if (cost == other.cost) {
            return profit > other.profit;
        }

        return cost < other.cost;
    }
};

int main()
{
    unsigned int vertecies, edges;
    cin >> vertecies >> edges;

    for (size_t i = 1; i <= vertecies; i++)
    {
        parent[i] = i;
    }

    vector<Road> roads;
    for (size_t i = 1; i <= edges; i++) {
        unsigned int startNode, endNode;
        long long cost, profit;
        cin >> startNode >> endNode >> cost >> profit;
        roads.push_back(Road(startNode, endNode, i, cost, profit));
    }

    sort(roads.begin(), roads.end());

    size_t maxRoadsCounter = 1;
    for (size_t i = 0; i < edges; i++) 
    {
        if (nodeUnion(roads[i].startNode, roads[i].endNode)) 
        {
            cout << roads[i].index << endl;
            maxRoadsCounter++;
            if (maxRoadsCounter == vertecies) 
            {
                break;
            }
        }
    }
}
