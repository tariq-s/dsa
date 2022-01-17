#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    if (n == 0 || n == INT_MIN)
        return false;
    return (n & (n - 1)) == 0;
}