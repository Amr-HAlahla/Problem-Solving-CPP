#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
struct Node
{
    int val;
    vector<Node *> neighbors;
    Node() : val(0), neighbors(vector<Node *>()) {}
    Node(int _val) : val(_val), neighbors(vector<Node *>()) {}
    Node(int _val, vector<Node *> _neighbors) : val(_val), neighbors(_neighbors) {}
};

Node *cloneGraph(Node *node, unordered_map<Node *, Node *> &visited)
{
    if (!node)
        return nullptr;
    if (visited.find(node) != visited.end())
        return visited[node];

    Node *clone = new Node(node->val);
    visited[node] = clone;
    for (Node *neighbor : node->neighbors)
    {
        clone->neighbors.push_back(cloneGraph(neighbor, visited));
    }
    return clone;
}

// Helper function to call cloneGraph without passing the map explicitly
Node *cloneGraph(Node *node)
{
    unordered_map<Node *, Node *> visited;
    return cloneGraph(node, visited);
}

int main()
{
    // Create a simple graph:
    // 1 -- 2
    // |    |
    // 4 -- 3
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    Node *cloned = cloneGraph(n1);

    // Print the cloned graph's nodes and their neighbors
    unordered_map<Node *, bool> printed;
    vector<Node *> stack = {cloned};
    while (!stack.empty())
    {
        Node *curr = stack.back();
        stack.pop_back();
        if (!curr || printed[curr])
            continue;
        printed[curr] = true;
        cout << "Node " << curr->val << ": neighbors -> ";
        for (Node *nb : curr->neighbors)
        {
            cout << nb->val << " ";
            if (!printed[nb])
                stack.push_back(nb);
        }
        cout << endl;
    }
    return 0;
}