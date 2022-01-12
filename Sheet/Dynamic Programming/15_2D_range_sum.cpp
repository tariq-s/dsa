#include <bits/stdc++.h>
using namespace std;

class NumMatrix
{
    vector<vector<int>> dp;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = matrix[i][j];
                }
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j - 1] + matrix[i][j];
                }
                else if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + matrix[i][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int a = row1 > 0 ? dp[row1 - 1][col2] : 0, b = col1 > 0 ? dp[row2][col1 - 1] : 0, c = row1 > 0 && col1 > 0 ? dp[row1 - 1][col1 - 1] : 0;
        return dp[row2][col2] - a - b + c;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */