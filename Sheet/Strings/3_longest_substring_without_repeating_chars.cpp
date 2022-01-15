#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    int i = 0, j = 0;
    unordered_map<char, bool> map;
    int res = 0;
    while (i < n && j < n)
    {
        while (j < n && map.find(s[j]) == map.end())
        {
            map[s[j]] = true;
            j++;
        }
        if (res < map.size())
            res = map.size();
        while (s[i] != s[j])
        {
            map.erase(s[i]);
            i++;
        }
        map.erase(s[i]);
        i++;
    }
    return res;
}