#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

Node *flatten(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        if (curr->child == NULL)
        {
            curr = curr->next;
            continue;
        }
        Node *next = curr->next;
        if (next)
            next->prev = NULL;

        Node *next_level = curr->child;
        curr->next = next_level;
        next_level->prev = curr;

        curr->child = NULL;

        while (next_level->next)
            next_level = next_level->next;

        next_level->next = next;
        if (next)
            next->prev = next_level;

        curr = flatten(curr);
        curr = next;
    }
    return head;
}