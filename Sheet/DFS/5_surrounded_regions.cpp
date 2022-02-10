#include <bits/stdc++.h>
using namespace std;

void fill(int r, int c, vector<vector<char>> &board, char color)
{
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != color)
        return;
    board[r][c] = '-';
    fill(r + 1, c, board, color);
    fill(r - 1, c, board, color);
    fill(r, c + 1, board, color);
    fill(r, c - 1, board, color);
}
void dfs(int r, int c, vector<vector<char>> &board, char from, char to)
{
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != from)
        return;
    board[r][c] = to;
    dfs(r + 1, c, board, from, to);
    dfs(r - 1, c, board, from, to);
    dfs(r, c + 1, board, from, to);
    dfs(r, c - 1, board, from, to);
}
void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O')
        {
            fill(i, 0, board, board[i][0]);
        }
        if (board[i][m - 1] == 'O')
        {
            fill(i, m - 1, board, board[i][m - 1]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (board[0][i] == 'O')
        {
            fill(0, i, board, board[0][i]);
        }
        if (board[n - 1][i] == 'O')
        {
            fill(n - 1, i, board, board[n - 1][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O')
                dfs(i, j, board, 'O', 'X');
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '-')
                dfs(i, j, board, '-', 'O');
        }
    }
}