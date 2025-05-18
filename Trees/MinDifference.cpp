#include <iostream>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode *root, TreeNode *&prev, int &minDiff)
{
    if (root == nullptr)
        return;
    inorder(root->left, prev, minDiff);

    if (prev != nullptr)
    {
        minDiff = min(minDiff, abs(root->val - prev->val));
    }
    prev = root;
    inorder(root->right, prev, minDiff);
}

int getMinimumDifference(TreeNode *root)
{
    int minDiff = INT_MAX;
    TreeNode *prev = nullptr;
    inorder(root, prev, minDiff);
    return minDiff;
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    cout << getMinimumDifference(root) << endl; // 1
    return 0;
}