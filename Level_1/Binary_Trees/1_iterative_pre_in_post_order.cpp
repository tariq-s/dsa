#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Pair
{
public:
    Node *node = nullptr;
    int state = 0;
    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
    }
};

Node *construct(vector<int> &arr)
{
    Node *root = new Node(arr[0]);
    pair<Node *, int> p = {root, 1};

    stack<pair<Node *, int>> st;
    st.push(p);

    int idx = 1;
    while (!st.empty())
    {
        if (st.top().second == 1)
        {
            st.top().second++;
            if (arr[idx] != -1)
            {
                st.top().first->left = new Node(arr[idx]);
                pair<Node *, int> lp = {st.top().first->left, 1};
                st.push(lp);
            }
            else
            {
                st.top().first->left = nullptr;
            }
            idx++;
        }
        else if (st.top().second == 2)
        {
            st.top().second++;
            if (arr[idx] != -1)
            {
                st.top().first->right = new Node(arr[idx]);
                pair<Node *, int> rp = {st.top().first->right, 1};
                st.push(rp);
            }
            else
            {
                st.top().first->right = nullptr;
            }
            idx++;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}

void iterativePrePostInTraversal(Node *node)
{
    vector<int> pre, inorder, post;

    stack<Pair> Stack;
    Stack.push(Pair(node, 0));

    while (!Stack.empty())
    {
        Pair x = Stack.top();
        if (x.state == 0)
        {
            pre.push_back(x.node->data);
            x.state++;

            if (x.node->left)
                Stack.push(Pair(x.node->left, 0));
        }
        else if (x.state == 1)
        {
            inorder.push_back(x.node->data);
            x.state++;

            if (x.node->right)
                Stack.push(Pair(x.node->right, 0));
        }
        else
        {
            post.push_back(x.node->data);
            Stack.pop();
        }
    }

    for (int i = 0; i < pre.size(); i++)
    {
        cout << pre[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < post.size(); i++)
    {
        cout << post[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if (temp == "n")
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = stoi(temp);
        }
    }
    Node *root = construct(arr);
    iterativePrePostInTraversal(root);
}