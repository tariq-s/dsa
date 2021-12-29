#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> get_maze_paths(int sr, int sc, int dr, int dc)
{
    //Write your code here
    if (sr > dr || sc > dc)
        return {};
    if (sr == dr && sc == dc)
        return {""};
    vector<string> ans;
    vector<string> h_moves;
    for (int i = 1; i <= dc; i++)
    {
        h_moves = get_maze_paths(sr, sc + i, dr, dc);
        for (int j = 0; j < h_moves.size(); j++)
        {
            ans.push_back("h" + to_string(i) + h_moves[j]);
        }
    }
    vector<string> v_moves;
    for (int i = 1; i <= dr; i++)
    {
        v_moves = get_maze_paths(sr + i, sc, dr, dc);
        for (int j = 0; j < v_moves.size(); j++)
        {
            ans.push_back("v" + to_string(i) + v_moves[j]);
        }
    }
    vector<string> d_moves;
    for (int i = 1; i <= min(dr, dc); i++)
    {
        d_moves = get_maze_paths(sr + i, sc + i, dr, dc);
        for (int j = 0; j < d_moves.size(); j++)
        {
            ans.push_back("d" + to_string(i) + d_moves[j]);
        }
    }
    return ans;
}

void display(vector<string> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> ans = get_maze_paths(0, 0, n - 1, m - 1);
    display(ans);

    return 0;
}