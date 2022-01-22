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

int height(TreeNode *root)
{
    if (root == NULL)
        return -1;
    return max(height(root->left), height(root->right)) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int height_left = height(root->left);
    int height_right = height(root->right);
    int dia_left = diameterOfBinaryTree(root->left);
    int dia_right = diameterOfBinaryTree(root->right);
    return max(height_left + height_right + 2, max(dia_right, dia_left));
}