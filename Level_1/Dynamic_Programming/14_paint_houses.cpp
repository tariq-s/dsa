#include <bits/stdc++.h>
using namespace std;

void min_cost(int arr[][3], int n)
{
    int dp[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0)
            {
                dp[i][j] = arr[i][j];
            }
            else
            {
                if (j == 0)
                {
                    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
                }
                else if (j == 1)
                {
                    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
                }
                else
                {
                    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
                }
                dp[i][j] += arr[i][j];
            }
        }
    }
    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
}

int main()
{
    int n;
    cin >> n;

    int arr[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    min_cost(arr, n);
    return 0;
}