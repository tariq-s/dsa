#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> map;
    map[0] = -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (map.find(sum % k) != map.end())
        {
            if (i - map[sum % k] > 1)
                return true;
        }
        else
        {
            map[sum % k] = i;
        }
    }
    return false;
}
