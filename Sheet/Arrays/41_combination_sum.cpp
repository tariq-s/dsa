#include <bits/stdc++.h>
using namespace std;

void get_comb(vector<int> &candidates, int idx, int target, vector<int> &comb, vector<vector<int>> &res)
{
    if (target < 0)
        return;
    if (target == 0)
    {
        res.push_back(comb);
        return;
    }
    for (int i = idx; i < candidates.size(); i++)
    {
        comb.push_back(candidates[i]);
        get_comb(candidates, i, target - candidates[i], comb, res);
        comb.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    int n = candidates.size();
    vector<vector<int>> res;
    vector<int> comb;
    get_comb(candidates, 0, target, comb, res);
    return res;
}