#include <bits/stdc++.h>
using namespace std;

int countBinaryStrings(int n)
{
    int ending_z[n + 1];
    int ending_o[n + 1];

    ending_z[0] = ending_o[0] = 0;
    ending_z[1] = ending_o[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        ending_z[i] = ending_o[i - 1];
        ending_o[i] = ending_o[i - 1] + ending_z[i - 1];
    }
    return ending_z[n] + ending_o[n];
}

int main()
{
    int n;
    cin >> n;
    cout << countBinaryStrings(n);
    return 0;
}