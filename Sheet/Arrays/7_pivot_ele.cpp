#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int n = nums.size();
    vector<int> accum_right(n);
    accum_right[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        accum_right[i] = accum_right[i + 1] + nums[i + 1];
    }
    int accum_left = 0;
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            accum_left += nums[i - 1];
        if (accum_left == accum_right[i])
        {
            return i;
        }
    }
    return res;
}