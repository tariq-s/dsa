#include <bits/stdc++.h>
using namespace std;

int bin_search(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;

    if (nums[mid] == target)
        return mid;
    if (nums[mid] < target)
        return bin_search(nums, mid + 1, high, target);
    return bin_search(nums, low, mid - 1, target);
}
int get_peak(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        int mid = low + ceil((float)(high - low) / 2);

        if (nums[mid] > nums[low])
            low = mid;
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int search(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;
    int peak = get_peak(nums);
    cout << peak;
    if (nums[0] <= target && target <= nums[peak])
        return bin_search(nums, 0, peak, target);
    return bin_search(nums, peak + 1, nums.size() - 1, target);
    return 0;
}