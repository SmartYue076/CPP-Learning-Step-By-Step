#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// remove elements without dummynode
ListNode *removeElements(ListNode *head, int val)
{
    while (head != NULL && head->val == val)
    {
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
    }
    ListNode *cur = head;
    while (cur != NULL && cur->next != NULL) // prevent head is NULL
    {
        if (cur->next->val == val)
        {
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        else
        {
            cur = cur->next;
        }
    }
    return head;
}

// remove elements with dummynode
ListNode *removeElements(ListNode *head, int val)
{
    ListNode *dummynode = new ListNode(0);
    dummynode->next = head;
    ListNode *cur = dummynode;
    while (cur != NULL and cur->next != NULL)
    {
        if (cur->next->val == val)
        {
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        else
        {
            cur = cur->next;
        }
    }
    head = dummynode->next;
    delete dummynode;
    return head;
}