#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    // First DFS to fill stack with finishing times
    void dfs1(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs1(v, adj, visited, st);
            }
        }
        st.push(u); // Push node after exploring its neighbors
    }
    
    // Second DFS to collect SCC
    void dfs2(int u, vector<vector<int>>& adjT, vector<bool>& visited, vector<int>& scc) {
        visited[u] = true;
        scc.push_back(u);
        for (int v : adjT[u]) {
            if (!visited[v]) {
                dfs2(v, adjT, visited, scc);
            }
        }
    }
    
public:
    vector<vector<int>> findSCC(int n, vector<vector<int>>& edges) {
        // Step 1: Build adjacency lists
        vector<vector<int>> adj(n), adjT(n); // adj: original, adjT: transposed
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);    // Original graph
            adjT[v].push_back(u);   // Transposed graph
        }
        
        // Step 2: First DFS to get finishing times
        vector<bool> visited(n, false);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs1(i, adj, visited, st);
            }
        }
        
        // Step 3: Second DFS on transposed graph
        fill(visited.begin(), visited.end(), false); // Reset visited
        vector<vector<int>> result;
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            if (!visited[u]) {
                vector<int> scc;
                dfs2(u, adjT, visited, scc);
                result.push_back(scc);
            }
        }
        
        return result;
    }
};

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,0}, {1,3}, {3,4}};
    Solution sol;
    vector<vector<int>> sccs = sol.findSCC(n, edges);
    for (auto& scc : sccs) {
        cout << "[";
        for (int i = 0; i < scc.size(); i++) {
            cout << scc[i];
            if (i < scc.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl; // Output: [0,1,2] [3] [4]
    return 0;
}