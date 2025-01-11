#include <vector>
using namespace std;

void setup(vector<int>& parent)
{
    for (size_t i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }
}

int Find(int vertex, vector<int>& parent)
{
    if (vertex == parent[vertex])
    {
        return vertex;
    }

    return parent[vertex] = Find(parent[vertex], parent);
}

bool Union(int v1, int v2, vector<int>& parent, vector<int>& depth)
{
    int p1 = Find(v1, parent);
    int p2 = Find(v2, parent);

    if (p1 == p2)
    {
        return false;
    }

    if (depth[p1] > depth[p2])
    {
        swap(p1, p2);
    }
    else if (depth[p1] == depth[p2]) 
    {
        depth[p2]++;
    }

    parent[p1] = p2;
    return true;
}