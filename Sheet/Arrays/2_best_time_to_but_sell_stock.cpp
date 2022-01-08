#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int best_buy = INT_MAX;
    int max_profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (prices[i] < best_buy)
        {
            best_buy = prices[i];
        }
        else
            max_profit = max(max_profit, prices[i] - best_buy);
    }
    return max_profit;
}