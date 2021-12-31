#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void min_cost(vector<vector<int>> arr, int n, int k)
{
    int dp[n][k];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i == 0)
            {
                dp[i][j] = arr[i][j];
            }
            else
            {
                int min_ = INT_MAX;
                for (int x = 0; x < k; x++)
                {
                    if (x != j)
                        min_ = min(min_, dp[i - 1][x]);
                }
                dp[i][j] = arr[i][j] + min_;
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        ans = min(ans, dp[n - 1][i]);
    }
    cout << ans;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<vector<int>> arr(n, vector<int>(k));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> arr[i][j];
        }
    }
    min_cost(arr, n, k);
}