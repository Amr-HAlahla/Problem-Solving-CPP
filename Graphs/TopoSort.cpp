#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/* Topological Sort using DFS and BFS (Kahn's Algorithm)
   Alogrithm:
    1. Create a graph from the prerequisites.
    2. For DFS:
       - Use a visited array to track the state of each node (0 = unvisited, 1 = visiting, 2 = visited).
       - Perform DFS and check for cycles.
       - If a cycle is detected, return an empty vector.
       - If no cycle, reverse the order of nodes to get the topological sort.
    3. For BFS (Kahn's Algorithm):
       - Create an adjacency list and an indegree array.
         - Initialize a queue with nodes having zero indegree.
         - Process nodes in the queue, reducing indegree of neighbors.
         - If all nodes are processed, return the order; otherwise, return an empty vector.
*/

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
/**
 * Finds a possible order to finish all courses given their prerequisites using BFS (Kahn's Algorithm).
 *
 * @param numCourses The total number of courses to be taken.
 * @param prerequisites A list of prerequisite pairs where each pair [a, b] indicates that course 'a' depends on course 'b'.
 * @return A vector containing one possible order to finish all courses. Returns an empty vector if it is impossible to finish all courses (i.e., there is a cycle).
 *
 * Note: The 'indegree' vector is used to keep track of the number of prerequisites (incoming edges) each course has.
 */
vector<int> findOrderBFS(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0); //
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

/*
| Concept         | Purpose                                                             |
| --------------- | ------------------------------------------------------------------- |
| In-degree count | Tracks prerequisites                                                |
| Queue           | For zero-indegree nodes                                             |
| Cycle detection | If not all nodes are visited, graph has cycle                       |
| Use case        | **Dependency resolution**, **scheduling**, **formal flow modeling** |
*/
