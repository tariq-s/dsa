#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void transactions(vector<int> arr)
{
    int n = arr.size();

    int min_past = arr[0];
    int sell[n];
    sell[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min_past)
        {
            min_past = arr[i];
        }
        sell[i] = max(sell[i - 1], arr[i] - min_past);
    }

    int max_future = arr[n - 1];
    int buy[n];
    buy[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > max_future)
        {
            max_future = arr[i];
        }
        buy[i] = max(buy[i + 1], max_future - arr[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, buy[i] + sell[i]);
    }
    cout << ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    transactions(arr);

    return 0;
}