#include <iostream>
using namespace std;

int powerLogarithmic(int x, int n)
{
    if (n == 0)
        return 1;
    int power_ = powerLogarithmic(x, n / 2);
    if (n % 2 == 0)
    {
        return power_ * power_;
    }
    return power_ * power_ * x;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << powerLogarithmic(x, n);
}