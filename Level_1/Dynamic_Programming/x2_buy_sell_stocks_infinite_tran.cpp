#include <iostream>
#include <vector>

using namespace std;

void transactions(vector<int> arr)
{

    int ans = 0;
    int b = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
        {
            ans += arr[i - 1] - arr[b];
            b = i;
        }
    }
    ans += arr[arr.size() - 1] - arr[b];
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