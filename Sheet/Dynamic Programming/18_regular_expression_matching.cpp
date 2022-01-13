#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p)
{
    int s_len = s.size(), p_len = p.size();
    vector<vector<bool>> dp(p_len + 1, vector<bool>(s_len + 1));
    for (int i = 0; i <= p_len; i++)
    {
        for (int j = 0; j <= s_len; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (j == 0)
            {
                if (p[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 2][j];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            else
            {
                if (p[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 2][j];
                    if ((p[i - 2] == '.') || (p[i - 2] == s[j - 1]))
                    {
                        dp[i][j] = (dp[i][j] || dp[i][j - 1]);
                    }
                }
                else
                {
                    if (p[i - 1] == '.' || p[i - 1] == s[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
            }
        }
    }
    return dp[p_len][s_len];
}