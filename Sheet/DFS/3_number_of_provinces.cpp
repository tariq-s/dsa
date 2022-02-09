#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> &isConnected, vector<bool> &visited)
{
    if (visited[i])
        return;
    visited[i] = true;
    for (int n = 0; n < isConnected.size(); n++)
    {
        if (isConnected[i][n])
            dfs(n, isConnected, visited);
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();

    vector<bool> visited(n, false);
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            res++;
            dfs(i, isConnected, visited);
        }
    }
    return res;
}