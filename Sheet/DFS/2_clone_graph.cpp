#include <bits/stdc++.h>
using namespace std;

Node *clone_dfs(vector<bool> &visited, Node *node, unordered_map<Node *, Node *> &map)
{
    if (!node)
        return NULL;
    if (visited[node->val])
        return map[node];
    visited[node->val] = true;
    Node *new_node = new Node(node->val);
    map[node] = new_node;
    for (Node *n : node->neighbors)
    {
        new_node->neighbors.push_back(clone_dfs(visited, n, map));
    }
    return new_node;
}
Node *cloneGraph(Node *node)
{
    vector<bool> visited(101, false);
    unordered_map<Node *, Node *> map;
    return clone_dfs(visited, node, map);
}