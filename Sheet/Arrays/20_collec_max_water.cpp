#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int n = height.size();
    int s = 0, e = n - 1;
    int max_collected = 0;
    while (s < e)
    {
        max_collected = max(max_collected, (e - s) * min(height[s], height[e]));
        if (height[s] < height[e])
        {
            s++;
        }
        else if (height[s] > height[e])
        {
            e--;
        }
        else
        {
            s++;
            e--;
        }
    }
    return max_collected;
}