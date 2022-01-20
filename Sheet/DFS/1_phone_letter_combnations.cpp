#include <bits/stdc++.h>
using namespace std;

vector<string> keys = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void get_combinations(string digits, int idx, string asf, vector<string> &ans)
{
    if (idx == digits.size())
    {
        ans.push_back(asf);
        return;
    }
    string curr_keys = keys[digits[idx] - '0'];
    for (char c : curr_keys)
    {
        get_combinations(digits, idx + 1, asf + c, ans);
    }
}
vector<string> letterCombinations(string digits)
{
    if (digits.size() == 0)
        return {};
    vector<string> ans;
    get_combinations(digits, 0, "", ans);
    return ans;
}