#include <bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s)
{
    int n = s.size();
    string res1 = "";
    int open = 0;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == '(')
            open++;
        else if (c == ')')
        {
            if (open == 0)
                continue;
            open--;
        }
        res1 += c;
    }
    string res = "";
    for (int i = res1.size() - 1; i >= 0; i--)
    {
        if (open > 0 && res1[i] == '(')
        {
            open--;
            continue;
        }

        res = res1[i] + res;
    }
    return res;
}