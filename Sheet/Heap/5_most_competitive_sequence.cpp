#include <bits/stdc++.h>
using namespace std;

vector<int> mostCompetitive(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n - k; i++)
        heap.push({nums[i], i});
    int prev_idx = -1;
    for (int i = n - k; i < n; i++)
    {
        heap.push({nums[i], i});

        while (heap.top().second < prev_idx)
            heap.pop();
        pair<int, int> x = heap.top();
        heap.pop();
        prev_idx = x.second;
        res.push_back(x.first);
    }
    return res;
}