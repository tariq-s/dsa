#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int> &nums)
{
    vector<int> res;
    int n = nums.size();
    if (n == 0)
        return res;
    int sum = nums[0];
    res.push_back(sum);
    for (int i = 1; i < n; i++)
    {
        sum += nums[i];
        res.push_back(sum);
    }
    return res;
}