#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> next_smaller_left(n, 0);
    next_smaller_left[0] = -1;

    stack<int> Stack;
    Stack.push(0);
    for (int i = 1; i < n; i++)
    {
        while (Stack.size() != 0 && arr[Stack.top()] >= arr[i])
        {
            Stack.pop();
        }
        if (Stack.size() == 0)
        {
            next_smaller_left[i] = -1;
        }
        else
        {
            next_smaller_left[i] = Stack.top();
        }

        Stack.push(i);
    }
    vector<int> next_smaller_right(n, 0);
    next_smaller_right[n - 1] = n;
    Stack = stack<int>();
    Stack.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (Stack.size() != 0 && arr[Stack.top()] >= arr[i])
        {
            Stack.pop();
        }
        if (Stack.size() == 0)
        {
            next_smaller_right[i] = n;
        }
        else
        {
            next_smaller_right[i] = Stack.top();
        }
        Stack.push(i);
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (next_smaller_right[i] - next_smaller_left[i] - 1) * arr[i]);
    }

    cout << ans;
    return 0;
}