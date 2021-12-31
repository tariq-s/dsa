#include <iostream>
#include <vector>

using namespace std;

void transactions(vector<int> arr, int fee)
{
    int n = arr.size();
    int prev_b = -arr[0];
    int prev_s = 0;

    int curr_b, curr_s;
    for (int i = 1; i < n; i++)
    {
        curr_b = max(prev_b, prev_s - arr[i]);
        curr_s = max(prev_s, prev_b + arr[i] - fee);

        prev_b = curr_b;
        prev_s = curr_s;
    }
    cout << curr_s;
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
    int fee;
    cin >> fee;

    transactions(arr, fee);

    return 0;
}
