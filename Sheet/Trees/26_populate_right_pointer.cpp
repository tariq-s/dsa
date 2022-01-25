#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    if (!root)
        return NULL;
    queue<Node *> Queue;
    Queue.push(root);

    while (!Queue.empty())
    {
        int size = Queue.size();

        for (int i = 0; i < size; i++)
        {
            Node *x = Queue.front();
            Queue.pop();
            if (i < size - 1)
                x->next = Queue.front();
            if (x->left)
                Queue.push(x->left);
            if (x->right)
                Queue.push(x->right);
        }
    }
    return root;
}