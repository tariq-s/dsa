#include <bits/stdc++.h>
using namespace std;
void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar)
{
    if (idx == arr.size())
    {
        if (sos == tar)
            cout << set << '.' << endl;
        return;
    }
    printTargetSumSubsets(arr, idx + 1, set + to_string(arr[idx]) + ", ", sos + arr[idx], tar);
    printTargetSumSubsets(arr, idx + 1, set, sos, tar);
}