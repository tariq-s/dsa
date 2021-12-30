#include <bits/stdc++.h>
using namespace std;
void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}
void targetSumSubset(vector<int> &arr, int target)
{
    bool dp[arr.size() + 1][target + 1];
    for (int i = 0; i <= arr.size(); i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = false;
        }
    }
    for (int i = 0; i <= arr.size(); i++)
    {
        dp[i][0] = true;
    }

    dp[1][arr[0]] = true;

    for (int i = 2; i <= arr.size(); i++)
    {
        for (int j = 1; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }
    cout << (dp[arr.size()][target] ? "true" : "false");
}
int main()
{
    int n, target;
    cin >> n;
    vector<int> vec(n, 0);
    input(vec);
    cin >> target;
    targetSumSubset(vec, target);
    return 0;
}