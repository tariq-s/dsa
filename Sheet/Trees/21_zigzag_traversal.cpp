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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (!root)
        return res;
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;
    bool dir = true;
    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        int size = s1.size();
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            temp.push_back(s1.top()->val);
            if (dir)
            {
                if (s1.top()->left)
                    s2.push(s1.top()->left);
                if (s1.top()->right)
                    s2.push(s1.top()->right);
            }
            else
            {
                if (s1.top()->right)
                    s2.push(s1.top()->right);
                if (s1.top()->left)
                    s2.push(s1.top()->left);
            }
            s1.pop();
        }
        res.push_back(temp);
        dir = !dir;
        s1 = s2;
        s2 = stack<TreeNode *>();
    }
    return res;
}