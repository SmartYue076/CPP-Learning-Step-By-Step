#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lenA = 0;
        int lenB = 0;
        ListNode *cur = headA;
        while (cur != nullptr)
        {
            cur = cur->next;
            ++lenA;
        }
        cur = headB;
        while (cur != nullptr)
        {
            cur = cur->next;
            ++lenB;
        }

        ListNode *curA = headA;
        ListNode *curB = headB;
        if (lenA > lenB)
        {
            int diff = lenA - lenB;
            while (diff)
            {
                curA = curA->next;
                diff--;
            }
        }
        else if (lenA < lenB)
        {
            int diff = lenB - lenA;
            while (diff)
            {
                curB = curB->next;
                diff--;
            }
        }

        if (lenA == lenB and curA == curB)
            return curA;

        while (curA != nullptr and curB != nullptr)
        {
            if (curA == curB)
                return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }

    void printLinkedList(ListNode *head)
    {
        ListNode *cur = head;
        while (cur != nullptr)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void addAtTail(ListNode *head, int val)
    {
        ListNode *cur = head;
        if (cur == nullptr)
        {
            cur = new ListNode(val);
            return;
        }
        while (cur->next != nullptr) // attention: not cur
        {
            cur = cur->next;
        }
        ListNode *node = new ListNode(val);
        cur->next = node;
    }
};

int main()
{
    Solution test = Solution();
    ListNode *head = new ListNode(1);
    return 0;
}