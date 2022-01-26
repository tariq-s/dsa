#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    for (int num : nums)
    {
        freq[num]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    for (auto entry : freq)
    {
        if (heap.size() < k)
            heap.push({entry.second, entry.first});
        else
        {
            if (heap.top().first < entry.second)
            {
                heap.pop();
                heap.push({entry.second, entry.first});
            }
        }
    }
    vector<int> res;
    while (!heap.empty())
    {
        res.push_back(heap.top().second);
        heap.pop();
    }
    return res;
}