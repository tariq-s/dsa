#include <bits/stdc++.h>
using namespace std;

int findMaxValueOfEquation(vector<vector<int>> &points, int k)
{
    int n = points.size();
    int res = INT_MIN;
    priority_queue<pair<int, int>> heap;
    heap.push({points[0][1] - points[0][0], 0});
    for (int i = 1; i < n; i++)
    {
        while (!heap.empty() && (points[i][0] - points[heap.top().second][0] > k))
            heap.pop();
        if (!heap.empty())
            res = max(res, points[i][0] + points[i][1] + heap.top().first);
        heap.push({points[i][1] - points[i][0], i});
    }
    return res;
}