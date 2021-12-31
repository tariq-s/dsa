#include <iostream>
#include <vector>
using namespace std;

void ways(int n, int k)
{
    long same = k;
    long diff = k * (k - 1);
    long total = diff + same;

    for (int i = 3; i <= n; i++)
    {
        same = diff;
        diff = total * (k - 1);
        total = diff + same;
    }
    cout << total;
}

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;

    ways(n, k);
}