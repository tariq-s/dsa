#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;

    int dp[n + 1][k + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 1)
            {
                dp[i][j] = 1;
            }
            else if (i < j)
            {
                dp[i][j] = 0;
            }
            else if (i == j)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = j * dp[i - 1][j] + dp[i - 1][k - 1];
            }
        }
    }
    cout << dp[n][k];
}