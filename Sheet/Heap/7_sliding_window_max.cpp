#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> Deque;
    int n = nums.size();
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (!Deque.empty() && Deque.front() == i - k)
        {
            Deque.pop_front();
        }
        while (!Deque.empty() && nums[Deque.back()] < nums[i])
        {
            Deque.pop_back();
        }
        Deque.push_back(i);

        if (i >= k - 1)
            res.push_back(nums[Deque.front()]);
    }
    return res;
}