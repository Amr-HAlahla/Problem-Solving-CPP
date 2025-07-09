#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << maxDepth(root) << endl; // 3
    return 0;
}

/*
Time Complexity: O(n), where n is the number of nodes. Each node is visited once.
Space Complexity: O(h), where h is the height of the tree (recursion stack).
Explanation: We recursively visit each node, and the maximum stack depth is the height of the tree.
*/