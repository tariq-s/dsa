#include <bits/stdc++.h>
using namespace std;
int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
        return n;
    vector<unordered_map<int, int>> dp(n);
    int max_len = 2;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = nums[i] - nums[j];
            if (dp[j].find(diff) != dp[j].end())
            {
                dp[i][diff] = dp[j][diff] + 1;
                max_len = max(max_len, dp[i][diff] + 1);
            }
            else
            {
                dp[i][diff] = 1;
            }
        }
    }
    return max_len;
}