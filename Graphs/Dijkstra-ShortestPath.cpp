#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(int n, vector<vector<int>> &edges, int src)
{
    // Step 1: Build adjacency list
    vector<vector<pair<int, int>>> adj(n); // {node, weight}
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w}); // Directed edge u -> v
    }

    // Step 2: Initialize distances and priority queue
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // {distance, node}
    pq.push({0, src});

    // Step 3: Dijkstra's algorithm
    while (!pq.empty())
    {
        int d = pq.top().first;  // Current distance
        int u = pq.top().second; // Current node
        pq.pop();

        // Skip if we've found a better distance
        if (d > dist[u])
            continue;

        // Explore neighbors
        for (auto &[v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w; // Update distance
                pq.push({dist[v], v}); // Add to priority queue
            }
        }
    }

    return dist;
}

int main()
{
    int n = 5, src = 0;
    vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 8}, {1, 2, 2}, {1, 3, 5}, {2, 3, 5}, {2, 4, 6}};
    vector<int> distances = dijkstra(n, edges, src);
    for (int d : distances)
    {
        cout << (d == INT_MAX ? -1 : d) << " "; // 0 4 6 9 12
    }
    cout << endl;
    return 0;
}