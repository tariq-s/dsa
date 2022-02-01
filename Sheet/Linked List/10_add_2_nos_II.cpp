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
    while (curr)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *p1 = reverse(l1);
    ListNode *p2 = reverse(l2);
    ListNode *head = new ListNode(-1);
    ListNode *tail = head;
    int carry = 0;

    while (p1 || p2 || carry)
    {
        int x = p1 ? p1->val : 0;
        int y = p2 ? p2->val : 0;

        int val = x + y + carry;
        ListNode *temp = new ListNode(val % 10);
        carry = val / 10;

        tail->next = temp;
        tail = temp;

        if (p1)
            p1 = p1->next;
        if (p2)
            p2 = p2->next;
    }
    ListNode *res = head->next;
    head->next = NULL;
    return reverse(res);
}