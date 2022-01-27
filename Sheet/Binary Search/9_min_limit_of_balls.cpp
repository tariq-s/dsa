#include <bits/stdc++.h>
using namespace std;

int minimumSize(vector<int> &nums, int maxOperations)
{
    int low = 1, high = INT_MIN;
    for (int n : nums)
        high = max(high, n);
    int ans = high;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int op = 0;
        for (int num : nums)
        {
            op += (num - 1) / mid;
        }
        if (op > maxOperations)
            low = mid + 1;
        else
        {
            ans = mid;
            high = mid;
        }
    }
    return ans;
}