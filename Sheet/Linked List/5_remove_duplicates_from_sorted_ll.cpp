#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *h = NULL;
    ListNode *t = NULL;
    ListNode *next;
    ListNode *curr = head;
    while (curr)
    {
        next = curr->next;
        if (h == NULL)
        {
            h = curr;
            t = curr;
        }
        else
        {
            if (t->val != curr->val)
            {
                t->next = curr;
                t = t->next;
            }
            else
            {
                curr->next = NULL;
            }
        }
        t->next = NULL;
        curr = next;
    }
    return h;
}