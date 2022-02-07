#include <bits/stdc++.h>
using namespace std;

double find_path(unordered_map<string, vector<pair<string, double>>> &adj, vector<string> q)
{
    string v1 = q[0];
    string v2 = q[1];

    if (adj.find(v1) == adj.end() || adj.find(v2) == adj.end())
        return -1;

    queue<pair<string, double>> Queue;
    Queue.push({v1, 1});
    unordered_map<string, bool> visited;

    while (!Queue.empty())
    {
        pair<string, double> x = Queue.front();
        Queue.pop();

        if (visited.find(x.first) != visited.end())
            continue;
        visited[x.first] = true;

        if (x.first == v2)
            return x.second;
        for (auto n : adj[x.first])
        {
            if (visited.find(n.first) == visited.end())
                Queue.push({n.first, x.second * n.second});
        }
    }
    return -1;
}
vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    unordered_map<string, vector<pair<string, double>>> adj;
    for (int i = 0; i < values.size(); i++)
    {
        string var1 = equations[i][0];
        string var2 = equations[i][1];

        adj[var1].push_back({var2, values[i]});
        adj[var2].push_back({var1, 1 / values[i]});
    }

    vector<double> res;
    for (int i = 0; i < queries.size(); i++)
    {
        res.push_back(find_path(adj, queries[i]));
    }
    return res;
}