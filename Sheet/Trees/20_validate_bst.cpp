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

bool isValidBST(TreeNode *root, int Min = INT_MIN, int Max = INT_MAX)
{
    if (!root)
        return true;
    if (root->val < Min || root->val > Max)
        return false;
    if (root->val == INT_MAX)
        return root->right == NULL && isValidBST(root->left, Min, root->val - 1);
    if (root->val == INT_MIN)
        return root->left == NULL && isValidBST(root->right, root->val + 1, Max);
    return isValidBST(root->left, Min, root->val - 1) && isValidBST(root->right, root->val + 1, Max);