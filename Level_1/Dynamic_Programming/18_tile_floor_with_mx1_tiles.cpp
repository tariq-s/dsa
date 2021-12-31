#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int dp[n + 1];
    for (int i = 1; i < m; i++)
    {
        dp[i] = 1;
    }
    dp[m] = 2;

    for (int i = m + 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - m];
    }

    cout << dp[n];
}