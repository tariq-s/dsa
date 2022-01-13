#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> max_left(n);
    vector<int> max_right(n);
    max_left[0] = 0;
    for (int i = 1; i < n; i++)
    {
        max_left[i] = max(max_left[i - 1], height[i - 1]);
    }
    max_right[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        max_right[i] = max(max_right[i + 1], height[i + 1]);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int collect = min(max_left[i], max_right[i]) - height[i];
        if (collect > 0)
            res += collect;
    }
    return res;
}