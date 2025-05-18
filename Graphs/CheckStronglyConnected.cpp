#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[u] = true;
    for (int nei : adj[u])
    {
        if (!visited[nei])
        {
            dfs(nei, adj, visited);
        }
    }
}

bool isStronglyConnected(int n, vector<vector<int>> &edges)
{
    // Build Adjacense List and Transposed version.
    vector<vector<int>> adj(n), adjT(n);
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }

    // DFS on the original graph
    vector<bool> visited(n, false);
    dfs(0, adj, visited);
    for (bool v : visited)
    {
        if (!v)
            return false;
    }

    fill(visited.begin(), visited.end(), false);
    // DFS on the Transposed Graph
    dfs(0, adjT, visited);
    for (bool v : visited)
    {
        if (!v)
            return false;
    }

    return true;
}

int main()
{
    // Test case 1
    int n1 = 5;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    cout << (isStronglyConnected(n1, edges1) ? "True" : "False") << endl; // False

    // Test case 2
    int n2 = 3;
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 0}};
    cout << (isStronglyConnected(n2, edges2) ? "True" : "False") << endl; // True
    return 0;
}
