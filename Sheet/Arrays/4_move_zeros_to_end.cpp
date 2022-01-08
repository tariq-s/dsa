#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = 0;
    while (i < n)
    {
        if (nums[i] == 0)
        {
            i++;
        }
        else
        {
            swap(nums, j, i);
            i++;
            j++;
        }
    }
}