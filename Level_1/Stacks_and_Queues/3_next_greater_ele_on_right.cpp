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
    Stack.push(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        while (Stack.size() != 0 && Stack.top() <= arr[i])
        {
            Stack.pop();
        }
        if (Stack.size() == 0)
        {
            ans.insert(ans.begin(), -1);
        }
        else
        {
            ans.insert(ans.begin(), Stack.top());
        }
        Stack.push(arr[i]);
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
    vector<int> nge(n, 0);
    nge = solve(arr);
    display(nge);
    return 0;
}