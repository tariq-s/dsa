#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int prev_buy = -prices[0];
    int prev_sell = 0;
    int buy, sell;
    for (int i = 1; i < n; i++)
    {
        buy = max(prev_buy, prev_sell - prices[i]);
        sell = max(prev_sell, prev_buy + prices[i]);

        prev_buy = buy;
        prev_sell = sell;
    }
    return max(prev_buy, prev_sell);
}