#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr || q == nullptr)
        return false;

    return p->val == q->val &&
           isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubTree(TreeNode *root, TreeNode *subRoot)
{
    if (subRoot == nullptr)
        return true;
    if (root == nullptr)
        return false;
    if (isSameTree(root, subRoot))
        return true;
    return isSameTree(root->left, subRoot) || isSameTree(root->right, subRoot);
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    TreeNode *subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);
    cout << (isSubTree(root, subRoot) ? "True" : "False") << endl; // True
    return 0;
}