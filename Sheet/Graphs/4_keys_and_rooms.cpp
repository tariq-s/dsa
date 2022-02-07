#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> &rooms, vector<bool> &visited)
{
    visited[i] = true;
    for (int n : rooms[i])
    {
        if (!visited[n])
            dfs(n, rooms, visited);
    }
}
bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    vector<bool> visited(n, false);

    dfs(0, rooms, visited);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            return false;
    }
    return true;
}