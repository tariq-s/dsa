#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int sign = x >= 0 ? 1 : -1;
    x = abs(x);
    int res = 0;
    while (x)
    {
        int last = x % 10;
        res = res * 10 + last;
        if ((res * sign > INT_MAX) || (res * sign < INT_MIN))
            return 0;
        x /= 10;
    }
    return res * sign;
}