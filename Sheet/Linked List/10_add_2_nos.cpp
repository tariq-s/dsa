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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(-1);
    ListNode *tail = head;
    int carry = 0;
    while (l1 || l2 || carry)
    {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int val = x + y + carry;
        carry = val / 10;

        ListNode *temp = new ListNode(val % 10);
        tail->next = temp;
        tail = temp;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    return head->next;
}