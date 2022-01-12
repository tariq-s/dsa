#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int prev_inc = nums[0];
    int prev_exc = 0;
    int curr_inc, curr_exc;
    for (int i = 1; i < n; i++)
    {
        curr_inc = nums[i] + prev_exc;
        curr_exc = max(prev_exc, prev_inc);

        prev_inc = curr_inc;
        prev_exc = curr_exc;
    }
    return max(prev_exc, prev_inc);
}