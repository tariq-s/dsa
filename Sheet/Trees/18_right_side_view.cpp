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

vector<int> rightSideView(TreeNode *root)
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

        if (x.second == res.size())
        {
            res.push_back(x.first->val);
        }
        else
        {
            res[x.second] = x.first->val;
        }

        if (x.first->left)
            Queue.push({x.first->left, x.second + 1});
        if (x.first->right)
            Queue.push({x.first->right, x.second + 1});
    }
    return res;
}