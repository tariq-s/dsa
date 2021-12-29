#include <iostream>
#include <vector>
using namespace std;

vector<int> allIndex(vector<int> &arr, int idx, int data, int n)
{
    if (idx == n)
        return {};
    vector<int> a1 = allIndex(arr, idx + 1, data, n);
    if (arr[idx] == data)
    {
        a1.insert(a1.begin(), idx);
    }
    return a1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        arr.push_back(d);
    }
    int data;
    cin >> data;
    vector<int> ans = allIndex(arr, 0, data, arr.size());
    if (ans.size() == 0)
    {
        cout << endl;
        return 0;
    }
    for (int ele : ans)
        cout << ele << endl;

    return 0;
}