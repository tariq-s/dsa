#include <bits/stdc++.h>
using namespace std;

bool divisorGame(int n)
{
    vector<int> dp(n + 1, false);
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0 && dp[i - j] == false)
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}