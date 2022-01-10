#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    vector<int> acc_left(n);
    vector<int> acc_right(n);
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += cardPoints[i];
        acc_left[i] = sum;
    }
    int res = sum;
    sum = 0;
    for (int i = n - 1; i > n - 1 - k; i--)
    {
        sum += cardPoints[i];
        acc_right[i] = sum;
    }
    res = max(res, sum);

    for (int i = 0, j = n - k + 1; j < n; i++, j++)
    {
        res = max(res, acc_left[i] + acc_right[j]);
    }
    return res;
}