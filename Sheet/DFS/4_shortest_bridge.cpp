#include <bits/stdc++.h>
using namespace std;

void fill(int r, int c, vector<vector<int>> &grid, int color, queue<pair<pair<int, int>, int>> &Queue)
{
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid.size() || grid[r][c] != color)
        return;

    grid[r][c] = 2;
    Queue.push({{r, c}, 0});

    fill(r + 1, c, grid, color, Queue);
    fill(r - 1, c, grid, color, Queue);
    fill(r, c + 1, grid, color, Queue);
    fill(r, c - 1, grid, color, Queue);
}
int bridge(vector<vector<int>> &grid, queue<pair<pair<int, int>, int>> &Queue)
{
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
    while (!Queue.empty())
    {
        pair<pair<int, int>, int> x = Queue.front();
        Queue.pop();

        int r = x.first.first;
        int c = x.first.second;

        if (visited[r][c])
            continue;
        visited[r][c] = true;

        if (grid[r][c] == 1)
            return x.second - 1;

        if (r + 1 < grid.size() && !visited[r + 1][c] && grid[r + 1][c] != 2)
            Queue.push({{r + 1, c}, x.second + 1});

        if (r - 1 >= 0 && !visited[r - 1][c] && grid[r - 1][c] != 2)
            Queue.push({{r - 1, c}, x.second + 1});

        if (c + 1 < grid.size() && !visited[r][c + 1] && grid[r][c + 1] != 2)
            Queue.push({{r, c + 1}, x.second + 1});

        if (c - 1 >= 0 && !visited[r][c - 1] && grid[r][c - 1] != 2)
            Queue.push({{r, c - 1}, x.second + 1});
    }
    return -1;
}
int shortestBridge(vector<vector<int>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {
            if (grid[i][j] == 1)
            {
                queue<pair<pair<int, int>, int>> Queue;
                fill(i, j, grid, grid[i][j], Queue);
                return bridge(grid, Queue);
            }
        }
    }
    return -1;
}