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

void count_good_nodes(TreeNode *root, int &res, int Max)
{
    if (root == NULL)
        return;
    if (root->val >= Max)
    {
        res++;
    }
    count_good_nodes(root->left, res, max(root->val, Max));
    count_good_nodes(root->right, res, max(root->val, Max));
}
int goodNodes(TreeNode *root)
{
    int res = 0;
    count_good_nodes(root, res, INT_MIN);
    return res;
}