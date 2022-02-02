#include <bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n)
{
    vector<int> dp(n + 1);
    dp[1] = 1;

    int p2 = 1;
    int p3 = 1;
    int p5 = 1;

    for (int i = 2; i <= n; i++)
    {
        int f2 = 2 * dp[p2];
        int f3 = 3 * dp[p3];
        int f5 = 5 * dp[p5];

        dp[i] = min(f2, min(f3, f5));

        if (dp[i] == f2)
            p2++;
        if (dp[i] == f3)
            p3++;
        if (dp[i] == f5)
            p5++;
    }
    return dp[n];
}