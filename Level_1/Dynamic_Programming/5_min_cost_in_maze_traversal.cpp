#include <bits/stdc++.h>
#include <vector>

using namespace std;

int minCost(int r, int c, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (r == arr.size() || r < 0 || c == arr[0].size() || c < 0)
        return INT_MAX;
    if (r == 0 && c == 0)
        return arr[0][0];
    if (dp[r][c] != -1)
        return dp[r][c];

    int min_t = minCost(r - 1, c, arr, dp);
    int min_l = minCost(r, c - 1, arr, dp);
    dp[r][c] = arr[r][c] + min(min_l, min_t);

    return dp[r][c];
}

int main()
{

    int n;
    int m;

    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    cout << minCost(n - 1, m - 1, arr, dp);
}
