#include <bits/stdc++.h>
using namespace std;

void dfs(int i, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
{
    if (visited[i])
        return;
    visited[i] = true;

    for (int n : adj[i])
    {
        dfs(n, adj, visited);
    }
}
int makeConnected(int n, vector<vector<int>> &connections)
{
    if (connections.size() < n - 1)
        return -1;
    vector<bool> visited(n, false);
    int connected_components = 0;
    unordered_map<int, vector<int>> adj;
    for (auto edge : connections)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            connected_components++;
            dfs(i, adj, visited);
        }
    }
    return connected_components - 1;
}