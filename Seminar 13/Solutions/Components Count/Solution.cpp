#include <vector>
using namespace std;

int n = 10;
vector<size_t> parent(n);
vector<size_t> depth(n, 0);

void setup()
{
    for (size_t i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}

int Find(size_t vertex)
{
    if (vertex == parent[vertex])
    {
        return vertex;
    }

    return parent[vertex] = Find(parent[vertex]);
}

bool Union(size_t v1, size_t v2)
{
    int p1 = Find(v1);
    int p2 = Find(v2);

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

size_t countComponents(size_t n, vector<pair<size_t, size_t>> edges)
{
    size_t components = n;
    
    setup();
    for (auto& edge : edges)
    {
        if (Union(edge.first, edge.second))
        {
            components--;
            if (components == 1)
            {
                return 1;
            }
        }
    }

    return components;
}