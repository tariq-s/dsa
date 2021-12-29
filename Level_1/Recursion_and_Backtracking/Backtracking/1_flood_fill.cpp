#include <iostream>
#include <vector>

using namespace std;

void flood_fill_helper(vector<vector<int>> &maze, int sr, int sc, int dr, int dc, vector<vector<bool>> &visited, string psf)
{
    if (sr == dr && sc == dc)
    {
        cout << psf << endl;
        return;
    }
    if (sr > dr || sr < 0 || sc > dc || sc < 0 || visited[sr][sc] || maze[sr][sc] != 0)
        return;
    visited[sr][sc] = true;
    flood_fill_helper(maze, sr - 1, sc, dr, dc, visited, psf + "t");
    flood_fill_helper(maze, sr, sc - 1, dr, dc, visited, psf + "l");
    flood_fill_helper(maze, sr + 1, sc, dr, dc, visited, psf + "d");
    flood_fill_helper(maze, sr, sc + 1, dr, dc, visited, psf + "r");
    visited[sr][sc] = false;
}

void floodfill(vector<vector<int>> maze)
{
    int n = maze.size();
    int m = maze[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m));
    flood_fill_helper(maze, -1, 0, n - 1, m - 1, visited, "t");
    flood_fill_helper(maze, 0, -1, n - 1, m - 1, visited, "l");
    flood_fill_helper(maze, 1, 0, n - 1, m - 1, visited, "d");
    flood_fill_helper(maze, 0, 1, n - 1, m - 1, visited, "r");
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    floodfill(arr);
}