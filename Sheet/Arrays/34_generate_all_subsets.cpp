#include <bits/stdc++.h>
using namespace std;

void get_subsets(vector<int> &nums, int idx, vector<int> curr, vector<vector<int>> &res)
{
    if (idx == nums.size())
    {
        res.push_back(curr);
        return;
    }
    get_subsets(nums, idx + 1, curr, res);
    curr.push_back(nums[idx]);
    get_subsets(nums, idx + 1, curr, res);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    get_subsets(nums, 0, {}, res);
    return res;
}