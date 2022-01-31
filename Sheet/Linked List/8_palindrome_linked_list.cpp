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
ListNode *middle_node(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
bool isPalindrome(ListNode *head)
{
    ListNode *mid = middle_node(head);
    ListNode *p1 = head;
    ListNode *p2 = mid->next;
    mid->next = NULL;
    ListNode *rev2 = reverse(p2);
    while (p1 && rev2)
    {
        if (p1->val != rev2->val)
            return false;
        p1 = p1->next;
        rev2 = rev2->next;
    }
    return true;
}