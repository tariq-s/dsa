#include <bits/stdc++.h>
using namespace std;

int deleteAndEarn(vector<int> &nums)
{
    vector<int> dp(10001, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        dp[nums[i]]++;
    }
    int p_inc = 0, p_exc = 0;
    int c_inc, c_exc;
    for (int i = 0; i <= 10000; i++)
    {
        c_inc = p_exc + dp[i] * i;
        c_exc = max(p_inc, p_exc);

        p_exc = c_exc;
        p_inc = c_inc;
    }
    return max(p_inc, p_exc);
}