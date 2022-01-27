#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<int, int>> Queue;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 2)
                Queue.push({i, j});
        }
    }
    int res = -1;
    while (!Queue.empty())
    {

        int size = Queue.size();

        for (int i = 0; i < size; i++)
        {
            pair<int, int> x = Queue.front();
            Queue.pop();

            if (x.first + 1 < grid.size() && grid[x.first + 1][x.second] == 1)
            {
                Queue.push({x.first + 1, x.second});
                grid[x.first + 1][x.second] = 2;
            }
            if (x.first - 1 >= 0 && grid[x.first - 1][x.second] == 1)
            {
                Queue.push({x.first - 1, x.second});
                grid[x.first - 1][x.second] = 2;
            }
            if (x.second + 1 < grid[0].size() && grid[x.first][x.second + 1] == 1)
            {
                Queue.push({x.first, x.second + 1});
                grid[x.first][x.second + 1] = 2;
            }
            if (x.second - 1 >= 0 && grid[x.first][x.second - 1] == 1)
            {
                Queue.push({x.first, x.second - 1});
                grid[x.first][x.second - 1] = 2;
            }
        }
        res++;
    }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }
    return res == -1 ? 0 : res;
}