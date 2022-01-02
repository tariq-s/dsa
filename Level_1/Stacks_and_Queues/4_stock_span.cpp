#include <bits/stdc++.h>
using namespace std;
void display(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }
}
vector<int> solve(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans;
    ans.push_back(-1);

    stack<int> Stack;
    Stack.push(0);

    for (int i = 1; i < n; i++)
    {
        while (Stack.size() != 0 && arr[Stack.top()] <= arr[i])
        {
            Stack.pop();
        }
        if (Stack.size() == 0)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(Stack.top());
        }
        Stack.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = i - ans[i];
    }
    return ans;
}
int main(int argc, char **argv)
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> span(n, 0);
    span = solve(arr);
    display(span);
    return 0;
}