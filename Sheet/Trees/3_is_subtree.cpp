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

bool are_equal(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (!root1 || !root2)
        return false;
    if (root1->val != root2->val)
        return false;
    return are_equal(root1->left, root2->left) && are_equal(root1->right, root2->right);
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (root == NULL && subRoot == NULL)
        return true;
    if (!root)
        return false;

    return are_equal(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}