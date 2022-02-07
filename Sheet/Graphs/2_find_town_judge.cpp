#include <bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>> &trust)
{
    vector<vector<bool>> trusts(n + 1, vector<bool>(n + 1, false));
    for (vector<int> e : trust)
        trusts[e[0]][e[1]] = true;
    stack<int> Stack;
    for (int i = 1; i <= n; i++)
        Stack.push(i);
    while (Stack.size() > 1)
    {
        int p1 = Stack.top();
        Stack.pop();
        int p2 = Stack.top();
        Stack.pop();

        if (trusts[p1][p2] && trusts[p2][p1])
            continue;
        if (trusts[p1][p2])
            Stack.push(p2);
        else
            Stack.push(p1);
    }
    if (Stack.empty())
        return -1;
    int pot = Stack.top();
    for (int i = 1; i <= n; i++)
    {
        if (trusts[pot][i])
            return -1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == pot)
            continue;
        if (!trusts[i][pot])
            return -1;
    }
    return pot;
}