#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s)
{
    vector<int> last_occ(26);
    for (int i = 0; i < s.size(); i++)
        last_occ[s[i] - 'a'] = i;
    vector<int> ans;
    int split = 0;
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        split = max(split, last_occ[s[i] - 'a']);
        if (i == split)
        {
            ans.push_back(i - j + 1);
            j = i + 1;
        }
    }
    return ans;
}