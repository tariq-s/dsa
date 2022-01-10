#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    if (nums.size() < 4)
        return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int sum = nums[i] + nums[j];
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] == target - sum)
                {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (nums[left] + nums[right] < target - sum)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    return res;
}