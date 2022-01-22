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

int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int res = 0;
    queue<TreeNode *> Queue;
    Queue.push(root);

    while (!Queue.empty())
    {
        res++;
        int size = Queue.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *x = Queue.front();
            Queue.pop();
            if (x->left)
                Queue.push(x->left);
            if (x->right)
                Queue.push(x->right);
        }
    }
    return res;
}