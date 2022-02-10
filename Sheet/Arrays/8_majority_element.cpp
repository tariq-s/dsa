#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int maj_ele;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
            maj_ele = nums[i];
        if (nums[i] == maj_ele)
            count++;
        else
            count--;
    }
    return maj_ele;
}