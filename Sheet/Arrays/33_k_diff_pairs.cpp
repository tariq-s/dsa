#include <bits/stdc++.h>
using namespace std;

int findPairs(vector<int> &nums, int k)
{
    if (k < 0)
        return 0;
    int count = 0;
    int n = nums.size();
    unordered_map<int, int> map;
    for (int num : nums)
    {
        map[num]++;
    }
    if (k == 0)
    {
        for (auto entry : map)
        {
            if (entry.second > 1)
                count++;
        }
        return count;
    }
    for (auto entry : map)
    {
        if (map.find(entry.first + k) != map.end())
            count++;
    }
    return count;
}