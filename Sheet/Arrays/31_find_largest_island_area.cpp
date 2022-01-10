#include <bits/stdc++.h>
using namespace std;

void calc_area(vector<vector<int>> &grid, int r, int c, int n, int m, int &area)
{
    if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0)
        return;

    grid[r][c] = 0;
    area++;
    calc_area(grid, r - 1, c, n, m, area);
    calc_area(grid, r + 1, c, n, m, area);
    calc_area(grid, r, c - 1, n, m, area);
    calc_area(grid, r, c + 1, n, m, area);
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int max_area = 0;
    int area = 0;
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                area = 0;
                calc_area(grid, i, j, n, m, area);
                max_area = max(max_area, area);
            }
        }
    }
    return max_area;
}