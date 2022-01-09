#include <bits/stdc++.h>
using namespace std;
int threeSumClosest(vector<int> &nums, int target)
{
    int n = nums.size();
    int diff = INT_MAX;
    int res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++)
    {
        int s = i + 1, e = n - 1;
        while (s < e)
        {
            int sum = nums[i] + nums[s] + nums[e];
            if (abs(sum - target) < diff)
            {
                res = sum;
                diff = abs(sum - target);
            }
            if (sum < target)
            {
                s++;
            }
            else if (sum > target)
            {
                e--;
            }
            else
            {
                return res;
            }
        }
    }
    return res;
}