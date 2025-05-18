#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
private:
    // First DFS to fill stack with finishing times
    void dfs1(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
    {
        visited[u] = true;
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                dfs1(v, adj, visited, st);
            }
        }
        st.push(u);
    }

    // Second DFS to explore SCC
    void dfs2(int u, vector<vector<int>> &adjT, vector<bool> &visited, int &count)
    {
        visited[u] = true;
        count++;
        for (int v : adjT[u])
        {
            if (!visited[v])
            {
                dfs2(v, adjT, visited, count);
            }
        }
    }

public:
    bool isStronglyConnected(int n, vector<vector<int>> &edges)
    {
        // Handle edge cases
        if (n <= 1)
            return true; // Single node or empty graph is strongly connected

        // Step 1: Build adjacency lists
        vector<vector<int>> adj(n), adjT(n);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);  // Original graph
            adjT[v].push_back(u); // Transposed graph
        }

        // Step 2: First DFS to get finishing times
        vector<bool> visited(n, false);
        stack<int> st;
        dfs1(0, adj, visited, st); // Start from node 0

        // Check if all nodes are reachable from node 0
        for (bool v : visited)
        {
            if (!v)
                return false; // Some nodes unreachable
        }

        // Step 3: Second DFS on transposed graph
        fill(visited.begin(), visited.end(), false);
        int count = 0; // Count nodes in first SCC
        dfs2(st.top(), adjT, visited, count);

        // Check if all nodes are in one SCC
        return count == n && visited == vector<bool>(n, true);
    }
};

int main()
{
    Solution sol;
    // Test case 1
    int n1 = 5;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    cout << (sol.isStronglyConnected(n1, edges1) ? "True" : "False") << endl; // False

    // Test case 2
    int n2 = 3;
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 0}};
    cout << (sol.isStronglyConnected(n2, edges2) ? "True" : "False") << endl; // True
    return 0;
}