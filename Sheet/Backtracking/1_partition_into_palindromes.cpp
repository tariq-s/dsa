#include <bits/stdc++.h>
using namespace std;

bool is_pal(string st)
{
    int s = 0, e = st.size() - 1;
    while (s < e && st[s] == st[e])
    {
        s++;
        e--;
    }
    return s >= e;
}
void get_partitions(string s, vector<string> &part, vector<vector<string>> &res)
{
    if (s.size() == 0)
    {
        res.push_back(part);
        return;
    }
    for (int i = 1; i <= s.size(); i++)
    {
        if (is_pal(s.substr(0, i)))
        {
            part.push_back(s.substr(0, i));
            get_partitions(s.substr(i), part, res);
            part.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> part;
    get_partitions(s, part, res);
    return res;
}