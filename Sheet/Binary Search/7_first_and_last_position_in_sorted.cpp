#include <bits/stdc++.h>
using namespace std;

int bin_search(vector<int> arr, int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int ans = n;
    while (high >= low)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] >= key)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return {-1, -1};
    int start = bin_search(nums, nums.size(), target);
    int end = bin_search(nums, nums.size(), target + 1) - 1;

    if (start <= end)
        return {start, end};
    return {-1, -1};
}