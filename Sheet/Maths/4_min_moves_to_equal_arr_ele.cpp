#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<int> &nums)
{
    int min_val = INT_MAX;
    int n = nums.size();
    if (n < 2)
        return 0;
    int sum = 0;
    for (int num : nums)
    {
        min_val = min(num, min_val);
        sum += num;
    }

    return sum - min_val * n;
}