#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int res = 0;
    unordered_map<int, int> hash;
    hash[0] = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (hash.find(sum - k) != hash.end())
        {
            res += hash[sum - k];
        }
        hash[sum]++;
    }
    return res;
}