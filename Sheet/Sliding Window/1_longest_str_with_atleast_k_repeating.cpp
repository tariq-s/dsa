#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k)
{
    if (s.size() == 0)
        return 0;
    unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;
    int res = 0;
    int start = 0;
    int end;
    for (end = 0; end < s.size(); end++)
    {
        if (freq[s[end]] < k)
        {
            res = max(res, longestSubstring(s.substr(start, end - start), k));
            start = end + 1;
        }
    }

    if (end - start == s.size())
        return s.size();
    return start < end ? max(res, longestSubstring(s.substr(start), k)) : res;
}