#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n);
    dp[0] = 1;
    int ans = dp[0];
    for (int i = 1; i < n; i++)
    {
        int prev_max = 0;
        for (int j = 0; j < i; j++)
        {

            if (nums[i] > nums[j])
            {
                prev_max = max(prev_max, dp[j]);
            }
        }
        dp[i] = prev_max + 1;
        ans = max(ans, dp[i]);
    }
    return ans;
}