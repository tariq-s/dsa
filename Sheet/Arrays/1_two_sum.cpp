#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    map<int, int> hash_map;
    for (int i = 0; i < n; i++)
    {
        if (hash_map.find(target - nums[i]) != hash_map.end())
        {
            return {i, hash_map[target - nums[i]]};
        }
        hash_map[nums[i]] = i;
    }
    return {-1, -1};
}