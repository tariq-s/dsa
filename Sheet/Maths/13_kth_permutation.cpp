#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k)
{
    vector<int> factorial(n + 1);
    factorial[0] = factorial[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial[i] = i * factorial[i - 1];
    }

    k--;
    vector<int> nums(n + 1);
    for (int i = 0; i <= n; i++)
        nums[i] = i;
    char c;
    string res = "";
    int idx;
    for (int i = 1; i <= n; i++)
    {
        idx = k / factorial[n - i];
        c = nums[idx] + 1 + '0';
        res += c;
        nums.erase(nums.begin() + idx);
        k %= factorial[n - i];
    }
    return res;
}