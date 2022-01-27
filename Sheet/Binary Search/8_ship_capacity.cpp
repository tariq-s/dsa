#include <bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int low = INT_MIN, high = 0;
    for (int w : weights)
    {
        low = max(low, w);
        high += w;
    }
    int ans = high;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int cap = mid;
        int d = days;
        int i = 0;

        while (i < n && d > 0)
        {
            cap -= weights[i];
            i++;
            if (i < n && cap < weights[i])
            {
                cap = mid;
                d--;
            }
        }

        if (i < n)
            low = mid + 1;
        else
        {
            ans = mid;
            high = mid;
        }
    }
    return ans;
}