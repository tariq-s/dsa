#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
void sortColors(vector<int> &nums)
{
    int i = 0;
    int k = nums.size() - 1;
    int j = 0;

    while (i <= k)
    {
        if (nums[i] == 0)
        {
            swap(nums, j, i);
            j++;
            i++;
        }
        else if (nums[i] == 1)
        {
            i++;
        }
        else
        {
            swap(nums, i, k);
            k--;
        }
    }
}