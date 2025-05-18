#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited)
{
    visited[node] = 1; // Mark as visiting
    for (int neighbor : adj[node])
    {
        if (visited[neighbor] == 1) // Cycle detected
            return false;
        if (visited[neighbor] == 0)
        {
            if (!dfs(neighbor, adj, visited))
                return false;
        }
    }
    visited[node] = 2; // Mark as visited
    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    vector<int> visited(numCourses, 0); // 0 == Unvisited, 1 == Visiting, 2 == Visited.

    // Build the adj list.
    for (auto &pre : prerequisites)
    {
        adj[pre[1]].push_back(pre[0]); // pre[1] -> pre[0]
    }

    for (int i = 0; i < numCourses; ++i)
    {
        if (visited[i] == 0)
        {
            if (!dfs(i, adj, visited))
                return false;
        }
    }
    return true;
}

int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout << (canFinish(numCourses, prerequisites) ? "True" : "False") << endl; // True
    return 0;
}