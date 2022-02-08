#include <bits/stdc++.h>
using namespace std;

void dfs(int r, int c, vector<vector<int>> &grid)
{
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != 0)
        return;

    grid[r][c] = 1;

    dfs(r + 1, c, grid);
    dfs(r - 1, c, grid);
    dfs(r, c + 1, grid);
    dfs(r, c - 1, grid);
}
int closedIsland(vector<vector<int>> &grid)
{
    int res = 0;
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] == 0)
            dfs(0, i, grid);
        if (grid[n - 1][i] == 0)
            dfs(n - 1, i, grid);
    }
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 0)
            dfs(i, 0, grid);
        if (grid[i][m - 1] == 0)
            dfs(i, m - 1, grid);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                res++;
                dfs(i, j, grid);
            }
        }
    }

    return res;
}