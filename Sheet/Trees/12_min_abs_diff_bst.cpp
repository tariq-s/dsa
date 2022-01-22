#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *prev = NULL;

void inorder(TreeNode *root, int &res)
{
    if (!root)
        return;
    inorder(root->left, res);
    if (prev)
    {
        res = min(res, root->val - prev->val);
    }
    prev = root;
    inorder(root->right, res);
}
int getMinimumDifference(TreeNode *root)
{
    int res = INT_MAX;
    inorder(root, res);
    return res;
}