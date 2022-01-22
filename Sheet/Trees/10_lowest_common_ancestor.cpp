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

vector<TreeNode *> node_to_root_path(TreeNode *root, TreeNode *node)
{
    if (root == NULL)
        return {};

    if (root == node)
    {
        return {root};
    }

    vector<TreeNode *> left = node_to_root_path(root->left, node);
    if (left.size() > 0)
    {
        left.insert(left.begin(), root);
        return left;
    }
    vector<TreeNode *> right = node_to_root_path(root->right, node);
    if (right.size() > 0)
    {
        right.insert(right.begin(), root);
        return right;
    }
    return {};
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> p1 = node_to_root_path(root, p);
    vector<TreeNode *> p2 = node_to_root_path(root, q);
    int i = 0;
    while (i < p1.size() && i < p2.size() && p1[i] == p2[i])
    {
        i++;
    }
    return p1[i - 1];
}