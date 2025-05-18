#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void dfs1(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
            dfs1(v, adj, visited, st);
    }
    st.push(u);
}

void dfs2(int u, vector<vector<int>> &adjT, vector<bool> &visited, vector<int> &component)
{
    visited[u] = true;
    component.push_back(u);
    for (int v : adjT[u])
    {
        if (!visited[v])
            dfs2(v, adjT, visited, component);
    }
}

vector<vector<int>> getStronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n), adjT(n);
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adjT[v].push_back(u); // transpose
    }

    // Step 1: DFS and push to stack in postorder
    vector<bool> visited(n, false);
    stack<int> st;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs1(i, adj, visited, st);
    }

    // Step 2: Transposed DFS based on finishing times
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;

    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (!visited[u])
        {
            vector<int> component;
            dfs2(u, adjT, visited, component);
            sccs.push_back(component);
        }
    }

    return sccs;
}

int main()
{
    int n = 8;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, // SCC1
        {3, 1},
        {3, 2}, // points into SCC1
        {4, 3},
        {4, 5},
        {5, 4}, // SCC2
        {6, 5},
        {6, 7},
        {7, 6} // SCC3
    };

    vector<vector<int>> sccs = getStronglyConnectedComponents(n, edges);

    cout << "Strongly Connected Components:\n";
    for (const auto &component : sccs)
    {
        for (int node : component)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}
/*
The first DFS stores vertices in postorder (finished last on top of stack).
The second DFS on the transposed graph finds each SCC by popping from the stack.
*/
