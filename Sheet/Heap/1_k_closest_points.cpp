#include <bits/stdc++.h>
using namespace std;

int distance(vector<int> &pt)
{
    return pt[0] * pt[0] + pt[1] * pt[1];
}
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<pair<int, int>> heap;

    for (int i = 0; i < k; i++)
        heap.push({distance(points[i]), i});

    for (int i = k; i < points.size(); i++)
    {
        int dist = distance(points[i]);
        if (dist < heap.top().first)
        {
            heap.pop();
            heap.push({dist, i});
        }
    }
    vector<vector<int>> res;
    while (!heap.empty())
    {
        res.push_back(points[heap.top().second]);
        heap.pop();
    }
    return res;
}