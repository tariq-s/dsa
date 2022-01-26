#include <bits/stdc++.h>
using namespace std;

bool compare(string w1, string w2, int dict[26])
{
    int i = 0;
    while (i < w1.size() && i < w2.size() && w1[i] == w2[i])
        i++;
    if (i == w1.size())
        return true;
    if (i == w2.size())
        return false;
    return dict[w1[i] - 'a'] < dict[w2[i] - 'a'];
}
bool isAlienSorted(vector<string> &words, string order)
{
    int dict[26];
    for (int i = 0; i < 26; i++)
    {
        dict[order[i] - 'a'] = i;
    }
    for (int i = 1; i < words.size(); i++)
    {
        if (!compare(words[i - 1], words[i], dict))
            return false;
    }
    return true;
}