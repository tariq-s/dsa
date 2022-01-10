#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size();
    int sum = 0;
    int count = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        int rem = sum % k < 0 ? sum % k + k : sum % k;
        if (map.find(rem) != map.end())
        {
            count += map[rem];
        }
        map[rem]++;
    }
    return count;
}