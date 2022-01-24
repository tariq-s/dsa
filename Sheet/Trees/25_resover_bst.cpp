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

TreeNode *first = NULL;
TreeNode *second = NULL;
TreeNode *prev = NULL;
TreeNode *next = NULL;
void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    if (prev)
    {
        if (prev->val > root->val)
        {
            if (!first)
            {
                first = prev;
                next = root;
            }
            else
                second = root;
        }
    }
    prev = root;
    inorder(root->right);
}
void recoverTree(TreeNode *root)
{
    inorder(root);
    if (second)
    {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    else
    {
        int temp = first->val;
        first->val = next->val;
        next->val = temp;
    }
}