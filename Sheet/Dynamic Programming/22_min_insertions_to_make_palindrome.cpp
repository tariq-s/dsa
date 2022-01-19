#include <bits/stdc++.h>
using namespace std;

int minInsertions(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));

    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
    }
    return dp[0][n - 1];
}