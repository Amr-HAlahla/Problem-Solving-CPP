#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int height(TreeNode *root, int &maxDiameter)
{
    if (root == nullptr)
        return 0;

    int leftHeight = height(root->left, maxDiameter);
    int rightHeight = height(root->right, maxDiameter);
    maxDiameter = max(maxDiameter, leftHeight + rightHeight);

    return max(leftHeight, rightHeight) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int maxDiameter = 0;
    height(root, maxDiameter);
    return maxDiameter;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << diameterOfBinaryTree(root) << endl; // 3
    return 0;
}