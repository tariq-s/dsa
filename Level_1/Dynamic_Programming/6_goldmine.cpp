#include <bits/stdc++.h>
using namespace std;

int collectGold(int n, int m, vector<vector<int>> &arr)
{
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        dp[i][m - 1] = arr[i][m - 1];
    }
    int ans = INT_MIN;
    for (int c = m - 2; c >= 0; c--)
    {
        dp[0][c] = arr[0][c] + max(dp[0][c + 1], dp[1][c + 1]);
        for (int r = 1; r < n - 1; r++)
        {
            dp[r][c] = arr[r][c] + max(max(dp[r - 1][c + 1], dp[r][c + 1]), dp[r + 1][c + 1]);
        }
        dp[n - 1][c] = arr[n - 1][c] + max(dp[n - 1 - 1][c + 1], dp[n - 1][c + 1]);
    }

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i][0]);
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << collectGold(n, m, arr);
}