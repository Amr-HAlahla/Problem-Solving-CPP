#include <iostream>
using namespace std;

/* Problem: Given a binary tree, determine if it is height-balanced.
A height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differs by more than one.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int checkHeight(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1)
        return -1;

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode *root)
{
    return checkHeight(root) != -1;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << (isBalanced(root) ? "True" : "False") << endl; // True
    return 0;
}