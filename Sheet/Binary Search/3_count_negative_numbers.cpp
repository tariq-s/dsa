#include <bits/stdc++.h>
using namespace std;

int count_negatives_in_array(vector<int> &arr)
{
    if (arr[0] < 0)
        return arr.size();
    if (arr.back() > 0)
        return 0;
    int ans;
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= 0)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return arr.size() - ans - 1;
}
int countNegatives(vector<vector<int>> &grid)
{
    int res = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        cout << count_negatives_in_array(grid[i]) << " ";
        res += count_negatives_in_array(grid[i]);
    }
    return res;
}