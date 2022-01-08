#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);
    vector<int> acc_left_prod(n);
    acc_left_prod[0] = 1;
    for (int i = 1; i < n; i++)
    {
        acc_left_prod[i] = acc_left_prod[i - 1] * nums[i - 1];
    }
    int right_prod = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        res[i] = acc_left_prod[i] * right_prod;
        right_prod *= nums[i];
    }
    return res;
}