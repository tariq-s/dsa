#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int rs = 0, re = matrix.size() - 1, cs = 0, ce = matrix[0].size() - 1;
    int total_ele = matrix.size() * matrix[0].size();
    int count = 0;
    while (count < total_ele)
    {
        for (int i = cs; i <= ce; i++)
        {
            res.push_back(matrix[rs][i]);
            count++;
        }
        rs++;
        for (int i = rs; i <= re && count < total_ele; i++)
        {
            res.push_back(matrix[i][ce]);
            count++;
        }
        ce--;
        for (int i = ce; i >= cs && count < total_ele; i--)
        {
            res.push_back(matrix[re][i]);
            count++;
        }
        re--;
        for (int i = re; i >= rs && count < total_ele; i--)
        {
            res.push_back(matrix[i][cs]);
            count++;
        }
        cs++;
    }
    return res;
}