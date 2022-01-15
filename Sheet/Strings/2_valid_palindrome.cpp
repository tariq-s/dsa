#include <bits/stdc++.h>
using namespace std;

bool isPal(string s)
{
    int i = 0;
    int j = s.size() - 1;

    while (i < j && s[i] == s[j])
    {
        i++;
        j--;
    }
    return i >= j;
}
bool validPalindrome(string s)
{
    if (isPal(s))
        return true;
    int i = 0, j = s.size() - 1;
    while (s[i] == s[j])
    {
        i++;
        j--;
    }
    return isPal(s.substr(i, j - i)) || isPal(s.substr(i + 1, j - i));
}