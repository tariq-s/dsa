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

ListNode *removeElements(ListNode *head, int val)
{
    if (head == NULL)
        return NULL;
    ListNode *p = head;
    while (p && p->next)
    {
        if (p->next->val == val)
            p->next = p->next->next;
        else
            p = p->next;
    }
    return head->val == val ? head->next : head;
}