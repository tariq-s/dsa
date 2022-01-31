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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            if (head == NULL)
            {
                head = list1;
            }
            else
            {
                tail->next = list1;
            }
            tail = list1;
            list1 = list1->next;
        }
        else
        {
            if (head == NULL)
            {
                head = list2;
            }
            else
            {
                tail->next = list2;
            }
            tail = list2;
            list2 = list2->next;
        }
        tail->next = NULL;
    }
    if (list1)
    {
        if (head == NULL)
            head = list1;
        else
            tail->next = list1;
    }
    else if (list2)
    {
        if (head == NULL)
            head = list2;
        else
            tail->next = list2;
    }
    return head;
}