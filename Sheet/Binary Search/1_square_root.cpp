#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x)
{
    if (x == 0)
        return 0;
    int low = 1, high = x;
    int ans;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid == x / mid)
            return mid;
        if (mid > x / mid)
            high = mid - 1;
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}