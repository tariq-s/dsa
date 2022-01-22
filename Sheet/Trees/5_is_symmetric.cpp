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

bool is_mirror(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    return root1->val == root2->val && is_mirror(root1->right, root2->left) && is_mirror(root1->left, root2->right);
}
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    return is_mirror(root->left, root->right);
}