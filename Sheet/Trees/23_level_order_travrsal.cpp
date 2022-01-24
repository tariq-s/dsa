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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (!root)
        return res;
    queue<TreeNode *> Queue;
    Queue.push(root);

    while (!Queue.empty())
    {
        int size = Queue.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = Queue.front();
            level.push_back(curr->val);
            if (curr->left)
                Queue.push(curr->left);
            if (curr->right)
                Queue.push(curr->right);
            Queue.pop();
        }
        res.push_back(level);
    }
    return res;
}