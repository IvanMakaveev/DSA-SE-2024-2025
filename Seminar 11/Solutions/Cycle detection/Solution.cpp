#include <iostream>
#include <unordered_set>
#include <unordered_map>

std::unordered_map<int, std::unordered_set<int>> graph;

bool dfs(int current, std::unordered_map<int, int> &colours, std::unordered_map<int, std::unordered_set<int>> &graph)
{
    colours[current] = 1;

    for (int neighbor : graph[current])
    {
        if (colours[neighbor] == 1)
        {
            return true;
        }

        if (colours[neighbor] == 2)
        {
            continue;
        }

        if (dfs(neighbor, colours, graph))
        {
            return true;
        }
    }

    colours[current] = 2;

    return false;
}

bool hasCycle(std::unordered_map<int, std::unordered_set<int>> &graph)
{
    std::unordered_map<int, int> colours;

    for (auto it = graph.cbegin(); it != graph.cend(); it++)
    {
        if (colours.count(it->first) != 0)
        {
            continue;
        }

        if (dfs(it->first, colours, graph))
        {
            return true;
        }
    }
    return false;
}

bool solve()
{
    int V, E;
    std::cin >> V >> E;

    for (int v = 1; v <= V; v++)
    {
        graph[v];
    }

    int x, y, w;
    for (int e = 0; e < E; e++)
    {
        std::cin >> x >> y >> w;

        graph[x].insert(y);
    }

    bool answer = hasCycle(graph);
    graph.clear();

    return answer;
}

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int Q;
    std::cin >> Q;

    for (int q = 0; q < Q; q++)
    {
        auto answer = solve() ? "true" : "false";
        std::cout << answer << " ";
    }

    return 0;
}