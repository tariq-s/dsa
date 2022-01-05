#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array,n length of array and k.
// It should print required output.

void print_heap_rev(priority_queue<int, vector<int>, greater<int>> h)
{
    if (h.size() == 0)
    {
        return;
    }
    int top = h.top();
    h.pop();
    print_heap_rev(h);
    cout << top << " ";
}

void solve(int n, vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < k; i++)
    {
        heap.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] > heap.top())
        {
            heap.pop();
            heap.push(arr[i]);
        }
    }
    print_heap_rev(heap);
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int k;
    cin >> k;
    solve(n, v, k);
}