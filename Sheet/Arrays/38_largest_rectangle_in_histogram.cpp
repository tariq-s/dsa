#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> left(n);
    vector<int> right(n);
    stack<int> Stack;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!Stack.empty() && heights[Stack.top()] >= heights[i])
        {
            Stack.pop();
        }
        if (Stack.empty())
            right[i] = n;
        else
            right[i] = Stack.top();
        Stack.push(i);
    }
    Stack = stack<int>();
    for (int i = 0; i < n; i++)
    {
        while (!Stack.empty() && heights[Stack.top()] >= heights[i])
        {
            Stack.pop();
        }
        if (Stack.empty())
            left[i] = -1;
        else
            left[i] = Stack.top();
        Stack.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
    }
    return ans;
}