#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n;

    int arr1[n];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    map<int, int> f_map;
    for (int i = 0; i < n; i++)
        f_map[arr1[i]]++;

    for (int i = 0; i < m; i++)
    {
        if (f_map[arr2[i]] > 0)
        {
            cout << arr2[i] << endl;
            f_map[arr2[i]]--;
        }
    }
    return 0;
}