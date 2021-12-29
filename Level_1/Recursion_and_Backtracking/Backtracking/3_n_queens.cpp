#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> &chess, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        if (chess[i][c] == 1)
            return false;
    }

    for (int i = 1; r - i >= 0 && c + i < chess.size(); i++)
    {
        if (chess[r - i][c + i] == 1)
            return false;
    }

    for (int i = 1; r - i >= 0 && c - i >= 0; i++)
    {
        if (chess[r - i][c - i] == 1)
            return false;
    }
    return true;
}

void printNQueens(vector<vector<int>> &chess, string qsf, int row)
{
    if (row == chess.size())
    {
        cout << qsf << ".\n";
        return;
    }
    for (int i = 0; i < chess.size(); i++)
    {
        if (check(chess, row, i))
        {
            chess[row][i] = 1;
            printNQueens(chess, qsf + to_string(row) + "-" + to_string(i) + ", ", row + 1);
            chess[row][i] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> chess(n, vector<int>(n));
    printNQueens(chess, "", 0);
}