#include <bits/stdc++.h>
using namespace std;

int max_sum_non_adj(int arr[], int n)
{
    int inc[n];
    int exc[n];

    inc[0] = arr[0];
    exc[0] = 0;
    for (int i = 1; i < n; i++)
    {
        inc[i] = arr[i] + exc[i - 1];
        exc[i] = max(exc[i - 1], inc[i - 1]);
    }
    return max(inc[n - 1], exc[n - 1]);
}

int main()
{
    int arr[6] = {5, 10, 10, 100, 5, 6};
    cout << max_sum_non_adj(arr, 6);
    return 0;
}