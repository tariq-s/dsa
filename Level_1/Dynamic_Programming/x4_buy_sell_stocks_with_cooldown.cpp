#include <iostream>
#include <vector>

using namespace std;

void transaction(vector<int> arr)
{
    int n = arr.size();
    int prev_b = -arr[0];
    int prev_s = 0;
    int prev_c = 0;
    int curr_b, curr_s, curr_c;
    for (int i = 1; i < n; i++)
    {
        curr_b = max(prev_b, prev_c - arr[i]);
        curr_s = max(prev_s, prev_b + arr[i]);
        curr_c = prev_s;

        prev_b = curr_b;
        prev_s = curr_s;
        prev_c = curr_c;
    }

    cout << max(curr_s, curr_c);
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

    transaction(arr);
    return 0;
}
