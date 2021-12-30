#include <bits/stdc++.h>
#include <vector>
using namespace std;

int cs(int arr[], int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int min_ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (i + arr[i] >= n)
        {
            min_ans = min(min_ans, cs(arr, i, dp));
        }
    }
    dp[n] = 1 + min_ans;
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> dp(n + 1, -1);

    cout << cs(arr, n, dp) << endl;
}