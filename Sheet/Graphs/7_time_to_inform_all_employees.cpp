#include <bits/stdc++.h>
using namespace std;

int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < manager.size(); i++)
    {
        if (manager[i] == -1)
            continue;

        adj[manager[i]].push_back(i);
    }

    int res = 0;
    queue<pair<int, int>> Queue;
    Queue.push({headID, 0});

    while (!Queue.empty())
    {
        pair<int, int> curr = Queue.front();
        Queue.pop();

        res = max(res, curr.second);

        for (int sub : adj[curr.first])
        {
            Queue.push({sub, curr.second + informTime[curr.first]});
        }
    }
    return res;
}