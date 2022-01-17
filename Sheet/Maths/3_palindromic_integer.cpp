#include <bits/stdc++.h>
using namespace std;

int ith_digit(int x, int i)
{
    return (int)(x / pow(10, i)) % 10;
}
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    if (x == 0)
        return true;
    int n = floor(log10(x)) + 1;
    int s = 0, e = n - 1;
    while (s < e)
    {
        if (ith_digit(x, s) != ith_digit(x, e))
            return false;
        s++;
        e--;
    }
    return true;
}