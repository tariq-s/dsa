#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> next_greater(n);
    stack<int> Stack;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!Stack.empty() && temperatures[Stack.top()] <= temperatures[i])
            Stack.pop();
        if (Stack.empty())
            next_greater[i] = -1;
        else
            next_greater[i] = Stack.top();
        Stack.push(i);
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        if (next_greater[i] == -1)
            res[i] = 0;
        else
            res[i] = next_greater[i] - i;
    }
    return res;
}