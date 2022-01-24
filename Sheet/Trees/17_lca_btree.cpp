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
    if (!root)
        return {};
    if (root == node)
    {
        return {node};
    }
    vector<TreeNode *> path_left = node_to_root_path(root->left, node);
    if (path_left.size() > 0)
    {
        path_left.insert(path_left.begin(), root);
        return path_left;
    }
    vector<TreeNode *> path_right = node_to_root_path(root->right, node);
    if (path_right.size() > 0)
    {
        path_right.insert(path_right.begin(), root);
        return path_right;
    }
    return {};
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> path_p = node_to_root_path(root, p);
    vector<TreeNode *> path_q = node_to_root_path(root, q);

    int i = 0;
    while (i < path_q.size() && i < path_p.size() && path_p[i] == path_q[i])
    {
        i++;
    }
    return path_p[i - 1];
}