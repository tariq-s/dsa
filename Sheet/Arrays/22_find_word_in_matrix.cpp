#include <bits/stdc++.h>
using namespace std;

bool word_exists(vector<vector<char>> &board, int r, int c, int idx, string word, vector<vector<bool>> &visited, int n, int m)
{
    if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c])
        return false;
    if (board[r][c] != word[idx])
        return false;
    if (idx == word.size() - 1)
        return true;
    visited[r][c] = true;
    bool exists = word_exists(board, r + 1, c, idx + 1, word, visited, n, m) ||
                  word_exists(board, r, c + 1, idx + 1, word, visited, n, m) ||
                  word_exists(board, r - 1, c, idx + 1, word, visited, n, m) ||
                  word_exists(board, r, c - 1, idx + 1, word, visited, n, m);
    visited[r][c] = false;
    return exists;
}
bool exist(vector<vector<char>> &board, string word)
{
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (word_exists(board, i, j, 0, word, visited, board.size(), board[0].size()))
                return true;
        }
    }
    return false;
}