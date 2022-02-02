#include <bits/stdc++.h>
using namespace std;

int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{
    priority_queue<int> heap;
    int n = heights.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (heights[i] - heights[i + 1] >= 0)
            continue;

        int diff = heights[i + 1] - heights[i];

        if (bricks >= diff)
        {
            bricks -= diff;
            heap.push(diff);
        }
        else if (ladders > 0)
        {
            if (!heap.empty() && heap.top() > diff)
            {
                bricks += heap.top();
                heap.pop();
                bricks -= diff;
                heap.push(diff);
            }
            ladders--;
        }
        else
        {
            return i;
        }
    }
    return n - 1;
}