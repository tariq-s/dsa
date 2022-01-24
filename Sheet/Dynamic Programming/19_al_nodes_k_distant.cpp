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
vector<int> k_down(TreeNode *root, int k, TreeNode *block)
{
    vector<int> res;
    if (!root)
        return res;

    queue<pair<TreeNode *, int>> Queue;
    Queue.push({root, 0});

    while (!Queue.empty())
    {
        pair<TreeNode *, int> x = Queue.front();
        Queue.pop();

        if (x.second == k)
            res.push_back(x.first->val);

        if (x.first->left && x.second < k && x.first->left != block)
            Queue.push({x.first->left, x.second + 1});

        if (x.first->right && x.second < k && x.first->right != block)
            Queue.push({x.first->right, x.second + 1});
    }
    return res;
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    if (!root)
        return {};
    vector<TreeNode *> ntrp = node_to_root_path(root, target);

    vector<int> res;
    vector<int> temp;
    int i = ntrp.size() - 1;
    while (k >= 0 && i >= 0)
    {
        temp = k_down(ntrp[i], k, i == ntrp.size() - 1 ? NULL : ntrp[i + 1]);
        res.insert(res.end(), temp.begin(), temp.end());
        k--;
        i--;
    }
    return res;
}