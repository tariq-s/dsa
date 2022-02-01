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

ListNode *reverse(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = NULL;
    ListNode *next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
ListNode *get_mid(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void reorderList(ListNode *head)
{
    ListNode *mid = get_mid(head);

    ListNode *p1 = head;
    ListNode *p2 = mid->next;
    mid->next = NULL;

    ListNode *rev2 = reverse(p2);

    ListNode *dummy = new ListNode(-1);
    ListNode *tail = dummy;

    while (p1)
    {
        tail->next = p1;
        tail = p1;
        p1 = p1->next;
        tail->next = NULL;
        if (rev2)
        {
            tail->next = rev2;
            tail = rev2;
            rev2 = rev2->next;
            tail->next = NULL;
        }
    }
}