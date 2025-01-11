#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const unsigned int MAXIMUM_NODES = 1e4;
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
    unsigned int speed;

    Road(unsigned int startNode,
        unsigned int endNode,
        unsigned int speed)
    {
        this->startNode = startNode;
        this->endNode = endNode;
        this->speed = speed;
    }

    bool operator<(const Road& other) const
    {
        return speed < other.speed;
    }
};

void resetParents(unsigned int vertecies)
{
    for (size_t i = 1; i <= vertecies; i++)
    {
        parent[i] = i;
    }
}

int main()
{
    unsigned int vertecies, edges;
    cin >> vertecies >> edges;

    resetParents(vertecies);

    vector<Road> roads;
    int minSpeed = 1e7;
    for (size_t i = 1; i <= edges; i++) {
        unsigned int startNode, endNode, speed;
        cin >> startNode >> endNode >> speed;
        roads.push_back(Road(startNode, endNode, speed));

        if (speed < minSpeed)
        {
            minSpeed = speed;
        }
    }
    minSpeed--;

    sort(roads.begin(), roads.end());
    unsigned int resultDiff = UINT32_MAX;
    unsigned int resultMin = 0;
    unsigned int resultMax = 0;

    while (true)
    {
        auto currentNode = upper_bound(roads.begin(), roads.end(), Road(0, 0, minSpeed));

        if (currentNode == roads.end())
        {
            break;
        }

        unsigned int currMin = (*currentNode).speed;
        unsigned int currMax = 0;

        size_t maxRoadsCounter = 1;
        for (; currentNode < roads.end(); currentNode++)
        {
            if (nodeUnion((*currentNode).startNode, (*currentNode).endNode))
            {
                if (currMax < (*currentNode).speed)
                {
                    currMax = (*currentNode).speed;
                }

                maxRoadsCounter++;
                if (maxRoadsCounter == vertecies)
                {
                    break;
                }
            }
        }

        if (maxRoadsCounter != vertecies)
        {
            break;
        }

        resetParents(vertecies);
        minSpeed = currMin;

        if (resultDiff > currMax - currMin)
        {
            resultDiff = currMax - currMin;
            resultMax = currMax;
            resultMin = currMin;
        }
    }

    cout << resultMin << ' ' << resultMax;
}