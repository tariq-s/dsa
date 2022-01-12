#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    int n = coins.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}