#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

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