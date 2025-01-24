#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int from;
    int to;
    long long weight;

    bool operator<(const Edge& other) const
    {
        return weight < other.weight;
    }
};

int myFind(int x, vector<int>& parent)
{
    if(x == parent[x])
        return x;
    
    return parent[x] = myFind(parent[x], parent);
}

bool myUnion(int x, int y, vector<int>& parent, vector<int>& depths, long long weight, vector<long long>& weights)
{
    int r1 = myFind(x, parent);
    int r2 = myFind(y, parent);

    if(r1 == r2)
    {
        return false;
    }
    
    parent[r1] = r2;
    weights[r2] += weight + weights[r1];
    
    return true;
}

void runApp()
{
    int vert, edgesC, k;
    cin >> vert >> edgesC >> k;
    
    vector<Edge> edges(edgesC);
    for(int i = 0; i < edgesC; i++)
    {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }
    
    vector<int> depth(vert, 0);
    vector<int> parent(vert);
    vector<long long> weights(vert, 0);

    for(int i = 0; i < vert; i++)
    {
        parent[i] = i;
    }
    
    sort(edges.begin(), edges.end());
    
    for(auto edge: edges)
    {
        myUnion(edge.from, edge.to, parent, depth, edge.weight, weights);
    }
    
    unordered_map<int, int> counts;
    for(int i = 0; i < vert; i++)
    {
        int root = myFind(i, parent);
        counts[root]+=1;
    }
    
    long long result = 0;
    for(auto kvp: counts)
    {
        int root = kvp.first;
        int count = kvp.second;
        
        if(count % k == 0)
        {
            result += weights[root];
        }
    }
    
    cout << result << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);


    int queries;
    cin >> queries;
    for(int i = 0; i < queries; i++)
    {
        runApp();
    }
}