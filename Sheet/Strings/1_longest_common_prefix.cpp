#include <bits/stdc++.h>
using namespace std;

string lcp(string s1, string s2)
{
    int n = min(s1.size(), s2.size());
    int i = 0;
    while (i < n)
    {
        if (s1[i] == s2[i])
            i++;
        else
            break;
    }
    return s1.substr(0, i);
}
string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    if (n == 0)
        return "";
    if (n == 1)
        return strs[0];
    string res = lcp(strs[0], strs[1]);
    for (int i = 2; i < n; i++)
    {
        res = lcp(res, strs[i]);
    }
    return res;
}