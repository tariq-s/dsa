#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> sell(n);
    sell[0] = 0;
    int prev_min = prices[0];
    for (int i = 1; i < n; i++)
    {
        if (prices[i] < prev_min)
        {
            prev_min = prices[i];
        }
        sell[i] = max(sell[i - 1], prices[i] - prev_min);
    }
    vector<int> buy(n);
    buy[n - 1] = 0;
    int prev_max = prices[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (prices[i] > prev_max)
        {
            prev_max = prices[i];
        }
        buy[i] = max(buy[i + 1], prev_max - prices[i]);
    }
    int max_profit = 0;
    for (int i = 0; i < n; i++)
    {
        max_profit = max(max_profit, sell[i] + buy[i]);
    }
    return max_profit;
}