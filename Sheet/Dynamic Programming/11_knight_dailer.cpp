#include <bits/stdc++.h>
using namespace std;

int knightDialer(int n)
{
    // int rows = 4, cols = 3;
    int mod = 1000000007;
    vector<vector<long long>> prev = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1},
        {0, 1, 0}};
    long long count = 10;
    vector<vector<long long>> curr(4, vector<long long>(3));
    for (int i = 2; i <= n; i++)
    {
        count = 0;
        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                if ((x == 3 && y == 0) || (x == 3 && y == 2))
                {
                    curr[x][y] = 0;
                    continue;
                }
                if (x - 2 >= 0 && y + 1 < 3)
                    curr[x][y] += prev[x - 2][y + 1] % mod;
                if (x - 1 >= 0 && y + 2 < 3)
                    curr[x][y] += prev[x - 1][y + 2] % mod;
                if (x - 2 >= 0 && y - 1 >= 0)
                    curr[x][y] += prev[x - 2][y - 1] % mod;
                if (x - 1 >= 0 && y - 2 >= 0)
                    curr[x][y] += prev[x - 1][y - 2] % mod;
                if (x + 1 < 4 && y + 2 < 3)
                    curr[x][y] += prev[x + 1][y + 2] % mod;
                if (x + 2 < 4 && y + 1 < 3)
                    curr[x][y] += prev[x + 2][y + 1] % mod;
                if (x + 2 < 4 && y - 1 >= 0)
                    curr[x][y] += prev[x + 2][y - 1] % mod;
                if (x + 1 < 4 && y - 2 >= 0)
                    curr[x][y] += prev[x + 1][y - 2] % mod;
                count = (count + curr[x][y] % mod) % mod;
            }
        }
        prev = curr;
        curr = vector<vector<long long>>(4, vector<long long>(3));
    }
    return (count % 1000000007);
}