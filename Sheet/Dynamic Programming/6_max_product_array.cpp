#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int prev_min = nums[0];
    int prev_max = nums[0];
    int curr_max, curr_min, res = nums[0];
    for (int i = 1; i < n; i++)
    {
        curr_max = max(max(nums[i] * prev_max, nums[i] * prev_min), nums[i]);
        curr_min = min(min(nums[i] * prev_max, nums[i] * prev_min), nums[i]);
        res = max(res, curr_max);
        prev_max = curr_max;
        prev_min = curr_min;
    }

    return res;
}