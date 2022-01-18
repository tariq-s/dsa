#include <bits/stdc++.h>
using namespace std;

int dist(vector<int> &p1, vector<int> &p2)
{
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
}
bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
{
    unordered_map<int, int> map;

    vector<vector<int>> points = {p1, p2, p3, p4};
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            map[dist(points[i], points[j])]++;
        }
    }
    if (map.size() != 2)
        return false;

    int side = INT_MAX, diag = INT_MIN;
    for (auto entry : map)
    {
        side = min(side, entry.first);
        diag = max(diag, entry.first);
    }

    return (map[side] == 4) && (map[diag] == 2);
}