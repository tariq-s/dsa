#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i1 = 0, i2 = 0, i = 0;
    vector<int> nums_1(m);
    for (int idx = 0; idx < m; idx++)
    {
        nums_1[idx] = nums1[idx];
    }

    while (i1 < m && i2 < n)
    {
        if (nums_1[i1] < nums2[i2])
        {
            nums1[i] = nums_1[i1];
            i1++;
        }
        else if (nums_1[i1] > nums2[i2])
        {
            nums1[i] = nums2[i2];
            i2++;
        }
        else
        {
            nums1[i] = nums_1[i1];
            i1++;
            i++;
            nums1[i] = nums2[i2];
            i2++;
        }
        i++;
    }
    if (i1 == m)
    {
        for (int x = i2; x < n; x++, i++)
        {
            nums1[i] = nums2[x];
        }
    }
    else
    {
        for (int x = i1; x < m; x++, i++)
        {
            nums1[i] = nums_1[x];
        }
    }
}