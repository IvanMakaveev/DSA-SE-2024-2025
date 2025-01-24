#include <bits/stdc++.h>

using namespace std;

void hasCycleComponent(vector<vector<int>>& adj, vector<bool>& visited, int curr, bool& flag, int parent)
{
    visited[curr] = true;
    
    for(auto child: adj[curr])
    {
        if(visited[child])
        {
            if(parent != -1 && parent != child)
            {
                flag = true;
            }
        }
        
        if(!visited[child])
        {
            hasCycleComponent(adj, visited, child, flag, curr);
        }
    }
}

void runApp()
{
    int vert, edges;
    cin >> vert >> edges;
    vector<vector<int>> adj(vert, vector<int>());
    for(int i = 0; i < edges; i++)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    vector<bool> visited(vert, false);
    int result = 0;
    for(int i = 0; i < vert; i++)
    {
        if(visited[i] == false)
        {
            bool hasCycle = false;
            int parent = -1;
            hasCycleComponent(adj, visited, i, hasCycle, parent);
            if(hasCycle)
            {
                result++;
            }
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