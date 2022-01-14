#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
int firstMissingPositive(vector<int> &nums)
{
    int i = 0;
    int n = nums.size();
    nums.push_back(0);
    while (i < n)
    {
        if (nums[i] < 0 || nums[i] > n || nums[i] == i || nums[i] == nums[nums[i]])
        {
            i++;
        }
        else
        {
            swap(nums, i, nums[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (nums[i] != i)
            return i;
    }
    return n + 1;
}