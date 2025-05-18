#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> bfsShortestPath(int n, vector<vector<int>> &edges, int src)
{
    // Step 1: Build adjacency list
    vector<vector<int>> adj(n);
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
    }

    // Step 2: Initialize distances and queue
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    queue<int> q;
    q.push(src);

    // Step 3: BFS
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        /* For a specific destination
        if(q == dest){
            return dest[u];
        }
        */
        for (int v : adj[u])
        {
            if (dist[v] == INT_MAX) // Not visisted
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}

int main()
{
    int n = 5, src = 0;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {2, 4}};
    vector<int> distances = bfsShortestPath(n, edges, src);
    for (int d : distances)
    {
        cout << (d == INT_MAX ? -1 : d) << " "; // 0 1 1 2 2
    }
    cout << endl;
    return 0;
}