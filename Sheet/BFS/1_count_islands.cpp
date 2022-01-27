#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>> &grid, int r, int c)
{
    queue<pair<int, int>> Queue;
    Queue.push({r, c});

    while (!Queue.empty())
    {
        pair<int, int> x = Queue.front();
        Queue.pop();

        grid[x.first][x.second] = '0';

        if (x.first + 1 < grid.size() && grid[x.first + 1][x.second] == '1')
            Queue.push({x.first + 1, x.second});
        if (x.first - 1 >= 0 && grid[x.first - 1][x.second] == '1')
            Queue.push({x.first - 1, x.second});
        if (x.second + 1 < grid[0].size() && grid[x.first][x.second + 1] == '1')
            Queue.push({x.first, x.second + 1});
        if (x.second - 1 >= 0 && grid[x.first][x.second - 1] == '1')
            Queue.push({x.first, x.second - 1});
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int res = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                res++;
                bfs(grid, i, j);
            }
        }
    }
    return res;
}