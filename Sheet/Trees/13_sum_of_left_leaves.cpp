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

int sum_left(TreeNode *root, char c)
{
    if (!root)
        return 0;
    if (!root->left && !root->right && c == 'l')
        return root->val;
    return sum_left(root->left, 'l') + sum_left(root->right, 'r');
}
int sumOfLeftLeaves(TreeNode *root)
{
    return sum_left(root, 'x');
}