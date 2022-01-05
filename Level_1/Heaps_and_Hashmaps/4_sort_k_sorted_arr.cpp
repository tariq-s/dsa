#include <bits/stdc++.h>
using namespace std;

int sortK(int arr[], int n, int k)
{

    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i <= k; i++)
    {
        heap.push(arr[i]);
    }
    cout << heap.top() << endl;
    heap.pop();

    for (int i = k + 1; i < n; i++)
    {
        heap.push(arr[i]);
        cout << heap.top() << endl;
        heap.pop();
    }

    while (heap.size())
    {
        cout << heap.top() << endl;
        heap.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        arr[i] = data;
    }
    int k;
    cin >> k;
    sortK(arr, n, k);
    return 0;
}