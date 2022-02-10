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

unordered_map<TreeNode *, int> dp;
int rob(TreeNode *root)
{
    if (!root)
        return 0;
    if (dp.find(root) != dp.end())
        return dp[root];

    int rob_curr_left = 0;
    if (root->left)
        rob_curr_left = rob(root->left->left) + rob(root->left->right);

    int rob_curr_right = 0;
    if (root->right)
        rob_curr_right = rob(root->right->left) + rob(root->right->right);

    int rob_curr = root->val + rob_curr_left + rob_curr_right;

    dp[root] = max(rob_curr, rob(root->left) + rob(root->right));

    return dp[root];
}