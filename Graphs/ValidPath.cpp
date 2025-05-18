#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS approach
bool dfs(int node, int dest, vector<vector<int>> &adj, vector<bool> &visited)
{
    if (node == dest)
        return true;
    visited[node] = true;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            if (dfs(neighbor, dest, adj, visited))
                return true;
        }
    }
    return false;
}

// BFS approach
bool bfs(int start, int dest, vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (node == dest)
            return true;
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

int main()
{
    // Example graph: 5 nodes, 4 edges
    int n = 5, m = 4;
    vector<vector<int>> adj(n);
    // Edges: 0-1, 0-2, 1-3, 3-4
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {3, 4}};
    for (auto &e : edges)
    {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }
    int start = 0, end = 4;

    // DFS
    vector<bool> visited(n, false);
    bool pathExistsDFS = dfs(start, end, adj, visited);
    cout << "Path exists (DFS): " << (pathExistsDFS ? "Yes" : "No") << endl;

    // BFS
    bool pathExistsBFS = bfs(start, end, adj);
    cout << "Path exists (BFS): " << (pathExistsBFS ? "Yes" : "No") << endl;

    return 0;
}
