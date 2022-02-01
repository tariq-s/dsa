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

int length(ListNode *head)
{
    int res = 0;
    while (head)
    {
        res++;
        head = head->next;
    }
    return res;
}
ListNode *rotateRight(ListNode *head, int k)
{
    if (k == 0 || !head || !head->next)
        return head;
    k = k % length(head);
    if (k == 0)
        return head;
    ListNode *p1 = head;
    ListNode *p2 = head;

    for (int i = 0; i < k; i++)
        p2 = p2->next;

    while (p2->next)
    {
        p1 = p1->next;
        p2 = p2->next;
    }

    ListNode *p = p1->next;
    p1->next = NULL;

    p2->next = head;

    return p;
}