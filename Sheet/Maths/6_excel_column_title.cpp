#include <bits/stdc++.h>
using namespace std;

string convertToTitle(int columnNumber)
{
    string res = "";
    while (columnNumber)
    {
        columnNumber--;
        char c = (columnNumber % 26) + 'A';
        res += c;
        columnNumber /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
}