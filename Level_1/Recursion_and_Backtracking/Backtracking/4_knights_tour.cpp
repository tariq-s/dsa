#include <bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>> &chess)
{
    for (int i = 0; i < chess.size(); i++)
    {
        for (int j = 0; j < chess.size(); j++)
        {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printKnightsTour(vector<vector<int>> &chess, int n, int r, int c, int upcomingMove)
{

    if (r >= n || r < 0 || c >= n || c < 0 || chess[r][c] != 0)
        return;
    if (upcomingMove == n * n)
    {
        chess[r][c] = upcomingMove;
        display(chess);
        chess[r][c] = 0;
        return;
    }
    chess[r][c] = upcomingMove;
    printKnightsTour(chess, n, r - 2, c + 1, upcomingMove + 1);
    printKnightsTour(chess, n, r - 1, c + 2, upcomingMove + 1);
    printKnightsTour(chess, n, r + 1, c + 2, upcomingMove + 1);
    printKnightsTour(chess, n, r + 2, c + 1, upcomingMove + 1);
    printKnightsTour(chess, n, r + 2, c - 1, upcomingMove + 1);
    printKnightsTour(chess, n, r + 1, c - 2, upcomingMove + 1);
    printKnightsTour(chess, n, r - 1, c - 2, upcomingMove + 1);
    printKnightsTour(chess, n, r - 2, c - 1, upcomingMove + 1);
    chess[r][c] = 0;
}

int main()
{
    int n, sr, sc;
    cin >> n >> sr >> sc;
    vector<vector<int>> chess(n, vector<int>(n));
    printKnightsTour(chess, n, sr, sc, 1);
}