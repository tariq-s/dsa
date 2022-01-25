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

int count_cameras(TreeNode *root, int &res)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return -1;

    int left = count_cameras(root->left, res);
    int right = count_cameras(root->right, res);

    if (left == -1 || right == -1)
    {
        res += 1;
        return 1;
    }
    if (left == 1 || right == 1)
        return 0;
    return -1;
}
int minCameraCover(TreeNode *root)
{
    int res = 0;
    int x = count_cameras(root, res);
    if (x == -1)
        res += 1;
    return res;
}