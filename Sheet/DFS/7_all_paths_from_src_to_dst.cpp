#include <bits/stdc++.h>
using namespace std;

void get_paths(int i, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &path, vector<vector<int>> &paths, int n)
{
    if (visited[i])
        return;

    if (i == n - 1)
    {
        path.push_back(i);
        paths.push_back(path);
        path.pop_back();
        return;
    }
    visited[i] = true;
    path.push_back(i);
    for (int nei : graph[i])
        get_paths(nei, graph, visited, path, paths, n);
    path.pop_back();
    visited[i] = false;
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> path;
    vector<vector<int>> paths;
    get_paths(0, graph, visited, path, paths, n);
    return paths;
}