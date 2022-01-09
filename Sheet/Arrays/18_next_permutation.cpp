#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &nums, int i1, int i2)
{
    int temp = nums[i1];
    nums[i1] = nums[i2];
    nums[i2] = temp;
}
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int i = n - 1;
    while (i > 0 && nums[i] <= nums[i - 1])
    {
        i--;
    }
    if (i != 0)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (nums[j] > nums[i - 1] && nums[j] < nums[k])
            {
                k = j;
            }
        }
        swap(nums, i - 1, k);
    }
    sort(nums.begin() + i, nums.end());
}