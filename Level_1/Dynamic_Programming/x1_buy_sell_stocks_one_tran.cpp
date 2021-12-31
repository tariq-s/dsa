#include <iostream>
#include <vector>

using namespace std;

void Transaction(vector<int> arr)
{
    int min_past = arr[0];
    int ans = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < min_past)
            min_past = arr[i];
        else
            ans = max(arr[i] - min_past, ans);
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
    Transaction(arr);
    return 0;
}