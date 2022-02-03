#include <bits/stdc++.h>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
{
    priority_queue<int> heap;
    int fuel = startFuel;
    int dist = 0;
    int ans = 0;
    for (int i = 0; i < stations.size(); i++)
    {
        while (!heap.empty() && fuel < stations[i][0] - dist)
        {
            fuel += heap.top();
            ans++;
            heap.pop();
        }

        if (fuel < stations[i][0] - dist)
            return -1;

        fuel -= stations[i][0] - dist;
        dist += stations[i][0] - dist;

        heap.push(stations[i][1]);
    }

    while (!heap.empty() && fuel < target - dist)
    {
        fuel += heap.top();
        ans++;
        heap.pop();
    }

    return fuel >= target - dist ? ans : -1;
}