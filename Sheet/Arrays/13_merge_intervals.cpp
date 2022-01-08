#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    stack<vector<int>> Stack;
    Stack.push(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (Stack.top()[1] < intervals[i][0])
        {
            Stack.push(intervals[i]);
        }
        else
        {
            Stack.top()[1] = max(Stack.top()[1], intervals[i][1]);
        }
    }
    vector<vector<int>> res(Stack.size());

    while (Stack.size())
    {
        res[Stack.size() - 1] = Stack.top();
        Stack.pop();
    }
    return res;
}