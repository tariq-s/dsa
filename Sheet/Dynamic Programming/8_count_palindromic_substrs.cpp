#include <bits/stdc++.h>
using namespace std;

nt countSubstrings(string s)
{
    int count = 0;
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));

    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = true;
            }
            else if (g == 1)
            {
                dp[i][j] = (s[i] == s[j]);
            }
            else
            {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
            if (dp[i][j])
                count++;
        }
    }
    return count;
}