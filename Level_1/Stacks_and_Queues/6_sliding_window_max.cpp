#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

vector<int> next_greatest_left(vector<int> arr)
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
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    vector<int> ans;

    vector<int> ngl = next_greatest_left(arr);

    for (int i = k - 1; i < n; i++)
    {
        int j = i;
        while (i - k + 1 <= ngl[j])
        {
            j = ngl[j];
        }
        ans.push_back(arr[j]);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}