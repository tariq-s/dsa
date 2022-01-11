#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    int m = matrix[0].size();
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int max_square_len = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                max_square_len = max(max_square_len, dp[i][j]);
            }
            else
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    max_square_len = max(max_square_len, dp[i][j]);
                }
            }
        }
    }
    return max_square_len * max_square_len;
}