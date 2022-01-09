#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    int s = 0, e = n - 1;
    while (s < e)
    {
        for (int i = 0; i < n; i++)
        {
            int temp = matrix[i][s];
            matrix[i][s] = matrix[i][e];
            matrix[i][e] = temp;
        }
        s++;
        e--;
    }
}