#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return true;
    int last = n - 1;
    int i;
    for (i = n - 2; i >= 0; i--)
    {
        if (i + nums[i] >= last)
        {
            if (i == 0)
                return true;
            last = i;
        }
    }
    return false;
}