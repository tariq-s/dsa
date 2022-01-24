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

class BSTIterator
{
public:
    stack<pair<TreeNode *, int>> Stack;
    BSTIterator(TreeNode *root)
    {
        Stack.push({root, 0});
    }

    int next()
    {
        while (!Stack.empty())
        {
            if (Stack.top().second == 0)
            {
                Stack.top().second = 1;
                if (Stack.top().first->left)
                    Stack.push({Stack.top().first->left, 0});
            }
            else if (Stack.top().second == 2)
            {
                Stack.pop();
            }
            else
            {
                int res = Stack.top().first->val;
                Stack.top().second = 2;
                if (Stack.top().first->right)
                    Stack.push({Stack.top().first->right, 0});
                return res;
            }
        }
        return -1;
    }

    bool hasNext()
    {
        while (!Stack.empty() && Stack.top().second == 2)
            Stack.pop();
        return !Stack.empty();
    }
};
