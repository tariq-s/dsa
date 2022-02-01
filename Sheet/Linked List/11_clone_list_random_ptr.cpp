#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    Node *copy_head = new Node(-1);
    Node *copy_tail = copy_head;
    unordered_map<Node *, Node *> map;

    Node *curr = head;
    while (curr)
    {
        Node *temp = new Node(curr->val);
        map[curr] = temp;
        copy_tail->next = temp;
        copy_tail = temp;
        curr = curr->next;
    }

    curr = head;
    Node *copy_curr = copy_head->next;
    while (curr)
    {
        copy_curr->random = curr->random ? map[curr->random] : NULL;
        curr = curr->next;
        copy_curr = copy_curr->next;
    }
    return copy_head->next;
}

Node *copyRandomList(Node *head)
{
    Node *copy_head = new Node(-1);
    Node *copy_tail = copy_head;
    unordered_map<Node *, Node *> map;

    Node *curr = head;
    while (curr)
    {
        Node *temp = new Node(curr->val);
        map[curr] = temp;
        copy_tail->next = temp;
        copy_tail = temp;
        curr = curr->next;
    }

    curr = head;
    Node *copy_curr = copy_head->next;
    while (curr)
    {
        copy_curr->random = curr->random ? map[curr->random] : NULL;
        curr = curr->next;
        copy_curr = copy_curr->next;
    }
    return copy_head->next;
}