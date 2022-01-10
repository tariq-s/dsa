#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{
    int n = nums.size();
    queue<pair<int, int>> Queue;
    Queue.push({0, 0});
    int max_so_far = 0;
    while (!Queue.empty())
    {
        pair<int, int> x = Queue.front();
        Queue.pop();

        if (x.first == n - 1)
        {
            return x.second;
        }

        for (int i = max(max_so_far, x.first + 1); i <= x.first + nums[x.first]; i++)
        {
            max_so_far = i;
            Queue.push({i, x.second + 1});
        }
    }
    return -1;
}