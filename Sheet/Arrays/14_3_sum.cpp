#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    if (n < 3 || nums[0] > 0)
        return {};

    vector<vector<int>> res;
    for (int i = 0; i < n - 2; i++)
    {
        if (nums[i] > 0)
            break;
        if (i != 0 && nums[i - 1] == nums[i])
            continue;
        int s = i + 1, e = n - 1;
        while (s < e)
        {
            if (nums[i] + nums[s] + nums[e] == 0)
            {
                res.push_back({nums[i], nums[s], nums[e]});
                int last_s = nums[s], last_e = nums[e];
                while (s < e && nums[s] == last_s)
                    s++;
                while (s < e && nums[e] == last_e)
                    e--;
            }
            else if (nums[i] + nums[s] + nums[e] < 0)
            {
                s++;
            }
            else
            {
                e--;
            }
        }
    }
    return res;
}