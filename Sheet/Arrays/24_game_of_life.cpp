#include <bits/stdc++.h>
using namespace std;

int count_live_neighbours(vector<vector<int>> &board, int i, int j, int n, int m)
{
    int count = 0;
    if (i - 1 >= 0 && board[i - 1][j] % 2)
        count++;

    if (i - 1 >= 0 && j + 1 < m && board[i - 1][j + 1] % 2)
        count++;

    if (j + 1 < m && board[i][j + 1] % 2)
        count++;

    if (i + 1 < n && j + 1 < m && board[i + 1][j + 1] % 2)
        count++;

    if (i + 1 < n && board[i + 1][j] % 2)
        count++;

    if (i + 1 < n && j - 1 >= 0 && board[i + 1][j - 1] % 2)
        count++;

    if (j - 1 >= 0 && board[i][j - 1] % 2)
        count++;

    if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] % 2)
        count++;

    return count;
}
void gameOfLife(vector<vector<int>> &board)
{
    int n = board.size(), m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int count = count_live_neighbours(board, i, j, n, m);
            if (board[i][j] == 1)
            {
                cout << count << " ";
                if (count == 2 || count == 3)
                {
                    board[i][j] = 3;
                }
            }
            else if (board[i][j] == 0)
            {
                if (count == 3)
                {
                    board[i][j] = 2;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i][j] = board[i][j] >> 1;
        }
    }
}