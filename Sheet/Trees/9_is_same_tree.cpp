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

bool isSameTree(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (!root1 || !root2)
        return false;
    if (root1->val != root2->val)
        return false;
    return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}