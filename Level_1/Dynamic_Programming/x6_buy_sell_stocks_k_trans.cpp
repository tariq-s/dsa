#include <iostream>
#include <vector>
#include <climits>

using namespace std;
// v1
// void transactions(vector<int> arr, int k)
// {
//     int n = arr.size();
//     int dp[k + 1][n];
//     for (int i = 0; i < n; i++)
//     {
//         dp[0][i] = 0;
//     }
//     for (int i = 0; i <= k; i++)
//     {
//         dp[i][0] = 0;
//     }
//     for (int i = 1; i <= k; i++)
//     {
//         for (int j = 1; j < n; j++)
//         {
//             dp[i][j] = dp[i][j - 1];
//             for (int x = 0; x < j; x++)
//             {
//                 dp[i][j] = max(dp[i][j], dp[i - 1][x] + arr[j] - arr[x]);
//             }
//         }
//     }
//     cout << dp[k][n - 1];
// }

//v2 optimized
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void transactions(vector<int> arr, int k)
{
    int n = arr.size();
    int dp[k + 1][n];
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= k; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= k; i++)
    {
        int max_ = INT_MIN;
        for (int j = 1; j < n; j++)
        {
            max_ = max(max_, dp[i - 1][j - 1] - arr[j - 1]);
            dp[i][j] = max(dp[i][j - 1], max_ + arr[j]);
        }
    }
    cout << dp[k][n - 1];
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    transactions(arr, k);

    return 0;
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    transactions(arr, k);

    return 0;
}