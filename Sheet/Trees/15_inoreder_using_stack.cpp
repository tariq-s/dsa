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

vector<int> inorderTraversal(TreeNode *root)
{
    if (!root)
        return {};
    vector<int> res;
    stack<pair<TreeNode *, int>> Stack;
    Stack.push({root, 0});

    while (!Stack.empty())
    {
        pair<TreeNode *, int> x = Stack.top();
        if (x.second == 0)
        {
            Stack.top().second = 1;
            if (x.first->left)
                Stack.push({x.first->left, 0});
        }
        else if (x.second == 1)
        {
            res.push_back(x.first->val);
            Stack.top().second = 2;
            if (x.first->right)
                Stack.push({x.first->right, 0});
        }
        else
        {
            Stack.pop();
        }
    }
    return res;
}