#include <iostream>
#include <vector>

using namespace std;

void zeroOneKnapsack(int n, vector<int> val, vector<int> weight, int cap)
{

    int dp[n + 1][cap + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= cap; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= cap; j++)
        {
            if (j < weight[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - weight[i - 1]]);
            }
        }
    }
    cout << dp[n][cap];
}

int main()
{

    int n;
    cin >> n;

    vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    vector<int> weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    int cap;
    cin >> cap;

    zeroOneKnapsack(n, val, weight, cap);
}