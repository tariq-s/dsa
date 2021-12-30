#include <iostream>
using namespace std;

int cs(int arr[], int n)
{
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = 0;

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j + arr[j] >= i)
            {
                dp[i] += dp[j];
            }
        }
    }

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
    cout << cs(arr, n) << endl;
}