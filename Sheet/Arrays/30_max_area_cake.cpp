#include <bits/stdc++.h>
using namespace std;

int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
{
    int tr = 0, tc = 0, br = h, bc = w;
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    int max_h = max(horizontalCuts[0], h - horizontalCuts.back()), max_v = max(verticalCuts[0], w - verticalCuts.back());

    for (int i = 1; i < horizontalCuts.size(); i++)
    {
        max_h = max(max_h, horizontalCuts[i] - horizontalCuts[i - 1]);
    }

    for (int i = 1; i < verticalCuts.size(); i++)
    {
        max_v = max(max_v, verticalCuts[i] - verticalCuts[i - 1]);
    }

    return (long)max_h * max_v % 1000000007;
}