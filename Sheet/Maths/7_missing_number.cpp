#include <bits/stdc++.h>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int xo = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xo ^= nums[i] ^ i;
    }
    return xo ^ nums.size();
}