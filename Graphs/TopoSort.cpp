#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &order)
{
    visited[node] = 1; // Mark as visiting
    for (int neighbor : adj[node])
    {
        if (visited[neighbor] == 1) // Cycle detected
            return false;
        if (visited[neighbor] == 0)
        {
            if (!dfs(neighbor, adj, visited, order))
                return false;
        }
    }
    visited[node] = 2; // Mark as visited
    order.push_back(node);
    return true;
}

vector<int> findOrderDFS(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    for (auto &pre : prerequisites)
    {
        adj[pre[1]].push_back(pre[0]); // pre[1] -> pre[0]
    }
    vector<int> visited(numCourses, 0);
    vector<int> order;

    for (int i = 0; i < numCourses; ++i)
    {
        if (visited[i] == 0)
        {
            if (!dfs(i, adj, visited, order))
                return {};
        }
    }
    reverse(order.begin(), order.end());
    return order;
}

// BFS (Kahn's Algorithm) implementation
vector<int> findOrderBFS(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto &pre : prerequisites)
    {
        adj[pre[1]].push_back(pre[0]);
        indegree[pre[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> order;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        order.push_back(node);
        for (int neighbor : adj[node])
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    if (order.size() != numCourses)
        return {};
    return order;
}

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    cout << "DFS-based Topological Sort: ";
    vector<int> orderDFS = findOrderDFS(numCourses, prerequisites);
    if (orderDFS.empty())
    {
        cout << "No valid order (cycle detected)" << endl;
    }
    else
    {
        for (int x : orderDFS)
            cout << x << " ";
        cout << endl;
    }

    cout << "BFS-based Topological Sort: ";
    vector<int> orderBFS = findOrderBFS(numCourses, prerequisites);
    if (orderBFS.empty())
    {
        cout << "No valid order (cycle detected)" << endl;
    }
    else
    {
        for (int x : orderBFS)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
