#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int kthSmallest(TreeNode *root, int k)
{
    stack<TreeNode *> s;
    TreeNode *current = root;

    while (current != nullptr || !s.empty())
    {
        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        k--;
        if (k == 0)
            return current->val;
        current = current->right;
    }
    return -1;
}

// Recursive implementation
void inorder(TreeNode *root, int &k, int &result)
{
    if (!root)
        return;
    inorder(root->left, k, result);
    k--;
    if (k == 0)
    {
        result = root->val;
        return;
    }
    inorder(root->right, k, result);
}

int kthSmallestRecursive(TreeNode *root, int k)
{
    int result = -1;
    inorder(root, k, result);
    return result;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int k = 1;
    cout << kthSmallest(root, k) << endl;          // 1
    cout << kthSmallestRecursive(root, k) << endl; // 1
    return 0;
}